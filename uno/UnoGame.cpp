#pragma warning (disable:4996)
#include "UnoGame.h"

using namespace std;

UnoGame::UnoGame()
{
	cout << "Start" << endl;
	BagofCards = new Bag<UnoCard>();
	drawDeck = new Queue<UnoCard>();
	fillBag();
	fillDrawDeck();
	player_container = new UnoPlayer[numPlayers];
	createPlayers();
	faceUpPile = new Stack<UnoCard>();
	setFaceUpCard();
}

UnoGame::~UnoGame()
{
	delete[] player_container;
	delete BagofCards;
	delete drawDeck;
	delete faceUpPile;
}

void UnoGame::fillBag()
{
	for (int i = 1; i <= cardCapacity; i++) {

		UnoCard redCard = UnoCard((Colour)RED, i);
		BagofCards->add(redCard);
		UnoCard yellowCard = UnoCard((Colour)YELLOW, i);
		BagofCards->add(yellowCard);
		UnoCard blueCard = UnoCard((Colour)BLUE, i);
		BagofCards->add(blueCard);
		UnoCard greenCard = UnoCard((Colour)GREEN, i);
		BagofCards->add(greenCard);
	}
	cout << "cards have been generated" << endl;
}

void UnoGame::fillDrawDeck()
{
	for (int i = 0; i < (int)BagofCards->capacity(); i++)
	{
		UnoCard tempCard1 = BagofCards->getOne();
		drawDeck->enqueue(tempCard1); // fill first 20
		BagofCards->add(tempCard1);
		UnoCard tempCard2 = BagofCards->getOne();
		drawDeck->enqueue(tempCard2); // fill second 20
	}

	cout << "Deck has been populated" << endl;
}

void UnoGame::createPlayers()
{
	for (int i = 0; i < numPlayers; i++) {
		UnoPlayer *player = new UnoPlayer();
		player->setName("Player No " + to_string(i + 1));

		for (int j = 0; j < initialHand; j++) {
			player->addToHand(drawDeck->dequeue());
		}
		player_container[i] = *player;
		cout << player_container[i].getName() << " has joined the game" << endl;
	}
}

void UnoGame::setFaceUpCard()
{
	faceUpPile->push(drawDeck->dequeue());
}

bool UnoGame::play()
{
	while (true) {

		for (int i = 0; i < numPlayers; i++) { //loop for the number of players
			UnoCard card = faceUpPile->peek(); //return the top of the fick up pile
			cout << "\n" << card << " is on the face up pile" << endl;
			cout << "\nIt is " << player_container[i].getName() << "'s turn";
			cout << "\n" << player_container[i];

			//when a card in the players hand matches the card in the face up pile (by number)
			if (player_container[i].isCardNumberMatch(card) >= 0) {
				faceUpPile->push(player_container[i].RemoveFromHand(player_container[i].isCardNumberMatch(card)));
				cout << player_container[i].getName() << " found a match! They played " << faceUpPile->peek() << endl;

				//when one card in left in the players hand
				if (player_container[i].oneCardLeft()) {
					cout << player_container[i].getName() << " yells UNO!" << endl;

				}

				//when players hand is empty
				if (player_container[i].emptyHand()) {
					cout << player_container[i].getName() << " wins!" << endl;
					return true; //exit loop
				}
			}

			//when a card in the players hand matches the card in the face up pile (by Colour)
			else if (player_container[i].isCardColourMatch(card) >= 0) {
				faceUpPile->push(player_container[i].RemoveFromHand(player_container[i].isCardColourMatch(card)));
				cout << player_container[i].getName() << " found a match! They played " << faceUpPile->peek() << endl;

				//when one card in left in the players hand
				if (player_container[i].oneCardLeft()) {
					cout << player_container[i].getName() << " yells UNO!" << endl;

				}

				//when players hand is empty
				if (player_container[i].emptyHand()) {
					cout << player_container[i].getName() << " wins!" << endl;
					return true; //exit loop
				}
			}

			//when there is no match between the players hand and the pick up pile 
			else {

				//when the deck is empty
				if (drawDeck->isEmpty()) {
					UnoCard temp = faceUpPile->pop();
					Bag<UnoCard> tempBag = Bag<UnoCard>();
					
					//when the face up pile is not empty
					while (!faceUpPile->isEmpty()) {
						int cardCounter = 0;
						//when bag is not full
						while (!tempBag.isFull()) {
							if (faceUpPile->isEmpty()) break; //in case face up pile is empty, exit loop
							tempBag.add(faceUpPile->pop());
							cardCounter++;
						}

						for (int i = 0; i < cardCounter; i++)
							drawDeck->enqueue(tempBag.getOne());
					}
				
					faceUpPile->push(temp);
					cout << "The deck has been repopulated" << endl;
				}

				player_container[i].addToHand(drawDeck->dequeue());
				cout << player_container[i].getName() << " did not find a match. They drew a card" << endl;
			}
		}
	}
}

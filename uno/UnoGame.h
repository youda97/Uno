#pragma once
#include "Bag.h"
#include "Queue.h"
#include "UnoCard.h"
#include "UnoPlayer.h"
#include "Stack.h"

#define numPlayers 3
#define initialHand 7
#define cardCapacity 5

class UnoGame { //represents a game of Uno

private:

	Bag<UnoCard> *BagofCards;
	Queue<UnoCard> *drawDeck;
	UnoPlayer * player_container;
	Stack<UnoCard> *faceUpPile;

	void fillBag();
	void fillDrawDeck();
	void createPlayers();
	void setFaceUpCard();

public:
	UnoGame(); //initializes the game
	~UnoGame();
	bool play(); //Plays the game

};


#pragma warning (disable:4996)
#include "UnoPlayer.h"
#include "UnoGame.h"

using namespace std;

UnoPlayer::UnoPlayer()
{
	hand = new OrderedList<UnoCard>(7);
}

UnoPlayer::~UnoPlayer()
{
	delete hand;
}

int UnoPlayer::isCardNumberMatch(UnoCard card)
{
	int result = -1;
	for (int i = 1; i <= hand->getLength(); i++) {
		if (hand->retrieve(i).isNumberMatch(card)) {
			result = i;
			break;
		}
	}
	return result;
}

int UnoPlayer::isCardColourMatch(UnoCard card)
{
	int result = -1;
	for (int i = 1; i <= hand->getLength(); i++) {
		if (hand->retrieve(i).isColourMatch(card)) {
			result = i;
			break;
		}			
	}
	return result;
}

void UnoPlayer::setName(string name)
{
	playerName = name;
}

string UnoPlayer::getName() const
{
	return playerName;
}
 
void UnoPlayer::addToHand(UnoCard card)
{
	hand->insert(card);
}

bool UnoPlayer::emptyHand()
{
	return hand->isEmpty();
}

bool UnoPlayer::oneCardLeft()
{
	return ((int)hand->getLength() == 1);
}

UnoCard UnoPlayer::RemoveFromHand(int pos)
{

	return hand->remove(pos);
}


std::ostream & operator<<(std::ostream & os, const UnoPlayer & a)
{
	cout << a.getName() << ": " << endl;
	int i;
	for (i = 1; i < a.hand->getLength(); i++)
		cout << (UnoCard) a.hand->retrieve(i) << ", ";
	cout << (UnoCard)a.hand->retrieve(i) << endl;
	return os;
}


#pragma once
#include <iostream>
#include "OrderedList.h"
#include "UnoCard.h"

using namespace std;

class UnoPlayer { //represents a player in the game

private:

	string playerName;
	OrderedList<UnoCard> *hand;

public:
	UnoPlayer();
	~UnoPlayer();
	int isCardColourMatch(UnoCard card); //looks for a card match (using number)
	int isCardNumberMatch(UnoCard card); //looks for a card match (using colour)
	void setName(string name);
	string getName() const;
	void addToHand(UnoCard card);
	bool emptyHand(); //checks to see if the hand is empty
	bool oneCardLeft(); //checks when a player has only 1 card in their hand
	UnoCard RemoveFromHand(int pos);

	friend std::ostream& operator<<(std::ostream& os, const UnoPlayer &a); //prints out players card
};



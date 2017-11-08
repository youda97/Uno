#pragma once
#include <iostream>

// User defined colour types (user-defined integers) 
enum Colour { RED = 1, YELLOW = 2, BLUE = 3, GREEN = 4 };

class UnoCard { //represents a card in the game

private:

	Colour m_colour; // private storage of Colour
	int number;


public:
	UnoCard();
	UnoCard(Colour colour, int num);
	~UnoCard();

	void setcolour(Colour colour);
	inline Colour getcolour(void) const;
	void setNumber(int num);
	int getNumber() const;
	bool isColourMatch(UnoCard to);
	bool isNumberMatch(UnoCard to);

	char toCharColour(); // returns a char that "describes" card's colour
	char toCharNumber(); // returns a char that "describes" card's number

	friend std::ostream& operator<<(std::ostream& os, const UnoCard &c); //prints a card
};


// global operator functions comparing numbers of two cards
// The cards a and b are passed by reference
inline bool operator<(const UnoCard& a, const UnoCard& b) {
	if (a.getNumber() == b.getNumber())
		return (a.getcolour()<b.getcolour());
	else                            
		return (a.getNumber()<b.getNumber());
}
inline bool operator>(const UnoCard& a, const UnoCard& b) {
	if (a.getNumber() == b.getNumber())
		return (a.getcolour()>b.getcolour());
	else                            
		return (a.getNumber()>b.getNumber());
}

// checks equality of colour and number for two cards
inline bool operator==(UnoCard& a, UnoCard& b) {
	return (a.getNumber() == b.getNumber() && a.getcolour() == b.getcolour()); 
}
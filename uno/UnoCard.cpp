#pragma warning (disable:4996)
#include "UnoCard.h"


UnoCard::UnoCard()
{
}

UnoCard::UnoCard(Colour colour, int num)
{
	m_colour = colour;
	number = num;
}

UnoCard::~UnoCard()
{
}


void UnoCard::setcolour(Colour colour)
{
	m_colour = colour;
}

Colour UnoCard::getcolour() const
{
	return  m_colour;
}

void UnoCard::setNumber(int num)
{
	number = num;
}

int UnoCard::getNumber() const
{
	return number;
}

bool UnoCard::isColourMatch(UnoCard to)
{
	if (m_colour == to.m_colour)
		return true;
	return false;
}

bool UnoCard::isNumberMatch(UnoCard to)
{
	if (number == to.number)
		return true;
	return false;
}

char UnoCard::toCharColour()
{
	if (m_colour == (Colour)RED)            return 'R';
	else if (m_colour == (Colour)YELLOW)    return 'Y';
	else if (m_colour == (Colour)BLUE)      return 'B';
	else      return 'G';
}

char UnoCard::toCharNumber()
{
	if (number == 1)	    return '1';
	else if (number == 2)	return '2';
	else if (number == 3)	return '3';
	else if (number == 4)	return '4';
	else 	return '5';
	
}

std::ostream & operator<<(std::ostream & os, const UnoCard & c)
{	
	int colour = c.getcolour();
	int demo = c.getNumber();
	switch (colour) {
	case 1:
		os << "RED-";
		break;
	case 2:
		os << "YELLOW-";
		break;
	case 3:
		os << "BLUE-";
		break;
	case 4:
		os << "GREEN-";
		break;
	}

	switch (demo) {
	case 1:
		os << "1";
		break;
	case 2:
		os << "2";
		break;
	case 3:
		os << "3";
		break;
	case 4:
		os << "4";
		break;
	case 5:
		os << "5";
		break;
	}
	return os;
}

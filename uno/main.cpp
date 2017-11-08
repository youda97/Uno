#pragma warning (disable:4996)
#pragma once
#include <iostream>
#include "UnoGame.h"
#include "UnoPlayer.h"
#include "UnoCard.h"
#include <ctime>

using namespace std;

int main() {

	srand(time(NULL));

	cout << "Welcome to Uno" << endl;

	UnoGame *uno = new UnoGame();
	uno->play();

	//system("pause");
}
/**
Ronnie Casasola
CECS 282-07
Project 1- War
09/12/16
**/

#ifndef DECK_H
#define DECK_H
#include "card.h"

class Deck{

private:
	Card storage[52];
	int count;

public:
	Deck();
	void display();
	void shuffle();
	Card deal(); // returns card
	int cardsLeft();
};
#endif

/**
Ronnie Casasola
CECS 282-07
Project 1- War
09/12/16
**/

#include <iostream>
#include "deck.h"
#include "card.h"
using namespace std;

Card storage[52];
int x;
int y;

Deck::Deck(){
	char rankNames1[] = { 'A',  '2', '3', '4', '5', '6', '7', '8', '9', 'T' , 'J', 'Q', 'K' };
	char suitNames[] = "SHDC";
	int  i = 0;
	for (int s = 0; s < 4; s++) {
		for (int r = 0; r < 13; r++) {
			storage[i].setCard(rankNames1[r], suitNames[s]);
			i++;
		}
	}
	count = 52;
}

void Deck::display(){
	for (int i = 0; i < cardsLeft(); i++) {
		storage[i].display();
		cout << "\n";
	}
}

void Deck::shuffle(){
	for (int i = 0; i < 100000; i++) {
		x = rand() % count;
		y = rand() % count;
		Card temp;
		temp = storage[x];
		storage[x] = storage[y];
		storage[y] = temp;
	}
}

Card Deck::deal(){
	if (count > 0) {
		count--;
		return storage[count];
	}
}
int Deck::cardsLeft(){
	return count;
}
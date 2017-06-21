/**
Ronnie Casasola
CECS 282-07
Project 1- War
09/12/16
**/

#ifndef CARD_H
#define CARD_H

class Card {
	public: 
		Card();
		Card(char r, char s);
		void setCard(char r, char s);
		void display();
		char getValue();
		int Card::getNumValue();
	private: 
		char suit;
		char rank;
};
#endif

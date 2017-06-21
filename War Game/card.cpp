/**
Ronnie Casasola
CECS 282-07
Project 1- War
09/12/16
**/

#include <iostream>
#include "card.h"
#include <string>
using namespace std;

char suit;
char rank;
char rankNames1[] = { 'A',  '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

Card::Card(){
	suit = 'H';
	rank = '3';
}

Card::Card(char r, char s) {
	suit = s;
	rank = r;
}

void Card::setCard(char r, char s){
	rank = r;
	suit = s;
}

char Card::getValue(){
	return rank;
}

int Card::getNumValue() {
	for (int i = 0; i < 13; i++) {
		if (rankNames1[i] == rank) {
			return i + 1;
		}
	}
}


void Card::display() {
	char c = getValue();
	if (suit == 'H') {
		if (getNumValue() == 10) {
			cout << ".--------.\n";
			cout << "|10_  _  |\n";
			cout << "| ( \\/ ) |\n";
			cout << "|  \\  /  |\n";
			cout << "|   \\/ 10|\n";
			cout << ".--------.\n";
		}
		else {
			cout << ".--------.\n";
			cout << "|" << c << " _  _  |\n";
			cout << "| ( \\/ ) |\n";
			cout << "|  \\  /  | \n";
			cout << "|   \\/ " << c << " |\n";
			cout << ".--------.\n";
		}
	}
	 else if (suit == 'S') {
		 if (getNumValue() == 10) {
			 cout << ".--------.\n";
			 cout << "|" << 10 << "   .   |\n";
			 cout << "|   / \\  |\n";
			 cout << "|  (_,_) |\n";
			 cout << "|    I  " << 10 << " |\n";
			 cout << ".--------.\n";
		 }
		 else {
			 cout << ".--------.\n";
			 cout << "|" << c << "   .   |\n";
			 cout << "|   / \\  |\n";
			 cout << "|  (_,_) |\n";
			 cout << "|    I  " << c << "|\n";
			 cout << ".--------.\n";
		 }
	}else if (suit == 'D') {
		if (getNumValue() == 10) {
			cout << ".--------.\n";
			cout << "|" << 10 << " /\\   |\n";
			cout << "|  /  \\  |\n";
			cout << "|  \\  /  | \n";
			cout << "|   \\/ " << 10 << "| \n";
			cout << ".--------.\n";
		}
		else {
			cout << ".--------.\n";
			cout << "|" << c << "  /\\   |\n";
			cout << "|  /  \\  |\n";
			cout << "|  \\  /  | \n";
			cout << "|   \\/ " << c << "|  \n";
			cout << ".--------.\n";
		}
	}else if (suit == 'C') {
		if (getNumValue() == 10) {
			cout << ".--------.\n";
			cout << "|" << 10 << "  _   |\n";
			cout << "|   ( )  |\n";
			cout << "|  (_x_) | \n";
			cout << "|    Y " << 10 << "|\n";
			cout << ".--------.\n";
		}
		else {
			cout << ".--------.\n";
			cout << "|" << c << "   _   |\n";
			cout << "|   ( )  |\n";
			cout << "|  (_x_) | \n";
			cout << "|    Y " << c << " |\n";
			cout << ".--------.\n";
		}        
	}
}


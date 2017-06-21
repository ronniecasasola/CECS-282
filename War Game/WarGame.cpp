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

int main() {

	Deck deck;
	int mainLoop = true;
	int score = 0;
	int compScore = 0;

	while (mainLoop) {

		cout << "Score: " << score << "\n" "Computer Score: " << compScore << "\n" <<endl;
		cout << "1) Get a new card deck\n 2) Show all cards in the deck\n 3) Shuffle\n 4) Play war \n 5) Exit \n" << endl;
		int menuChoice;
		cin >> menuChoice;

		switch (menuChoice) {

		case 1: {
			score = 0;
			compScore = 0;
			deck = Deck();
			cout << "new deck!\n" << endl;
			break;
		}
		case 2: {
			deck.display();
			break;
		}
		case 3: {
			if (deck.cardsLeft() > 0) {
				deck.shuffle();
				cout << "Shuffled\n" << endl;
			}
			else {
				cout << "No more cards!" << endl;
			}
			break;
		}
		case 4: {
			int gameLoop = true;
			if (deck.cardsLeft() > 0) {
				while (gameLoop) {
					cout << "my card\n" << endl;
					Card mine = deck.deal();
					mine.display();

					cout << "your card\n" << endl;
					Card yours = deck.deal();
					yours.display();

					if (mine.getNumValue() == yours.getNumValue()) {
						cout << "Tie game - keep playing.\n" << endl;
					}
					else if (yours.getNumValue() > mine.getNumValue()) {
						score++;
						cout << "You win\n" << endl;
					}
					else {
						compScore++;
						cout << "I win!\n" << endl;
					}

					cout << "\nThere are " << deck.cardsLeft() << " cards in the deck.\n" << endl;

					if (!deck.cardsLeft()) {
						gameLoop = false;
					}
					else {
						cout << "Wanna play again? (y/n) \n" << endl;
						string repeat;
						gameLoop = (repeat == "y" || repeat == "yes");
					}
				}
			}
			else {
				cout << "No more cards!" << endl;
				gameLoop = 0;
			}
			break;
		}
		case 5: {
			cout << "Game Over!" << endl;
			mainLoop = false;
			break;
			}
		}
	}
	return 0;
}


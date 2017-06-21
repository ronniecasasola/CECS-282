// Ronald Casasola
// CECS 282 LAB 21

#include <iostream>
using namespace std;


const int ROWS = 4;
const int COLS = 5;

int getTotal(int arr[ROWS][COLS], int, int) {
	int total = 0;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			total = total + arr[i][j];
		}
	}

	return total;
}

double getAverage(int arr[ROWS][COLS], int, int) {
	int total = 0;
	int num = 0;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			total = total + arr[i][j];
			num++;
		}
	}

	return total / (double) num;
}

int getRowTotal(int arr[ROWS][COLS], int num, int COLS) {

	int total = 0;
	
	for (int j = 0; j < COLS; j++) {
		total = total + arr[num][j];
	}

	return total;
}

int getColumnTotal(int arr[ROWS][COLS], int num, int ROWS) {

	int total = 0;

	for (int j = 0; j < ROWS; j++) {
		total = total + arr[j][num];
	}

	return total;
}

int getHighestInRow(int arr[ROWS][COLS], int num, int COLS) {

	int highest = 0;

	for (int j = 0; j < COLS; j++) {
		if (arr[num][j] > highest) {
			highest = arr[num][j];
		}
	}

	return highest;
}

int getLowestInRow(int arr[ROWS][COLS], int num, int COLS) {

	int lowest = arr[num][0];

	for (int j = 0; j < COLS; j++) {
		if (arr[num][j] < lowest) {
			lowest = arr[num][j];
		}
	}

	return lowest;
}


int main() {

	// Array with test data
	int testArray[ROWS][COLS] =
	{ { 1, 2, 3, 4, 5 },
	{ 6, 7, 8, 9, 10 },
	{ 11, 12, 13, 14, 15 },
	{ 16, 17, 18, 19, 20 }
	};

	// Display the total of the array elements.
	cout << "The total of the array elements is "
		<< getTotal(testArray, ROWS, COLS)
		<< endl;

	// Display the average of the array elements.
	cout << "The average value of an element is "
		<< getAverage(testArray, ROWS, COLS)
		<< endl;

	// Display the total of row 0.
	cout << "The total of row 0 is "
		<< getRowTotal(testArray, 0, COLS)
		<< endl;

	// Display the total of column 2.
	cout << "The total of col 2 is "
		<< getColumnTotal(testArray, 2, ROWS)
		<< endl;

	// Display the highest value in row 2. 
	cout << "The highest value in row 2 is "
		<< getHighestInRow(testArray, 2, COLS)
		<< endl;

	// Display the lowest value in row 2.
	cout << "The lowest value in row 2 is "
		<< getLowestInRow(testArray, 2, COLS)
		<< endl;

	system("pause");
	return 0;
}
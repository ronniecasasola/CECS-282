// Ronald Casasola
// CECS 282 LAB 21

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void inputRainfall(int rainFall[], int size) {

	string line;
	ifstream file;
	file.open("rainfall.txt");
	int month = 0;
	while (month < 12) {
		file >> rainFall[month];
		month++;
	}
		
}

int calculateAverageRainFall(int rainFall[], int size) {
	int total = 0;

	for (int i = 0; i < size; i++) {
		total = total + rainFall[i];
	}

	return total / size ;
}

string returnMonth(int num) {

	string month = "";
	if (num == 1)
		month = "January";
	if (num == 2)
		month = "February";
	if (num == 3)
		month = "March";
	if (num == 4)
		month = "April";
	if (num == 5)
		month = "May";
	if (num == 6)
		month = "June";
	if (num == 7)
		month = "July";
	if (num == 8)
		month = "August";
	if (num == 9)
		month = "September";
	if (num == 10)
		month = "October";
	if (num == 11)
		month = "November";
	if (num == 12)
		month = "December";
	return month;
}

void classifyAndDisplayRainfall(int rainFall[], int months) {

	int avg = calculateAverageRainFall(rainFall, months);
	cout << "This years average rainfall was: " << avg << " mm" << endl;

	int highest = rainFall[0];
	int highestMonth = 0;
	int lowest = rainFall[0];
	int lowestMonth = 1;

	for (int i = 0; i < months; i++) {
		if (rainFall[i] > highest) {
			highest = rainFall[i];
			highestMonth = i + 1;
		}
		if (rainFall[i] < lowest) {
			lowest = rainFall[i];
			lowestMonth = i + 1;
		}
	}

	cout << returnMonth(highestMonth) << " has the highest rainfall (" << rainFall[highestMonth - 1] << ") mm" << endl;
	cout << returnMonth(lowestMonth) << " has the lowest rainfall (" << rainFall[lowestMonth - 1] << ") mm" << endl;
	cout << endl;

	cout << "Month      Rainfall      Classification" << endl;
	cout << "------      ---------     ---------------" << endl;
	for (int i = 0; i < months; i++) {
		string classification = "";

		if (rainFall[i] >= (avg * 1.20)) {
			classification = "rainy";
		}
		else if (rainFall[i] <= avg * .75) {
			classification = "dry";
		}
		else {
			classification = "average";
		}

		cout << left<< setw(12)<< i + 1 << setw(15) << rainFall[i] << setw(15) << classification << endl;
	}
	cout << endl;
}



int main() {

	const int months = 12;
	int rainFall[months];

	inputRainfall(rainFall, months);
	classifyAndDisplayRainfall(rainFall, months);

	system("pause");
	return 0;

}
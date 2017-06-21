//Ronnie Casasola
//012737398
//CECS 282 Lab 6

#include <iostream>
using namespace std;

void bubble_sort(int *array, int size, int(*compare)(int a, int b)) {

	int t;

	for (int i = 0; i<size; i++) {
		for (int j = 0; j<size; j++) {

			int r = compare(*(array + i), *(array + j));
			if (r == 1) {
				t = *(array + i);
				*(array + i) = *(array + j);
				*(array + j) = t;
			}
		}
	}
}

int ascendingCompare(int a, int b) {
	if (a < b) {
		return 1;
	}
	else {
		return -1;
	}
}
int descendingCompare(int a, int b) {
	if (a > b) {
		return 1;
	}
	else{
		return -1;
	}
}

int main() {
	int size;

	cout << "Please enter the size of array" << endl;
	cin >> size;

	int *array = new int[size];

	cout << "Enter the " << size << " array elements" << endl;
	for (int i = 0; i<size; i++) {

		bool valid = false;
		do {
			cin >> *(array + i);
			if (cin.good()) {
				valid = true;
			}
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input; please re-enter." << endl;
			}

		} while (!valid);
	}
	cout << endl;

	cout << "The array sorted in ascending order: " << endl;
	bubble_sort(array, size, &ascendingCompare);
	for (int i = 0; i<size; i++) {
		cout << *(array + i) << " ";
	}
	cout << endl;

	cout << "The array sorted in decending order: " << endl;
	bubble_sort(array, size, &descendingCompare);
	for (int i = 0; i<size; i++) {
		cout << *(array + i) << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
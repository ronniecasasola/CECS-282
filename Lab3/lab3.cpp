// Ronald Casasola
// CECS 282 LAB #3

using namespace std;
#include <iostream>
#include <fstream>
#include <string>

int readData(int *arr) {
	string line;
	ifstream file;
	file.open("data.txt");
	file >> *(arr + 0);
	int num = *(arr + 0);
	int count = 0;
	while (count < num) {
		file >> *(arr + count);
		count++;
	}
	return num;
}

void bsort(int *arr, int last) {

	int i, j;
	int temp = 0;
	int num;

	for (i = 0; i < last; i++)
	{

		for (j = 0; j < last - 1; j++)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
}

void writeToConsole(int *arr, int last) {

	for (int i = 0; i < last; i++) {
		cout << *(arr + i) << endl;
	}

	cout << endl;

}

int main() {

	int myarray[10];
	int * mypointer;

	mypointer = myarray;
	
	int num = readData(mypointer);
	bsort(mypointer, num);
	writeToConsole(mypointer, num);

	system("pause");
	return 0;
}

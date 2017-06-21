// Ronnie Casasola
// 012737398
// CECS282 Lab 7

#include <iostream>
#include <string> 
#include <iomanip>
using namespace std;

class person {

protected:
	string name; 
	float salary;

public:
	void setPerson(){

		cout << "Enter name: ";
		cin >> name;
		cout << "Enter salary: ";
		cin >> salary;
	}

	void printValues(){

		cout << setw(20) << left << name << salary << endl;
	}

	string getName(){

		return name;
	}

	float getSalary(){

		return salary;
	}
};


int main(){

	int j;
	void bsort(person**, int, bool);
	person* persPtr[100];
	int n = 0; 
	char choice;

	do { 
		persPtr[n] = new person;
		persPtr[n]->setPerson(); 
		n++; 
		cout << "Enter another (y/n)? "; 
		cin >> choice; 
	} while (choice == 'y'); 

	cout << "\nUnsorted list:" << endl;
	cout << endl;
	cout << setw(20)<< left<< "Names" << left << "Salaries" << endl;
	cout << setw(20) << left << "----------" << left <<"----------" << endl;

	for (int j = 0; j<n; j++){

		persPtr[j]->printValues();
	}

	cout << "-------------------------------" << endl;

	cout << endl;

	bsort(persPtr, n, true);

	cout << "\nSorted By Name:" << endl;
	cout << endl;
	cout << setw(20) << left << "Names" << left << "Salaries" << endl;
	cout << setw(20) << left << "----------" << left << "----------" << endl;
	cout << endl;

	for (j = 0; j<n; j++){

		persPtr[j]->printValues();
	}

	cout << "-------------------------------" << endl;

	bsort(persPtr, n, false);

	cout << "\nSorted By Salary:" << endl;
	cout << endl;
	cout << setw(20) << left << "Names" << left << "Salaries" << endl;
	cout << setw(20) << left << "----------" << left << "----------" << endl;
	cout << endl;

	for (j = 0; j<n; j++) {

		persPtr[j]->printValues();
	}

	cout << "-------------------------------" << endl;

	cout << endl;
	system("pause");
	return 0;
} 


void bsort(person** pp, int n, bool sort) {

	if (sort) {
		void sortByName(person**, person**);
		int j, k;
		for (j = 0; j < n; j++)
			for (k = j + 1; k < n; k++)
				sortByName(pp + j, pp + k);
	}
	else {
		void sortBySalary(person**, person**);
		int j, k;
		for (j = 0; j < n; j++)
			for (k = j + 1; k < n; k++)
				sortBySalary(pp + j, pp + k);
	}
}

void sortByName(person** pp1, person** pp2) 
{ 
	if ((*pp1)->getName().compare((*pp2)->getName()) >= 0 )
	{
		person* tempptr = *pp1;
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}

void sortBySalary(person** pp1, person** pp2)
{
	if ((*pp1)->getSalary() <= (*pp2)->getSalary())
	{
		person* tempptr = *pp1;
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}
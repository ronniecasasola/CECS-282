/**
Structure.cpp
Ronnie Casasola
CECS 282-07
Project 3- student list
due date: 10/10/16
**/

#include <cstring>
#include <string>
#include <iostream>
#include <iostream>
#include "myDate.h"
#include <iomanip>

using namespace std;

struct student{
	int id;
	char name[20];
	char grade;
	myDate bday;
	string hometown;
};

void initialize(struct student *s) {

	strcpy_s((s + 0)->name, "Ronnie");
	strcpy_s((s + 1)->name, "Steve");
	strcpy_s((s + 2)->name, "Erik");
	strcpy_s((s + 3)->name, "Emily");
	strcpy_s((s + 4)->name, "Andrea");
	strcpy_s((s + 5)->name, "Tom");
	strcpy_s((s + 6)->name, "Jerry");
	strcpy_s((s + 7)->name, "Alyssa");
	strcpy_s((s + 8)->name, "Tiffany");
	strcpy_s((s + 9)->name, "Charlie");

	(s + 0)->hometown = "Miami";
	(s + 1)->hometown = "Los Angeles";
	(s + 2)->hometown = "Downey";
	(s + 3)->hometown = "Bellflower";
	(s + 4)->hometown = "Cerritos";
	(s + 5)->hometown = "Huntington";
	(s + 6)->hometown = "Seal Beach";
	(s + 7)->hometown = "Whittier";
	(s + 8)->hometown = "New York";
	(s + 9)->hometown = "San Francisco";
	
	char grades[] = { 'A', 'B', 'C', 'D', 'F' };

	myDate startDate(01, 01, 1994);
	myDate endDate(12, 31, 1998);
	int days = startDate.daysBetween(endDate);

	for (int i = 0; i < 10; i++) {

		int j = (int)(rand() % 9000) + 1000;
		(s + i)->id = j;

		(s + i)->grade = grades[(int)(rand() % 4)];

		int ran =(int) (rand() % days);
		myDate randDate(1, 1, 1994);
		randDate.incrDate(ran);
		(s + i)->bday = randDate;

	}
}

void display(student* ptr[]) {
	cout << setw(10) << left << "ID" << setw(10) << left << "Name" << setw(18) << left << "Birthday" << setw(16) << left << "Grade" << setw(1) << left << "Hometown" << "\n";
	for (int i = 0; i<10; i++) {
		cout << setw(10) << left << ptr[i]->id << setw(10) << left << ptr[i]->name << left << ptr[i]->bday.getMonth() << "-" << ptr[i]->bday.getDay() << "-" << setw(15) << left << ptr[i]->bday.getYear() << setw(15) << left << ptr[i]->grade << setw(15) << left << ptr[i]->hometown;
		cout << "\n";
	}
}


int mainMenu() {
	cout << "Menu:\n1) Display original list\n2) Display list sorted by student ID\n3) Display list sorted by student birthday\n4) Display list sorted by student name\n5) Display list sorted by student grade\n6) Display list sorted by home town\n7) Exit\n";
	int userSelection;
	int valid = false;
	while (!valid) {
		cin >> userSelection;
		if (userSelection >= 1 && userSelection <= 7) {
			valid = true;
		}
		else {
			cout << "Enter a valid input\n";
		}
	}
	return userSelection;
}

void sortByID(struct student **ptr, int size, int low, int high) {
	if (ptr == NULL || size == 0) {
		return;
	}
	if (low >= high) {
		return;
	}
	
	int middle = low + (high - low) / 2;
	struct student *pivot = *(ptr + middle);
	
	int i = low, j = high;
	while (i <= j) {
		while ((*(ptr + i))->id< pivot->id) {
			i++;
		}
		while ((*(ptr + j))->id > pivot->id) {
			j--;
		}
		if (i <= j) {
			struct student *temp = *(ptr + i);
			*(ptr + i) = *(ptr + j);
			*(ptr + j) = temp;
			i++;
			j--;
		}
	}
	if (low < j) {
		sortByID(ptr, size, low, j);
	}
	if (high > i) {
		sortByID(ptr, size, i, high);
	}
}

void sortByAge(struct student **ptr, int size, int low, int high) {
	if (ptr == NULL || size == 0) {
		return;
	}
	if (low >= high) {
		return;
	}

	int middle = low + (high - low) / 2;
	struct student *pivot = *(ptr + middle);
	
	int i = low, j = high;
	while (i <= j) {
		while ((*(ptr + i))->bday.daysBetween(pivot->bday)<0) {
			i++;
		}
		while ((*(ptr + j))->bday.daysBetween(pivot->bday)>0) {
			j--;
		}
		if (i <= j) {
			struct student *temp = *(ptr + i);
			*(ptr + i) = *(ptr + j);
			*(ptr + j) = temp;
			i++;
			j--;
		}
	}
	if (low < j) {
		sortByAge(ptr, size, low, j);
	}
	if (high > i) {
		sortByAge(ptr, size, i, high);
	}
}

void sortByName(struct student **ptr, int size, int low, int high) {
	if (ptr == NULL || size == 0) {
		return;
	}
	if (low >= high) {
		return;
	}
	
	int middle = low + (high - low) / 2;
	struct student *pivot = *(ptr + middle);
	
	int i = low, j = high;
	while (i <= j) {
		while (strcmp((*(ptr + i))->name, pivot->name)<0) {
			i++;
		}
		while (strcmp((*(ptr + j))->name, pivot->name)>0) {
			j--;
		}
		if (i <= j) {
			struct student *temp = *(ptr + i);
			*(ptr + i) = *(ptr + j);
			*(ptr + j) = temp;
			i++;
			j--;
		}
	}
	if (low < j) {
		sortByName(ptr, size, low, j);
	}
	if (high > i) {
		sortByName(ptr, size, i, high);
	}
}

void sortByHometown(struct student **ptr) {
	
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if ((*(ptr + j))->hometown.compare((*(ptr + j + 1))->hometown) > 0) {
				struct student *temp = *(ptr + j);
				*(ptr + j) = *(ptr + j + 1);
				*(ptr + j + 1) = temp;
			}
		}

	}
}

void sortByGrade(struct student **ptr, int size, int low, int high) {
	if (ptr == NULL || size == 0) {
		return;
	}
	if (low >= high) {
		return;
	}
	
	int middle = low + (high - low) / 2;
	struct student *pivot = *(ptr + middle);
	
	int i = low, j = high;
	while (i <= j) {
		while ((*(ptr + i))->grade< pivot->grade) {
			i++;
		}
		while ((*(ptr + j))->grade > pivot->grade) {
			j--;
		}
		if (i <= j) {
			struct student *temp = *(ptr + i);
			*(ptr + i) = *(ptr + j);
			*(ptr + j) = temp;
			i++;
			j--;
		}
	}
	if (low < j) {
		sortByGrade(ptr, size, low, j);
	}
	if (high > i) {
		sortByGrade(ptr, size, i, high);
	}
}


int main() {
	
	student myClass[10];
	initialize(myClass);

	student	*originalList[10], *sortedIDList[10], *sortedAgeList[10], *sortedNameList[10], *sortedGradeList[10], *sortedHometownList[10];

	for (int i = 0; i < 10; i++) {
		originalList[i] = &myClass[i];
		sortedIDList[i] = &myClass[i];
		sortedAgeList[i] = &myClass[i];
		sortedNameList[i] = &myClass[i];
		sortedGradeList[i] = &myClass[i];
		sortedHometownList[i] = &myClass[i];
	}

	sortByID(sortedIDList, 10, 0, 9);
	sortByAge(sortedAgeList, 10, 0, 9);
	sortByName(sortedNameList, 10, 0, 9);
	sortByGrade(sortedGradeList, 10, 0, 9);
	sortByHometown(sortedHometownList);

	while (true) {
		switch (mainMenu()) {
		case 1: {
			display(originalList);
			break;
		}
		case 2: {
			display(sortedIDList);
			break;
		}
		case 3: {
			display(sortedAgeList);
			break;
		}
		case 4: {
			display(sortedNameList);
			break;
		}
		case 5: {
			display(sortedGradeList);
			break;
		}
		case 6: {
			display(sortedHometownList);
			break;
		}

		case 7: {
			return 0;
		}
	}
}

	system("pause");
	return 0;
}


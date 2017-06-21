//Ronnie Casasola
//012737398
//Lab 8A

#include<iostream>
#include<string>
using namespace std;

class Publication{

private:
	string title;
	float price;

public:

	void getData(){

		cout << "\nEnter the title of the publication : ";
		cin >> title;
		cout << "Enter the price : $";
		cin >> price;
	}

	void putData(){

		cout << "\nTitle: " << title << "\nPrice : " << price;
	}
};


class Sales{

private:
	float sales[3];

public:

	void getData(){

		for (int i = 0; i<3; i++){
			cout << "Enter Sales number[" << i + 1 << "] : $";
			cin >> sales[i];
		} 
	}

	void putData(){

		for (int i = 0; i<3; i++)
			cout << "\nSales number[" << i + 1 << "] : $" << sales[i];
	}
};


class Book :

	private Publication, private Sales
{
private:
	int pages;

public:

	void getData(){

		Publication::getData();
		cout << "Enter the number of pgs : ";
		cin >> pages;
		Sales::getData();
	}

	void putData(){

		Publication::putData();
		cout << "\nPages: " << pages;
		Sales::putData();
	}
};



class Digital :
	private Publication, private Sales{

private:
	float capacity;
public:

	void getData(){
		Publication::getData(); 
		cout << "Enter capacity in megabytes : ";
		cin >> capacity;
		Sales::getData();
	}

	void putData(){

		Publication::putData();
		cout << "\nStorage Capacity: " << capacity;
		Sales::putData();
	}
};


int main(){

	Book b;
	Digital d;
	b.getData();
	d.getData();
	b.putData();
	cout << endl;
	d.putData();
	cout << endl;
	system("pause");
	return 0;
}
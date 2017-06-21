#ifndef MYDATE_H_
#define MYDATE_H_
class myDate {

public:
	myDate();

	myDate(int M, int D, int Y);

	void display(char s[]);

	void incrDate(int N);

	void decrDate(int N);

	int daysBetween(myDate D);

	int getMonth();

	int getDay();


	int getYear();


	int getYearOffset();
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return the number of day since the current Year begin

	static int NumberOfDayInMonth(int M, int Y);
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return the number of days in a specific month

private:
	int Month, Day, Year;
	//Month: integer value of month. It can be any value from 1 to 12
	//Day: the current day of Month. The range of day is depended on the month
	//Year: the Year

	double GregorianToJulian();
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Return the Julian date of this object

	void JulianToGregorian(double JD);
	//Precondtion:
	//	_none
	//Postcondition:
	//	_Convert the date value of this object into a Gregorian date value represented by JD Julian Date
};

#endif
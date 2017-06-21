#include "upDate.h"
#include <iostream>

//Precondition:
//	_dateCount must be zero
//Postcondition:
//	_dateCount will keep track on how many upDate still existed
int upDate::dateCount = 0;

//Precondition:
//	_None.
//Postcondition:
//	_Construct and allocated memory for upDate object and initialize its value to 5/11/1959.
//	_Increase dateCount by 1.
upDate::upDate()
{
	date = new int[3]{ 5,11,1959 };
	dateCount++;
}

//Precondition:
//	_None.
//Postcondition:
//	_Construct and allocated memory for upDate object and initialize its value with a given date if it's a valid date else initialize object's value to 5/11/1959.
//	_Increase dateCount by 1.
upDate::upDate(int m, int d, int y) {
	if (m > 12 || y > 4000) {
		date = new int[3]{ 5,11,1959 };
	}
	else {
		date = new int[3]{ m,d,y };
	}
	++upDate::dateCount;
}

//Precondition:
//	_None.
//Postcondition:
//	_Copy the value stored inside object d into this object with allocated memory space.
//	_Increase dateCount by 1.
upDate::upDate(const upDate & d)
{
	date = new int[3];
	*date = *(d.date);
	*(date + 1) = *(d.date + 1);
	*(date + 2) = *(d.date + 2);
	dateCount++;
}

//Precondition:
//	_None.
//Postcondition:
//	_Delete the allocated memory space used to store date of this object
//	_Decrease dateCount by 1
upDate::~upDate() {
	delete[] date;
	dateCount--;
}

//Precondition:
//	_None.
//Postcondition:
//	_Set the date of this object into a given date if the given date is valid else throw an error message.
void upDate::setDate(int M, int D, int Y) {
	int test[3];
	JulianToGregorian(test, GregorianToJulian(M, D, Y));
	if (test[0] == M && test[1] == D && test[2] == Y) {
		date[0] = M;
		date[1] = D;
		date[2] = Y;
	}
	else {
		std::cout << "Invalid date" << std::endl;
	}
}

//Precondition:
//	_None.
//Postcondition:
//	_Return integer month.
int upDate::getMonth() const {
	return date[0];
}

//Precondition:
//	_None.
//Postcondition:
//	_Return integer day.
int upDate::getDay() const {
	return date[1];
}

//Precondition:
//	_None.
//Postcondition:
//	_Return integer year.
int upDate::getYear() const {
	return date[2];
}

//Precondition:
//	_None.
//Postcondition:
//	_Return string month
std::string upDate::getMonthName() {
	int m = getMonth();
	switch (m) {
	case 1:
		return "January";
	case 2:
		return "February";
	case 3:
		return "March";
	case 4:
		return "April";
		break;
	case 5:
		return "May";
		break;
	case 6:
		return "June";
	case 7:
		return "July";
	case 8:
		return "August";
	case 9:
		return "September";
	case 10:
		return "October";
	case 11:
		return "November";
	case 12:
		return "December";
	default:
		return "Unknown";
	}
}

//Precondition:
//	_list must have an allocated memory location to stored three integer values.
//Postcondition:
//	_Return an array that stored integer month at index 0, integer month at index 1, and integer year at index 2.
void upDate::JulianToGregorian(int* date, int JD) {
	int L = JD + 68569 + 1;
	int N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	int	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	int	J = 80 * L / 2447;
	int	K = L - 2447 * J / 80 ;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;
	date[0] = J;
	date[1] = K;
	date[2] = I;
}

//Precondition:
//	_Month, day, and year must be a combination of valid date.
//Postcondition:
//	_Return a julian date represented by the given gregorian date.
double upDate::GregorianToJulian(int M, int D, int Y) {
	return (367 * Y) - (trunc((7 * (Y + trunc((M + 9) / 12))) / 4)) + trunc(275 * M / 9) + D + 1721013.5;
}

//Precondition:
//	_i is positive integer.
//Postcondition:
//	_Return the date of this object increased by i day/days.
upDate upDate::operator+(const int i) {
	upDate newdate;
	int newDay = *(date + 1);
	int newMonth = *date;
	int newYear = *(date + 2);
	int rem = i;
	while (rem > 0) {
		if ((rem + newDay) < daysInMonth(newMonth, newYear)) {
			newDay = rem + newDay;
			rem = 0;
		}
		else if (newMonth == 11) {
			rem = rem - (daysInMonth(newMonth, newYear) - newDay);
			newYear++;
			newMonth = 0;
			newDay = 0;
		}
		else {
			rem = rem - (daysInMonth(newMonth, newYear) - newDay);
			newDay = 0;
			newMonth++;
		}
	}
	newdate.setDate(newMonth , newDay, newYear);
	return newdate;
}

//Precondition:
//	_i is positive integer.
//Postcondition:
//	_Return the date of this object decreased by i day/days.
upDate upDate::operator-(const int i)
{

	int k[3];
	upDate::JulianToGregorian(k, (*this).julian() - i);
	(*this).setDate(k[0], k[1], k[2]);
	return *this;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return the sum of this date and d's date.
int upDate::operator-(const upDate & d)
{
	return (*this).julian() - d.julian();
}

//Precondition:
//	_None.
//Postcondition:
//	_Return the date of this object increased by 1
upDate upDate::operator++(int)
{
	upDate tmp(*this);
	operator++();
	return tmp;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return the original date of this object then increase the date by 1.
upDate upDate::operator++()
{
	int k[3];
	upDate::JulianToGregorian(k, (*this).julian() + 1);
	(*this).setDate(k[0], k[1], k[2]);
	return *this;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return the date of this object decreased by 1
upDate upDate::operator--(int)
{
	upDate tmp(*this);
	operator--();
	return tmp;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return the original date of this object then decrease the date by 1.
upDate upDate::operator--()
{
	int k[3];
	upDate::JulianToGregorian(k, (*this).julian() - 1);
	(*this).setDate(k[0], k[1], k[2]);
	return *this;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return the julian date of this object
long upDate::julian() const
{
	int K = *(date + 1);
	int J = *date;
	int I = *(date + 2);
	return K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return true if date of this object and date of d object is the same else return false.
bool upDate::operator==(const upDate & d)
{
	if ((*this).julian() == (d).julian()) {
		return true;
	}
	return false;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return true if date of this object is bigger than the date of d object else return false.
bool upDate::operator>(const upDate & d)
{
	if ((*this).julian() > d.julian()) {
		return true;
	}
	return false;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return ture if date of this object is less than the date of d object else return false.
bool upDate::operator<(const upDate & d)
{
	if ((*this).julian() < d.julian()) {
		return true;
	}
	return false;
}

//Precondition:
//	_None.
//Postcondition:
//	_Return the number of upDate object still existed.
int upDate::GetDateCount()
{
	return dateCount;
}

//Precondition:
//	_None.
//Postcondition:
//	_Copy the date of d object into the date of this object.
void upDate::operator=(const upDate & d)
{
	(*this).setDate(d.getMonth(), d.getDay(), d.getYear());
}

//Precondition:
//	_i is positive integer.
//Postcondition:
//	_Return the date of d object increased by i day/days.
upDate operator+(const int i, const upDate& d)
{
	int k[3];
	upDate::JulianToGregorian(k, d.julian() + i);
	return upDate(k[0], k[1], k[2]);
}

int upDate::daysInMonth(int m, int y) {
	int monthLength[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (m != 1) {
		return monthLength[m];
	}
	else {
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
			return monthLength[m] + 1;
		}
		else {
			return monthLength[m];
		}
	}
}

//Precondition:
//	_None.
//Postcondition:
//	_Print date of d object in the following format: Month/Day/Year. Ex: 5/11/1959.
std::ostream & operator<<(std::ostream & os, const upDate& d)
{
	os << *(d.date) << "/" << *(d.date + 1) << "/" << *(d.date + 2);
	return os;
}
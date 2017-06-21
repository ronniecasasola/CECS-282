/**
myDate.h
Ronnie Casasola
CECS 282-07
Project 2- myDate
due date: 09/26/16
**/

#ifndef MYDATE_H
#define MYDATE_H
#include <string>

class myDate
{

private: 
	int Month, Day, Year;

public:
	myDate();
	myDate(int M, int D, int Y);
	void display();
	void incrDate(int N);
	void decrDate(int N);
	int daysBetween(myDate D);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	std:: string dayOfWeek();
	int daysInMonth(int m, int y);
	void JulianToGregorian(double JD);
	double GregorianToJulian();


};
#endif

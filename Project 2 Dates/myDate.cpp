/**
myDate.cpp
Ronnie Casasola
CECS 282-07
Project 2- myDate
due date: 09/26/16
**/

#include "myDate.h"
#include <iostream>
using namespace std;


myDate::myDate(){
	Day = 11;
	Month = 5;
	Year = 1959;
}

myDate::myDate(int M, int D, int Y){
	if (M > 0 && M < 13 && D > 0 && D <= daysInMonth(M, Y)
		&& Y >= 1959) {
		Month = M, Day = D, Year = Y;
	}
	else {
		Month = 5, Day = 11, Year = 1959;
	}
}

void myDate::display(){
	string monthNames[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	cout << monthNames[Month-1] << " " << Day << ", " << Year;
}

void myDate::incrDate(int N){
	double JD = GregorianToJulian() + N;
	JulianToGregorian(JD);
}

void myDate::decrDate(int N){
	double JD = GregorianToJulian() - N;
	JulianToGregorian(JD);
}

int myDate::daysBetween(myDate D) {
	return abs(GregorianToJulian() - D.GregorianToJulian());
}

int myDate::getMonth()
{
	return Month;
}

int myDate::getDay()
{
	return Day;
}

int myDate::getYear()
{
	return Year;
}

int myDate::dayOfYear()
{
	return abs(GregorianToJulian() - myDate(1, 1, Year).GregorianToJulian())+1;
}

std::string myDate::dayOfWeek()
{

	int num = GregorianToJulian();
	int dayOfWeek = (num + 1) % 7;

	string days[]{ "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	if (dayOfWeek == 0) {
		return days[0];
	}
	else  if (dayOfWeek == 1){
		return days[1];
	}
	else  if (dayOfWeek == 2) {
		return days[2];
	}
	else  if (dayOfWeek == 3) {
		return days[3];
	}
	else  if (dayOfWeek == 4) {
		return days[4];
	}
	else  if (dayOfWeek == 5) {
		return days[5];
	}
	else  if (dayOfWeek == 6) {
		return days[6];
	}
	
}

int myDate::daysInMonth(int m, int y) {
	int monthLength[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (m != 2) {
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


void myDate::JulianToGregorian(double JD) {
	int L = JD + 68569 + 1;
	int N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	int I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	int J = 80 * L / 2447;
	int K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;
	Year = I;
	Month = J;
	Day = K;
}

double myDate::GregorianToJulian() {
	return (367 * Year) - (trunc((7 * (Year + trunc((Month + 9) / 12))) / 4))
		+ trunc(275 * Month / 9) + Day + 1721013.5;
}



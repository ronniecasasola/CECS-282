#include <cstring>
#include <iostream>
#include <cmath>
#include "myDate.h"

using namespace std;

myDate::myDate() {
	Month = 5, Day = 11, Year = 1959;
}

myDate::myDate(int M, int D, int Y) {
	if (M > 0 && M < 13 && D > 0 && D <= NumberOfDayInMonth(M, Y)
		&& Y >= 1959) {
		Month = M, Day = D, Year = Y;
	}
	else {
		Month = 5, Day = 11, Year = 1959;
	}
}

void myDate::display(char f[]) {
	char s[20];
	switch (Month) {
	case 1:
		strcpy_s(s, "January");
		break;
	case 2:
		strcpy_s(s, "February");
		break;
	case 3:
		strcpy_s(s, "March");
		break;
	case 4:
		strcpy_s(s, "April");
		break;
	case 5:
		strcpy_s(s, "May");
		break;
	case 6:
		strcpy_s(s, "June");
		break;
	case 7:
		strcpy_s(s, "July");
		break;
	case 8:
		strcpy_s(s, "August");
		break;
	case 9:
		strcpy_s(s, "September");
		break;
	case 10:
		strcpy_s(s, "October");
		break;
	case 11:
		strcpy_s(s, "November");
		break;
	case 12:
		strcpy_s(s, "December");
		break;
	}
	char day[15];
	sprintf_s(day, " %d, %d", Day, Year);
	strcat_s(s, sizeof s, day);
	strcpy_s(f, sizeof s, s);
}

void myDate::incrDate(int N) {
	double JD = GregorianToJulian() + N;
	JulianToGregorian(JD);
}

void myDate::decrDate(int N) {
	double JD = GregorianToJulian() - N;
	JulianToGregorian(JD);
}


int myDate::daysBetween(myDate D) {
	return (GregorianToJulian() - D.GregorianToJulian());
}


int myDate::getMonth() {
	return Month;
}

int myDate::getDay() {
	return Day;
}

int myDate::getYear() {
	return Year;
}

int myDate::getYearOffset() {
	return abs(GregorianToJulian() - myDate(1, 1, Year).GregorianToJulian());
}

double myDate::GregorianToJulian() {
	return (367 * Year) - (trunc((7 * (Year + trunc((Month + 9) / 12))) / 4))
		+ trunc(275 * Month / 9) + Day + 1721013.5;
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


int myDate::NumberOfDayInMonth(int Month, int Year) {
	switch (Month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 2:
		
		if (Year % 4 != 0) {
			return 28;
		}
		else if (Year % 400 == 0) {
			return 29;
		}
		else if (Year % 100 == 0) {
			return 28;
		}
		else {
			return 29;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	default:
		return 0;
	}
}
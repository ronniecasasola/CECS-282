#include <iostream>
#include <iomanip>

using namespace std;

static double FEDERAL_INCOME_TAX = 0.20;
static double STATE_TAX = 0.04;
static double SS_TAX = 0.035;
static double MEDICARE = 0.0275;
static double PENSION = 0.06;
static double HEALTH_INSURANCE = 80;

int main() {

	double grossAmount = 0;

	cout << "Enter your gross amount in dollars: ";
	cin >> grossAmount;

	double federal = grossAmount * FEDERAL_INCOME_TAX;
	double state = grossAmount * STATE_TAX;
	double social = grossAmount * SS_TAX;
	double med = grossAmount * MEDICARE;
	double pens = grossAmount * PENSION;
	double netPay = grossAmount * (federal + state + social + med + pens + HEALTH_INSURANCE);

	cout << left << setw(26) << "Gross Amount: " << right << setprecision(2) << "$" << setw(7) << setprecision(4) <<  grossAmount << endl;
	cout << left << setw(26) << "Federal Tax " << right << setprecision(2) << "$" << setw(7) << setprecision(5) << federal << endl;
	cout << left << setw(26) << "State Tax: " << right << setprecision(2) << "$" << setw(7) << setprecision(5) << state << endl;
	cout << left << setw(26) << "Social Security Tax: " << setprecision(2) << right << "$" << setw(7) << setprecision(5) << social << endl;
	cout << left << setw(26) << "Medicare/Medicaid Tax: " << setprecision(2) << right << "$" << setw(7) << setprecision(4) << med << endl;
	cout << left << setw(26) << "Pension Plan: " << right << setprecision(2) << "$" << setw(7) << setprecision(5) << pens << endl;
	cout << left << setw(26) << "Health Insurance: " << right << "$" << setw(7) << setprecision(5) << HEALTH_INSURANCE << endl;
	cout << left << setw(26) << "Net Pay: " << right << "$" << setw(5) << netPay << endl;






	system("pause");
	return 0;
}
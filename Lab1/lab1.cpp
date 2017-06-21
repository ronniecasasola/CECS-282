// Ronnie Casasola
// CECS 282 LAB #1

#include <iostream>
#include <iomanip>

using namespace std;

static float FEDERAL_INCOME_TAX = 0.20;
static float STATE_TAX = 0.04;
static float SS_TAX = 0.035;
static float MEDICARE = 0.0275;
static float PENSION = 0.06;
static float HEALTH_INSURANCE = 80;

int main() {

	float grossAmount = 0;

	cout << "Enter your gross amount in dollars: ";
	cin >> grossAmount;

	float federal = grossAmount * FEDERAL_INCOME_TAX;
	float state = grossAmount * STATE_TAX;
	float social = grossAmount * SS_TAX;
	float med = grossAmount * MEDICARE;
	float pens = grossAmount * PENSION;
	float netPay = grossAmount - (federal + state + social + med + pens + HEALTH_INSURANCE);

	cout << endl;

	cout << left << setw(26) << "Gross Amount: " << right << "$   " << setprecision(2) << fixed <<  setw(7) << grossAmount << endl;
	cout << left << setw(26) << "Federal Tax " << right << "$   " << setprecision(2) << setw(7) << federal << endl;
	cout << left << setw(26) << "State Tax: " << right << setprecision(2) << "$   " << setw(7) << state << endl;
	cout << left << setw(26) << "Social Security Tax: " << setprecision(2) << right << "$   " << setw(7) << social << endl;
	cout << left << setw(26) << "Medicare/Medicaid Tax: " << setprecision(2) << right << "$   " << setw(7) << med << endl;
	cout << left << setw(26) << "Pension Plan: " << right << setprecision(2) << "$   " << setw(7) << pens << endl;
	cout << left << setw(26) << "Health Insurance: " << right << "$   " << setw(7) << HEALTH_INSURANCE << endl;
	cout << left << setw(26) << "Net Pay: " << right << "$   " << setw(7) << netPay << endl;

	cout << endl;



	system("pause");
	return 0;
}
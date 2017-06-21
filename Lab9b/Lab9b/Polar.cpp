//Ronnie Casasola
//012737398
//CECS 282 Lab92
#include <math.h>
#include <iostream>
using namespace std;

class Polar {
private:
	double radius, angles;
public:
	Polar() {
		radius = 0;
		angles = 0;
	}
	Polar(double rad, double ang) {
		radius = rad;
		angles = ang;
	}
	void display() {
		cout << "(" << radius << ", " << angles << ")";
	}
	Polar operator+(Polar p) {
		double x = radius * cos(angles) + p.radius * cos(p.angles);
		double y = radius * sin(angles) + p.radius * sin(p.angles);
		return Polar(sqrt(x * x + y * y), atan(y / x));
	}
};

int main() {
	Polar p1(10.0, 0.0); 
	Polar p2(10.0, 1.570796325); 
	Polar p3; 
	p3 = p1 + p2; 
	cout << "\np1="; p1.display(); 
	cout << "\np2="; p2.display();
	cout << "\np3="; p3.display();
	cout << endl;

	system("pause");
	return 0;
}
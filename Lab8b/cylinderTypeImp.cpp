//Ronnie Casasola
//012737398
//Lab 8b
#include <iostream>
#include "circleType.h"
#include "cylinderType.h"
#include "pointType.h"

using namespace std;

cylinderType::cylinderType(double x, double y, double radius, double newHeight)
	: circleType(x, y, radius) {

	height = newHeight;
}

void cylinderType::print() const{

	cout << "Base Center: ";
	pointType::print();
	cout << endl;

	cout << "Base Radius: " << radius << endl;
	cout << "Base Circumference: " << getCircumference() << endl;
	cout << "Base Area: " << getArea() << endl;

	cout << "Cylinder height: " << height << endl;
	cout << "Cylinder surface area: " << getSurfaceArea() << endl;
	cout << "Cylinder volume: " << getVolume() << endl;
}


void cylinderType::setHeight(double h){

	if (h >= 0)
		height = h;
	else
		height = 0;
}

double cylinderType::getHeight() const{

	return height;
}

double cylinderType::getSurfaceArea() const{

	return (2 * 3.1416 * getRadius() * height);
}

double cylinderType::getVolume() const{

	return 3.1416 * getRadius() * getRadius() * height;
}

void cylinderType::setCenterRadiusHeight(double x, double y, double radius, double newHeight) {

	setPoint(x, y);
	setRadius(radius);
	height = newHeight;
}

void cylinderType::setBaseCenter(double x, double y){

	setPoint(x, y);
}

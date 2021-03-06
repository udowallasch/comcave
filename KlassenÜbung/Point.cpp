#include "pch.h"
#include "Point.h"


using std::cout;
using std::string;
using std::to_string;


void Point::print() const {
	cout << "(" << x << "|" << y << ")";
}
string Point::sprint() const {
	return "(" + to_string(x) + "|" + to_string(y) + ")";
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

void Point::setX(int x) {
	this->x = x;
}

void Point::setY(int y) {
	this->y = y;
}

Point::~Point() {}

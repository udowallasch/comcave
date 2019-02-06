#include "pch.h"
#include "Point.h"


void Point::print() const {
	cout << "(" << x << "|" << y << ")";
}
string Point::sprint() const {
	return "(" + to_string(x) + "|" + to_string(y) + ")";
}

Point::~Point() {}

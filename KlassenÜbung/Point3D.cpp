#include "pch.h"
#include "Point3D.h"


using std::cout;
using std::string;
using std::to_string;

using namespace _3D;

void Point::print() const {
	cout << "(" << x << "|" << y << "|" << z <<")";
}
string Point::sprint() const {
	return "(" + to_string(x) + "|" + to_string(y) + "|" + to_string(z) + ")";
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

int Point::getZ() {
	return z;
}

void Point::setX(int x) {
	this->x = x;
}

void Point::setY(int y) {
	this->y = y;
}

void Point::setZ(int z) {
	this->z = z;
}
Point::~Point() {}

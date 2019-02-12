#include "pch.h"
#include "Point.h"
#include <sstream>
#include <iomanip>

using std::cout;
using std::string;
using std::to_string;
using std::stringstream;
using std::setprecision;

string Point::sprint() const {
	stringstream ss{};
	ss << setprecision(4) << "(" << x << "|" << y << ")";
	return ss.str();
}

void Point::print() const {
	cout << sprint();
}

double Point::getX() const {
	return x;
}

double Point::getY() const {
	return y;
}

void Point::setX(double x) {
	this->x = x;
}

void Point::setY(double y) {
	this->y = y;
}

double Point::dist(const Point& p) const {
	return sqrt((x - p.getX())*(x - p.getX()) + (y - p.getY())*(y - p.getY()));
};


Point::~Point() {}

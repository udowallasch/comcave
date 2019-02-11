#include "pch.h"
#include "Circle.h"
#include<iomanip>
#include<sstream>

using std::string;
using std::stringstream;
using std::setprecision;
using std::cout;

double Circle::getRadius() const {
	return radius;
};

Point Circle::getMP() const {
	return M;
};

void Circle::setRadius(double r) {
	radius = r;
};

void Circle::setMP(Point p) {
	M = p;
};


double Circle::getFlaeche() const {
	return PI * radius * radius;
}
double Circle::getUmfang() const {
	return 2 * PI * radius;
}

bool Circle::isWithin(Point& p) const {
	return M.dist(p) <= radius;
};


void Circle::print() const {
	cout << sprint();
}

string Circle::sprint() const {
	stringstream ss{};
	ss << setprecision(4) << "R = " << radius << ", M = " << M.sprint();
	return ss.str();
}

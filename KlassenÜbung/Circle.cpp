#include "pch.h"
#include "Circle.h"

using std::string;
using std::stringstream;
using std::setprecision;
using std::cout;

double Circle::getRadius() {
	return radius;
};

Point Circle::getMP() {
	return M;
};

void Circle::setRadius(double r) {
	radius = r;
};

void Circle::setMP(Point p) {
	M = p;
};


double Circle::getFlaeche() const {
	return 3.14 * radius * radius;
}
double Circle::getUmfang() const {
	return 2 * 3.14 * radius;
}

void Circle::print() const {
	cout << sprint();
}

string Circle::sprint() const {
	stringstream ss{};
	ss << setprecision(4) << "R = " << radius << ", M = " << M.sprint();
	return ss.str();
}

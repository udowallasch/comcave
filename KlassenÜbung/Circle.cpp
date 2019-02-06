#include "pch.h"
#include "Circle.h"



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
	stringstream ss{};
	
	ss << setprecision(4) << radius;		
	cout << "R = " << ss.str() << ", M = " << M.sprint();
}



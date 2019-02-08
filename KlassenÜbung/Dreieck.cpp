#include "pch.h"
#include "Dreieck.h"

using std::string;
using std::stringstream;
using std::setprecision;
using std::cout;

double Dreieck::getFlaeche() const {
	return 1.1;
}
double Dreieck::getUmfang() const {
	return 1.1;
};

void Dreieck::print() const {
	cout << sprint();
};

string Dreieck::sprint() const {
	stringstream ss{};
	ss << setprecision(4) << "a =" << A.sprint() <<  " b =" << B.sprint() << " c=" << C.sprint();
	return ss.str();
}

void Dreieck::setA(Point p) {
	A = p;
};

void Dreieck::setB(Point p) {
	B = p;
};

void Dreieck::setC(Point p) {
	C = p;
};

Point Dreieck::getA() {
	return A;
};

Point Dreieck::getB() {
	return B;
};

Point Dreieck::getC() {
	return C;
};

Point** Dreieck::getCoords() {
	return coords;
}

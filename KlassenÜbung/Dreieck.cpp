#include "pch.h"
#include "Dreieck.h"

double Dreieck::getFlaeche() const {
	return 1.1;
}
double Dreieck::getUmfang() const {
	return 1.1;
};

void Dreieck::print() const {
	cout << "a =" << A.sprint() << " b =" << B.sprint() << " c=" << C.sprint();
};


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
	return d;
}

Dreieck::~Dreieck() {}

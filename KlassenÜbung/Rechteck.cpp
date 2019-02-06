#include "pch.h"
#include "Rechteck.h"

double Rechteck::getFlaeche() const {
	return a * b;
}

double Rechteck::getUmfang() const {
	return 2 * (a + b);
}

void Rechteck::setA(double d) {
	a = d;
};

void Rechteck::setB(double d) {
	b = d;
};

double Rechteck::getA() {
	return a;
};
 
double Rechteck::getB() {
	return b;
};

void Rechteck::printc() {
	cout << "Laenge = " << a << " Breite = " << b << " count: " << count;
	count++;
}

void Rechteck::print() const {
	cout << "Laenge = " << a << " Breite = " << b << " count: " << count;
}
Rechteck::~Rechteck() {}

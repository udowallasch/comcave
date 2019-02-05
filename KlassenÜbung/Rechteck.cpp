#include "pch.h"
#include "Rechteck.h"

int Rechteck::getFlaeche() {
	return a * b;
}

int Rechteck::getUmfang() {
	return 2*(a + b);
}
Rechteck::~Rechteck() {}

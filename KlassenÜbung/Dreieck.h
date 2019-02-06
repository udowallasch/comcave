#pragma once

#include "Point.h"
#include "Figur.h"


class Dreieck : Figur {
	Point A;
	Point B;
	Point C;
	Point* d[3];

public:
	double getFlaeche() const override;
	double getUmfang() const override;
	void print() const override;

	void setA(Point);
	void setB(Point);
	void setC(Point);

	Point getA();
	Point getB();
	Point getC();

	Point** getCoords();
	//d muss mit A,B,C initialisiert werden, sonst funkts nicht. Bei d[0] = a gibt's garbage!!!! Wieso??? 
	// das gilt nur für a!! Bei d[0] = &b geht's....
	Dreieck(Point a, Point b, Point c) : A(a), B(b), C(c) { d[0] = &A; d[1] = &B; d[2] = &C;};
	Dreieck() {};
	~Dreieck();
};


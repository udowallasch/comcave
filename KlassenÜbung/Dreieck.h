#pragma once

#include "Point.h"
#include "Figur.h"


class Dreieck : Figur {
	Point A;
	Point B;
	Point C;

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

	Dreieck(Point a, Point b, Point c) : A(a), B(b), C(c) {};
	Dreieck() {};
	~Dreieck();
};


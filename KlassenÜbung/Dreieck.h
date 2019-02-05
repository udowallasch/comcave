#pragma once

#include "Point.h"



class Dreieck {
	Point A;
	Point B;
	Point C;

public:
	Dreieck(Point a, Point b, Point c) : A(a), B(b), C(c) {};
	~Dreieck();
};


#pragma once

#include "Point.h"


class Circle {
	int radius;
	Point M;
	
public:
	Circle(int r, Point m) : radius(r), M(m) {};
	~Circle();
};


#ifndef CIRCLE_H
#define CIRCLE_H

#pragma once

#include "Point.h"

double const PI = 3.1415;

class Circle  {
	double radius;
	Point M;
	
public:
	double getFlaeche() const;
	double getUmfang() const;
	void print() const;
	std::string sprint() const;

	double getRadius() const;
	Point getMP() const;
	void setRadius(double);
	void setMP(Point);
	bool isWithin(Point&) const;

	Circle(double radius = 1, Point M = Point{}) : radius(radius), M(M) {};
	~Circle() {};
};

#endif

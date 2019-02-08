#ifndef CIRCLE_H
#define CIRCLE_H

#pragma once

#include "Point.h"
#include "Figur.h"


class Circle : public Figur {
	double radius;
	Point M;
	
public:
	double getFlaeche() const override;
	double getUmfang() const  override;
	void print() const override;
	std::string sprint() const override;

	double getRadius();
	Point getMP();
	void setRadius(double);
	void setMP(Point);

	Circle(int r, Point m) : radius(r), M(m) {};
	Circle() {};
	~Circle() {};
};

#endif

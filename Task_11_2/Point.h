#ifndef POINT_H
#define POINT_H

#pragma once
#include<iostream>
#include<string>

class Point {
	double x;
	double y;
public:
	void print() const;
	std::string sprint() const;
	double getX() const;
	double getY() const;
	void setX(double);
	void setY(double);
	double dist(Point&) const;

	Point(double x = 0, double y = 0) : x(x) , y(y) {};
	~Point();
};

#endif




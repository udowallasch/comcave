#ifndef POINT_H
#define POINT_H

#pragma once
#include<iostream>
#include<string>

class Point {
	int x;
	int y;
public:
	void print() const;
	std::string sprint() const;
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	Point(int x, int y) : x(x) , y(y) {};
	Point(): x(0), y(0) {};
	~Point();
};

#endif




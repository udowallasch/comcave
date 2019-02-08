
#ifndef POINT3D_H
#define POINT3D_H

#pragma once
#include<iostream>
#include<string>

namespace _3D {

class Point {
	int x;
	int y;
	int z;
public:
	void print() const;
	std::string sprint() const;
	int getX();
	int getY();
	int getZ();
	void setX(int);
	void setY(int);
	void setZ(int);
	Point(int x, int y, int z) : x{ x }, y{ y }, z{ z } {};
	Point() : x{ 0 }, y{ 0 }, z{ 0 } {};
	~Point();
};

}
#endif




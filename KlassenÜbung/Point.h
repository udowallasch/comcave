#pragma once
#include<iostream>
#include<string>

using std::cout;
using std::string;
using std::to_string;


class Point {
	int x;
	int y;
public:
	void print() const;
	string sprint() const;
	Point(int x, int y) : x(x) , y(y) {};
	Point(): x(0), y(0) {};
	~Point();
};






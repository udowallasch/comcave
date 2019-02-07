#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include <iomanip> //setprecision

using std::string;
using std::stringstream;
using std::setprecision;
using std::to_string;
using std::cout;

class Figur {


public:
	virtual double getFlaeche() const = 0;
	virtual double getUmfang() const = 0;
	virtual void print() const = 0;
	virtual string sprint() const = 0;

};


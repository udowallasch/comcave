#ifndef FIGUR_H
#define FIGUR_H
#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include <iomanip> //setprecision


class Figur {


public:
	virtual double getFlaeche() const = 0;
	virtual double getUmfang() const = 0;
	virtual void print() const = 0;
	virtual std::string sprint() const = 0;

};

#endif
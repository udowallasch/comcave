#pragma once
#include "Figur.h"

class Rechteck : public Figur{
	size_t count{ 0 };
	int a;
	int b;
public:
	double getFlaeche() const override;
	double getUmfang() const override;
	void print() const override;
	string sprint() const override;
	void printc();

	void setA(double);
	void setB(double);

	double getA();
	double getB();


	Rechteck(int a, int b) : a(a), b(b) {};
	Rechteck() {};
	~Rechteck();
};


// Task_21_2_complex.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <sstream>
using namespace::std;

class Complex {
private:
	double re;
	double im;
public:
	Complex(double re, double im): re{re}, im{im}{}
	string toString() const;
	friend Complex operator+(Complex &, Complex &);
	friend Complex operator-(Complex &, Complex &);
	friend Complex operator*(Complex &, Complex &);
	friend Complex operator/(Complex &, Complex &);

};


Complex operator+(Complex &a, Complex &b) {
	return Complex(a.re + b.re, a.im + b.im);
}

Complex operator-(Complex &a, Complex &b) {
	return Complex(a.re - b.re, a.im - b.im);
}

Complex operator*(Complex &a, Complex &b) {
	double r = a.re * b.re - a.im * b.im;
	double i = a.re * b.im + a.im * b.re;
	return Complex(r, i);
}

Complex operator/(Complex &a, Complex &b) {
	double r = (a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im);
	double i = (a.im * b.re - a.re * b.im) / (b.re * b.re + b.im * b.im);
	return Complex(r, i);
}

string Complex::toString() const {
	stringstream ss{};
	ss << "[ " << re << " | " << im << " ]";
	return ss.str();
}

ostream& operator<<(ostream& os, const Complex& c) {
	os << c.toString();
	return os;
}


int main() {
	Complex c1{ 2,5 };//
	Complex c2{ 3,7 };//
	Complex c = c1 + c2;//operator + muss überladen
	cout << c << endl;
	c = c1 * c2;
	cout << c << endl;
	c = c1 / c2;
	cout << c<< endl;
	c = c1 - c2;
	cout << c << endl;
	cout << c << c1 << c2;
	
	return 0;
}



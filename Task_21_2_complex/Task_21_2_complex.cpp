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
	Complex(double re=0, double im=0): re{re}, im{im}{}
	string toString() const;
	friend Complex operator+(const Complex &, const Complex &);
	friend Complex operator-(const Complex &, const Complex &);
	friend Complex operator*(Complex &, Complex &);
//	friend Complex operator*(double, Complex &);
//	friend Complex operator*(Complex &, double);
	friend Complex operator/(Complex &, Complex &);
	friend Complex operator+(double, Complex &);
	friend Complex operator+(Complex &, double);
	friend istream& operator>>(istream &, Complex&);

};


Complex operator+(const Complex &a, const  Complex &b) {
	return Complex(a.re + b.re, a.im + b.im);
}

Complex operator+(double a, Complex &b) {
	return Complex(a+ b.re, b.im);
}
Complex operator+(Complex &a, double b) {
	return Complex(a.re + b, a.im );
}

Complex operator-(const Complex &a, const Complex &b) {
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
	ss<<"(" << re << (this->im > 0 ? " +" : " ") << im << "i"<<")";
	return ss.str();
}

// '>>' ist befreundet, kann deshalb direkt auf die privaten member von &c zugreifen
istream& operator>>(istream & is, Complex& c){
	return is >> c.re >> c.im;
}

// '<<' ist nicht befreundet, deshalb muss er den toString von &c nutzen. Geht auch. 
// Ist gut im Sinne der Sichtbarkeitsminimierung.
ostream& operator<<(ostream& os, const Complex& c) {
	return os << c.toString();
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
	cout << c<<" " << c1<<" " << c2;

	//Achtung WICHTIG!!!!!
	// Damit solche Kettenrechnungen funktionieren, müssen die Referenz-Parameter der überladenen Operatoren
	// 'const' sein! Sonst funktioniert das nicht, weil versucht würde Zwischenergebnisse (Werte!) in einer nicht 
	// zugewiesenen Referenz abzulegen etwa so : int& i = 4; -> geht nicht weil lvalue verlangt, aber const int& i = 4; geht.
	c = c1+c2-c1;
	Complex z1, z2;
	cout << endl;
	cin >> z1 >> z2;
	cout << z1 << "  " << z2;
	return 0;
}



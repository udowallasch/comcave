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
	double getRe() const;
	double getIm() const;
	Complex(double re=0, double im=0): re{re}, im{im}{}
	string toString() const;
//	friend Complex operator+(const Complex &, const Complex &);
	friend Complex operator-(const Complex &, const Complex &);
	friend Complex operator*(Complex &, Complex &);
//	friend Complex operator*(double, Complex &);
//	friend Complex operator*(Complex &, double);
	friend Complex operator/(Complex &, Complex &);
//	friend Complex operator+(double, Complex &);  -> geht nicht als Methode!
//	friend Complex operator+(Complex &, double);
	friend istream& operator>>(istream &, Complex&);
	Complex operator=(const Complex &);

	Complex operator+(double);
	Complex operator+( const Complex &);
};

double Complex::getRe() const {
	return re;
}
double Complex::getIm() const {
	return im;
}

Complex Complex::operator+(const  Complex &b) {
	return Complex(this->re + b.re, this->im + b.im);
}

Complex Complex::operator=(const  Complex &b) {
	this->re = b.re;
	this->im = b.im;
	return *this;
}

Complex Complex::operator+(double a	) {
	return Complex(a+ this->re,this->im);
}

//Complex operator+(Complex &a, double b) {
//	return Complex(a.re + b, a.im );
//}

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
	ss << re << (this->im > 0 ? " +" : " ") << im << "i";
	return ss.str();
}

// >> ist befreundet, kann deshalb direkt auf die privaten member von &c zugreifen
istream& operator>>(istream & is, Complex& c){
	return is >> c.re >> c.im;
}

// << ist nicht befreundet, deshalb muss << den toString von &c nutzen. Geht auch. 
// Gut im Sinne der Sichtbarkeitsminimierung.
ostream& operator<<(ostream& os, const Complex& c) {
	os << c.toString();
	return os;
}


int main() {
	Complex c1{ 2,5 };//
	Complex c2{ 3,7 };//
	Complex c = c1 + c2;//operator + muss überladen
	cout << c << endl;
	c = c1 + 6.0;
	cout << c << endl;
	c = c1;
	cout << c << endl;
	//c = 6.0 + c; -> geht nicht als Methode weil der linke Operand weggelassen werden müsste
	cout << c << endl;
	c = c1 = c2;
	cout << c << endl;
	cout << c1 << endl;

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
	// zugewiesen Referenz abzulegen etwa so : int& i = 4; -> geht nicht weil lvalue verlangt, aber const int& i = 4; geht.
	c = c1+c2-c1;
	Complex z1, z2;
	cout << endl;
	cin >> z1 >> z2;
	cout << z1 << "  " << z2;
	return 0;
}




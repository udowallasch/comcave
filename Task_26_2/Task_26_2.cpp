// Task_26_2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<sstream>
using namespace std;

double const PI = 3.1415;

class Circle {
private:
	double xpos, ypos, radius;
public:
	Circle (double xpos=0, double ypos=0, double radius=1)
		: xpos{ xpos }, ypos{ ypos }, radius{ radius }{}
	~Circle() {};

	double getX() const { return xpos; }
	void setX(double x) { xpos = x; }

	double getY() const { return ypos; }
	void setY(double y) { ypos = y; }

	double getRadius() const { return radius; }
	void setRadius(double r) { radius = r; }

	double getUmfang() const { return 2.0 * PI * radius; }
	double getFlaeche() const { return PI * radius * radius; }

	friend ostream& operator<<(ostream&, const Circle&);
	friend istream& operator>>(istream&, Circle&);

};

ostream& operator<<(ostream& os, const Circle& c) {
	return os << "M = [ " << c.xpos << ", " << c.ypos << "], R = " << c.radius;
}

istream& operator>>(istream& is, Circle& c) {
	return is >> c.xpos >> c.ypos >> c.radius;
}

class Rectangle {
private:
	double xpos, ypos, length, width;
public:
	Rectangle(double xpos = 0, double ypos = 0, double length = 1, double width = 1)
		: xpos{ xpos }, ypos{ ypos }, length{ length }, width{ width } {}
	~Rectangle() {};

	double getX() const { return xpos; }
	void setX(double x) { xpos = x; }

	double getY() const { return ypos; }
	void setY(double y) { ypos = y; }

	double getLength() const { return length; }
	void setLength(double l) { length = l; }

	double getWidth() const { return width; }
	void setWidth(double w) { width = w; }

	double getUmfang() const { return 2.0 * (length + width); }
	double getFlaeche() const { return length * width; }

	friend ostream& operator<<(ostream&, const Rectangle&);
	friend istream& operator>>(istream&, Rectangle&);

};

ostream& operator<<(ostream& os, const Rectangle& r) {
	return os	\
		<< "A = [ " << r.xpos << ", " << r.ypos << "], " \
		<< "B = [ " << r.xpos + r.length << ", " << r.ypos << "], " \
		<< "C = [ " << r.xpos + r.length << ", " << r.ypos + r.width << "], " \
		<< "D = [ " << r.xpos << ", " << r.ypos + r.width << "]. ";
}

istream& operator>>(istream& is, Rectangle& r) {
	return is >> r.xpos >> r.ypos >> r.length >> r.width;
}


int main()
{

	Circle c1;
	Circle c2{ 1,2,3 };
	cout << c1 << ": Umfang: " << c1.getUmfang() << " Flaeche: " << c1.getFlaeche() << endl;
	cout << c2 << ": Umfang: " << c2.getUmfang() << " Flaeche: " << c2.getFlaeche() << endl;

	Rectangle r1;
	Rectangle r2{ 1,2,3,4 };
	cout << r1 << ": Umfang: " << r1.getUmfang() << " Flaeche: " << r1.getFlaeche() << endl;
	cout << r2 << ": Umfang: " << r2.getUmfang() << " Flaeche: " << r2.getFlaeche() << endl;

	cout << "Kreis eingeben. M(x,y) r:" << endl;
	Circle c3;
	cin >> c3;
	cout << c3 << endl;

	cout << "Rechteck eingeben. A(x,y) l,w:" << endl;
	Rectangle r3;
	cin >> r3;
	cout << r3 << endl;

	return 0;
}

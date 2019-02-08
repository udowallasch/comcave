// KlassenÜbung.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "Circle.h"
#include "Point.h"
#include "Point3D.h"
#include "Rechteck.h"
#include "Dreieck.h"

using std::string;
using std::stringstream;
using std::setprecision;
using std::cout;

void print(Point);
void printR(Point&);
void print(Point*);


int add(int, int);
int addr(int&, int&);
int add(int*, int*);

void print(Circle);
void printR(Circle&);
void print(Circle*);

void print(Dreieck);
void printR(Dreieck&);
void print(Dreieck*);

void print(Rechteck);
void printR(Rechteck&);
void print(Rechteck*);

void print(_3D::Point*);

int main()
{
	//Circle c = Circle(5, Point(5, 5));
	//Dreieck d = Dreieck(Point(1,1),Point(-2,0),Point(1,0));

	Rechteck r1 = Rechteck(2, 3);
	std::cout << "\nRechteck Flaeche: " << r1.getFlaeche();
	std::cout << "\nRechteck Umfang: " << r1.getUmfang();
	//
	//std::cout << "\nKreis: "; c.print();

	//print(c);
	//Point p = Point(1, 2);
	//print(p);
	//r.print();

	//int a = 1;
	//int b = 2;
	//


	//cout << "\n a = " << a << " b = " << b;
	//cout << "\n By value  add(a, b): " << add(a, b);
	//cout << "\n a = " << a << " b = " << b;
	//cout << "\n By reference addr(a, b): " << addr(a, b);
	//cout << "\n a = " << a << " b = " << b;
	//cout << "\n By  pointer add(pa, pb);: " << add(&a, &b);
	//cout << "\n a = " << a << " b = " << b;


	//-------------------------Task-------------------------------------
		Circle c1{ 5, Point(5, 5) };
		Circle c2{};

		cout << "\n Circle 1 by value: "; print(c1);
		cout << "\n Circle 1 by ref: "; printR(c1);
		cout << "\n Circle 1 by addr: "; print(&c1);

		cout << "\n Circle 2 by value: "; print(c2);
		cout << "\n Circle 2 by ref: "; printR(c2);
		cout << "\n Circle 2 by addr: "; print(&c2);

		c2.setMP(Point(2, 2));
		c2.setRadius(33);

		cout << "\n Circle 2 by value: "; print(c2);
		cout << "\n Circle 2 by ref: "; printR(c2);
		cout << "\n Circle 2 by addr: "; print(&c2);


		Dreieck d{ Point(1, 1), Point(-2, 0), Point(1, 0) };
		cout << "\n Dreieck  by value: "; print(d);
		cout << "\n Dreieck  by ref: "; printR(d);
		cout << "\n Dreieck  by addr: "; print(&d);
		cout << "\n Dreieck getCoords:";
		d.getCoords()[0]->print();
		d.getCoords()[1]->print();
		d.getCoords()[2]->print(); 
		(*d.getCoords()[2]).print();


		Rechteck r{ 2, 3 };
		cout << "\n Rechteck  by value: "; print(r);
		cout << "\n Rechteck  by ref: "; printR(r);
		cout << "\n Rechteck  by addr: "; print(&r);

		Point p{ 1, 2 };
		cout << "\n Point  by value: "; print(p);
		cout << "\n Point  by ref: "; printR(p);
		cout << "\n Point  by addr: "; print(&p);

		_3D::Point p3d{ 1, 2, 3 };
		cout << "\n Point 3D  by addr: "; print(&(p3d));
		cout << "\n Point 3D: " << p3d.sprint();
}


int add(int a, int b) {
	int sum = a + b;
	a = 88;
	return sum;
};


int addr(int& a, int& b) {
	int sum = a + b;
	a = 99;
	return sum;
};

int add(int* a, int* b) {
	int sum =  *a + *b;
	*a = 111;
	return sum;
};

void print(Circle c) {
	c.print();
};

void printR(Circle& c) {
	c.print();
};

void print(Circle* c) {
	c->print();
};

void print(Dreieck c) {
	c.print();
};

void printR(Dreieck& c) {
	c.print();
};

void print(Dreieck* c) {
	c->print();
};

void print(Rechteck c) {
	c.print();
};

void printR(Rechteck& c) {
	c.print();
};

void print(Rechteck* c) {
	c->print();
};

void print(Point c) {
	c.print();
};

void printR(Point& c) {
	c.print();
};

void print(Point* c) {
	c->print();
};

void print(_3D::Point* c) {
	c->print();
};

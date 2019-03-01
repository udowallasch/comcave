// Task_1_3.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"

#include <iostream>
using namespace std;

class A {
public:
	int i;
public:
	A(int i) : i{ i } {
		cout << "A one-argconstructor called " << endl;
	}
	A() : i{ 0 } {
		cout << "A no-argconstructor called " << endl;
	}
	A(const A &a) {
		cout << "A copy constructor called " << endl;
		this->i = a.i;
	}
	void m() const {
		cout << "m aus A called " << endl;
	}
	virtual void f() const {
		cout << " f aus A called " << endl;
	}
};
class B : public A {
public:
	int j;

public:

	B(int i, int j) : A{ i }, j{ j }{
		cout << "B two-argconstructor called " << endl;
	}
	B() : A{ 0 }, j{ 0 } {
		cout << "B no-argconstructor called " << endl;
	}
	
	B(const B &b) {
		cout << "B copy constructor called " << endl;
	/*	this->i = b.i;
		this->j = b.j;*/
	}
	void m() const {
		cout << "m aus B called " << endl;
	}
	virtual void f() const {
		cout << " f aus B called " << endl;
	}
};

int main() {
	A a;
	cout << "erwartet: A no - argconstructor called" << endl;
	cout << "---------------------------------------------------\n";
	B b;
	cout << "erwartet: A one - argconstructor called" << endl;
	cout << "erwartet: B no - argconstructor called" << endl;
	cout << "---------------------------------------------------\n";
	A a2 = a;
	cout << "erwartet: A copy constructor called" << endl;
	cout << "---------------------------------------------------\n";
	B b2 = b;
	cout << "erwartet: A no - argconstructor called" << endl;
	cout << "erwartet: B copy constructor called" << endl;
	cout << "---------------------------------------------------\n";
	A a3 = b;
	cout << "erwartet: A copy constructor called" << endl;
	cout << "---------------------------------------------------\n";
	A &ra = b;
	cout << "erwartet:nix" << endl;
	cout << "---------------------------------------------------\n";

	A *pa = &b;
	cout << "erwartet:nix" << endl;
	cout << "---------------------------------------------------\n";

	a3.m();
	cout << "erwartet: m aus A called" << endl;
	cout << "---------------------------------------------------\n";

	a3.f();
	cout << "erwartet:f aus A called " << endl;
	cout << "---------------------------------------------------\n";
	ra.m();
	cout << "erwartet:m aus A called " << endl;
	cout << "---------------------------------------------------\n";

	ra.f();
	cout << "erwartet: f aus B called " << endl;
	cout << "---------------------------------------------------\n";
	pa->m();
	cout << "erwartet:m aus A called " << endl;
	cout << "---------------------------------------------------\n";

	pa->f();
	cout << "erwartet: f aus B called " << endl;
	cout << "---------------------------------------------------\n";
	return 0;
}
// Task_28_2_override.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "uebung1a.h"
#include "uebung1b.h"
#include "uebung1c.h"
#include "uebung1d.h"
#include "uebung1e.h"
#include "uebung1f.h"
#include <string>
using namespace std;


class Animal {
protected:
	string name;
	//string name, laut;
	//Animal(string name, string laut) : name{ name }, laut{ laut }{}//Animal Objekte können von main heraus nicht erzeugt werden
	Animal(string name) : name{ name }{}//Animal Objekte können von main heraus nicht erzeugt werden
public:

	string getName() const { return name; }
	virtual string  getLaut() const { return "generische Laut"; }
	//string  getLaut() const { return laut; }
};

class Dog : public Animal {

public:
	Dog(string name) :Animal{ name } {}
	//Dog(string name) :Animal{ name,"Wau" } {}
	string getName() const { return name; }
	string  getLaut() const { return "Wau"; }
};

class Cat : public Animal {
public:
	Cat(string name) :Animal{ name } {}
	//Cat(string name) :Animal{ name, "Meow" } {}
	string getName() const { return name; }
	//string  getLaut() const { return laut; }
	string  getLaut() const { return "Meow"; }
};


int main1() {
	//Cat c{ "Lily" };
	//Dog d{ "Paul" };

	//cout << c.getName() << " " << c.getLaut() << endl;
	//cout << d.getName() << " " << d.getLaut() << endl;
	//Animal *p = &c;
	//cout << endl;
	//cout << p->getName() << "  " << p->getLaut() << endl;//Lily Meow
	//p = &d;
	//cout << p->getName() << "  " << p->getLaut() << endl;//Paul Vau
	cout << "------------ uebung1a -------------------------\n";
	uebung1a a1;
	a1.run();
	cout << "------------ uebung1b -------------------------\n";
	uebung1b b1;
	b1.run();
	cout << "------------ uebung1c -------------------------\n";
	uebung1c c1;
	c1.run();
	cout << "------------ uebung1d -------------------------\n";
	uebung1d d1;
	d1.run();
	cout << "------------ uebung1e -------------------------\n";
	uebung1e e1;
	e1.run();
	cout << "------------ uebung1f -------------------------\n";
	uebung1f f1;
	f1.run();

	return 0;
}

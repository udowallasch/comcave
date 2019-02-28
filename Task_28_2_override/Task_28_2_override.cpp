// Task_28_2_override.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "uebung1a.h"
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


int main() {
	//Cat c{ "Lily" };
	//Dog d{ "Paul" };

	//cout << c.getName() << " " << c.getLaut() << endl;
	//cout << d.getName() << " " << d.getLaut() << endl;
	//Animal *p = &c;
	//cout << endl;
	//cout << p->getName() << "  " << p->getLaut() << endl;//Lily Meow
	//p = &d;
	//cout << p->getName() << "  " << p->getLaut() << endl;//Paul Vau

	uebung1a a1;
	a1.run();


	return 0;
}

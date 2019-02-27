// Task_27_2_mehrfach_vererbung.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
using namespace std;

class Pferd {
public:
	int p;
	Pferd() { cout << " Pferd \n"; }
	void c() { cout << "c aus Pferd\n"; }
};

class Esel {
public:
	int e;
	Esel() { cout << " Esel \n"; }
	void c() { cout << "c aus Esel\n"; }
};

class Muli : public Esel, public Pferd  {
public:
	//using Esel::c;
	void c() { cout << "c aus Muli\n"; }
};


class Base {
private:
	int i;
protected:
	int j;
	void m() { cout << "m aus der Klasse Base " << endl; }
public:
	Base(int i = 0, int j = 0) : i{ i }, j{ j }{}
	void f() { cout << "f aus Base " << endl; }
};

class Derived :  public Base {
private:
	int k;
	//using Base::j;
protected:
	using Base::f; // verbergen geht -> damit nur 
	//using Base::i; //error wg private -> kann nur veröffentlichen , was ich selber sehe
public:
	/**
	Für die Initialisierung der geerbten Elemente ist der Basiskonstruktor verantwortlich!!!
	*/
	Derived(int i, int j, int k) : Base{ i,j } /*i{i}, j{j},-> error*/, k{ k }{
		//this->i = i;//Error, i ist in Base private
		this->j = j;//Assignement
	}
	using Base::j;

	using Base::m;
};

class Derived_Derived : public Derived {

public:
	Derived_Derived(int i, int j, int k) : Derived{ i, j,k } {
		//this->i = 1;//error
		//this->j = 2;//error
	}
	void d() {
		this->j;
	}
};




int main3()
{
	//Muli m;
	//m.c();

	//Esel *e = &m;
	//Pferd *p = &m;
	//e->c();
	//p->c();

	//Pferd p1 = m;
	//Esel e1 = m;
	
	Derived d{ 1,2,3 };
	d.j = 1;
	return 0;

}


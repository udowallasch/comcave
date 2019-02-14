// Task_13_2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
using namespace std;

class Etwas {
private:
	int i{ 4711 }, j{ 4711 }, k{ 4711 };
};

int main() {
	int i = 5;
	cout << i << endl;
	cout << &i << endl;
	cout << *&i << endl;
	//Dekaration

	int a = 78;
	int& r = a;

	int* p;//Garbage Adress
	p = &a;
	cout << "a = " << a << ", r = " << r << ", p = " << p << ", &a = " << &a << endl;

	//int x, y= 2,z;
	int *r2 = &i, *s = &i, *t = &i;//vorsicht mit int* r2, s,t; hat eine andere Auswirkung!!

	cout << "r2 = " << r2 << ", s= " << s << ", t = " << t << endl;
	//
	//int &r3 = 45;//error: Für non const referenzen Initialisierung mittels r-values geht nicht
	int const &r3 = 47;
	int const r4 = 48;
	cout << r3;
	// int *p2 = 565868;//error:
	//int *p2 = 0x28ff08;
	//cout << p2 << endl;

	cout << "Der Datentyp von &i = " << typeid(&i).name() << endl;//pi (Pointer to int) = int*
	//double* dp;
	//int* pi = dp;//error


	//
	Etwas ew;
	char ch = 'c';
	char *pc = &ch; int *pi = &i; Etwas *e = &ew;

	cout << sizeof(pc) << " " << sizeof(pi) << " " << sizeof(e) << endl;
	cout << sizeof(ch) << " " << sizeof(i) << " " << sizeof(ew) << endl;


	Etwas e1[10];

	Etwas *pe = e1;
	cout << "pe "<<e1 + 0 <<" "<<e1+1 << " " << e1 + 2 << endl;


}


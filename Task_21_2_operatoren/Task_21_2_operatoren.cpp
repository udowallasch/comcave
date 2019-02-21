// Task_21_2_operatoren.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
using namespace std;

class Box {
private :
	int n;
public:
	Box(int n) :n{ n } { cout << "Box[n = " << n << "] erzeugt" << endl; }
	//explicit Box(int n) :n{ n } { cout << "Box[n = " << n << "] erzeugt" << endl; }
	// explicit bewirkt, dass keine implizite Typumwandlung geschieht (conversion constructor, gibt's nur bei 1-Argument Konstruktor),
	// also Box b = 6 funktioniert damit nicht, ohne aber schon 

	void print() {
		cout << "Box[n = " << n << "]" << endl;
	}
	friend Box operator+(Box&, Box&);
};

Box operator+(Box &a, Box &b) {
	Box result{ a.n + b.n };
	return result;
}
int main()
{
	Box b1{ 1 };
	Box b2{ 2 };

	Box b3 = b1 + b2;

	b3.print();
	Box b4 = 6;
}


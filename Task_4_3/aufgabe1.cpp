#include "pch.h"
#include "aufgabe1.h"
#include <iostream>

using namespace std;

void fa1(int, int, int&, int&, int&);


void aufgabe1::run() {
	int s, p, a;
	fa1(7, 8, s, p, a);
	cout << "s=" << s << " p=" << p << " a=" << a << endl;
}

void fa1(int a, int b, int& sum, int& prod, int& abs) {
	sum = a + b;
	prod = a * b;
	abs = a - b;
	abs > 0 ? abs : abs=-abs;
}

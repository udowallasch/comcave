#include "pch.h"
#include "aufgabe2.h"
#include <iostream>
using namespace std;

int a[] = { 2,47,23,9,49,3,4,5,7,47,9,8 };

int minimum(int*, int);


void aufgabe2::run() {
	cout << "min: " << minimum(a,11) << endl;
}

int minimum(int* ia, int len) {
	int m = *ia;
	for (int i = 0; i < len-1; i++ ) {
		if (*(++ia) < m) m = *ia;
		cout << *ia << endl;
	}
	return m;
}

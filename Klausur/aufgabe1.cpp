#include "pch.h"
#include<iostream>
#include<sstream>
#include "aufgabe1.h"

using namespace std;

namespace {


	

}
int checkArray(int[], int length, int& cntPos, int& cntNeg);

void fun(double& d) {
	cout << d << endl;
}
void funRef(double& d) {
	cout << d << endl;
}
void funPoi(double* d) {
	cout << *d << endl;
}

void harmonisch(int anzahlElemente) {
	double* darr = new double[anzahlElemente];
	for (int i = 0; i < anzahlElemente; i++) {
		darr[i] = 1.0 / (i+1);
	
	}

	for (int i = 0; i < anzahlElemente; i++) {
		cout << darr[i] << endl;

	}

	delete[] darr;
}


void aufgabe1::run() {
	cout << "aufgabe 1 ----------------------------------------" << endl;

	harmonisch(5);
	int a[] = { 1,2,3,4,5 };

	
	int c=0, d=0;
	int b = checkArray(a, 5,c, d);

	double dd = 2.0;
	fun(dd);
	funRef(dd);
	funPoi(&dd);


}
int checkArray(int a[] , int length, int& cntPos, int& cntNeg) {
	int z = 0;
	for (int i = 0; i < length; i++) {
		if (a[i] == 0) {
			z++;
		}
		else {
			a[i]>0?cntPos++:cntNeg++;
		};
	}
	return z;

}

aufgabe1::aufgabe1() {}
aufgabe1::~aufgabe1() {}

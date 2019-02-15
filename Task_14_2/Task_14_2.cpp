// Task_14_2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
using namespace std;

void f(int *a) {
	cout << "eins" << endl;
}

void f(double * a) {
	cout << "zwei" << endl;
}


int main()
{
	int a = 13;
	double *ptr{};
	ptr = NULL;

	double ad[]{ 1.1,2.2,3.3,4.4 };
	cout << sizeof( ad) << endl;
	void * vp = ad;
	cout << "*vp = " << *(double *)vp << endl;
	cout << "*vp+1 = " << *((double *)vp +1) << endl;

	int const i{ 4 };
	int  j{ 5 };

	int  const *   pi = &j;
	pi = &j;

	int * const cpi = &j;
	*cpi = 2;

	int const * const cp2i = &i;


	//int *****************************************a;
	int l;
	int* ai[]{ &l,&j};

	int** k = ai;
	**k = 4711;
	cout << " l = " << l << endl;



	int *b = &j;
	int* &c = b;


	*b = 1;
	cout << "c: " << c << endl;
	cout << "j: " << j << endl;

	int d;
	const int e{ 1 };
	const int &f = d;
	//f = 1;
	const int &g = e;

	int const * const h = &e;
	//h = &e;
	//h = &d;
	//*h = 1;

	//*h++;
	
	const int *m = &d;
	m = &e;

	//int *n = &e;
	//n = &d;

	int * const p = &d;
	int const *  r = &d;
	r = &e;

	const int* const s = &d;
	//s = &e;


}



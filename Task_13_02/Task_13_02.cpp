// Task_13_02.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include<time.h>

using namespace std;


unsigned int fac(unsigned int);
unsigned int fac1(unsigned int);

class Bla {
public:
	int i{ 1 }, j{ 2 };
	double d{ 1.1 }, d1{ 2.2 };
};

int main()
{
	int i, j, k;
	//cout << i << " " << j << " " << k << endl;
	//garbage Fehler
	i = 1; j = 2; k = 3;
	cout << i << " " << j << " " << k << endl;
	//1,2,3
	int &ref_i = i;
	cout << &ref_i << endl;
	// addr i
	const int &ref_j = j;
	cout << &ref_j << endl;
	// addr j
	j++;
	cout << j << endl;
	//3
	ref_i = k;
	cout << ref_i<< endl;
	//3
	k++;
	cout <<k++ << endl;
	//4
	int x = ref_j;
	cout << x << endl;
	//3
	 int v = 444;
	int &rv = v;

	rv++;


	time_t t1, t2, t3, t4;

	time_t rawtime;
	struct tm * timeinfo;

	//time(&t1);
	//for (int i = 0; i < 100000000; i++) fac(20);
	//time(&t2);
	//cout << "dT1: " << t2 - t1 << endl;

	//time(&t3);
	//for (int i = 0; i < 100000000; i++) fac1(30);
	//time(&t4);
	//cout << "dT2: " << t4 - t3 << endl;

	

	cout <<endl;

		cout<< "-----------------------------" << endl;
		short s_value = 7;
		short s_value_2 = 3;
		_int16 i16 = 4;

		short *ptr = &s_value;
		cout << &s_value << endl;		// 0x2cfa24
		cout << s_value << endl;		// 7
		cout << ptr << endl;			// 0x2cfa24
		cout << *ptr << endl;			// 7
		cout << endl;

		*ptr = 9;

		cout << &s_value << endl;		// 0x2cfa24
		cout << s_value << endl;		// 9
		cout << ptr << endl;			// 0x2cfa24
		cout << *ptr << endl;			// 9
		cout << endl;

		ptr = &s_value_2;
		cout << &s_value << endl;		// 0x2cfa24
		cout << s_value << endl;		// 9
		cout << ptr << endl;			// 0x2cfa44
		cout << *ptr << endl;			// 3
		cout << endl;

		cout << sizeof(ptr) << endl;	// 8
		cout << sizeof(*ptr) << endl;	// 2

		cout << sizeof(i16) << endl;

		cout << "-----------------------------" << endl;

		Bla b[10];
		cout << b->i << endl;
		cout << (b+9)->i << endl;



}








unsigned int fac(unsigned int n) {
	if (n > 1) return fac(n - 1)*n;
	return 1;
}

unsigned int fac1(unsigned int n) {
	unsigned ret = 1;
	for (unsigned i = 2; i <= n; i++) {
		ret *= i;
	}
	return ret;
}
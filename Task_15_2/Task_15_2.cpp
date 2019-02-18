// Task_15_2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
using namespace std;

int f(int x, int y) {
	int temp = x;
	int* sum;
	sum = &x;
	x += y;

	cout << "summe = " << sum << endl;
	int *prod;
	prod = &y;
	y = temp * y;
	cout << "product = " << prod << endl;
	return *prod;
}

int main()
{
	int a = 3, b = 4;

	int r;

	r = f(a, b);

	std::cout << "return = " << r << endl;
	std::cout << "&return = " << &r << endl;

	int *ptr = new int;
	int * ptr_2 = new int;
	int * ptr_3 = ptr_2;
	delete ptr_3;
	delete ptr_2;
	delete ptr;
	int * x = new int;
	delete x;
	//delete x;
	//delete x;
	x = nullptr;
	delete x;



}


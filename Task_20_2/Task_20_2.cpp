// Task_20_2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>

using namespace std;

class TT {


public:
	const int i;
	TT(int i ): i{i} {}


};


int main()
{
	TT t;
	std::cout << "Hello World!" << t.i << endl;
	return 0;
}


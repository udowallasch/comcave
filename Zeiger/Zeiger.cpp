// Zeiger.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>

int main()
{
	using namespace std;

	int  x = 10;
	int * const px = &x;

	std::cout << "\nx " << x;
	std::cout << "\npx " << px;
	std::cout << "\n*px " << *px;

	*px = 11;
	px = &x;
	std::cout << "\nx " << x;
	std::cout << "\npx " << px;
	std::cout << "\n*px " << *px;


	int y = 12;
	int  const *   py = &y;
	*py = 2;
	py = &x;
	y = 4;
	py = &y;
	y = 4;


	std::cout << "\ny " << y;
	std::cout << "\npy " << py;
	std::cout << "\n*py " << *py;

}


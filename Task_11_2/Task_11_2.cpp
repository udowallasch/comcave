// Task_11_2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include"Point.h"
#include"Circle.h"
int main()
{
	Point p1{ 1,1 };
	Point p2{ 4,5 };
	Circle c1{1.5};
	Circle c2{ 3,Point {4,6} };

	   
	std::cout << "\nAbstand P1 " << p1.sprint() << " zu P2" << p2.sprint() << ": " << p1.dist(p2);
	std::cout << "\nUmfang c1: " << c1.getUmfang() << ", Flaeche c1: " << c1.getFlaeche();
	std::cout << "\nUmfang c2: " << c2.getUmfang() << ", Flaeche c2: " << c2.getFlaeche();
	std::cout << "\nP1 in c1 " << (c1.isWithin(p1) ? "Yes" : "No") << ", P1 in c2: " << (c2.isWithin(p1) ? "Yes" : "No");
	std::cout << "\nP2 in c1 " << (c1.isWithin(p2) ? "Yes" : "No") << ", P2 in c2: " << (c2.isWithin(p2) ? "Yes" : "No");

}


// KlassenÜbung.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "Circle.h"
#include "Point.h"
#include "Rechteck.h"
#include "Dreieck.h"

int main()
{
	Circle c = Circle(5, Point(5, 5));
	Rechteck r = Rechteck(2, 3);
	Dreieck d = Dreieck(Point(1,1),Point(-2,0),Point(1,0));

	std::cout << "\nRechteck Flaeche: " << r.getFlaeche();
	std::cout << "\nRechteck Umfang: " << r.getUmfang();
}



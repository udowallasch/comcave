// Task_20_2_uebung_1_3.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "Point3d.h"
#include "Vector3d.h"


int main() {
	Point3d p(1.0, 2.0, 3.0);
	Vector3d v(2.0, 2.0, -3.0);

	p.print();
	p.verschiebe_durch_vektor(v);
	p.print();

	return 0;
}
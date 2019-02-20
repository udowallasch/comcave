// Task_20_2_uebung.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <iostream>

class Vector3d;

class Point3d {
private:
	double x, y, z;

public:
	Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: x(x), y(y), z(z) {

	}

	void print() {
		std::cout << "Point(" << x << " , " << y << " , " << z << ")" << std::endl;
	}

	void verschiebe_durch_vektor(const Vector3d &);
};

class Vector3d {
private:
	double x, y, z;

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: x(x), y(y), z(z) {

	}

	void print() {
		std::cout << "Vector(" << x << " , " << y << " , " << z << ")" << std::endl;
	}

	friend void Point3d::verschiebe_durch_vektor(const Vector3d &);
};


void Point3d::verschiebe_durch_vektor(const Vector3d &v) {
	// implementiere diese Methode als Freund von Vector3d
	x += v.x;
	y += v.y;
	z += v.z;
}

int main() {
	Point3d p(1.0, 2.0, 3.0);
	Vector3d v(2.0, 2.0, -3.0);

	p.print();
	p.verschiebe_durch_vektor(v);
	p.print();

	return 0;
}
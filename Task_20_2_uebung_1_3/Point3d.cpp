#include "pch.h"
#include <iostream>
#include "Point3d.h"
#include "Vector3d.h"

using namespace std;
class Vector3d;

void Point3d::print() {
	std::cout << "Point(" << x << " , " << y << " , " << z << ")" << std::endl;
}

void Point3d::verschiebe_durch_vektor(const Vector3d &v) {
	// implementiere diese Methode als Freund von Vector3d
	x += v.x;
	y += v.y;
	z += v.z;
}

Point3d::Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
	: x(x), y(y), z(z) {}

#include "pch.h"
#include "Vector3d.h"
#include <iostream>

using std::cout;

Vector3d::Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
	: x(x), y(y), z(z) {
}

void Vector3d::print() {
	std::cout << "Vector(" << x << " , " << y << " , " << z << ")" << std::endl;
}

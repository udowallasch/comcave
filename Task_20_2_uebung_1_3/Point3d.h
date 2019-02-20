#ifndef POINT3D_H
#define POINT3D_H
#pragma once

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


#endif
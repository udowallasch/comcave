
#ifndef VECTOR3D_H
#define VECTOR3D_H
#pragma once

#include "Point3d.h"

class Vector3d {
private:
	double x, y, z;

public:
	Vector3d(double, double, double);

	void print();

	friend void Point3d::verschiebe_durch_vektor(const Vector3d &);
	//friend class Point3d;

};

#endif
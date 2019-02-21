#ifndef POINT3D_H
#define POINT3D_H
#pragma once


class Vector3d;

class Point3d {
private:
	double x, y, z;
	public:
	Point3d(double, double, double);
		void print();
		void verschiebe_durch_vektor(const Vector3d &v);


	};

#endif
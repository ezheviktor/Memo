#include <iostream>
#include "Vector3D.h"



void Vector3D::print()
{
	std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}

Vector3D::Vector3D(double x = 0.0, double y = 0.0, double z = 0.0)
	: m_x(x), m_y(y), m_z(z)
{}
void Point3D::moveByVector(const Vector3D& v)
{
	{
		m_x += v.m_x;
		m_y += v.m_y;
		m_z += v.m_z;
	}
}

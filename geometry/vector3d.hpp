#pragma once

#include <iostream>

#include "vo3d.hpp"

class Vector3d : public Vo3d
{
	public:
		Vector3d();
		Vector3d(float x, float y, float z);
		
		Vector3d& operator+=(const Vector3d&);
		Vector3d& operator-=(const Vector3d&);

	private:
		
	friend std::ostream& operator<< (std::ostream& flux, Vector3d const& vector);
};

Vector3d operator-(Vector3d first, const Vector3d &other);
Vector3d operator+(Vector3d first, const Vector3d &other);

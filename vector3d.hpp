#pragma once

#include <iostream>

class Vector3d
{
	public:
		Vector3d();
		Vector3d(float x, float y, float z);
		float getX();
		void setX(float x);
		float getY();
		void setY(float y);
		float getZ();
		void setZ(float z);
		
		Vector3d& operator+=(const Vector3d&);
		Vector3d& operator-=(const Vector3d&);

	private:
		float x;
		float y;
		float z;
		
	friend std::ostream& operator<< (std::ostream& flux, Vector3d const& vector);
};

Vector3d operator-(Vector3d first, const Vector3d &other);
Vector3d operator+(Vector3d first, const Vector3d &other);

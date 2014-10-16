#pragma once

#include <iostream>

class Vector
{
	public:
		Vector();
		Vector(float x, float y, float z);
		float getX();
		void setX(float x);
		float getY();
		void setY(float y);
		float getZ();
		void setZ(float z);
		
		Vector& operator+=(const Vector&);
		Vector& operator-=(const Vector&);

	private:
		float x;
		float y;
		float z;
		
	friend std::ostream& operator<< (std::ostream& flux, Vector const& vector);
};

Vector operator-(Vector first, const Vector &other);
Vector operator+(Vector first, const Vector &other);

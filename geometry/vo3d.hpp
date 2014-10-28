#pragma once

#include <iostream>

class Vo3d
{
	public:
		Vo3d();
		Vo3d(float x, float y, float z);
		float getX() const;
		void setX(float x);
		float getY() const;
		void setY(float y);
		float getZ() const;
		void setZ(float z);

	private:
		float x;
		float y;
		float z;

	friend std::ostream& operator<< (std::ostream& flux, Vector3d const& vector);
};

#pragma once

#include <iostream>

class Coordinates
{
	public:
		Coordinates();
		Coordinates(float x, float y, float z);
		float getX();
		void setX(float x);
		float getY();
		void setY(float y);
		float getZ();
		void setZ(float z);
		

	private:
		float x;
		float y;
		float z;
		
	friend std::ostream& operator<< (std::ostream& flux, Coordinates const& coordinates);
};

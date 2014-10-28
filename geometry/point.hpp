#pragma once

#include "vo3d.hpp"
#include "vector3d.hpp"

class Point : public Vo3d
{
	public:
		Point();
		Point(int x, int y, int z);
		virtual ~Point();

		Vector3d operator-=(const Point&);

	private:
};

Vector3d operator-(Point first, const Point &other);

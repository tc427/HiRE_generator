#pragma once

#include "vo3d.hpp"

class Point : public Vo3d
{
	public:
		Point();
		Point(int x, int y, int z);
		virtual ~Point();

		Point& operator-=(const Point&);

	private:
};

Point operator-(Point first, const Point &other);

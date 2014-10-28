#include "point.hpp"

Point::Point() : Vo3d()
{

}

Point::Point(int x, int y, int z) : Vo3d(x, y, z)
{

}

Point::~Point() {
	// TODO Auto-generated destructor stub
}

Vector3d Point::operator-=(const Point& other)
{
  return Vector3d(other.x - x, other.y - y, other.z- z);
}

Vector3d operator-(Point first, const Point &other)
{
  return first-=other;
}

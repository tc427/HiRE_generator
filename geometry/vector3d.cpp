#include "vector3d.hpp"

using namespace std;

Vector3d::Vector3d() : Vo3d()
{
	
}

Vector3d::Vector3d(float x, float y, float z) : Vo3d(x, y, z)
{

}

ostream &operator<<( ostream &out, Vector3d const& vector )
{
	out << "< x=" << vector.x << " y=" << vector.y << " z=" << vector.z << " >" ;
    return out ;
}


Vector3d& Vector3d::operator+=(const Vector3d& other) {
  x += other.x;
  y += other.y;
  z += other.z;
  return *this;
}

Vector3d operator+(Vector3d first, const Vector3d &other)
{
  return first+=other;
}

Vector3d& Vector3d::operator-=(const Vector3d& other) {
  x -= other.x;
  y -= other.y;
  z -= other.z;
  return *this;
}

Vector3d operator-(Vector3d first, const Vector3d &other)
{
  return first-=other;
}

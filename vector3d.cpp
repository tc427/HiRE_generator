#include "vector3d.hpp"

using namespace std;

Vector3d::Vector3d() : x(0), y(0), z(0)
{
	
}

Vector3d::Vector3d(float x, float y, float z) : x(x), y(y), z(z)
{

}

float Vector3d::getX()
{
	return x;
}

void Vector3d::setX(float x)
{
	x = x;
}

float Vector3d::getY()
{
	return y;
}

void Vector3d::setY(float y)
{
	y = y;
}

float Vector3d::getZ()
{
	return z;
}

void Vector3d::setZ(float z)
{
	z = z;
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

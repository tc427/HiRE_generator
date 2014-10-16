#include "vector.hpp"

using namespace std;

Vector::Vector() : x(0), y(0), z(0)
{
	
}

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z)
{

}

float Vector::getX()
{
	return x;
}

void Vector::setX(float x)
{
	x = x;
}

float Vector::getY()
{
	return y;
}

void Vector::setY(float y)
{
	y = y;
}

float Vector::getZ()
{
	return z;
}

void Vector::setZ(float z)
{
	z = z;
}

ostream &operator<<( ostream &out, Vector const& vector )
{
	out << "< x=" << vector.x << " y=" << vector.y << " z=" << vector.z << " >" ;
    return out ;
}


Vector& Vector::operator+=(const Vector& other) {
  x += other.x;
  y += other.y;
  z += other.z;
  return *this;
}

Vector operator+(Vector first, const Vector &other)
{
  return first+=other;
}

Vector& Vector::operator-=(const Vector& other) {
  x -= other.x;
  y -= other.y;
  z -= other.z;
  return *this;
}

Vector operator-(Vector first, const Vector &other)
{
  return first-=other;
}

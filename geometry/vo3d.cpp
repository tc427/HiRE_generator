#include "vo3d.hpp"

using namespace std;

Vo3d::Vo3d() : x(0), y(0), z(0)
{

}

Vo3d::Vo3d(float x, float y, float z) : x(x), y(y), z(z)
{

}

float Vo3d::getX() const
{
	return x;
}

void Vo3d::setX(float _x)
{
	x = _x;
}

float Vo3d::getY() const
{
	return y;
}

void Vo3d::setY(float _y)
{
	y = _y;
}

float Vo3d::getZ() const
{
	return z;
}

void Vo3d::setZ(float _z)
{
	z = _z;
}

ostream &operator<<( ostream &out, Vo3d const& vector )
{
	out << "< x=" << vector.x << " y=" << vector.y << " z=" << vector.z << " >" ;
    return out ;
}

#include "coordinates.hpp"

using namespace std;

Coordinates::Coordinates() : x(0), y(0), z(0)
{
	
}

Coordinates::Coordinates(float x, float y, float z) : x(x), y(y), z(z)
{
	
}

float Coordinates::getX()
{
	return x;
}

void Coordinates::setX(float x)
{
	x = x;
}

float Coordinates::getY()
{
	return y;
}

void Coordinates::setY(float y)
{
	y = y;
}

float Coordinates::getZ()
{
	return z;
}

void Coordinates::setZ(float z)
{
	z = z;
}

ostream &operator<<( ostream &out, Coordinates const& coordinates )
{
	out << "<x=" << coordinates.x << " y=" << coordinates.y << " z=" << coordinates.z << " >" ;
    return out ;
}

#include "geometry.hpp"

#define PI 3.14159265

using namespace std;

float norm(Vector v)
{
	return sqrt( pow(v.getX(),2) + pow(v.getY(),2) + pow(v.getZ(),2) );
}

float angle(Vector v1, Vector v2)
{
	return acos( dotProduct(v1, v2) / ( norm(v1)*norm(v2) ) ) * 180.0 / PI;
}

float dotProduct(Vector v1, Vector v2)//Produit scalaire
{
	return v1.getX()*v2.getX()+v1.getY()*v2.getY()+v1.getZ()*v2.getZ();
}

Vector crossProduct(Vector v1, Vector v2)//Produit vectoriel
{
	//http://fr.wikipedia.org/wiki/Produit_vectoriel
	return Vector(v1.getY()*v2.getZ() - v1.getZ()*v2.getY(),
				  v1.getZ()*v2.getX() - v1.getX()*v2.getZ(),
				  v1.getX()*v2.getY() - v1.getY()*v2.getX() );
}

float dihedral(Vector v1, Vector v2, Vector v3, Vector v4)
{
	Vector U = v2-v1;
	Vector V = v3-v2;
	Vector W = v4-v3;

	return angle(crossProduct(U, V), crossProduct(V,W));
}

float dihedral(Atom atom1, Atom atom2, Atom atom3, Atom atom4)
{
	return dihedral(atom1.getCoordinates(), atom2.getCoordinates(), atom3.getCoordinates(), atom4.getCoordinates());
}


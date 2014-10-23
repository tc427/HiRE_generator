#include "geometry.hpp"

#define PI 3.14159265

using namespace std;

float norm(Vector3d v)
{
	return sqrt( pow(v.getX(),2) + pow(v.getY(),2) + pow(v.getZ(),2) );
}

float angle(Vector3d v1, Vector3d v2)
{
	
	float d ( dotProduct(v1, v2) / ( norm(v1)*norm(v2) ) );

	if(d <= -0.99999 and d >= -1.00001)
	{
		return 180;
	}
	else if(d >= 0.99999 and d <= 1.00001)
	{
		return 0;
	}
	else
	{
		return acos( d ) * 180.0 / PI;
	}
}

float determinant(Vector3d v1, Vector3d v2)
{
	
}

float dotProduct(Vector3d v1, Vector3d v2)//Produit scalaire
{
	return v1.getX()*v2.getX()+v1.getY()*v2.getY()+v1.getZ()*v2.getZ();
}

Vector3d crossProduct(Vector3d v1, Vector3d v2)//Produit vectoriel
{
	//http://fr.wikipedia.org/wiki/Produit_vectoriel
	return Vector3d(v1.getY()*v2.getZ() - v1.getZ()*v2.getY(),
				  v1.getZ()*v2.getX() - v1.getX()*v2.getZ(),
				  v1.getX()*v2.getY() - v1.getY()*v2.getX() );
}

float dihedral(Vector3d v1, Vector3d v2, Vector3d v3, Vector3d v4)
{
	Vector3d U = v2-v1;
	Vector3d V = v3-v2;
	Vector3d W = v4-v3;

	Vector3d vec1 = crossProduct(U, V);
	Vector3d vec2 = crossProduct(V, W);

	if(angle(crossProduct(vec1, vec2), V) == 0)
	{
		return angle(vec1, vec2);
	}
	else
	{
		return 360-angle(vec1, vec2);
	}
}

vector<float> dihedrals(Atom atom1, Atom atom2, Atom atom3, Atom atom4)
{
	vector<float> dihedralsList;
	for(std::vector<Vector3d>::size_type i = 0; i != 8000; i++)
	{
		dihedralsList.push_back( dihedral(atom1.getCoordinates()[i], 
										  atom2.getCoordinates()[i], 
										  atom3.getCoordinates()[i], 
										  atom4.getCoordinates()[i]) );
	}
	
	return dihedralsList;
}




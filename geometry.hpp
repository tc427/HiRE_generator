#include "vector3d.hpp"
#include "entities/atom.hpp"

#include <math.h> 
#include <vector>

std::vector<float> distances(Atom atom1, Atom atom2);
float dist(Vector3d v1, Vector3d v2);
float norm(Vector3d v);
float angle(Vector3d v1, Vector3d v2);
float dotProduct(Vector3d v1, Vector3d v2);//Produit scalaire
Vector3d crossProduct(Vector3d v1, Vector3d v2);//Produit vectoriel
float dihedral(Vector3d v1, Vector3d v2, Vector3d v3, Vector3d v4);
std::vector<float> dihedrals(Atom atom1, Atom atom2, Atom atom3, Atom atom4);

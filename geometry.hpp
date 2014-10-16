#include "vector.hpp"
#include "atom.hpp"

#include <math.h> 

float norm(Vector v);
float angle(Vector v1, Vector v2);
float dotProduct(Vector v1, Vector v2);//Produit scalaire
Vector crossProduct(Vector v1, Vector v2);//Produit vectoriel
float dihedral(Vector v1, Vector v2, Vector v3, Vector v4);
float dihedral(Atom atom1, Atom atom2, Atom atom3, Atom atom4);

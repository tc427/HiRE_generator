#include "atom.hpp"

using namespace std;

Atom::Atom()
{
	parent = 0;
}

Atom::Atom(int number, string name, string type) : parent(parent), number(number), name(name), type(type)
{
	parent = 0;	
}

Atom::Atom(int number, string name, string type, Vector3d coordinates) : parent(parent), number(number), name(name), type(type)
{
	parent = 0;
	addCoordinates(coordinates);
}

int Atom::getNumber() const
{
	return number;
}

void Atom::setNumber(int n)
{
	number = n;
}

string Atom::getType() const
{
	return type;
}

void Atom::setType(string t)
{
	type = t;
}

string Atom::getName() const
{
	return name;
}

void Atom::setName(string n)
{
	name = n;
}

void Atom::addCoordinates(Vector3d coord)
{
	coordinates.push_back(coord);
}

vector<Vector3d>& Atom::getCoordinates()
{
	return coordinates;
}

void Atom::setParent(Residue *par)
{
	parent = par;
}

Residue *Atom::getParent()
{
	return parent;
}

ostream &operator<<( ostream &out, Atom const& atom )
{
	out << "<atom number=" << atom.number << " name=" << atom.name << " type=" << atom.type << " numberOfFrames=" << atom.coordinates.size() << " >" ;
    return out ;
}

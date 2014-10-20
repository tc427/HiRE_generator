#include "atom.hpp"

using namespace std;

Atom::Atom()
{
	
}

Atom::Atom(int number, string name, string type) : number(number), name(name), type(type)
{
	
}

Atom::Atom(int number, string name, string type, Vector3d coordinates) : number(number), name(name), type(type)
{
	addCoordinates(coordinates);
}

int Atom::getNumber()
{
	return number;
}

string Atom::getType()
{
	return type;
}


string Atom::getName()
{
	return name;
}


void Atom::addCoordinates(Vector3d coord)
{
	coordinates.push_back(coord);
}

vector<Vector3d>& Atom::getCoordinates()
{
	return coordinates;
}


ostream &operator<<( ostream &out, Atom const& atom )
{
	out << "<atom number=" << atom.number << " name=" << atom.name << " type=" << atom.type << " numberOfFrames=" << atom.coordinates.size() << ">" ;
    return out ;
}

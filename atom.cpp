#include "atom.hpp"

using namespace std;

Atom::Atom()
{
	
}

Atom::Atom(int number, string name, string type) : number(number), name(name), type(type)
{
	
}

Atom::Atom(int number, string name, string type, Vector coordinates) : number(number), name(name), type(type), coordinates(coordinates)
{
	
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


void Atom::setCoordinates(Vector coordinates)
{
	coordinates = coordinates;
}

Vector& Atom::getCoordinates()
{
	return coordinates;
}


ostream &operator<<( ostream &out, Atom const& atom )
{
	out << "<atom number=" << atom.number << " name=" << atom.name << " type=" << atom.type << " vector= " << atom.coordinates << ">" ;
    return out ;
}

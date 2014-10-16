#include "atom.hpp"

using namespace std;

Atom::Atom()
{
	
}

Atom::Atom(int number, string name, string type) : number(number), name(name), type(type)
{
	
}

Atom::Atom(int number, string name, string type, Coordinates coordinates) : number(number), name(name), type(type), coordinates(coordinates)
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


void Atom::setCoordinates(Coordinates coordinates)
{
	coordinates = coordinates;
}

Coordinates Atom::getCoordinates()
{
	return coordinates;
}


ostream &operator<<( ostream &out, Atom const& atom )
{
	out << "<atom number=" << atom.number << " name=" << atom.name << " type=" << atom.type << " coordinates= " << atom.coordinates << ">" ;
    return out ;
}

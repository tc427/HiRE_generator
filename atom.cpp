#include "atom.hpp"

using namespace std;

Atom::Atom()
{
	
}

Atom::Atom(int number, string name, string type) : number(number), name(name), type(type)
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

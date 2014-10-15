#include "residue.hpp"

using namespace std;

Residue::Residue(int number, string type) : number(number), type(type)
{
	
}

Residue::Residue()
{

}

void Residue::addAtom(Atom atom)
{
	atoms[atom.getNumber()] = atom;
}

Atom Residue::getAtom(int atomNumber)
{
	return atoms[atomNumber];
}

bool Residue::hasAtom(int atomNumber)
{
	return atoms.count(atomNumber);
}

int Residue::getNumber()
{
	return number;
}

string Residue::getType()
{
	return type;
}

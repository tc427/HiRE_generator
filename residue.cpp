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
	atoms[atom.getName()] = atom;
}

Atom& Residue::getAtom(string atomName)
{
	return atoms[atomName];
}

bool Residue::hasAtom(string atomName)
{
	return atoms.count(atomName);
}

int Residue::getNumber()
{
	return number;
}

string Residue::getType()
{
	return type;
}

map<int, Atom> Residue::getAtoms()
{ 
	map<int, Atom> mapToReturn;
	
	for (map<string, Atom>::const_iterator it=atoms.begin(); it!=atoms.end(); ++it) {
		Atom atom = it->second;
		mapToReturn[atom.getNumber()] = atom;
	}
	
	return mapToReturn;
}

void Residue::printResidue(ostream& out) const
{
	out << "<residueNumber=" << number << " residueType=" <<  type << " atomsCount="<< atoms.size()  << "   ";
    for (map<string, Atom>::const_iterator it=atoms.begin(); it!=atoms.end(); ++it) {
		out << it->second << " ";
	}

	out << ">" ;
}

ostream &operator<<( ostream &out, Residue const& residue )
{
	residue.printResidue(out);
	return out ;
}


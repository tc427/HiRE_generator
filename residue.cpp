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

Atom& Residue::getAtom(int atomNumber)
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


void Residue::printResidue(ostream& out) const
{
	out << "<residueNumber=" << number << " residueType=" <<  type << " atomsCount="<< atoms.size()  << "   ";
    for (map<int, Atom>::const_iterator it=atoms.begin(); it!=atoms.end(); ++it) {
		out << it->second << " ";
	}

	out << ">" ;
}

ostream &operator<<( ostream &out, Residue const& residue )
{
	residue.printResidue(out);
	return out ;
}


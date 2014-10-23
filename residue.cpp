#include "residue.hpp"

using namespace std;

Residue::Residue(int number, string type) : number(number), type(type)
{
	parent = 0;
}

Residue::Residue()
{
	number = 0;
	parent = 0;
}

void Residue::addAtom(Atom atom)
{
	atom.setParent( this );
	atoms[atom.getName()] = atom;
}

Atom& Residue::getAtom(string atomName)
{
	if(hasAtom(atomName)) {
		atoms[atomName].setParent(this);}

	return atoms[atomName];
}

void Residue::removeAtom(string atomName)
{
	atoms.erase(atomName);
}

bool Residue::hasAtom(string atomName)
{
	return atoms.count(atomName);
}

int Residue::getNumber() const
{
	return number;
}

string Residue::getType() const
{
	return type;
}

map<int, Atom> Residue::getAtoms()
{ 
	map<int, Atom> mapToReturn;
	
	for (map<string, Atom>::const_iterator it=atoms.begin(); it!=atoms.end(); ++it) {
		Atom atom = it->second;
		//atom.setParent(this);
		mapToReturn[atom.getNumber()] = atom;
	}
	
	return mapToReturn;
}

void Residue::setParent(Chain *par)
{
	parent = par;
}

Chain *Residue::getParent()
{
	return parent;
}

int Residue::checkAtomsNumbers(int atomNumber)
{
	for (map<string, Atom>::iterator it=atoms.begin(); it!=atoms.end(); ++it )
	{
		it->second.setNumber(atomNumber++);
	}
	return atomNumber;
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


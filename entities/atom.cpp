#include "atom.hpp"

using namespace std;

int Atom::nAtoms = 0;

Atom::Atom() : Entity(), m_parent(0)
{
	nAtoms++;
}

Atom::Atom(int number, string name, string type) : Entity(number, type, name), m_parent(0)
{
	nAtoms++;
}

Atom::Atom(int number, string name, string type, Vector3d coordinates) : Entity(number, type, name)
{
	addCoordinates(coordinates);
	nAtoms++;
}

Atom::~Atom()
{
	nAtoms--;
}

void Atom::addCoordinates(Vector3d coord)
{
	m_childs.push_back(coord);
}

vector<Vector3d>& Atom::getCoordinates()
{
	return m_childs;
}

Residue *Atom::getParent()
{
	return m_parent;
}

void Atom::setParent(Residue *parent)
{
	m_parent = parent;
}

int Atom::getNAtoms()
{
	return nAtoms;
}

ostream &operator<< ( ostream &out, Atom const& atom )
{
	out << "<atom number=" << atom.m_number;
	out << " name=" << atom.m_number;
	out << " type=" << atom.m_type;
	out << " numberOfFrames=" << atom.m_childs.size() << " >" ;
    return out ;
}

bool operator< (Atom const& atom1, Atom const& atom2)
{
	return atom1.m_number<atom2.m_number;
}

bool operator> (Atom const& atom1, Atom const& atom2)
{
	return atom1.m_number>atom2.m_number;
}

#include "residue.hpp"

using namespace std;

int Residue::nResidues = 0;

Residue::Residue(int number, string type) : Entity(number, type, ""), m_parent(0)
{
	nResidues++;
}

Residue::Residue() : Entity(), m_parent(0)
{
	nResidues++;
}

Residue::~Residue()
{
	nResidues--;
}

bool Residue::hasAtom(std::string name)
{
	return m_atoms.count(name);
}

Atom& Residue::getAtom(std::string name)
{
	if(hasAtom(name))
	{
		m_atoms[name].setParent(this);
		return m_atoms[name];
	}
	else
	{
		cout << "ERROR: residue " << this << "doesn't have atom named <" << name << "> to return!!!" << endl;
	}
	return m_atoms[name]; // TODO : lancer une exeption pour remplacer ca
}

void Residue::removeAtom(std::string name)
{
	if(hasAtom(name))
	{
		m_atoms.erase(name);
	}
	else
	{
		cout << "WARNING: residue " << this << "doesn't have atom named <" << name << "> to remove!!!" << endl;
	}
}

void Residue::addAtom(Atom atom)
{
	m_atoms[atom.getName()] = atom;
}

vector<Atom> Residue::getAtoms()
{
	vector<Atom> vecToReturn;
	for (map<string, Atom>::iterator it=m_atoms.begin(); it!=m_atoms.end(); ++it)
	{
		it->second.setParent(this);
		vecToReturn.push_back(it->second);
	}

	return vecToReturn;
}

Chain *Residue::getParent()
{
	return m_parent;
}

void Residue::setParent(Chain *parent)
{
	m_parent = parent;
}

int Residue::checkAtomsNumbers(int atomNumber)
{
	for (map<string, Atom>::iterator it=m_atoms.begin(); it!=m_atoms.end(); ++it )
	{
		it->second.setNumber(atomNumber++);
	}
	return atomNumber;
}

void Residue::printResidue(ostream& out) const
{
	out << "<residueNumber=" << m_number<< " residueType=" <<  m_type << " atomsCount="<< m_atoms.size()  << "   ";
    for (map<string, Atom>::const_iterator it=m_atoms.begin(); it!=m_atoms.end(); ++it) {
		out << it->second << " ";
	}

	out << ">" ;
}

int Residue::getNResidues()
{
	return nResidues;
}

ostream &operator<<( ostream &out, Residue const& residue )
{
	residue.printResidue(out);
	return out ;
}

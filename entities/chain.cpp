#include <iostream>

#include "chain.hpp" 

using namespace std;

Chain::Chain() : Entity(), m_parent(0)
{

}

Chain::Chain(string name) : Entity(0, "", name), m_parent(0)
{

}

bool Chain::hasResidue(int number)
{
	return m_residues.count(number);
}

Residue& Chain::getResidue(int number)
{
	if(hasResidue(number))
	{
		m_residues[number].setParent(this);
		return m_residues[number];
	}
	else
	{
		cout << "ERROR: residue " << this << "doesn't have residue number <" << number << "> ro return!!!" << endl;
	}
	return m_residues[number]; // TODO : lancer une exeption pour remplacer ca
}

void Chain::removeResidue(int number)
{
	if(hasResidue(number))
	{
		m_residues.erase(number);
	}
	else
	{
		cout << "WARNING: residue " << this << "doesn't have residue number <" << number << "> ro remove!!!" << endl;
	}
}

void Chain::addResidue(Residue residue)
{
	m_residues[residue.getNumber()] = residue;
}

vector<Residue> Chain::getResidues()
{
	vector<Residue> vecToReturn;
	for (map<int, Residue>::iterator it=m_residues.begin(); it!=m_residues.end(); ++it)
	{
		vecToReturn.push_back(it->second);
	}

	return vecToReturn;
}

vector<Atom> Chain::getAtoms()
{
	vector<Atom> vecToReturn;
	for (map<int, Residue>::iterator it=m_residues.begin(); it!=m_residues.end(); ++it)
	{
		vector<Atom> vecTmp(it->second.getAtoms());
		vecToReturn.insert(vecToReturn.end(), vecTmp.begin(), vecTmp.end());
	}
	return vecToReturn;
}

Molecule *Chain::get_parent()
{
	return m_parent;
}

void Chain::setParent(Molecule *parent)
{
	m_parent = parent;
}

void Chain::printChain(ostream& out) const
{
	out << "<chain identifier=" << m_name << " residuesCount="<< m_residues.size()  << "   ";
    for (map<int, Residue>::const_iterator it=m_residues.begin(); it!=m_residues.end(); ++it) {
		out << it->second << " ";
	}

	 out << ">" ;
}

string Chain::getSequence()
{
	vector<int> residueNumbers;
	for( map<int, Residue>::iterator it=m_residues.begin(); it!=m_residues.end(); ++it)
	{
		residueNumbers.push_back(it->first);
	}

	sort(residueNumbers.begin(), residueNumbers.end());

	string sequence;
	for( vector<int>::iterator it=residueNumbers.begin(); it!=residueNumbers.end(); ++it)
	{
		sequence += m_residues[*it].getType();
	}

	return sequence;
}

void Chain::checkType()
{
	string sequence = getSequence();
	size_t nU = std::count(sequence.begin(), sequence.end(), 'U');
	size_t nC = std::count(sequence.begin(), sequence.end(), 'C');
	size_t nT = std::count(sequence.begin(), sequence.end(), 'T');
	size_t nA = std::count(sequence.begin(), sequence.end(), 'A');
	size_t nG = std::count(sequence.begin(), sequence.end(), 'G');

	if(sequence.size() == nA+nC+nT+nG) {
		m_type = "DNA";
	} else if(sequence.size() == nA+nC+nU+nG) {
		m_type = "RNA";
	} else {
		m_type = "UNDEFINED";
		cout << "ERROR: Cannot determine chain type for sequence :" << endl;
		cout << sequence << endl << this << endl;
	}
}

ostream &operator<<( ostream &out, Chain const& chain )
{
	chain.printChain(out);
	return out ;
}

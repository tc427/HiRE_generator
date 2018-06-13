#include <iostream>

#include "chain.hpp" 

using namespace std;

int Chain::nChains = 0;

Chain::Chain() : Entity(), m_parent(0)
{
	nChains++;
}

Chain::Chain(string name) : Entity(0, "", name), m_parent(0)
{
	nChains++;
}

Chain::~Chain()
{
	nChains--;
}

bool Chain::hasResidue(int number)
{
	return m_residues.count(number)!=0;
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
		it->second.setParent(this);
		vecToReturn.push_back(it->second);
	}

	sort(vecToReturn.begin(), vecToReturn.end());

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

int Chain::getIntType()
{
	string sequence = getSequence();
	size_t nU = std::count(sequence.begin(), sequence.end(), 'U');
	size_t nC = std::count(sequence.begin(), sequence.end(), 'C');
	size_t nT = std::count(sequence.begin(), sequence.end(), 'T');
	size_t nA = std::count(sequence.begin(), sequence.end(), 'A');
	size_t nG = std::count(sequence.begin(), sequence.end(), 'G');
	size_t nD = std::count(sequence.begin(), sequence.end(), 'D');

	cout << "getIntType" << endl;
	cout << sequence << endl;
	cout << nU << nC << nT << nA << nG << nD << endl;
	if(sequence.size()-nD == nA+nC+nT+nG) {
		return Chain::DNA;
	} else if(sequence.size()-nD == nA+nC+nU+nG) {
		return Chain::RNA;
	} else {
		cout << "ERROR: Cannot determine chain type for sequence :" << endl;
		cout << sequence << endl << this << endl;
		return Chain::UNKNOWN;
	}
}

int Chain::checkAtomsNumbers(int atomNumber)
{
	for (map<int, Residue>::iterator it=m_residues.begin(); it!=m_residues.end(); ++it )
	{
		atomNumber = it->second.checkAtomsNumbers(atomNumber);
	}
	return atomNumber;
}

int Chain::getNChains()
{
	return nChains;
}

ostream &operator<<( ostream &out, Chain const& chain )
{
	chain.printChain(out);
	return out ;
}

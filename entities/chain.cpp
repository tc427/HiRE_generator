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

vector<string> Chain::getSequence()
{
	vector<int> residueNumbers;
	for( map<int, Residue>::iterator it=m_residues.begin(); it!=m_residues.end(); ++it)
	{
		residueNumbers.push_back(it->first);
	}

	sort(residueNumbers.begin(), residueNumbers.end());

	vector<string> sequence;
	for( vector<int>::iterator it=residueNumbers.begin(); it!=residueNumbers.end(); ++it)
	{
		sequence.push_back(m_residues[*it].getType());
	}

	return sequence;
}

int Chain::getIntType()
{
	// map residue type (string) to count
	map<std::string, unsigned int> rc;
	vector<string> sequence = getSequence();
	for(auto rseq: sequence)
	{
		rc[rseq] += 1;
	}


	if(sequence.size() == rc["MG"]) {
	    return Chain::IONS;
	} else if(sequence.size()-rc["D"] == rc["DA"]+rc["DC"]+rc["DT"]+rc["DG"]) {
		return Chain::DNA;
	} else if(sequence.size()-rc["D"] == rc["A"]+rc["C"]+rc["U"]+rc["G"]) {
		return Chain::RNA;
	} else if(sequence.size()-rc["D"] == rc["A"]+rc["C"]+rc["T"]+rc["G"]) {
		return Chain::DNA;
	} else {
		cout << "ERROR: Cannot determine chain type for sequence :" << endl;
		for( auto& si: sequence)
		{
			cout << si;
		}
		cout << endl;
		cout << "seq length: " << sequence.size() << endl;
		cout << "# DNA residues: " << rc["DA"]+rc["DC"]+rc["DT"]+rc["DG"] << endl;
		cout << "# RNA residues: " << rc["A"]+rc["C"]+rc["U"]+rc["G"] << endl;
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

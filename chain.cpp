#include <iostream>

#include "chain.hpp" 

using namespace std;

Chain::Chain()
{

}

Chain::Chain(string identifer) : identifer(identifer)
{
	
}

void Chain::addResidue(Residue residue)
{
	residues[residue.getNumber()] = residue;
}

Residue& Chain::getResidue(int residueNumber)
{
	return residues[residueNumber];
}

bool Chain::hasResidue(int residueNumber)
{
	return residues.count(residueNumber);
}

string Chain::getIdentifer()
{
	return identifer;
}

std::map<int, Residue>& Chain::getResidues()
{
	return residues;
}

void Chain::printChain(ostream& out) const
{
	out << "<chain indentifer=" << identifer << " residuesCount="<< residues.size()  << "   ";
    for (map<int, Residue>::const_iterator it=residues.begin(); it!=residues.end(); ++it) {
		out << it->second << " ";
	}

	 out << ">" ;
}

ostream &operator<<( ostream &out, Chain const& chain )
{
	chain.printChain(out);
	return out ;
}

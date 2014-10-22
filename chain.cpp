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
	residue.setParent( this );
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

map<int, Residue>& Chain::getResidues()
{
	return residues;
}

void Chain::setParent(Molecule *parent)
{
	parent = parent;
}

map<int, Atom> Chain::getAtoms() 
{
	map<int, Atom> mapToReturn;
	
	for (map<int, Residue>::iterator it=residues.begin(); it!=residues.end(); ++it)
	{
		map<int, Atom> mapTemp = it->second.getAtoms();
		
		for (map<int, Atom>::const_iterator it=mapTemp.begin(); it!=mapTemp.end(); ++it)
		{ 
			if(mapToReturn.count(it->first))
			{
				cout << "ERROR: Atom number " << it->first << " exist twice in molecule !!" << endl ;
			}
			else
			{
				mapToReturn[it->first] = it->second;
			}
		}
	}
	
	return mapToReturn;
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

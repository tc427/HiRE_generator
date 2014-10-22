#include "molecule.hpp"

using namespace std;

Molecule::Molecule()
{
	
}

bool Molecule::hasChain(std::string chainIdentifer)
{
	return chains.count(chainIdentifer);
}

Chain& Molecule::getChain(std::string chainIdentifer)
{	
	chains[chainIdentifer].setParent(this);
	return chains[chainIdentifer];
}

void Molecule::addChain(Chain chain)
{
	chain.setParent( this );
	chains[chain.getIdentifer()]=chain;
}

int Molecule::countChains()
{
	return chains.size();
}

map<std::string, Chain>& Molecule::getChains()
{
	return chains;
}

map<int, Atom> Molecule::getAtoms()
{
	map<int, Atom> mapToReturn;
	
	for (map<string, Chain>::iterator it=chains.begin(); it!=chains.end(); ++it)
	{
		map<int, Atom> mapTemp(it->second.getAtoms());
		
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

void Molecule::printMolecule(ostream& out) const
{
	out << "\n\n<molecule chainsCount=" << chains.size() << "   ";
	for (map<string, Chain>::const_iterator it=chains.begin(); it!=chains.end(); ++it) {
		out << it->second << " ";
	}

	 out << ">" ;
}

ostream &operator<<( ostream &out, Molecule const& molecule )
{
	molecule.printMolecule(out);
    return out ;
}

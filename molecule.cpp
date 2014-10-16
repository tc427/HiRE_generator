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
	return chains[chainIdentifer];
}

void Molecule::addChain(Chain chain)
{
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

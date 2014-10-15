#include "molecule.hpp"

using namespace std;

Molecule::Molecule()
{
	
}

bool Molecule::hasChain(std::string chainIdentifer)
{
	return chains.count(chainIdentifer);
}

Chain Molecule::getChain(std::string chainIdentifer)
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

ostream &operator<<( ostream &out, Molecule const& molecule )
{
	out << "<molecule chainsCount=" << molecule.chains.size() << ">" ;
    return out ;
}

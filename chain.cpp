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

Residue Chain::getResidue(int residueNumber)
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

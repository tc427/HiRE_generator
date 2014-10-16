#include <iostream>

#include "molecule.hpp"
#include "pdbParser.hpp"

using namespace std;

int main()
{
	
	Molecule molecule = pdbParser::getMoleculeFromPdb("test.pdb");
	
	return 0;
}



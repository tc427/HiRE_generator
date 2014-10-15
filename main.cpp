#include <iostream>

#include "molecule.hpp"

using namespace std;

int main()
{
	cout << "hello world" << endl;
	
	Molecule molecule;
	
	molecule.addChain(Chain("A"));
	
	molecule.getChain("A").addResidue(Residue(1, "T"));
	
	molecule.getChain("A").getResidue(1).addAtom(Atom(1, "CA", "C"));
	
	
	cout << molecule << endl;
	
	return 0;
}


// molecule
// chain chain_lettre
// residue residue_type, residue_number
// atom

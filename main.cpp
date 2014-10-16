#include <iostream>

#include "molecule.hpp"
#include "pdbParser.hpp"
#include "vector.hpp"
#include "geometry.hpp"

using namespace std;

int main()
{
	
	Molecule molecule = pdbParser::getMoleculeFromPdb("test.pdb");

	for (map<string, Chain>::const_iterator it=molecule.getChains().begin(); it!=molecule.getChains().end(); ++it) {
		Chain chain = it->second;
		for (map<int, Residue>::const_iterator it2=chain.getResidues().begin(); it2!=chain.getResidues().end(); ++it2) {
			Residue residue = it2->second;
			if(residue.getType() == "A")
			{
				if(residue.hasAtom("CA") and
				   residue.hasAtom("CY") and
				   residue.hasAtom("A1") and
				   residue.hasAtom("A2") )
				{
					cout << "A" << residue.getNumber() << " : " 
						 << dihedral(residue.getAtom("CA").getCoordinates() ,
									 residue.getAtom("CY").getCoordinates() ,
									 residue.getAtom("A1").getCoordinates() ,
									 residue.getAtom("A2").getCoordinates() ) << endl;					
				}
			}
			else if (residue.getType() == "G")
			{
				
				if(residue.hasAtom("CA") and
				   residue.hasAtom("CY") and
				   residue.hasAtom("G1") and
				   residue.hasAtom("G2") )
				{
					cout << "G" << residue.getNumber() << " : " 
						 << dihedral(residue.getAtom("CA").getCoordinates() ,
									 residue.getAtom("CY").getCoordinates() ,
									 residue.getAtom("G1").getCoordinates() ,
									 residue.getAtom("G2").getCoordinates() ) << endl;					
				}
			}
		}
	}
	

	return 0;
}




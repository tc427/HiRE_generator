#include <iostream>
#include <vector>

#include "molecule.hpp"
#include "pdbParser.hpp"
#include "xtcParser.hpp"
#include "vector3d.hpp"
#include "geometry.hpp"
#include "stats.hpp"
#include "analysis.hpp"




using namespace std;


int main(int argc, char ** argv)
{
	//trjconv -f min.xtc -o traj.pdb -s conf_initiale_RNA.pdb
	
	Molecule molecule = pdbParser::getMoleculeFromPdb(argv[1]);
	Analysis analysis(molecule);
	analysis.plotAntiSyn();

	

	return 0;
}

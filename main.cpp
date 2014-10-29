#include <iostream>
#include <vector>

#include "entities/molecule.hpp"
#include "inout/pdbParser.hpp"
#include "inout/pdbWriter.hpp"
#include "inout/xtcParser.hpp"
#include "geometry/vector3d.hpp"
#include "geometry/geometry.hpp"
#include "mathematics/stats.hpp"
#include "geometry/analysis.hpp"
#include "fa2cg.hpp"
#include "param/fa2cgParam.hpp"

using namespace std;


int main(int argc, char ** argv)
{

	//trjconv -f min.xtc -o traj.pdb -s conf_initiale_RNA.pdb

	Molecule molecule = pdbParser::getMoleculeFromPdb(argv[1]);
	//Analysis analysis(molecule);
	//analysis.plotAntiSyn();
	//analysis.plotBasesEcarts();

	Fa2cg::fa2cg(molecule);
	PdbWriter::write("test.pdb", molecule);

	return 0;
}

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
#include "inout/opepInputParamWriter.h"

using namespace std;


int main(int argc, char ** argv)
{

	//trjconv -f min.xtc -o traj.pdb -s conf_initiale_RNA.pdb
	//string fileName = argv[1];

	//Molecule molecule = pdbParser::getMoleculeFromPdb(fileName);
	//PdbWriter::write("test.pdb", molecule);
	//Analysis analysis(molecule);
	//analysis.plotAntiSyn();
	//analysis.plotBasesEcarts();

	//string name = fileName.substr (0, fileName.size()-4);

	//Fa2cg fa = Fa2cg();
	//Molecule faMolecule = fa.fa2cg(molecule);
	//PdbWriter::write(name+"_CG.pdb", faMolecule);
	//PdbWriter::write("conf_initiale_RNA.pdb", faMolecule);
	//OpepInputParamWriter opepInputParamWriter(faMolecule);

	//opepInputParamWriter.write(name+".top");
	//PdbWriter::write("test.pdb", molecule);


	string fileName = argv[1];

	Molecule molecule = pdbParser::getMoleculeFromPdb(fileName);
	PdbWriter::write("test.pdb", molecule);
	Analysis analysis(molecule);
	analysis.plotStrongStopDist();


	return 0;
}

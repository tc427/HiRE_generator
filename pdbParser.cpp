#include "pdbParser.hpp" 

using namespace std;
using namespace boost;

pdbParser::pdbParser()
{
	
}

Molecule pdbParser::getMoleculeFromPdb(string path)
{

	ifstream file(path.c_str(), ios::in);  // on ouvre le file en lecture
	Molecule molecule;

	if(file)  // si l'ouverture a réussi
	{    
		molecule = parsePdb(file);
		file.close();  // on ferme le file
	}
	else  // sinon
	{
		cerr << "Impossible d'ouvrir le file !" << endl;
	}
	
	return molecule;
}


bool pdbParser::checkAtomLine(string line)
{
	if(line.length()>4) {
		if(line.substr(0,4) == "ATOM") {
			return true; } }
	return false;
}

bool pdbParser::checkAtomModel(string line)
{
	if(line.length()>5) {
		if(line.substr(0,5) == "MODEL") {
			return true; } }
	return false;
}

Molecule pdbParser::parsePdb(ifstream& pdbFile)
{
	string line;
	Molecule molecule;
	
	int count(0);
	
	while(getline(pdbFile, line))  // tant que l'on peut mettre la line dans "contenu"
	{
		if(checkAtomModel(line))
		{
			//cout << "lecture frame : " << count << "\r";
			count++;
		}
		if(checkAtomLine(line))
		{
			string sChain = line.substr(21,1);
			string sResidueNumber = line.substr(22,4);
			string atomName = line.substr(12,4);
			trim(sChain);
			trim(sResidueNumber);
			trim(atomName);
			
			int residueNumber = lexical_cast<int>(sResidueNumber);
			
			if(!molecule.hasChain(sChain))
			{
				molecule.addChain(Chain(sChain));
			}
			
			if(!molecule.getChain(sChain).hasResidue(residueNumber))
			{
				string sResidueType = line.substr(17,3);
				trim(sResidueType);
				molecule.getChain(sChain).addResidue(Residue(residueNumber,sResidueType));
			}
			if(!molecule.getChain(sChain).getResidue(residueNumber).hasAtom(atomName))
			{
				string sAtomNumber = line.substr(6,5);
				string atomType = line.substr(76,2);
				
				trim(atomType);
				trim(sAtomNumber);
				
				molecule.getChain(sChain).getResidue(residueNumber).addAtom(Atom(lexical_cast<int>(sAtomNumber), atomName, atomType ));
				
			}
			string sX = line.substr(30,8);
			string sY = line.substr(38,8);
			string sZ = line.substr(46,8);
		
			trim(sX);
			trim(sY);
			trim(sZ);
		
			molecule.getChain(sChain).getResidue(residueNumber).getAtom(atomName).addCoordinates(Vector3d(lexical_cast<float>(sX), lexical_cast<float>(sY), lexical_cast<float>(sZ)));
		}
	}

	return molecule;
}

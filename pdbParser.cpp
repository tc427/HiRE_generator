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

Atom pdbParser::getAtomFromLine(std::string line)
{
	string sNumber = line.substr(6,5);
	string name = line.substr(12,4);
	string type = line.substr(76,2);
	string sX = line.substr(30,8);
	string sY = line.substr(38,8);
	string sZ = line.substr(46,8);
	
	trim(name);
	trim(type);
	trim(sNumber);
	trim(sX);
	trim(sY);
	trim(sZ);
		
	return Atom(lexical_cast<int>(sNumber), name, type, Vector(lexical_cast<float>(sX), lexical_cast<float>(sY), lexical_cast<float>(sZ)) );
}

Molecule pdbParser::parsePdb(ifstream& pdbFile)
{
	Molecule molecule;
	
	string line;
	while(getline(pdbFile, line))  // tant que l'on peut mettre la line dans "contenu"
	{
		if(checkAtomLine(line))
		{
			string sChain = line.substr(21,1);
			string sResidueNumber = line.substr(22,4);
			trim(sChain);
			trim(sResidueNumber);
			
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
			molecule.getChain(sChain).getResidue(residueNumber).addAtom(getAtomFromLine(line));
		}
	}
	
	return molecule;
}

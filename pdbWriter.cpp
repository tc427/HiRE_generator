#include "pdbWriter.hpp"

using namespace std;

PdbWriter::PdbWriter()
{
	
}

void PdbWriter::write(std::string filename, Molecule molecule)
{
	

	FILE* fileOut = fopen (filename.c_str(), "w");

	if (fileOut == NULL)
		cout << "Impossible d'ouvrir le fichier " + filename + " en écriture !" << endl;
	else
	{
	  
		map<int, Atom> atoms = molecule.getAtoms();
		vector<int> atomNumbers ;
		
		for (map<int, Atom>::const_iterator it=atoms.begin(); it!=atoms.end(); ++it)
		{
			atomNumbers.push_back(it->first);
		}
		
		sort(atomNumbers.begin(), atomNumbers.end());
		
		for (std::vector<int>::iterator it=atomNumbers.begin(); it!=atomNumbers.end(); ++it)
		{
			Atom atom = atoms[*it];
			Residue *residue = atom.getParent();
			//cout << atom << residue->getNumber() << endl;
			Chain *chain = residue->getParent();
			
			fprintf (fileOut, "ATOM  %5d %4s %3s %1s%4d    %8.3f%8.3f%8.3f%6.2f%6.2f          %2s%2s\n",
							   atom.getNumber(), atom.getName().c_str(), residue->getType().c_str(),
							   chain->getIdentifer().c_str(), residue->getNumber(),
							   atom.getCoordinates()[0].getX(), atom.getCoordinates()[0].getY(),
							   atom.getCoordinates()[0].getZ(), 1.0, 0.0, atom.getType().c_str(), "0");
		}
		
	//    
		fclose (fileOut);
	}
}


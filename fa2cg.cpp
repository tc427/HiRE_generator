#include "fa2cg.hpp"

using namespace std;

Fa2cg::Fa2cg()
{

}

void Fa2cg::fa2cg(Molecule &molecule)
{
	vector<Residue> residues = molecule.getResidues();
	for (vector<Residue>::iterator iTresidue=residues.begin(); iTresidue!=residues.end(); ++iTresidue)
	{
		Residue residue = molecule.getChain(iTresidue->getParent()->getName())
								  .getResidue(iTresidue->getNumber());
		normaliseResidue(residue);
		transformResidue(residue);
	}
	molecule.checkAtomsNumbers();
}

void Fa2cg::transformResidue(Residue &residue)
{

	vector<string> listToKeep;

	// main chain
	map<string, string > elementFa2cg = Fa2cgParam::getFa2cg();
	for (map<string, string>::iterator it=elementFa2cg.begin(); it!=elementFa2cg.end(); ++it)
	{
		if(residue.hasAtom(it->first))
		{
			residue.getAtom(it->first).setName(it->second);
		}
		listToKeep.push_back(it->second);
	}

	// side chain
	map<vector<string>, string > cyclesFa2cg = Fa2cgParam::getFa2cgCycles(residue.getType());
	for (map<vector<string>, string >::iterator it=cyclesFa2cg.begin(); it!=cyclesFa2cg.end(); ++it)
	{
		vector<Atom> listAtoms;
		vector<string> listAtomNames(it->first);

		for (vector<string>::iterator it2=listAtomNames.begin(); it2!=listAtomNames.end(); ++it2 )
		{
			if(residue.hasAtom(*it2))
			{
				listAtoms.push_back(residue.getAtom(*it2));
			}
			else
			{
				cout << "ERROR : atom " << *it2 << " not found in residu number " << residue.getNumber() << endl;
			}
		}
		residue.addAtom(Atom(0, it->second, "C", getCoordFromAtomVector(listAtoms)));
		listToKeep.push_back(it->second);
	}

	// remove useless atoms
	vector<Atom> listAtoms = residue.getAtoms();
	for (vector<Atom>::iterator itAtom=listAtoms.begin(); itAtom!=listAtoms.end(); ++itAtom)
	{
		if(find(listToKeep.begin(), listToKeep.end(), itAtom->getName())==listToKeep.end())
		{
			residue.removeAtom(itAtom->getName());
		}
	}

}

void Fa2cg::normaliseResidue(Residue &residue)
{
	map<string, string> normalisationDic = Fa2cgParam::getNormalisation();
	for (map<string, string>::iterator it=normalisationDic.begin(); it!=normalisationDic.end(); ++it)
	{
		if(residue.hasAtom(it->first))
		{
 			residue.getAtom(it->first).setName(it->second);
 			residue.addAtom(residue.getAtom(it->first));
 			residue.removeAtom(it->first);
		}
	}
}

Vector3d Fa2cg::getCoordFromAtomVector(vector<Atom> listAtoms)
{
	float x(0);
	float y(0);
	float z(0);
	float n(0);

	for (vector<Atom>::iterator it=listAtoms.begin(); it!=listAtoms.end(); ++it)
	{
		float mass = Fa2cgParam::getMass(it->getType());
		Vector3d coordinates = it->getCoordinates()[0];
		x += mass * coordinates.getX();
		y += mass * coordinates.getY();
		z += mass * coordinates.getZ();
		n += mass;
	}

	return Vector3d(x/n, y/n, z/n);
}

#include "molecule.hpp"

using namespace std;

Molecule::Molecule() : Entity()
{
	
}

Molecule::~Molecule()
{

}

bool Molecule::hasChain(std::string name)
{
	return m_chains.count(name);
}

Chain& Molecule::getChain(std::string name)
{
	if(hasChain(name))
	{
		m_chains[name].setParent(this);
		return m_chains[name];
	}
	else
	{
		cout << "ERROR: residue " << this << "doesn't have chain named <" << name << "> to return!!!" << endl;
	}
	return m_chains[name]; // TODO : lancer une exeption pour remplacer ca
}

void Molecule::removeChain(std::string name)
{
	if(hasChain(name))
	{
		m_chains.erase(name);
	}
	else
	{
		cout << "WARNING: residue " << this << "doesn't have chain named <" << name << "> to remove!!!" << endl;
	}
}

void Molecule::addChain(Chain chain)
{
	m_chains[chain.getName()] = chain;
}

vector<Chain> Molecule::getChains()
{
	vector<Chain> vecToReturn;
	for (map<string, Chain>::iterator it=m_chains.begin(); it!=m_chains.end(); ++it)
	{
		it->second.setParent(this);
		vecToReturn.push_back(it->second);
	}
	return vecToReturn;
}

vector<Residue> Molecule::getResidues()
{
	vector<Residue> vecToReturn;
	for (map<string, Chain>::iterator it=m_chains.begin(); it!=m_chains.end(); ++it)
	{
		vector<Residue> vecTmp(it->second.getResidues());
		vecToReturn.insert(vecToReturn.end(), vecTmp.begin(), vecTmp.end());
	}
	return vecToReturn;
}

vector<Atom> Molecule::getAtoms()
{
	vector<Atom> vecToReturn;
	for (map<string, Chain>::iterator it=m_chains.begin(); it!=m_chains.end(); ++it)
	{
		vector<Atom> vecTmp(it->second.getAtoms());
		vecToReturn.insert(vecToReturn.end(), vecTmp.begin(), vecTmp.end());
	}

	sort(vecToReturn.begin(), vecToReturn.end());

	return vecToReturn;
}

void Molecule::checkAtomsNumbers()
{
	int atomNumber = 0;

	for (map<string, Chain>::iterator it=m_chains.begin(); it!=m_chains.end(); ++it )
	{
		atomNumber = it->second.checkAtomsNumbers(atomNumber);
	}
}

int Molecule::getIntChainsType()
{
	vector<int> vec;
	int mini(15);
	int maxi(-5);
	int n;

	for(map<string, Chain>::iterator it=m_chains.begin(); it!=m_chains.end(); ++it)
	{
		n = it->second.getIntType();
		if(n<mini) {
			mini = n;}
		if(n>maxi) {
			maxi = n;}
	}

	if(mini == maxi) {
		return mini;
	} else {
		return -1; }
}

MOLECULE_TYPE Molecule::getMoleculeType()
{
	unsigned int nA(0);
	unsigned int nC(0);
	unsigned int nT(0);
	unsigned int nG(0);
	unsigned int nU(0);

	for(auto residue: getResidues())
	{
		if(residue.getType() == "A") {
			nA++;
		} else if(residue.getType() == "C") {
			nC++;
		} else if(residue.getType() == "T") {
			nT++;
		} else if(residue.getType() == "G") {
			nG++;
		} else if(residue.getType() == "U") {
			nU++;
		} else {
			return MOLECULE_TYPE::UNKNOWN;
		}
	}

	if(nA+nC+nT+nG == getResidues().size()) {
		return MOLECULE_TYPE::DNA;
	} else if (nA+nC+nG+nU  == getResidues().size() ){
		return MOLECULE_TYPE::RNA;
	} else {
		return MOLECULE_TYPE::UNKNOWN;
	}
}

/*void Molecule::checkType()
{
	bool isCG = false;
	bool ifFA = false;

	vector<Residue> residues = getResidues();

	for(vector<Residue>::iterator residue=residues.begin(); residue!=residues.end(); ++residue)
	{

	}
}*/

void Molecule::printMolecule(ostream& out) const
{
	out << "\n\n<molecule chainsCount=" << m_chains.size() << "   ";
	for (map<string, Chain>::const_iterator it=m_chains.begin(); it!=m_chains.end(); ++it) {
		out << it->second << " ";
	}

	 out << ">" ;
}

ostream &operator<<( ostream &out, Molecule const& molecule )
{
	molecule.printMolecule(out);
    return out ;
}

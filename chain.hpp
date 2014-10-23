#pragma once

#include <map>
#include <string>

#include "residue.hpp"
#include "atom.hpp"

class Residue;
class Molecule;

class Chain
{
	public:
		Chain();
		Chain(std::string identifer);	
		void addResidue(Residue residue);
		Residue& getResidue(int residueNumber);
		bool hasResidue(int residueNumber);
		std::string getIdentifer() const;
		std::map<int, Residue>& getResidues();
		std::map<int, Atom> getAtoms();
		void printChain(std::ostream& out) const;
		void setParent(Molecule *parent);
		Molecule *getParent();

		int checkAtomsNumbers(int atomNumber);
		
	private:
		std::map<int, Residue> residues;
		std::string identifer;
		Molecule* parent;
		
	friend std::ostream& operator<< (std::ostream& flux, Chain const& chain);
};

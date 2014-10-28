#pragma once

#include <map>
#include <string>
#include <algorithm>
#include <vector>

#include "residue.hpp"
#include "atom.hpp"
#include "entity.h"

class Residue;
class Molecule;

class Chain : public Entity
{
	public:
		Chain();
		Chain(std::string name);

		bool hasResidue(int number);
		Residue& getResidue(int number);
		void removeResidue(int number);
		void addResidue(Residue residue);

		std::vector<Residue> getResidues();
		std::vector<Atom> getAtoms();

		Molecule *get_parent();
		void setParent(Molecule *parent);

		int checkAtomsNumbers(int atomNumber);
		std::string getSequence();
		void checkType();
		void printChain(std::ostream& out) const;

	private:
		std::map<int, Residue> m_residues;
		Molecule *m_parent;
		

	friend std::ostream& operator<< (std::ostream& flux, Chain const& chain);
};

#pragma once

#include <string>
#include <map>

#include "atom.hpp"
#include "entity.h"

class Atom;
class Chain;

class Residue : public Entity
{

	public:
		Residue();
		Residue(int number, std::string type);

		bool hasAtom(std::string name);
		Atom& getAtom(std::string name);
		void removeAtom(std::string name);
		void addAtom(Atom atom);

		std::vector<Atom> getAtoms();

		Chain* getParent();
		void setParent(Chain *parent);

		void printResidue(std::ostream& out) const;
		int checkAtomsNumbers(int atomNumber);

	private:
		std::map<std::string, Atom> m_atoms;
		Chain *m_parent;

	friend std::ostream& operator<< (std::ostream& flux, Residue const& residue);
};

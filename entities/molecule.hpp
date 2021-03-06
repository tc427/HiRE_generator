#pragma once

#include <string>
#include <map>
#include <iostream>
#include <algorithm>

#include "chain.hpp"
#include "residue.hpp"
#include "atom.hpp"
#include "entity.h"


enum class MOLECULE_TYPE {RNA, DNA, PROTEIN, IONS, UNKNOWN};

class Molecule : public Entity
{

	public:
		Molecule();
		~Molecule();
		
		void printMolecule(std::ostream& out) const;
		void checkAtomsNumbers();

		bool hasChain(std::string name);
		Chain& getChain(std::string name);
		void removeChain(std::string name);
		void addChain(Chain chain);

		std::vector<Chain> getChains();
		std::vector<Residue> getResidues();
		std::vector<Atom> getAtoms();

		MOLECULE_TYPE getMoleculeType();

		int getIntChainsType();

		enum GRAIN_TYPE {CG, FA};
		enum MOLECULE_TYPE_OLD {RNA, DNA, PROTEIN, UNKNOWN};

	private:
		std::map<std::string, Chain> m_chains;
		
	friend std::ostream& operator<< (std::ostream& flux, Molecule const& molecule);
};

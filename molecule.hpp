#pragma once

#include <string>
#include <map>
#include <iostream>

#include "chain.hpp"
#include "residue.hpp"
#include "atom.hpp"

class Molecule
{

	public:
		Molecule();
		bool hasChain(std::string chainIdentifer);
		Chain& getChain(std::string chainIdentifer);
		void addChain(Chain chain);
		int countChains();
		std::map<std::string, Chain>& getChains();
		
		void printMolecule(std::ostream& out) const;
		
	private:
		std::map<std::string, Chain> chains;
		
	friend std::ostream& operator<< (std::ostream& flux, Molecule const& molecule);
};

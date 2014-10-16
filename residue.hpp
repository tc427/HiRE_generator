#pragma once

#include <string>
#include <map>

#include "atom.hpp"

class Residue
{

	public:
		Residue();
		Residue(int number, std::string type);
	
		void addAtom(Atom atom);
		Atom& getAtom(int atomNumber);
		bool hasAtom(int atomNumber);
	
		int getNumber();
		std::string getType();
		
		void printResidue(std::ostream& out) const;
	
	private:
		std::map<int, Atom> atoms;
		int number;
		std::string type;
		
	friend std::ostream& operator<< (std::ostream& flux, Residue const& residue);
};

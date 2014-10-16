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
		Atom& getAtom(std::string atomName);
		bool hasAtom(std::string atomName);
	
		int getNumber();
		std::string getType();
		
		void printResidue(std::ostream& out) const;
	
	private:
		std::map<std::string, Atom> atoms;
		int number;
		std::string type;
		
	friend std::ostream& operator<< (std::ostream& flux, Residue const& residue);
};

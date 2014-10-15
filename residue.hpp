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
		Atom getAtom(int atomNumber);
		bool hasAtom(int atomNumber);
	
		int getNumber();
		std::string getType();
	
	private:
		std::map<int, Atom> atoms;
		int number;
		std::string type;
};

#pragma once

#include <string>
#include <map>

#include "atom.hpp"

class Atom;
class Chain;

class Residue
{

	public:
		Residue();
		Residue(int number, std::string type);
	
		void addAtom(Atom atom);
		Atom& getAtom(std::string atomName);
		std::map<int, Atom> getAtoms(); 
		bool hasAtom(std::string atomName);
	
		int getNumber();
		std::string getType();
		
		void printResidue(std::ostream& out) const;
		void setParent(Chain *parent);
		Chain *getParent();
	
	private:
		std::map<std::string, Atom> atoms;
		int number;
		std::string type;
		Chain* parent;
		
	friend std::ostream& operator<< (std::ostream& flux, Residue const& residue);
};

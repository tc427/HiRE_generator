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
		void removeAtom(std::string atomName);
		std::map<int, Atom> getAtoms(); 
		bool hasAtom(std::string atomName);
	
		int getNumber() const;
		std::string getType() const;
		
		void printResidue(std::ostream& out) const;
		void setParent(Chain *parent);
		Chain *getParent();

		int checkAtomsNumbers(int atomNumber);

	private:
		std::map<std::string, Atom> atoms;
		int number;
		std::string type;
		Chain* parent;
		
	friend std::ostream& operator<< (std::ostream& flux, Residue const& residue);
};

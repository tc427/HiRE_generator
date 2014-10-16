#pragma once

#include <boost/algorithm/string.hpp> // for trim fonction.
#include <boost/lexical_cast.hpp> // for string to int conversion

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <stdlib.h>

#include "atom.hpp"
#include "residue.hpp"
#include "chain.hpp"
#include "molecule.hpp"
#include "vector.hpp"

class pdbParser
{
	public:
		pdbParser();
		static Molecule getMoleculeFromPdb(std::string path);

	private:
		static bool checkAtomLine(std::string line);
		static Atom getAtomFromLine(std::string line);
		static Molecule parsePdb(std::ifstream& pdbFile);
};

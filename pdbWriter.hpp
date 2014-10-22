#pragma once

#include <boost/algorithm/string.hpp> // for trim fonction.
#include <boost/lexical_cast.hpp> // for string to int conversion

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>

#include "atom.hpp"
#include "residue.hpp"
#include "chain.hpp"
#include "molecule.hpp"
#include "vector3d.hpp"

class PdbWriter
{
	public:
		PdbWriter();
		static void write(std::string filename, Molecule molecule);

	private:
		
};

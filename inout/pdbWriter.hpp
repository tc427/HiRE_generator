#pragma once

#include <boost/algorithm/string.hpp> // for trim fonction.
#include <boost/lexical_cast.hpp> // for string to int conversion

#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>

#include "../entities/atom.hpp"
#include "../entities/residue.hpp"
#include "../entities/chain.hpp"
#include "../entities/molecule.hpp"
#include "../geometry/vector3d.hpp"

class PdbWriter
{
	public:
		PdbWriter();
		static void write(std::string filename, Molecule & molecule);

	private:
		
};

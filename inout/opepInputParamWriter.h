#pragma once

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "../entities/molecule.hpp"
#include "../functions.h"
#include "../param/chainParameterManager.h"
#include "../param/chainParameters.h"

class OpepInputParamWriter
{
	public:
		OpepInputParamWriter(Molecule& molecule);
		virtual ~OpepInputParamWriter();
		void write(std::string filename);

	private:
		void printRecap(int nBondsInSystem, int nAnglesInSystem, int nDihedralsInSystem);
		void printAtomsDetails();
		void printResiduesDetails();

		void printBondsDefinitionDetails();
		void printAnglesDefinitionDetails();
		void printDihedresDefinitionDetails();

		void printDetails(vector<int> vector);

		void writeBaselistFile();
		void writeIchainFile();
		void writeCshFile();

		Molecule& m_molecule;
		std::vector<std::string> m_atomTypesInSystem;
		ChainParameters& m_chainParameters;

		ofstream m_topFile;
};


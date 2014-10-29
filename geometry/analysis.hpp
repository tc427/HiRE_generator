#include "../entities/molecule.hpp"
#include "geometry.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Analysis
{
	 
	public:
		Analysis();
		Analysis(Molecule moleculeToAnalyse);
		void plotAntiSyn();
		void plotBasesEcarts();

	 private:
		Molecule moleculeToAnalyse;
		void pythonPlotAntiSyn();
		void pythonPlotBasesEcarts();
		std::vector<int> getClosestBases(Residue residue);
		std::map<std::string, std::string> lastAtom;
	 
};
 

template<typename Type>
void printVector(std::vector< Type > vec, bool first=true);

template<typename Type>
void printVector(std::vector< std::vector<Type> > vec, bool first=true);

template<typename Type1, typename Type2>
void printVector(std::map< Type1 , Type2 > vec, bool first=true);


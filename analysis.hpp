#include "molecule.hpp"
#include "geometry.hpp"

#include <string>
#include <iostream>
#include <vector>

class Analysis
{
	 
	public:
		Analysis();
		Analysis(Molecule moleculeToAnalyse);
		void plotAntiSyn();

	 private:
		Molecule moleculeToAnalyse;
		void printVector(std::vector<float> vec);
		void pythonPlotDic();
	 
};
 
 














 

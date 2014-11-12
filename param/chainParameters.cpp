#include "chainParameters.h"

using namespace std;


ChainParameters::~ChainParameters()
{

}

map<string, string>& ChainParameters::getAtomNamesToAtomType()
{
	return atomNameToAtomType;
}

string ChainParameters::getAtomNameToAtomType(string type)
{
	return atomNameToAtomType[type];
}

string ChainParameters::getAtomTypeToAtomName(string type)
{
	return atomTypeToAtomName[type];
}

map<string, string>& ChainParameters::getAtomTypeToMSE()
{
	return atomTypeToMSE;
}


map<string, int>& ChainParameters::getResidueLetterToResidueNumber()
{
	return residueLetterToResidueNumber;
}


string ChainParameters::getResidueLetterToResidueName(string letter)
{
	return residueLetterToResidueName[letter];
}

map<string, double>& ChainParameters::getWeights()
{
	return weights;
}

double ChainParameters::getWeight(string atomType)
{
	return weights[atomType];
}

vector<BondParam>& ChainParameters::getBonds()
{
	return bonds;
}

vector<AngleParam>& ChainParameters::getAngles()
{
	return angles;
}

vector<DihedralParam>& ChainParameters::getDiedrals()
{
	return diedrals;
}

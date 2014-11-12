#pragma once

#include<string>
#include<map>
#include<vector>
#include<iostream>

#include "structsParam.h"

class ChainParameters
{
	public:
		virtual ~ChainParameters();

		std::map<std::string, std::string>& getAtomNamesToAtomType();
		string getAtomNameToAtomType(std::string name);
		std::string getAtomTypeToAtomName(std::string);
		std::map<std::string, std::string>& getAtomTypeToMSE();
		std::map<std::string, int>& getResidueLetterToResidueNumber();
		std::string getResidueLetterToResidueName(std::string letter);

		std::map<std::string, double>& getWeights();
		double getWeight(std::string atomType);
		std::vector<BondParam>& getBonds();
		std::vector<AngleParam>& getAngles();
		std::vector<DihedralParam>& getDiedrals();

	protected:
		std::map<std::string, std::string> atomNameToAtomType;
		std::map<std::string, std::string> atomTypeToAtomName;
		std::map<std::string, std::string> atomTypeToMSE;
		std::map<std::string, int> residueLetterToResidueNumber;
		std::map<std::string, std::string> residueLetterToResidueName;

		std::map<std::string, double> weights;
		std::vector<BondParam> bonds;
		std::vector<AngleParam> angles;
		std::vector<DihedralParam> diedrals;
};

#include "chainParameterManager.h"

using namespace std;

map<int, ChainParameters> ChainParameterManager::m_chainParameters = map<int, ChainParameters>();

ChainParameters& ChainParameterManager::getParametersForChainType(int chainType)
{
	// TODO: return an error if key not in map
	if(m_chainParameters.count(chainType)==0) {
		init(chainType);}

	return m_chainParameters[chainType];
}

void ChainParameterManager::init(int chainType)
{
	switch(chainType) {
		case(Molecule::RNA):
			m_chainParameters[Molecule::RNA] = RNAParameters();
			break;
		case(Molecule::DNA):
			m_chainParameters[Molecule::DNA] = DNAParameters();
			break;
		case(Molecule::PROTEIN):
			cout << "ERROR: PROTEIN param not yet implemented !!!" << endl;
			break;
		case(Molecule::UNKNOWN):
			m_chainParameters[Molecule::UNKNOWN] = RNAParameters();
			cout << "ERROR: UNKNOWN chain don't have any parameters !!!" << endl;
			break;
	}
}

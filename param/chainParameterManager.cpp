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
		case(Chain::RNA):
			m_chainParameters[Chain::RNA] = RNAParameters();
			break;
		case(Chain::DNA):
			m_chainParameters[Chain::DNA] = DNAParameters();
			break;
		case(Chain::PROTEIN):
			cout << "ERROR: PROTEIN param not yet implemented !!!" << endl;
			break;
		case(Chain::IONS):
			cout << "Using RNA parameter set for ions" << endl;
			m_chainParameters[Chain::IONS] = RNAParameters();
			break;
		case(Chain::UNKNOWN):
			m_chainParameters[Chain::UNKNOWN] = RNAParameters();
			cerr << "UNKNOWN chain, using RNA parameters." << endl;
			break;
	}
}

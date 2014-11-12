#include "chainParameterManager.h"

using namespace std;

map<int, ChainParameters> ChainParameterManager::m_chainParameters = map<int, ChainParameters>();

ChainParameters& ChainParameterManager::getParametersForChainType(int chainType)
{
	// TODO: return an error if key not in map
	init();
	return m_chainParameters[chainType];
}

void ChainParameterManager::init()
{
	m_chainParameters[Molecule::RNA] = RNAParameters();
}

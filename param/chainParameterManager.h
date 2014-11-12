#pragma once

#include <map>

#include "chainParameters.h"
#include "../entities/molecule.hpp"
#include "RNAParameters.h"

class ChainParameterManager
{
	public:
		static ChainParameters& getParametersForChainType(int chainType);

	private:
		static void init();
		static std::map<int, ChainParameters> m_chainParameters;
};

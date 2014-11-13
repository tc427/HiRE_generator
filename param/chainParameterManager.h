#pragma once

#include <map>

#include "chainParameters.h"
#include "../entities/molecule.hpp"
#include "RNAParameters.h"
#include "DNAParameters.h"

class ChainParameterManager
{
	public:
		static ChainParameters& getParametersForChainType(int chainType);

	private:
		static void init(int chainType);
		static std::map<int, ChainParameters> m_chainParameters;
};

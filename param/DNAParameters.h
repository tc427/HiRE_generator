#pragma once

#include<string>
#include<map>
#include<vector>
#include<iostream>

#include "structsParam.h"
#include "chainParameters.h"

class DNAParameters: public ChainParameters
{
	public:
		DNAParameters();
		virtual ~DNAParameters();

	private:
		void init();
};

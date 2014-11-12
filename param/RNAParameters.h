#pragma once

#include<string>
#include<map>
#include<vector>
#include<iostream>

#include "structsParam.h"
#include "chainParameters.h"

class RNAParameters : public ChainParameters
{
	public:
		RNAParameters();
		virtual ~RNAParameters();

	private:
		void init();
};

#pragma once

#include <map>
#include <string>
#include <vector>

class Fa2cgParam
{
	public:
		static float getMass(std::string element);
		static std::map<std::string, std::string > getFa2cg();
		static std::map<std::vector<std::string>, std::string > getFa2cgCycles(std::string type);
		static std::vector<std::string> getFa2cgOrder();

	private:
		Fa2cgParam();
		virtual ~Fa2cgParam();

		void static initialise();

		static std::map<std::string, float> mass;
		static std::map<std::string, std::string > fa2cg;
		static std::vector<std::string> fa2cgOrder;
		static std::map<std::string, std::map<std::vector<std::string>, std::string > > fa2cgCycles;
};

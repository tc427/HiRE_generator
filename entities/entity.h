#pragma once

#include <map>
#include <vector>
#include <string>

#include "entitySearchCriteria.hpp"

enum LEVEL {MOLECULE, CHAIN, RESIDUE, ATOM};

class Entity
{
	public:
		Entity();
		Entity(int number,std::string type, std::string name);
		virtual ~Entity();

		int getNumber();
		void setNumber(int number);
		std::string getType();
		void setType(std::string type);
		std::string getName();
		void setName(std::string name);

	protected:
		int m_number;
		std::string m_name;
		std::string m_type;

		static LEVEL level;

		static std::map<std::string, int> strTypeToInt;
		static std::map<int, std::string> intTypeToStr;
};

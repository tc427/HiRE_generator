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
		template <typename T>
		Entity(int number,T type, std::string name);
		virtual ~Entity();

		int getNumber();
		void setNumber(int number);
		int getType();
		std::string getType();
		void setType(int type);
		void setType(std::string type);
		std::string getName();
		void setName(std::string name);

	protected:
		int m_number;
		int m_type;
		std::string m_name;

		static LEVEL level;

		static std::map<std::string, int> strTypeToInt;
		static std::map<int, std::string> intTypeToStr;
};

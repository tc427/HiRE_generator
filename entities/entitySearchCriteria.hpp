#pragma once

#include <string>

class EntitySearchCriteria {
	public:
		EntitySearchCriteria();
		virtual ~EntitySearchCriteria();

		int getNumber();
		EntitySearchCriteria *setNumber(int number);
		int getType();
		EntitySearchCriteria *setType(int type);
		std::string getName();
		EntitySearchCriteria *setName(std::string name);

	private:
		int m_number;
		int m_type;
		std::string m_name;

};

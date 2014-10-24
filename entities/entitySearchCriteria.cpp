#include "entitySearchCriteria.hpp"

using namespace std;

EntitySearchCriteria::EntitySearchCriteria() : m_number(-1), m_type(-1), m_name("")
{

}

EntitySearchCriteria::~EntitySearchCriteria()
{

}

int EntitySearchCriteria::getNumber()
{
	return m_number;
}

EntitySearchCriteria *EntitySearchCriteria::setNumber(int number)
{
	m_number= number;
	return this;
}

int EntitySearchCriteria::getType()
{
	return m_type;
}

EntitySearchCriteria *EntitySearchCriteria::setType(int type)
{
	m_type = type;
	return this;
}


std::string EntitySearchCriteria::getName()
{
	return m_name;
}

EntitySearchCriteria *EntitySearchCriteria::setName(std::string name)
{
	m_name = name;
	return this;
}

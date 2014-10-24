#include "entity.h"

using namespace std;

Entity::Entity() :m_number(-1)
{

}

Entity::Entity(int number, std::string type, std::string name) : m_number(number), m_type(type), m_name(name)
{

}

Entity::~Entity()
{

}

int Entity::getNumber()
{
	return m_number;
}

void Entity::setNumber(int number)
{
	m_number= number;
}

string Entity::getType()
{
	return m_type;
}

void Entity::setType(string type)
{
	m_type = type;
}


std::string Entity::getName()
{
	return m_name;
}

void Entity::setName(std::string name)
{
	m_name = name;
}

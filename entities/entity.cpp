#include "entity.h"

using namespace std;

Entity::Entity() :m_number(-1)
{

}

template <typename T>
Entity::Entity(int number, T type, std::string name) : m_number(number), m_name(name)
{
	setType(type);
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

int Entity::getType()
{
	return m_type;
}

string Entity::getType()
{
	return intTypeToStr[m_type];
}

void Entity::setType(int type)
{
	m_type = type;
}


void Entity::setType(string type)
{
	m_type = strTypeToInt[type];
}

std::string Entity::getName()
{
	return m_name;
}

void Entity::setName(std::string name)
{
	m_name = name;
}

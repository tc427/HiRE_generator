#include "entity.h"

using namespace std;

map<int, string> Entity::intTypeToStr = map<int, string>();
map<string, int> Entity::strTypeToInt = map<string, int>();

Entity::Entity() :m_number(-1)
{

}

Entity::Entity(int number, string type, std::string name) : m_number(number), m_name(name), m_type(type)
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



std::vector<Entity> getEntitiesByNumber(int number);
std::vector<Entity> getEntitiesByType(std::string type);
std::vector<Entity> getEntitiesByName(std::string name);
Entity getEntityByNumber(int number);
Entity getEntityByType(std::string type);
Entity getEntityByName(std::string name);

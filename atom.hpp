#pragma once

#include <string>


class Atom
{
	
	public:
		Atom();
		Atom(int number, std::string name, std::string type);
		int getNumber();
		std::string getType();
	
	
	private:
		int number;
		std::string name;
		std::string type;
};

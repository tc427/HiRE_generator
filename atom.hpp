#pragma once

#include <string>
#include <iostream>

#include "vector.hpp"

class Atom
{
	
	public:
		Atom();
		Atom(int number, std::string name, std::string type);
		Atom(int number, std::string name, std::string type, Vector coordinates);
		int getNumber();
		std::string getType();
		std::string getName();
		void setCoordinates(Vector coordinates);
		Vector& getCoordinates();
	
	
	private:
		int number;
		std::string name;
		std::string type;
		Vector coordinates;
		
	friend std::ostream& operator<< (std::ostream& flux, Atom const& atom);
};

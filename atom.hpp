#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "coordinates.hpp"

class Atom
{
	
	public:
		Atom();
		Atom(int number, std::string name, std::string type);
		Atom(int number, std::string name, std::string type, Coordinates coordinates);
		int getNumber();
		std::string getType();
		void setCoordinates(Coordinates coordinates);
		Coordinates getCoordinates();
	
	
	private:
		int number;
		std::string name;
		std::string type;
		Coordinates coordinates;
		
	friend std::ostream& operator<< (std::ostream& flux, Atom const& atom);
};

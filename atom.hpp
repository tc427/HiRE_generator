#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "vector3d.hpp"
#include "residue.hpp"

class Residue;

class Atom
{
	
	public:
		Atom();
		Atom(int number, std::string name, std::string type);
		Atom(int number, std::string name, std::string type, Vector3d coordinates);
		int getNumber();
		std::string getType();
		std::string getName();
		void addCoordinates(Vector3d coordinates);
		std::vector<Vector3d>& getCoordinates();
		void setParent(Residue *parent);
		Residue *getParent(); 
	
	private:
		int number;
		std::string name;
		std::string type;
		std::vector<Vector3d> coordinates;
		Residue* parent;
		
	friend std::ostream& operator<< (std::ostream& flux, Atom const& atom);
};

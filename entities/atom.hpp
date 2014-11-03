#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "../geometry/vector3d.hpp"
#include "residue.hpp"
#include "entity.h"

class Residue;

class Atom : public Entity
{

	public:
		Atom();
		Atom(int number, std::string name, std::string type);
		Atom(int number, std::string name, std::string type, Vector3d coordinates);
		~Atom();
		void addCoordinates(Vector3d coordinates);
		std::vector<Vector3d>& getCoordinates();

		Residue *getParent();
		void setParent(Residue *parent);

		static int getNAtoms();

		enum ATOM_TYPE {H, C, N, O, P, Mg};


	private:
		Residue *m_parent;
		std::vector<Vector3d> m_childs;

		static int nAtoms;

		friend std::ostream& operator<< (std::ostream& flux, Atom const& atom);
		friend bool operator< (Atom const& atom1, Atom const& atom2);
		friend bool operator> (Atom const& atom1, Atom const& atom2);
};

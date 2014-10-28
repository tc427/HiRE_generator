#pragma once

#include <string>
#include <map>
#include <vector>

using namespace std;

struct weightParam
{

	string atom;

	float weight;

};

struct bondParam
{
	string atom1;

	string atom2;

	float l;

	float force;
};

struct angleParam
{
	string atom1;

	string atom2;

	string atom3;

	float rk;

	float req;
};

struct dihedralParam
{

	string atom1;

	string atom2;

	string atom3;

	string atom4;

	float pk;

	float pn;

	float phase;

};



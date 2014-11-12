#pragma once

#include <string>
#include <map>
#include <vector>

using namespace std;

struct BondParam
{
	string atom1;

	int decalageAtom1;

	string atom2;

	int decalageAtom2;

	double l;

	double force;

};

struct AngleParam
{
	string atom1;

	int decalageAtom1;

	string atom2;

	int decalageAtom2;

	string atom3;

	int decalageAtom3;

	double rk;

	double req;
};

struct DihedralParam
{
	string atom1;

	int decalageAtom1;

	string atom2;

	int decalageAtom2;

	string atom3;

	int decalageAtom3;

	string atom4;

	int decalageAtom4;

	double pk;

	double pn;

	double phase;

};



#include "fa2cgParam.hpp"

using namespace std;

map<string, float> Fa2cgParam::mass;
map<string, string > Fa2cgParam::fa2cg;
map<string, map<vector<string>, string > > Fa2cgParam::fa2cgCycles;
map<string, string> Fa2cgParam::normalisation;

Fa2cgParam::Fa2cgParam() {
	// TODO Auto-generated constructor stub

}

Fa2cgParam::~Fa2cgParam() {
	// TODO Auto-generated destructor stub
}

void Fa2cgParam::initialise()
{
	mass["H"] = 1;
	mass["C"] = 12;
	mass["N"] = 14;
	mass["O"] = 16;
	mass["Mg"] = 24;
	mass["P"] = 30;

	fa2cg = map< string, string >();
	fa2cg["P"]   = "P";
	fa2cg["O5*"] = "O5";
	fa2cg["C5*"] = "C5'";
	fa2cg["CA"]  = "C4'";
	fa2cg["C1*"]  = "CY";

	vector<string> A1;
	vector<string> A2;
	vector<string> C1;
	vector<string> G1;
	vector<string> G2;
	vector<string> U1;
	vector<string> T1;

	A1.push_back("N7");
	A1.push_back("N9");
	A1.push_back("C4");
	A1.push_back("C5");
	A1.push_back("C8");

	A2.push_back("N1");
	A2.push_back("N3");
	A2.push_back("N6");
	A2.push_back("C2");
	A2.push_back("C4");
	A2.push_back("C5");
	A2.push_back("C6");

	C1.push_back("N1");
	C1.push_back("N3");
	C1.push_back("N4");
	C1.push_back("C2");
	C1.push_back("C4");
	C1.push_back("C5");
	C1.push_back("C6");
	C1.push_back("O2");

	G1.push_back("N7");
	G1.push_back("N9");
	G1.push_back("C4");
	G1.push_back("C5");
	G1.push_back("C8");

	G2.push_back("N1");
	G2.push_back("N2");
	G2.push_back("N3");
	G2.push_back("C2");
	G2.push_back("C4");
	G2.push_back("C5");
	G2.push_back("C6");
	G2.push_back("O6");

	U1.push_back("N1");
	U1.push_back("N3");
	U1.push_back("C2");
	U1.push_back("C4");
	U1.push_back("C5");
	U1.push_back("C6");
	U1.push_back("O2");
	U1.push_back("O4");
	U1.push_back("O");

	T1.push_back("N1");
	T1.push_back("N3");
	T1.push_back("C2");
	T1.push_back("C4");
	T1.push_back("C5");
	T1.push_back("C6");
	T1.push_back("O2");
	T1.push_back("O4");
	T1.push_back("C7");

	fa2cgCycles["A"] = map< vector<string>, string > ();
	fa2cgCycles["C"] = map< vector<string>, string > ();
	fa2cgCycles["T"] = map< vector<string>, string > ();
	fa2cgCycles["G"] = map< vector<string>, string > ();
	fa2cgCycles["U"] = map< vector<string>, string > ();

	fa2cgCycles["DA"] = map< vector<string>, string > ();
	fa2cgCycles["DC"] = map< vector<string>, string > ();
	fa2cgCycles["DT"] = map< vector<string>, string > ();
	fa2cgCycles["DG"] = map< vector<string>, string > ();
	fa2cgCycles["DU"] = map< vector<string>, string > ();

	fa2cgCycles["A"][ A1 ] = "A1";
	fa2cgCycles["A"][ A2 ] = "A2";
	fa2cgCycles["C"][ C1 ] = "C1";
	fa2cgCycles["G"][ G1 ] = "G1";
	fa2cgCycles["G"][ G2 ] = "G2";
	fa2cgCycles["U"][ U1 ] = "U1";
	fa2cgCycles["T"][ T1 ] = "U1";

	fa2cgCycles["DA"][ A1 ] = "A1";
	fa2cgCycles["DA"][ A2 ] = "A2";
	fa2cgCycles["DC"][ C1 ] = "C1";
	fa2cgCycles["DG"][ G1 ] = "G1";
	fa2cgCycles["DG"][ G2 ] = "G2";
	fa2cgCycles["DU"][ U1 ] = "U1";
	fa2cgCycles["DT"][ T1 ] = "U1";

	normalisation["C5M"] = "C7";
	normalisation["O"] = "O2";


}

float Fa2cgParam::getMass(string element)
{
	if(mass.empty()) {
		initialise(); }

	return mass.count(element)?mass[element]:1;
}

map<string, string > Fa2cgParam::getFa2cg()
{
	if(fa2cg.empty()) {
		initialise(); }

	return fa2cg;
}

map<vector<string>, string > Fa2cgParam::getFa2cgCycles(string type)
{
	if(fa2cgCycles.empty()) {
		initialise(); }

	return fa2cgCycles[type];
}


map<string, string> Fa2cgParam::getNormalisation()
{
	return normalisation;
}

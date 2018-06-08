/*
 * DNAParameters.cpp
 *
 *  Created on: 13 nov. 2014
 *      Author: cg
 */

#include "DNAParameters.h"

DNAParameters::DNAParameters()
{
	init();
}

DNAParameters::~DNAParameters()
{
	// TODO Auto-generated destructor stub
}


void DNAParameters::init()
{
	atomNameToAtomType = { {"P", "P"},
						   {"O5*", "O"},
						   {"C5*", "C"},
						   {"CA", "R4"},
						   {"CY", "R1"},
						   {"A1", "A1"},
						   {"A2", "A2"},
						   {"G1", "G1"},
						   {"G2", "G2"},
						   {"C1", "C1"},
						   {"U1", "U1"},
						   {"D",  "D"},
						   {"MG", "MG"}};

	for(map<string, string>::iterator it=atomNameToAtomType.begin(); it!=atomNameToAtomType.end(); ++it)
	{
		atomTypeToAtomName[it->second] = it->first;
	}

	atomTypeToMSE = { {"P", "M"},
					  {"O", "M"},
					  {"C", "M"},
					  {"R4", "M"},
					  {"R1", "S"},
					  {"A1", "S"},
					  {"A2", "E"},
					  {"G1", "S"},
					  {"G2", "E"},
					  {"C1", "E"},
					  {"U1", "E"},
					  {"D", "M"},
					  {"MG", "H"} };

	residueLetterToResidueNumber = { {"G", 1},
									 {"A", 2},
									 {"C", 3},
									 {"T", 4},
									 {"D", 5} };

	residueLetterToResidueName = { {"G", "GUA"},
								   {"A", "ADE"},
								   {"C", "CYT"},
								   {"T", "URA"},
								   {"D", "DUM"} };

	weights = { {"BR",   79.900  },
				{ "C",   12.010  },
				{"CA",   12.010  },
				{ "A",   12.010  },
				{"CB",   12.010  },
				{"CN",   12.010  },
				{"CC",   12.010  },                // ?
				{"CD",   13.020  },                // ?
				{"CE",   13.020  },
				{"CF",   13.020  },
				{"CG",   13.020  },
				{"L1",   44.110  },                 // !! MASSE CORRECTE POUR MD
				{"K1",   73.050  },                 // !! MASSES OK FOR MD
				{"I1",   57.130  },                 // !! OK for MD
				{"I2",   13.020  },
				{"E1",   60.060  },                 // !!  OK for MD
				{"E2",   13.020  },
				{"Y1",   83.130  },                 // !! MASSE OK for MD
				{"Y2",   13.020  },
				{"S1",   31.040  },                 // !! MASSE CORRECTE POUR MD
				{"S2",   13.020  },
				{"S4",   13.020  },
				{"X1",   82.120  },                  // !! MASSE CORRECTE POUR MD
				{"X2",   13.020  },
				{"N1",    1.020  },
				{"N5",   13.020  },
				{"N2",   13.020  },
				{"M1",   76.170  },                  // !! MASSE OK for MD
				{"M2",   13.020  },
				{"V1",   30.080  },                  // !! MASSE CORRECTE POUR MD
				{"T1",   45.070  },                  // !!  MASSE CORRECTE POUR MD
				{"Q2",   13.020  },
				{"Z2",   13.020  },
				{"Q1",   60.080  },                  // !! MASSE CORRECTE POUR MD
				{"CH",   13.020  },
				{"W1",  130.180  },                 // !!  MASSE OK for MD
				{"W2",   13.020  },
				{"D1",   46.030  },                  // !!   MASSE OK for MD
				{"W1",    1.020  },
				{"AS",   46.050  },                  // !! MASSE CORRECTE POUR MD
				{"D2",   13.020  },
				{"F1",   79.130  },                  // !!  MASSE OK for MD
				{"F2",   13.020  },
				{"CI",    1.020  },
				{"CJ",   13.020  },
				{"CK",   12.010  },
				{"CM",   12.010  },
				{"CN",   12.010  },
				{"CP",   13.020  },
				{"CQ",   12.010  },                // ?
				{"CR",   12.010  },
				{"CT",   12.010  },
				{"CV",   12.010  },
				{"CW",   12.010  },
				{"CX",   14.030  },
				{"CY",   12.010  },                  // !!  MASSE CORRECTE FOR CYS FREE
				{"CZ",   14.030  },
				{"C2",   14.030  },
				{"C3",   15.040  },
				{"C*",   12.010  },
				{"CL",   35.450  },
				{"C0",   40.080  },               // c0 is calcium
				{ "F",   19.000  },
				{ "H",    1.008  },
				{"HC",    1.008  },
				{"HO",    1.008  },
				{"HS",    1.008  },
				{"HW",    1.008  },
				{"H2",    1.008  },
				{"H3",    1.008  },
				{"H4",    1.008  },
				{ "I",  126.900  },
				{"IM",   35.450  },                 // ASSUMED TO BE CL-
				{"IP",   22.990  },                 // ASSUMED TO BE NA+
				{ "N",   14.010  },
				{"NA",   14.010  },
				{"NB",   14.010  },
				{"NZ",   14.010  },
				{"NP",   14.010  },
				{"NO",   14.010  },
				{"NC",   14.010  },
				{"NT",   14.010  },
				{"N2",   14.010  },
				{"N3",   17.040  },                 // !! N3 for NH3 OK FOR MD
				{"N*",   14.010  },
				{"O",    16.000  },
				{"W",    16.000  },
				{"OW",   16.000  },
				{"OH",   16.000  },
				{"OM",   16.000  },
				{"OS",   16.000  },
				{"O2",   16.000  },
				{"P",    36.970  },
				{"QC",  132.900  },               // qc is cesium
				{"QK",   39.100  },               // qk is potassium
				{"QL",    6.940  },               // ql is lithium
				{"QN",   22.990  },               // qn is  sodium
				{"QR",   85.470  },               // qr is rubidium
				{"S",    32.060  },
				{"SH",   32.060  },
				{"SF",   32.060  },
				{"S*",   32.060  },
				{"CU",   63.550  },
				{"FE",   55.000  },
				{"LP",    3.000  },
				{"R4",   20.000  },
				{"R5",   12.000  },
				{"R1",   12.000  },
				{"G1",   75.000  },
				{"G2",   75.000  },
				{"A1",   67.000  },
				{"A2",   67.000  },
				{"U1",  131.000  },
				{"C1",  130.000  },
				{ "D", 1000.000  },
				{"MG",   24.305  } };

	// struct BondParam: string atom1; string atom2; float l; float force;
	bonds = { {"R4", 0,  "P", 1,  20, 3.850},    //! 3.818 -> 3.900 -> 3.820 -> 3.6  softer ???
			  {"R4", 0, "R1", 0, 200, 2.344},
			  {"R1", 0, "G1", 0, 200, 2.622},
			  {"R1", 0, "A1", 0, 200, 2.633},
			  {"R1", 0, "U1", 0, 200, 3.062},
			  {"R1", 0, "C1", 0, 200, 3.004},
			  {"G1", 0, "G2", 0, 200, 2.450},
			  {"A1", 0, "A2", 0, 200, 2.180},
			  { "C", 0, "R4", 0, 200, 1.520},
			  { "P", 0,  "O", 0, 200, 1.593},
			  { "O", 0,  "C", 0, 200, 1.430},
			  { "D", 0,  "D", 0,  40, 12.00},
			  {"R4", 0,  "D", 0,  10, 12.00},
			  { "D", 0,  "O", 0,  10, 12.00},
			  { "D", 0,  "P", 0,  10, 12.00} };

	angles = { {"R4", 0, "R1", 0, "A1", 0,  70, 135.0  },    // k=50 works
			   {"R4", 0, "R1", 0, "U1", 0,  70, 142.0  },
			   {"R4", 0, "R1", 0, "G1", 0,  70, 131.0  },
			   {"R4", 0, "R1", 0, "C1", 0,  70, 138.0  },
			   {"R1", 0, "A1", 0, "A2", 0, 120, 118.0  },
			   {"R1", 0, "G1", 0, "G2", 0, 120, 111.2  },
			   { "P", 0,  "O", 0,  "C", 0,  70, 120.0  },
			   { "O", 0,  "C", 0, "R4", 0,  70, 110.6  },
			   { "C", 0, "R4", 0,  "P", 1,  70, 120.0  },       // 100 or 109 or 95.1 orig
			   {"R4", 0,  "P", 1,  "O", 1,  50, 101.0  },    	// 105.0 or 101.3
			   { "C", 0, "R4", 0, "R1", 0,  70, 130.0  },
			   {"R1", 0, "R4", 0,  "P", 1,  20,  85.0  },
			   { "D", 0,  "D", 0,  "D", 0,  80, 180.0  } };

	diedrals = { {"R4", 0, "R1", 0, "G1", 0, "G2", 0, 20.0,  -120.0, 2  },       // -20
				 {"R4", 0, "R1", 0, "A1", 0, "A2", 0, 20.0,  -120.0, 2  },       // -20
				 { "C", 0, "R4", 0,  "P", 1,  "O", 1,  6.0,   15.0, 1  },       // history coef: 75 -> 50 angle: 75 -> 25 -> 35
				 { "C", 0, "R4", 0, "R1", 0, "A1", 0, 10.0,  160.0, 1  },       // history coef: 50 -> 150
				 { "C", 0, "R4", 0, "R1", 0, "G1", 0, 10.0,  155.0, 1  },       // history coef: 50 -> 150
				 { "C", 0, "R4", 0, "R1", 0, "C1", 0, 10.0,  150.0, 1  },
				 { "C", 0, "R4", 0, "R1", 0, "U1", 0, 10.0,  145.0, 1  },
				 { "P", 0,  "O", 0,  "C", 0, "R4", 0, 15.0,  -10.0, 1  },       // history: coef: 50 -> 10
				 {"R4", 0,  "P", 1,  "O", 1,  "C", 1,  7.0,  100.0, 1  },		// val AMBER  history: 95 -> 85
				 { "O", 0,  "C", 0, "R4", 0,  "P", 1,  2.0, -115.0, 1  },		// -105 history coef: 25 -> 2
				 { "O", 0,  "C", 0, "R4", 0, "R1", 0,  2.0,  150.0, 1  },
//				 { "C", 0, "R1", 0, "R4", 0,  "P", 1,  0.0,  170.0, 1  },       // history coef: 50 -> 200 angle: 70 -> 60
				 { "P", 1, "R4", 0, "R1", 0, "G1", 0, 15.0,  30.0, 1  },
				 { "P", 1, "R4", 0, "R1", 0, "A1", 0, 15.0,  30.0, 1  },
				 { "P", 1, "R4", 0, "R1", 0, "C1", 0, 15.0,  30.0, 1  },
				 { "P", 1, "R4", 0, "R1", 0, "U1", 0, 15.0,  30.0, 1  },
				 {"R1", 0, "R4", 0,  "P", 1,  "O", 1,  5.0,  165.0, 1  } };
}

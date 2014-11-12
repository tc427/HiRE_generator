#include "opepInputParamWriter.h"

using namespace std;

OpepInputParamWriter::OpepInputParamWriter(Molecule& molecule) : m_molecule(molecule), m_chainParameters(ChainParameterManager::getParametersForChainType(m_molecule.getIntChainsType()))
{
	m_atomTypesInSystem = {"C", "O", "P", "R4", "R1", "G1", "G2", "A1", "A2", "U1", "C1", "D", "MG"};
}

OpepInputParamWriter::~OpepInputParamWriter()
{

}

void OpepInputParamWriter::write(string filename)
{
	vector<int> bondNumbers = vector<int>();
	vector<int> angleNumbers = vector<int>();
	vector<int> dihedralNumbers = vector<int>();

	for(Residue residue: m_molecule.getResidues())
	{
		Chain* chain = residue.getParent();
		int residueNumber(residue.getNumber());
		int n(0);

		for(BondParam bondParam: m_chainParameters.getBonds())
		{
			n++;
			if( chain->hasResidue(residueNumber+bondParam.decalageAtom1) &&
				chain->hasResidue(residueNumber+bondParam.decalageAtom2) )
			{
				Residue residue1 = chain->getResidue(residueNumber+bondParam.decalageAtom1);
				Residue residue2 = chain->getResidue(residueNumber+bondParam.decalageAtom2);

				if ( residue1.hasAtom( m_chainParameters.getAtomTypeToAtomName( bondParam.atom1) ) &&
					 residue2.hasAtom( m_chainParameters.getAtomTypeToAtomName( bondParam.atom2) ) )
				{
					bondNumbers.push_back(3*( residue1.getAtom( m_chainParameters.getAtomTypeToAtomName( bondParam.atom1) ).getNumber() -1 ) );
					bondNumbers.push_back(3*( residue2.getAtom( m_chainParameters.getAtomTypeToAtomName( bondParam.atom2) ).getNumber() -1 ) );
					bondNumbers.push_back(n);
				}
			}
		}

		n = 0;
		for(AngleParam angleParam: m_chainParameters.getAngles())
		{
			n++;
			if( chain->hasResidue(residueNumber+angleParam.decalageAtom1) &&
				chain->hasResidue(residueNumber+angleParam.decalageAtom2) &&
				chain->hasResidue(residueNumber+angleParam.decalageAtom3) )
			{
				Residue residue1 = chain->getResidue(residueNumber+angleParam.decalageAtom1);
				Residue residue2 = chain->getResidue(residueNumber+angleParam.decalageAtom2);
				Residue residue3 = chain->getResidue(residueNumber+angleParam.decalageAtom3);

				if ( residue1.hasAtom( m_chainParameters.getAtomTypeToAtomName( angleParam.atom1) ) &&
					 residue2.hasAtom( m_chainParameters.getAtomTypeToAtomName( angleParam.atom2) ) &&
					 residue3.hasAtom( m_chainParameters.getAtomTypeToAtomName( angleParam.atom3) ) )
				{
					angleNumbers.push_back(3*( residue1.getAtom( m_chainParameters.getAtomTypeToAtomName( angleParam.atom1) ).getNumber() -1 ) );
					angleNumbers.push_back(3*( residue2.getAtom( m_chainParameters.getAtomTypeToAtomName( angleParam.atom2) ).getNumber() -1 ) );
					angleNumbers.push_back(3*( residue3.getAtom( m_chainParameters.getAtomTypeToAtomName( angleParam.atom3) ).getNumber() -1 ) );
					angleNumbers.push_back(n);
				}
			}
		}

		n = 0;
		for(DihedralParam dihedralParam: m_chainParameters.getDiedrals())
		{
			n++;
			if( chain->hasResidue(residueNumber+dihedralParam.decalageAtom1) &&
				chain->hasResidue(residueNumber+dihedralParam.decalageAtom2) &&
				chain->hasResidue(residueNumber+dihedralParam.decalageAtom3) &&
				chain->hasResidue(residueNumber+dihedralParam.decalageAtom4) )
			{
				Residue residue1 = chain->getResidue(residueNumber+dihedralParam.decalageAtom1);
				Residue residue2 = chain->getResidue(residueNumber+dihedralParam.decalageAtom2);
				Residue residue3 = chain->getResidue(residueNumber+dihedralParam.decalageAtom3);
				Residue residue4 = chain->getResidue(residueNumber+dihedralParam.decalageAtom4);

				if ( residue1.hasAtom( m_chainParameters.getAtomTypeToAtomName( dihedralParam.atom1) ) &&
					 residue2.hasAtom( m_chainParameters.getAtomTypeToAtomName( dihedralParam.atom2) ) &&
					 residue3.hasAtom( m_chainParameters.getAtomTypeToAtomName( dihedralParam.atom3) ) &&
					 residue4.hasAtom( m_chainParameters.getAtomTypeToAtomName( dihedralParam.atom4) ) )
				{
					dihedralNumbers.push_back(3*( residue1.getAtom( m_chainParameters.getAtomTypeToAtomName( dihedralParam.atom1) ).getNumber() -1 ) );
					dihedralNumbers.push_back(3*( residue2.getAtom( m_chainParameters.getAtomTypeToAtomName( dihedralParam.atom2) ).getNumber() -1 ) );
					dihedralNumbers.push_back(3*( residue3.getAtom( m_chainParameters.getAtomTypeToAtomName( dihedralParam.atom3) ).getNumber() -1 ) );
					dihedralNumbers.push_back(3*( residue4.getAtom( m_chainParameters.getAtomTypeToAtomName( dihedralParam.atom4) ).getNumber() -1 ) );
					dihedralNumbers.push_back(n);
				}
			}
		}

	}


	m_topFile.open(filename.c_str());

	printRecap(bondNumbers.size()/3, angleNumbers.size()/4, dihedralNumbers.size()/5);
	printAtomsDetails();
	printResiduesDetails();
	printBondsDefinitionDetails();
	printAnglesDefinitionDetails();
	printDihedresDefinitionDetails();
	printDetails(bondNumbers);
	printDetails(angleNumbers);
	printDetails(dihedralNumbers);

	m_topFile.close();
}

void OpepInputParamWriter::printRecap(int nBondsInSystem, int nAnglesInSystem, int nDihedralsInSystem)
{

	switch(m_molecule.getIntChainsType()) {
		case(Molecule::RNA):
				m_topFile << "RNA molecule" << endl;
				break;
		case(Molecule::DNA):
				m_topFile << "DNA molecule" << endl;
				break;
		case(Molecule::PROTEIN):
				m_topFile << "PROTEIN molecule" << endl;
				break;
		case(Molecule::UNKNOWN):
				m_topFile << "UNKNOWN molecule" << endl;
				break;
	}

	m_topFile << setw(6) << m_molecule.getAtoms().size();
	m_topFile << setw(6) << m_chainParameters.getWeights().size();
	m_topFile << setw(6) << m_atomTypesInSystem.size();
	m_topFile << setw(6) << nBondsInSystem;
	m_topFile << setw(6) << nAnglesInSystem;
	m_topFile << endl;
	m_topFile << setw(6) << nDihedralsInSystem;
	m_topFile << setw(6) << m_molecule.getResidues().size();
	m_topFile << setw(6) << m_chainParameters.getBonds().size();
	m_topFile << setw(6) << m_chainParameters.getAngles().size();
	m_topFile << setw(6) << m_chainParameters.getDiedrals().size();
	m_topFile << endl;
}

void OpepInputParamWriter::printAtomsDetails()
{
	m_topFile << left;
	int n(0);
	for(Atom atom: m_molecule.getAtoms())
	{
		if(n%20 == 0 && n>0) {
			m_topFile << endl; }
		m_topFile << setw(4) << m_chainParameters.getAtomNameToAtomType( atom.getName());
		n++;
	}
	m_topFile << endl << right;

	n = 0;
	for(Atom atom: m_molecule.getAtoms())
	{
		if(n%5 == 0 && n>0) {
			m_topFile << endl; }
		m_topFile << OpepFunctions::getFortranFloat(m_chainParameters.getWeight(m_chainParameters.getAtomNameToAtomType( atom.getName() ) ) );
		n++;
	}

	m_topFile << endl;
	n = 0;
	for(Atom atom: m_molecule.getAtoms())
	{
		if(n%12 == 0 && n>0) {
			m_topFile << endl; }
		m_topFile << setw(6) << OpepFunctions::index_of(m_atomTypesInSystem, m_chainParameters.getAtomNameToAtomType( atom.getName() ) ) + 1;
		n++;
	}
	m_topFile << endl;
}

void OpepInputParamWriter::printResiduesDetails()
{
	int n(0);
	for(Residue residue: m_molecule.getResidues())
	{
		if(n%20== 0 && n>0) {
			m_topFile << endl; }
		m_topFile << m_chainParameters.getResidueLetterToResidueName( residue.getType() );
		if(n==0) {
			m_topFile << "i";
		} else {
			m_topFile << " ";
		}
		n++;
	}
	m_topFile << endl;

	n = 0;
	for(Residue residue: m_molecule.getResidues())
	{
		if(n%12== 0 && n>0) {
			m_topFile << endl; }
		m_topFile << setw(6) << residue.getAtoms()[0].getNumber();
		n++;
	}
	m_topFile << endl;

}

void OpepInputParamWriter::printBondsDefinitionDetails()
{
	int n(0);
	for(BondParam bonParam: m_chainParameters.getBonds())
	{
		if(n%5== 0 && n>0) {
			m_topFile << endl; }
		m_topFile << OpepFunctions::getFortranFloat( bonParam.l );
		n++;
	}
	m_topFile << endl;

	n = 0;
	for(BondParam bonParam: m_chainParameters.getBonds())
	{
		if(n%5== 0 && n>0) {
			m_topFile << endl; }
		m_topFile << OpepFunctions::getFortranFloat( bonParam.force );
		n++;
	}
	m_topFile << endl;
}

void OpepInputParamWriter::printAnglesDefinitionDetails()
{
	int n(0);
	for(AngleParam angleParam: m_chainParameters.getAngles())
	{
		if(n%5== 0 && n>0) {
			m_topFile << endl; }
		m_topFile << OpepFunctions::getFortranFloat( angleParam.rk );
		n++;
	}
	m_topFile << endl;

	n = 0;
	for(AngleParam angleParam: m_chainParameters.getAngles())
	{
		if(n%5== 0 && n>0) {
			m_topFile << endl; }
		m_topFile << OpepFunctions::getFortranFloat( OpepFunctions::deg2rad( angleParam.req ) );
		n++;
	}
	m_topFile << endl;
}

void OpepInputParamWriter::printDihedresDefinitionDetails()
{
	int n(0);
	for(DihedralParam dihedralParam: m_chainParameters.getDiedrals())
	{
		if(n%5== 0 && n>0) {
			m_topFile << endl; }
		m_topFile << OpepFunctions::getFortranFloat( dihedralParam.pk );
		n++;
	}
	m_topFile << endl;

	n = 0;
	for(DihedralParam dihedralParam: m_chainParameters.getDiedrals())
	{
		if(n%5== 0 && n>0) {
			m_topFile << endl; }
		m_topFile << OpepFunctions::getFortranFloat( dihedralParam.phase );
		n++;
	}
	m_topFile << endl;

	n = 0;
	for(DihedralParam dihedralParam: m_chainParameters.getDiedrals())
	{
		if(n%5== 0 && n>0) {
			m_topFile << endl; }
		m_topFile << OpepFunctions::getFortranFloat( OpepFunctions::deg2rad( dihedralParam.pn ) );
		n++;
	}
	m_topFile << endl;
}

void OpepInputParamWriter::printDetails(vector<int> vector)
{
	int n(0);
	for(int number: vector)
	{
		if(n%12 == 0 && n>0) {
			m_topFile << endl; }
		m_topFile << setw(6) << number;
		n++;
	}
	m_topFile << endl << endl;
}

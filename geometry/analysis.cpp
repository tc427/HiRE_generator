#include "analysis.hpp"

using namespace std ;

template< typename Type >
void printVector( vector< Type > vec, bool first=true)
{
	bool firstElement(true);

	if(first) {
		cout << "dic = "; }
	cout << "[" ;

	for(typename std::vector< Type >::size_type i = 0; i != vec.size(); i++) {
		if(firstElement) {
			firstElement = false;
		} else {
			cout << "," ;}
		cout << vec[i] ;
	}

	cout << "]" ;
}


template<typename Type>
void printVector(vector< vector< Type > > vec, bool first=true)
{
	bool firstElement(true);

	if(first) {
		cout << "dic = "; }
	cout << "[" ;

	for(typename vector< vector<Type> >::size_type i = 0; i != vec.size(); i++) {
		if(firstElement) {
			firstElement = false;
		} else {
			cout << "," ;}
		printVector(vec[i], false) ;
	}

	cout << "]" ;
}

template<typename Type1, typename Type2>
void printVector(map< Type1 , Type2 > vec, bool first=true)
{
	bool firstElement = true;

	if(first) {
		cout << "dic = "; }
	cout << "{";
	for (typename map< Type1 , Type2 >::iterator it=vec.begin(); it!=vec.end(); ++it)
	{
		if(firstElement) {
			firstElement = false;
		} else {
			cout << ","; }
		cout << it->first  << " : ";
		printVector(it->second, false);
	}
	cout << "}" << endl ;
}

Analysis::Analysis()
{
	lastAtom["A"] = "A2";
	lastAtom["C"] = "C1";
	lastAtom["T"] = "T1";
	lastAtom["G"] = "G2";
	lastAtom["U"] = "U1";
}

Analysis::Analysis(Molecule mol) : moleculeToAnalyse(mol)
{
	lastAtom["A"] = "A2";
	lastAtom["C"] = "C1";
	lastAtom["T"] = "T1";
	lastAtom["G"] = "G2";
	lastAtom["U"] = "U1";
}

void Analysis::plotAntiSyn()
{
	map<int, vector<float> > results;
	vector<Residue> residues = moleculeToAnalyse.getResidues();

	for (vector<Residue>::iterator residue=residues.begin(); residue!=residues.end(); ++residue) {
		string resType = residue->getType();
		if(resType == "A" or resType == "G")
		{
			if(residue->hasAtom("CA") and
			   residue->hasAtom("CY") and
			   residue->hasAtom(resType + "1") and
			   residue->hasAtom(resType + "2") )
			{

				results[residue->getNumber()] = dihedrals( residue->getAtom("CA"),
													   	  residue->getAtom("CY"),
														  residue->getAtom(resType + "1"),
													      residue->getAtom(resType + "2") );
			}
		}
	}

	printVector(results);
	pythonPlotAntiSyn();
 }

void Analysis::plotBasesEcarts()
{
	map<int, vector<int> > result;
	vector<Residue> residues = moleculeToAnalyse.getResidues();

	for (vector<Residue>::iterator itResidue1=residues.begin(); itResidue1!=residues.end(); ++itResidue1 )
	{
		int nResidue1 = itResidue1->getNumber();
		result[nResidue1] = getClosestBases(*itResidue1);
	}

	printVector(result);
	pythonPlotBasesEcarts();
}

vector<int> Analysis::getClosestBases(Residue residue)
{
	Atom lastAtom1 = residue.getAtom(lastAtom[residue.getType()]);
	int nFrame = lastAtom1.getCoordinates().size();
	vector<int> result;
	vector<Residue> residues ( moleculeToAnalyse.getResidues() );

	for (int frame(0); frame<nFrame; frame++)
	{
		int mini;
		int closestResidue (-1);

		for(vector<Residue>::iterator itResidue=residues.begin(); itResidue!=residues.end(); ++itResidue)
		{
			if(residue.getNumber() != itResidue->getNumber())
			{
				if(residue.hasAtom(lastAtom[residue.getType()]) and
				   itResidue->hasAtom(lastAtom[itResidue->getType()]))
				{
					int d = dist(residue.getAtom(lastAtom[residue.getType()]).getCoordinates()[frame],
									 itResidue->getAtom(lastAtom[itResidue->getType()]).getCoordinates()[frame]);
					if (d<mini or closestResidue==-1)
					{
						mini = d;
						closestResidue = itResidue->getNumber();
					}
				}
			}
		}
		result.push_back(closestResidue);
	}


	return result;

}

void Analysis::pythonPlotAntiSyn()
{
	cout << "from matplotlib.lines import Line2D" << endl;
	cout << "import pylab # the matlab-like interface of matplotlib import numpy" << endl;
	cout << "import numpy" << endl << endl;
	cout << "import math" << endl << endl;

	cout << "for resNumber in dic:" << endl;
	cout << "	angles = dic[resNumber]" << endl;
	cout << "	values,bins=numpy.histogram(angles,bins=36)" << endl;
	cout << "	pylab.bar(left=bins[:-1],height=values,width=10);" << endl;
	cout << "	pylab.xlim( (0,360) )" << endl;
	cout << "	pylab.title('Residue number '+str(resNumber))" << endl;
	cout << "	pylab.savefig(str(resNumber)+'.png')" << endl;
	cout << "	pylab.clf()" << endl;
	cout << "for resNumber in dic:" << endl;
	cout << "	angles = dic[resNumber]" << endl;
	cout << "	values,bins=numpy.histogram(angles,bins=36)" << endl;
	cout << "	pylab.bar(left=bins[:-1],height=[ math.log(v)  if v!=0 else 0 for v in values] ,width=10);" << endl;
	cout << "	pylab.xlim( (0,360) )" << endl;
	cout << "	pylab.title('Residue number '+str(resNumber))" << endl;
 	cout << "	pylab.savefig('log_'+str(resNumber)+'.png')" << endl;
	cout << "	pylab.clf()" << endl;
	cout << "for resNumber in dic:" << endl;
	cout << "	angles = dic[resNumber]" << endl;
	cout << "	rad_angles = [elem*(numpy.pi/180) for elem in angles]" << endl;
	cout << "	values,bins=numpy.histogram(rad_angles,bins=36)" << endl;
	cout << "	pylab.axes(polar=True);" << endl;
	cout << "	pylab.bar(left=bins[:-1],height=values,width=2*numpy.pi/36);" << endl;
	cout << "	pylab.title('Residue number '+str(resNumber))" << endl;
	cout << "	pylab.savefig('polar_'+str(resNumber)+'.png')" << endl;
	cout << "	pylab.clf()" << endl;
	cout << "for resNumber in dic:" << endl;
	cout << "	angles = dic[resNumber]" << endl;
	cout << "	rad_angles = [elem*(numpy.pi/180) for elem in angles]" << endl;
	cout << "	values,bins=numpy.histogram(rad_angles,bins=36)" << endl;
	cout << "	pylab.axes(polar=True);" << endl;
	cout << "	pylab.bar(left=bins[:-1],height=[ math.log(v)  if v!=0 else 0 for v in values] ,width=2*numpy.pi/36);" << endl;
	cout << "	pylab.title('Residue number '+str(resNumber))" << endl;
	cout << "	pylab.savefig('polar_log_'+str(resNumber)+'.png')" << endl;
	cout << "	pylab.clf()" << endl;
}


void Analysis::pythonPlotBasesEcarts()
{
	cout << "from matplotlib.lines import Line2D" << endl;
	cout << "import pylab # the matlab-like interface of matplotlib import numpy" << endl;
	cout << "import numpy" << endl;
	cout << "import math" << endl;
	cout << "import os" << endl << endl;

	cout << "try:" << endl;
	cout << "	os.makedirs('basesEcarts')"<< endl;
	cout << "except:"<< endl;
	cout << "	pass"<< endl;

	cout << "for resNumber in dic:" << endl;
	cout << "	y = dic[resNumber]" << endl;
	cout << "	pylab.plot(range(len(y)), y)" << endl;
	cout << "	pylab.savefig('basesEcarts/'+str(resNumber)+'.png')" << endl;
	cout << "	pylab.clf()" << endl;

	cout << "for resNumber in dic:" << endl;
	cout << "	y = dic[resNumber]" << endl;
	cout << "	values,bins=numpy.histogram(y,bins=36)" << endl;
	cout << "	pylab.bar(left=bins[:-1],height=values);" << endl;
	cout << "	pylab.savefig('basesEcarts/hist'+str(resNumber)+'.png')" << endl;
	cout << "	pylab.clf()" << endl;
	cout << "	pylab.clf()" << endl;
}

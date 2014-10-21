#include "analysis.hpp"

using namespace std ;

Analysis::Analysis()
{
	
}

Analysis::Analysis(Molecule mol) : moleculeToAnalyse(mol)
{
	
}

void Analysis::plotAntiSyn()
{
	cout << "dic = {" << endl;
	
	bool first(true);
		
	for (map<string, Chain>::const_iterator it=moleculeToAnalyse.getChains().begin(); it!=moleculeToAnalyse.getChains().end(); ++it) {
		Chain chain = it->second;
		for (map<int, Residue>::const_iterator it2=chain.getResidues().begin(); it2!=chain.getResidues().end(); ++it2) {
			Residue residue = it2->second;
			string resType = residue.getType();
			if(resType == "A" or resType == "G")
			{
				if(residue.hasAtom("CA") and
				   residue.hasAtom("CY") and
				   residue.hasAtom(resType + "1") and
				   residue.hasAtom(resType + "2") )
				{
						
					if(first) {
						first = false;
					} else {
						cout << "," << endl; }
					cout << residue.getNumber() << " : " ;
					printVector(dihedrals( residue.getAtom("CA"),
										   residue.getAtom("CY"), 
										   residue.getAtom(resType + "1"), 
										   residue.getAtom(resType + "2") ));			
				}
			}
		}
	}
	cout << "}" << endl << endl;
		
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

void Analysis::printVector(vector<float> vec)
{
	bool first(true);
	
	cout << "[" ;
	
	for(std::vector<float>::size_type i = 0; i != vec.size(); i++) {
		if(first) {
			first = false; 
		} else {
			cout << "," ;}
		cout << vec[i] ;
	}
	
	cout << "]" ;
}

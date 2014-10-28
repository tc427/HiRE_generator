#include "xtcParser.hpp" 

#include <sstream>
//#include <netinet/in.h> // for ntohl function

using namespace std;


XtcParser::XtcParser()
{
	
}

void XtcParser::readXtcFile(string path)
{
	
}

/*void XtcParser::readXtcFileWhitoutGromacsLibrary(string path)
{
	ifstream file(path.c_str(), ios::in | ios::binary);  // on ouvre le file en lecture

	if(file)  // si l'ouverture a réussi
	{   
		int x;
		file.read((char*)&x, sizeof(int));
		cout << ntohl(x) << endl;
		file.read((char*)&x, sizeof(int));
		cout << ntohl(x) << endl;
		file.read((char*)&x, sizeof(int));
		cout << ntohl(x) << endl;
		file.close();  // on ferme le file
	}
	else  // sinon
	{
		cerr << "Impossible d'ouvrir le file !" << endl;
	}
}*/

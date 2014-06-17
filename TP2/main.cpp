#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "process.hpp"
#include "common.hpp"
#include "dictionary.hpp"
#include "NetworkElementClass.hpp"
#include "cmdline.h"
#include "options.hpp"

using namespace std;

istream *iss = 0;
ostream *oss = 0;
fstream ifs, ofs;
extern option_t options[];
extern string network_element_type[];

/**** MAIN ****/

int main(int argc,char *argv[])
{
//OPTIONS AND ARGUMENTS VALIDATION
	cmdline cmdl(options);
	cmdl.parse(argc, argv);

	string str, aux;
	string NetName;
    getline(*iss,str);
    istringstream ifss(str);

//NetworkName
    if(getNetName(ifss, NetName)==false){
        cerr << "error: missing NetworkName" << endl;
        return 1;
    }

//Vector of NetworkElements
    size_t line=1;
    vector <NetworkElement> v;
    size_t i=0;

    while( getline(*iss,str) )
    {
        line++;
        istringstream ifss(str);
        ifss >> aux;

    //Wrong text
        if(aux!="NetworkElement" && aux!= "Connection"){
            cerr << "error: unknown parameter "<< aux <<" at line: " << line << endl;
            return 1;
        }
    //Setting Up the vector
        if(aux=="NetworkElement"){
            if(processVector( ifss, v, i))return 1;
        }

    //Setting Up the Connections
       if(aux=="Connection"){
        if(processConnections(ifss, v))return 1;
       }
    }
    //Printing out the topology
    ofs << "NetworkName "<<NetName << endl;
    for(size_t i=0; i< v.size(); i++)
        v[i].showElements(*oss);
    for(size_t i=0; i< v.size(); i++)
        v[i].showConnections(*oss);

	//Find hub1----
	size_t rootPosition=FindRoot(v);

	//Wrong connections or loops detected
	v.data()[rootPosition].validateIconnection(v.size());
	v.data()[rootPosition].isRepeaten(v);
	v.data()[rootPosition].validateCycle();
    return 0;
}

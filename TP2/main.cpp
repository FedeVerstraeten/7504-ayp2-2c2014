#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include"common.hpp"
#include "dictionary.hpp"
#include "process.hpp"
#include "NetworkElementClass.hpp"
#include "cmdline.h"
#include "options.hpp"
#include <vector>
#include <algorithm>

using namespace std;

istream *iss_net = 0;
istream *iss_faults =0;
ostream *oss_net = 0;
ostream *oss_faults = 0;
fstream ifs_net, ifs_faults, ofs_net, ofs_faults;
extern option_t options[];
extern string network_element_type[];
extern string network_faults[];

string getNetName(string);
bool NetworkElementType(string);
size_t line=0;
/**** MAIN ****/

int main(int argc,char *argv[])
{
//OPTIONS AND ARGUMENTS VALIDATION
	cmdline cmdl(options);
	cmdl.parse(argc, argv);

	string str, str2, aux;
	string NetName;


/***************TOPOLOGY***************************/
    getline(*iss_net,str);
    istringstream ifs_nets(str);

//NetworkName
    if(getNetName(ifs_nets, NetName)==false){
        cerr << "error: missing NetworkName" << endl;
        return 1;
    }
//Vector of NetworkElements
    line=1;
    vector <NetworkElement> v;
    size_t i=0;

    while( getline(*iss_net,str) )
    {
        line++;
        istringstream stream_net(str);
        stream_net >> aux;

    //Wrong text
        if(aux!="NetworkElement" && aux!= "Connection"){
            cerr << "error: unknown parameter "<< aux <<" at line: " << line << endl;
            return 1;
        }
    //Setting Up the vector
        if(aux=="NetworkElement"){
            if(processVector( stream_net, v, i))return 1;
        }

    //Setting Up the Connections
       if(aux=="Connection"){
        if(processConnections(stream_net, v))return 1;
       }
    }
//ACA IMPRIME SEGUN EL ORDEN DEL ARREGLO ENTONCES SE DEBERIA IMPRIMIR SEGUN LA JERARQUIA ..!!!111
            *oss_net << "NetworkName "<<NetName << endl;
            for(size_t i=0; i< v.size(); i++)
				v[i].showElements(*oss_net);
            for(size_t i=0; i< v.size(); i++)
				v[i].showConnections(*oss_net);

/***************LOOPS***********************/
	//Encuentro el hub1----
	if(v.size()){
	    size_t rootPosition=FindRoot(v);
	//Empieza las validaciones de ciclos e inconexiones

//	cout<<v.data()[rootPosition].getName()<<endl;
	v.data()[rootPosition].validateIconnection(v.size());
	v.data()[rootPosition].isRepeaten(v);
	v.data()[rootPosition].validateCycle();
	}
/*****************************************************/

/***************FAULTS**********************/

    line=0;

    while( getline(*iss_faults,str2) )
    {
        line++;
        istringstream stream_faults(str2);
        cout<<processFaults(stream_faults, v)<<endl;

    }

/******************************************/

            return 0;
}

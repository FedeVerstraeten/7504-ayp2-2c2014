#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include"file_load.hpp"
#include"common.hpp"
#include "printers.hpp"
#include "dictionary.hpp"
#include "process.hpp"
#include "arguments.hpp"
#include "NetworkElementClass.hpp"
#include "cmdline.h"
#include "options.hpp"
#include <vector>
#include <algorithm>

using namespace std;

istream *iss = 0;
ostream *oss = 0;
fstream ifs, ofs;
extern option_t options[];
extern string network_element_type[];

string getNetName(string);
bool NetworkElementType(string);
/**** MAIN ****/

int main(int argc,char *argv[])
{
//OPTIONS AND ARGUMENTS VALIDATION
	cmdline cmdl(options);
	cmdl.parse(argc, argv);

    string **lines; //este lo usa loadFileMemory()
	size_t number_lines; //este lo usa loadFileMemory()
	status_t f_; //estos se usan
	string str, str1, str2, str3;
	string NetName;

//NetworkName
    getline(ifs,str);
    NetName=getNetName(str);
        if(NetName=="error: missing NetworkName"){
                cerr << NetName << endl;
                cout << NetName << endl;
                return 0;
                }

//Vector of NetworkElements
    vector <NetworkElement> v;
    size_t i=0;

    while( getline(ifs,str) )
    {
            cout << "getline("<<i<<") = "<< str << endl;
            v.push_back(NetworkElement());
    //Setting Up the vector: NetworkElements
            string aux;
            istringstream iss(str);
            iss >> aux;

            //Wrong text
            if(aux!="NetworkElement" && aux!= "Connection")
            {
                cerr << "error: unknown parameter "<< aux << endl;
                //delete all memory assigned
                return 0;
            }

            if(aux=="NetworkElement")
            {
                iss >> aux;
                v[i].setName(aux);
                iss >> aux;
                if(!NetworkElementType(aux)){
                        cerr << "error: unrecognized Networkelement " << aux << endl;
                        return 0;
                }
                v[i].setType(aux);
                v[i].showContent();
                i++;
            }


    //Setting Up the Connections
            if(aux=="Connection") //Connection CM1 Amp1
            {
                cout << "Acá hay que conectar los elementos" << endl;
                /*
                NetworkElement* N1, N2;
                iss >> aux;
                N1=v.find(aux);//N1 is the son
                iss >> aux;
                N2=v.find(aux);
                N1.connectToElement(N2);
                */
            }

    }
            return 1;
}


string getNetName(string str)
/*getNetName() valida el primer string
del archivo de entrada, que ya es asignado
como string previamente. */
{
    string aux;
    istringstream iss(str);
    iss >> aux;
    if(aux=="NetworkName"){
        iss >> aux;
        return aux;
        }
    else
        return "error: missing NetworkName";
}


#define NET_TYPES 4
bool NetworkElementType(string aux)
{
    for( size_t i=0;i<NET_TYPES;i++){
        if(aux==network_element_type[i])
            return true;
    }
    return false;
}

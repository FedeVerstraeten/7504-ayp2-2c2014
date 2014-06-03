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
bool isName(NetworkElement , string );

string getNetName(string);
bool NetworkElementType(string);
int binaryNameSearch(vector <NetworkElement>, int , int , string );
/**** MAIN ****/

int main(int argc,char *argv[])
{
//OPTIONS AND ARGUMENTS VALIDATION
	cmdline cmdl(options);
	cmdl.parse(argc, argv);

//NetworkName
	string str;
	string NetName;
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
            //  cout << "getline("<<i<<") = "<< str << endl;
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
                v.push_back(NetworkElement());
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
            iss >> aux;
            int son=binaryNameSearch(v,0,v.size(), aux);
            cout << aux << " es v["<<son<<"] con ";
            iss >> aux;
            int father=binaryNameSearch(v,0,v.size(),aux);
            cout<< aux<<" padre v["<<father << "]"<<endl;
            }

    }

            return 1;
}

bool isName(NetworkElement n, string s)
{
    if(n.getName()==s) return true;
    else return false;
}

int binaryNameSearch(vector <NetworkElement> v, int min, int max, string Name)
{
    if(min>max)return -1;
    else{
        int mid = (min+max)/2;
        if(Name==v[mid].getName())return mid;
        else{
            if(Name<v[mid].getName())return binaryNameSearch(v,mid+1, max, Name);
            else return binaryNameSearch(v,min,mid-1, Name);
        }
    }
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

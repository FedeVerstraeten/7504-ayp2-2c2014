#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include"common.hpp"
#include "printers.hpp"
#include "dictionary.hpp"
#include "process.hpp"
#include "NetworkElementClass.hpp"
#include "cmdline.h"
#include "options.hpp"
#include <vector>


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

//NetworkName
	string str;
	string NetName;
    getline(*iss,str);

    NetName=getNetName(str);
        if(NetName=="error: missing NetworkName"){
                cerr << NetName << endl;
                //cout << NetName << endl;
                return 1;
                }
    size_t line=1;

//Vector of NetworkElements
    vector <NetworkElement> v;
    size_t i=0;

    while( getline(*iss,str) )
    {
            line++;
        //Setting Up the vector: NetworkElements
            string aux;
            istringstream iss(str);
            iss >> aux;

        //Wrong text
            if(aux!="NetworkElement" && aux!= "Connection")
            {
                cerr << "error: unknown parameter "<< aux <<" at line: " << line << endl;
                //delete all memory assigned
                return 1;
            }

            if(aux=="NetworkElement")
            {
                v.push_back(NetworkElement());
                iss >> aux;

                v[i].setName(aux);
                iss >> aux;
                if(!NetworkElementType(aux)){
                        cerr << "error: unrecognized Networkelement " << aux << endl;
                        return 1;
                }
                v[i].setType(aux);
                v[i].showContent(ofs);
                i++;
            }


        //Setting Up the Connections
            if(aux=="Connection")
            {
                string aux1, aux2;
                size_t i1, i2;
                bool son=false,father=false;
                iss >> aux1;
                iss >> aux2;
                for(size_t i=0; i<v.size();i++)
				{
                    if(v[i].getName()==aux1)
					{
						i1=i; 
						if(son==false){son=true;}
						else {son=false;}
					}
                    if(v[i].getName()==aux2)
					{
						i2=i; 	
						if(father==false){father=true;}
						else {father=false;}
                	}
				}
                if(son==false) 
				{
					cout << "Son node isn't found or multiple found"<<endl
						 << aux <<" Error at line: " << line << endl;
				}
                if(father==false)
				{
					cout << "Father node isn't found or multiple found"<<endl
						 << aux <<" Error at line: " << line << endl;
				}                
				//cout <<"index of son= "<<i1 <<" and index of father= "<<i2 <<endl;
                if(son==true && father==true)
                    v[i2].connectToElement(v[i1]);

            }

    }
/*	ofs << "NetworkName "<<NetName << endl;
	for(size_t i=0; i< v.size(); i++){
	v[i].showContent(ofs);
            }*/

	//Encuentro el hub1---- 
	//Empieza las validacionesd de ciclos e inconexiones
	size_t rootPosition=FindRoot(v);
//	cout<<v.data()[rootPosition].getName()<<endl;		
	v.data()[rootPosition].validateIconnection(v.size());
	v.data()[rootPosition].isRepeaten(v);
	v.data()[rootPosition].validateCycle();
	


     
            return 0;
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

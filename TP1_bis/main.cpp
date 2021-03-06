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
ostream *oss_net = 0;
fstream ifs_net, ofs_net;
unsigned int configThreshold=0; //inicializo en cero

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
        return PROGRAM_SHUT;
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
            return PROGRAM_SHUT;
        }
    //Setting Up the vector
        if(aux=="NetworkElement"){
            if(processVector( stream_net, v, i))return PROGRAM_SHUT;
        }

    //Setting Up the Connections
       if(aux=="Connection"){
        if(processConnections(stream_net, v))return PROGRAM_SHUT;
       }
    }
//ACA IMPRIME SEGUN EL ORDEN DEL ARREGLO ENTONCES SE DEBERIA IMPRIMIR SEGUN LA JERARQUIA ..!!!111
        *oss_net << "NetworkName "<<NetName << endl;
        for(size_t i=0; i< v.size(); i++)
            v[i].showElements(*oss_net);
        for(size_t i=0; i< v.size(); i++)
            v[i].showConnections(*oss_net);

/***************LOOPS***********************/
	// Encuentro el Hub y realizo
	// validaciones sobre el arbol construido

	if(v.size())
    {
	    size_t rootPosition=FindRoot(v);
	    bool tree_ok=true;
	//Empieza las validaciones de ciclos e inconexiones

    //	cout<<v.data()[rootPosition].getName()<<endl;
        tree_ok=v.data()[rootPosition].validateIconnection(v.size());
        tree_ok=v.data()[rootPosition].isRepeaten(v);
        tree_ok=v.data()[rootPosition].validateCycle();

        if(tree_ok==false) return PROGRAM_SHUT;
	}
/****************** SET THRESHOLD **************/
// Si el programa llega hasta aqui, el arbol esta ok.
// Paso a inicializar el umbral de inferencia de fallas.
// Los elementos contruidos vienen por defecto en 5.
    if(configThreshold)
    {
        // El programa ingresa unicamente si se ingreso
        // un valor de umbral por linea de argumentos,
        // sino se deja el valor por defecto que carga
        // los constructores, que es 5 (cinco).
        // confiThreshold esta inicializado en 0 (cero).

        for(size_t i=0; i< v.size(); i++)
            v[i].setThreshold(configThreshold);
    }
/***************FAULTS**********************/
/*
    line=0;
    int v_pos=0;

    while( getline(*iss_faults,str2) )
    {
        // A medida que voy leyendo linea a linea por la entrada del
        // archivo de fallas, voy procesando y luego imprimiendo (?
        line++;
        istringstream stream_faults(str2);
        v_pos=processFaults(stream_faults, v);

        if(v_pos==ERROR_PROCESS)
        {
            cerr << "error at line: " << line << endl;

            return PROGRAM_SHUT; // ¡¡REVISAR ESTO!!
        }

        else
            v[v_pos].showStatus(*oss_faults);
    }
*/
/******************************************/

    return EXIT_SUCCESS;
}

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
//#include <vector>
#include <algorithm>
#include "TableHash.hpp"

using namespace std;

istream *iss_net = 0;
istream *iss_faults =0;
ostream *oss_net = 0;
ostream *oss_faults = 0;
fstream ifs_net, ifs_faults, ofs_net, ofs_faults;
unsigned int configThreshold=0; //inicializo en cero

extern option_t options[];
extern string network_element_type[];
extern string network_faults[];

string getNetName(string);
bool NetworkElementType(string);
size_t line=0;
NetworkElement *root=NULL;


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
//Tabla Hash of NetworkElements
    line=1;
    TableHash t_hash(500);

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
            if(processVector(stream_net, t_hash))return PROGRAM_SHUT;
        }

    //Setting Up the Connections
       if(aux=="Connection"){
        if(processConnections(stream_net, t_hash))return PROGRAM_SHUT;
       }
    }
//ACA IMPRIME SEGUN EL ORDEN DEL ARREGLO ENTONCES SE DEBERIA IMPRIMIR SEGUN LA JERARQUIA ..!!!111
        *oss_net << "NetworkName "<<NetName << endl;
        root->PrintElements();
        root->Printconnection();

/***************LOOPS***********************/
	// Encuentro el Hub y realizo
	// validaciones sobre el arbol construido

	if(t_hash.getTableSize())
    {
	    bool tree_ok=true;
	//Empieza las validaciones de ciclos e inconexiones

        tree_ok=root->validateIconnection(t_hash.getTableSize());
        if(tree_ok==false) return PROGRAM_SHUT;

        tree_ok=root->validateCycle();
        if(tree_ok==false) return PROGRAM_SHUT;


	}
/*
***************** SET THRESHOLD *************
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
*/

/***************FAULTS**********************/

    line=0;
    NetworkElement *NetElem=NULL;

    while( getline(*iss_faults,str2) )
    {
        // A medida que voy leyendo linea a linea por la entrada del
        // archivo de fallas, voy procesando y luego imprimiendo (?
        line++;
        istringstream stream_faults(str2);
        NetElem=processFaults(stream_faults, t_hash);

        if(NetElem==NULL)
        {
            cerr << "error at line: " << line << endl;

            return PROGRAM_SHUT; // ¡¡REVISAR ESTO!!
        }

        else
            NetElem->showStatus(*oss_faults);
    }

/***************hashing******************/
/*
TableHash t_hash(3);
NetworkElement N1("CM1","CM");
NetworkElement N2("CM2","CM");
NetworkElement N3("CM3","CM");

t_hash.insert(N1);
t_hash.insert(N2);
t_hash.insert(N3);
*/
/******************************************/

    return EXIT_SUCCESS;
}

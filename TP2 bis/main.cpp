#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

#include "common.hpp"
#include "dictionary.hpp"
#include "process.hpp"
#include "NetworkElementClass.hpp"
#include "cmdline.h"
#include "options.hpp"
#include "TableHash.hpp"
#include "NodeTable.hpp"

using namespace std;

istream *iss_net = 0;
istream *iss_faults =0;
ostream *oss_net = 0;
ostream *oss_faults = 0;
fstream ifs_net, ifs_faults, ofs_net, ofs_faults;
unsigned int configThreshold=5; //inicializo en cero valormpor defecto

extern option_t options[];
extern string network_element_type[];
extern string network_faults[];

string getNetName(string);
bool NetworkElementType(string);
size_t line=0;
string root_name=" ";


/**** MAIN ****/

int main(int argc,char *argv[])
{
//OPTIONS AND ARGUMENTS VALIDATION
	cmdline cmdl(options);
	cmdl.parse(argc, argv);

	string str, str2, aux;
	string NetName;

	NodeTable *nodeRoot=NULL;
    NetworkElement rootElement;


/***************TOPOLOGY***************************/
    getline(*iss_net,str);
    istringstream ifs_nets(str);

//NetworkName
    if(getNetName(ifs_nets, NetName)==false)
    {
        cerr << "error: missing NetworkName" << endl;
        return EXIT_PROGRAM;
    }
//Tabla Hash of NetworkElements
    line=1;
    TableHash t_hash(BUCKETS_DEFAULT);

    while( getline(*iss_net,str) )
    {
        line++;
        istringstream stream_net(str);
        stream_net >> aux;

    //Wrong text
        if(aux!="NetworkElement" && aux!= "Connection"){
            cerr << "error: unknown parameter "<< aux <<" at line: " << line << endl;
            return EXIT_PROGRAM;
        }
    //Setting Up the vector
        if(aux=="NetworkElement"){
            if(processVector(stream_net, t_hash))return EXIT_PROGRAM;
        }

    //Setting Up the Connections
       if(aux=="Connection"){
        if(processConnections(stream_net, t_hash))return EXIT_PROGRAM;
       }
    }

   // Busco la raiz (root) en la tabla, en este caso el hub

    nodeRoot=t_hash.searchNode(root_name);

    if(nodeRoot!=NULL) rootElement=nodeRoot->getElement();

    else
    {
        cerr<<"Root not exist"<<endl;
        return EXIT_PROGRAM;
    }

/***************LOOPS***********************/
	// Encuentro el Hub y realizo
	// validaciones sobre el arbol construido

	if(t_hash.getNumElements())
    {
	    bool tree_ok=true;
	//Empieza las validaciones de ciclos e inconexiones

        tree_ok=rootElement.validateIconnection(t_hash.getNumElements());
        if(tree_ok==false) return EXIT_PROGRAM;

        tree_ok=rootElement.validateCycle();
        if(tree_ok==false) return EXIT_PROGRAM;


	}

/***************PRINTS**********************/
// Si el arbol esta ok, imprimo por el flujo de salida los elementos
// y las conexiones recorriendo en profundid el arbol construido en
// memoria desde la raiz (root).
    cout<<"ahora imprimiendo"<<endl;
    *oss_net << "NetworkName "<<NetName << endl;
    rootElement.PrintElements();
    rootElement.Printconnection();


/***************FAULTS**********************/
    cout<<"iniciado gestor de fallas"<<endl;
    line=0;
    NetworkElement *NetElem=NULL;

    while( getline(*iss_faults,str2) )
    {
        // A medida que voy leyendo linea a linea por la entrada del
        // archivo de fallas, voy procesando y luego imprimiendo
        line++;
        istringstream stream_faults(str2);
        NetElem=processFaults(stream_faults, t_hash);

        if(NetElem==NULL)
        {
            cerr << "error at line: " << line << endl;

            return EXIT_PROGRAM; // ¡¡REVISAR ESTO!!
        }

        else
            NetElem->showStatus(*oss_faults);
    }

    return EXIT_SUCCESS;
}

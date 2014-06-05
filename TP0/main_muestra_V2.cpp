/**************************************************************************************************
Viernes 11 de Abril de 2014.
TP0 - Algoritmos II - Cátedra Calvo

Docentes: Lucio Santi, Leandro Santi

Federico Verstraeten <federico.verstraeten@gmail.com>
Cristian Zozimo Aranda Cordero <cristian.pinky@gmail.com>
Carlos Carreño Romano <-------------------------dsdsds-d-s-d-s-ds->
Título: NOMBRE DEL  TP

NOTA:

***************************************************************************************************/


/**** BIBLIOTECAS ****/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include"file_load.hpp"
#include"common.hpp"
#include"printers.hpp"
#include"dictionary.hpp"
#include"process.hpp"
#include"arguments.hpp"

int number_of_elements[5];
/**** DEFINICIONES ****/
#define SIG_ARG_POS 1
#define CHAR_VOID 0

using namespace std;
#include <sstream>



#define MAX_LINES_DEFAULT 100



//Prototipos

void uploadLine(string, string **);

void printLine(string);

void processLine(string);

void printElements(int *, ostream&);
void printNetworkName(string, ostream&);
//int  searchNetworkName(string**);


//Diccionarios: HAY QUE ACORDAR UNA NOMNECLATURA PARA STRINGS , VARIABLES y ARREGLOS.
string network_struct[]   = {"NetworkName","NetworkElement","Connection"};

string network_element_type[] = {"Hub","Node","Amp","CM"};
string network_element_nam[MAX_LINES_DEFAULT];


int number_of_elements[5];// = {"Number_of_Hubs","Number_of_Nodes", "Number_of_Amps","Number_of_CM", "Number_of_Connections"};

static size_t   n=0;// i=0;


/**** PROTOTIPOS ****/

status_t read_argument(const char  arg[]);
status_t route_verification(char arg[],char** route);
void close_all_stream_file(ifstream& ,ofstream& );
int validateArgument(int argc,char *argv[],char* &route_in,char* &route_out);

/**** MAIN ****/

int main(int argc,char *argv[])
{
	char *route_in=NULL, *route_out=NULL;
	string **lines;
	size_t number_lines;
	size_t i;
	int f_;

	f_=validateArgument(argc,argv,route_in,route_out);

	if(f_==1)
	{
		ifstream file_in (route_in); //Flujo archivo file_in, abierto
		ofstream file_out (route_out,ios_base::out);//Flujo archivo file_out, abierto
		loadFileMemory(file_in,&lines,number_lines);     
	
		printNetworkName((*lines[0]),file_out); // esta tiene el contenido del nombre de la red
		for(i=1;i<number_lines;i++)   
			processLine((*lines[i]));

		printElements(number_of_elements, file_out); 
		close_all_stream_file(file_in,file_out);
		eraseFileMemory(&lines,number_lines);
	}
	else
	{
		cout<<"Error: no se pudieron abrir los stream correctamente"<<endl;
		if(route_in==NULL)
			cout<<"Error: stream entrada falso"<<endl;
		if(route_out==NULL)
			cout<<"Error: stream salida falso"<<endl;
	}
	
	return 0;
}

/**************************************************************************************************
TP - Algoritmos II - Lic. Calvo
Jueves 8 de Mayo 2014

Docentes:
    Lucio Santi, Leandro Santi
Alumnos:
    Carlos Carreno Romano <charlieromano@gmail.com>
    Federico Verstraeten <federico.verstraeten@gmail.com>
    Cristian Zozimo Aranda Cordero <cristian.pinky@gmail.com>

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

/**** MAIN ****/


int main(int argc,char *argv[])
{
	char *route_in=NULL, *route_out=NULL;
	string **lines;
	size_t number_lines;
	size_t i;
	status_t f_, status;
	ifstream file_in;


	f_=validateArgument(argc,argv,route_in,route_out);

	if(f_==OK)
	{
		file_in.open( route_in ); //Flujo archivo file_in, abierto
		if (!file_in.is_open())
                {
			printErrorMessage(ERROR_INVALID_INPUT_ROUTE,cout);
			return 1;
                }


		ofstream file_out ( route_out , ios_base::out );//Flujo archivo file_out, abierto
		loadFileMemory( file_in , &lines , number_lines );

		printNetworkName( (*lines[0]) , file_out) ; // esta tiene el contenido del nombre de la red
		for( i=1 ; i<number_lines ; i++ )
			processLine( (*lines[i]) );

		printElements( number_of_elements , file_out );
		close_all_stream_file( file_in , file_out );
		eraseFileMemory( &lines , number_lines );
	}

	if(f_==OK_INPUT_CIN)
	{
        inputFromConsole();
        printElements( number_of_elements , cout );
	}

	else
	{
        printErrorMessage(f_,cout);
        return ERROR_ARG;
	}
    return 0;
}



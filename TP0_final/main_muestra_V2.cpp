/**************************************************************************************************
Lunes 28 de Abril de 2014.
TP0 - Algoritmos II - Cátedra Calvo

Docentes:
    Lucio Santi, Leandro Santi
Alumnos:
    Carlos Carreño Romano <charlieromano@gmail.com>
    Federico Verstraeten <federico.verstraeten@gmail.com>
    Cristian Zozimo Aranda Cordero <cristian.pinky@gmail.com>
NOTA:
    Modifique arguments.cpp. Hay que corregir las validaciones.
    El programa no debe terminar si encuentra errores?
    Agregue mas tipos para status_t y las impresiones de errores.

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
	int f_;

	f_=validateArgument(argc,argv,route_in,route_out);

	if(f_==OK)
	{
		ifstream file_in ( route_in ); //Flujo archivo file_in, abierto
		ofstream file_out ( route_out , ios_base::out );//Flujo archivo file_out, abierto
		loadFileMemory( file_in , &lines , number_lines );

		printNetworkName( (*lines[0]) , file_out) ; // esta tiene el contenido del nombre de la red
		for( i=1 ; i<number_lines ; i++ )
			processLine( (*lines[i]) );

		printElements( number_of_elements , file_out );
		close_all_stream_file( file_in , file_out );
		eraseFileMemory( &lines , number_lines );
	}
	else
	{
	    status_t status;
		cout<<"Error: no se pudieron abrir los stream correctamente"<<endl;
		if(route_in==NULL)
			cout<<"Error: stream entrada falso"<<endl; //QUE ES FALSO?
		if(route_out==NULL)
           printErrorMessage(status=ERROR_STREAM_OUT,cout);
           //aca no tiene que terminar el programa?
	}

	return 0;
}

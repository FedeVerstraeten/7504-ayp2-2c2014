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
#include"NetworkElementClass.hpp"


/**** MAIN ****/


int main(int argc,char *argv[])
{

    char *route_in=NULL, *route_out=NULL;
	string **lines;
	size_t number_lines;
	size_t i;
	status_t f_, status;
	ifstream file_in;
	string st1, st2;

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

		for( i=1 ; i<number_lines ; i++ )
		{
            status = processLine( (*lines[i]), st1, st2);
            if(status==OK_NETWORK_TYPE)
            {
                NetworkElement Net0(st1,st2);
                Net0.showContent();
                cout<<"FLAG"<<endl;
                //Crear objeto (aux[0]=name, aux[1]=type);
                //Asignar al vector de Objetos
            }
            if(status==OK_NETWORK_NAME)//aca se supone que ya se crearon TODOS los objetos necesarios
            {
                cout<<"FLAG 2"<<endl;
                //buscar name 1
                //buscar name 2
                //Estan OK los nombres? (si estan mal, destruir todo y salir)
                //Crear conexiones(aux[0]=name1, aux[1]=name2);
            }
            if(status==ERROR_TEXT_LINE_INVALID)
            {
                cout<<"FLAG 3"<<endl;
                //Delete todo lo creado para que no haya fugas de memoria
                //Imprimo errores
                //final del programa
            }
		}


	//	printElements( number_of_elements , file_out );
		close_all_stream_file( file_in , file_out );
		eraseFileMemory( &lines , number_lines );
	}

	if(f_==OK_INPUT_CIN)
	{
	    string aux, line;
	    string net_name;
	    getline(cin, line);
        istringstream iss(line);
        iss >> aux;

            if(aux == "NetworkName")
            {
                status = OK_NETNAME;
                iss >> aux;
                net_name=aux;
            }
            else
            {
                cout << "error: missing NetworkName" << "\n";
                return ERROR_NETNAME;
            }


        inputFromConsole();
        cout << net_name << endl;
//        printElements( number_of_elements , cout );
	}

	else
	{
        printErrorMessage(f_,cout);
        return ERROR_ARG;
	}


}

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include"file_load.hpp"
#include"common.hpp"
#include "printers.hpp"
#include "dictionary.hpp"
#include "process.hpp"
#include "arguments.hpp"
#include "NetworkElementClass.hpp"
#include "cmdline.h"
#include "options.hpp"

istream *iss = 0;
ostream *oss = 0;
fstream ifs;
fstream ofs;

extern option_t options[];

/**** MAIN ****/

int main(int argc,char *argv[])
{

	cmdline cmdl(options);
	cmdl.parse(argc, argv);

    string **lines; //este lo usa loadFileMemory()
	size_t number_lines; //este lo usa loadFileMemory()
	status_t f_, status; //estos se usan
	string st1, st2;

	loadFileMemory( ifs , &lines , number_lines );

		for( size_t i=1 ; i<number_lines ; i++ )
		{
            status = processLine( (*lines[i]), st1, st2);
            if(status==OK_NETWORK_TYPE)
            {
                cout << st1 << st2 << endl;
                NetworkElement Net0[i](st1,st2);
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

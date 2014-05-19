#include"arguments.hpp"
#include"common.hpp"

/**** FUNCIONES ****/

status_t read_argument(char const arg[])
{

		/*  Todos los parámetros de este programa deben
            pasarse en forma de opciones, con el prefijo '-'.
            Encontrar un
            parámetro no-opción es un error.
		*/

		if (arg[0]== '-')
		{
            if(arg[1]=='i' && arg[2]==CHAR_VOID)
			//Con CHAR_VOID verifico que no se ingresen cosas como "-increible" y lo
			//valide, es decir el caracter seguid de "-i" sea vacio o blanco.
                return OK_INPUT;

            else if(arg[1]=='o' && arg[2]==CHAR_VOID)
                return OK_OUTPUT;


		}

    return ERROR_INVALID_ARGUMENT; //Consideramos que deberìa ir ERROR_INVALID_OPTION
}

status_t route_verification(char arg[],char* &route)
{
    if (string(arg)=="/dev/null")
	// Valida como caso particular que la entrada sea /dev/null
    {
        return ERROR_NULL_FILE;
    }
    if ( string(arg)=="-") //{cout<<"Se pide cin\n";
        return OK_INPUT_CIN;//}
	else route=arg;

    return OK_ROUTE_NAME;
    //ACA DETALLAR QUE TIPO DE ERROR ES, AGREGARLO A COMMON.HPP Y AGREGAR
    //EL CASE ARG_ERR EN printErrorMessage() en PRINTERS.CPP/HPP
}

void close_all_stream_file(ifstream &file_in, ofstream &file_out)
{
    file_in.close();
    file_out.close();
}


status_t validateArgument(int argc,char *argv[],char* &route_in,char* &route_out)
{
	if(argc==1) return ERROR_NO_ARGS;
	//Salvo caso en que no se ingresen argumentos, ejemplo ./programa.exe <vacìo>

    status_t status;


   	for (int i = 1; i < argc; ++i)
	{

		status=read_argument(argv[i]);

    	if((status!=OK_INPUT) && (status!=OK_OUTPUT)) return status;
		//validacion contra '-i' y '-o', salva por ejemplo '-increible'

		if(status==OK_INPUT && (i+1)!=argc)
        {
			status=route_verification(argv[i+1],route_in);
            if(status!=OK_ROUTE_NAME) return status;

			else i+= SIG_ARG_POS;
            //El argumento siguiente debe contener la ruta del archivo, lo valido y lo apunto con la varuiable route
        }

        else if(status==OK_OUTPUT && (i+1)!=argc)
        {
			status=route_verification(argv[i+1],route_out);
            if(status!=OK_ROUTE_NAME) return status;

			else i+= SIG_ARG_POS;
        }


    }
	// Si el ciclo finaliza correctamente, la verificacion de los argumentos fue 		// exitosa.

    if(route_in!=NULL && route_out!=NULL)return OK; // Esta linea VERY IMPORTANT es la que verifica que las rutas (apertura de archivo)
													// esten cargadas. El funciona con las dos rutas cargadas: -i hfif -o hbasd.




//-------------------------------------------------------------------------------------

		/*antes de salir se puede validar -i -*/


/*
struct noop {
    void operator()(...) const {}
};

// ...

shared_ptr<istream> input;
if (filename == "-")
    input.reset(&cin, noop());
else
    input.reset(new ifstream(filename.c_str()));
*/

//-------------------------------------------------------------------------------------


	return ERROR_ROUTE_NAME_INVALID;
}



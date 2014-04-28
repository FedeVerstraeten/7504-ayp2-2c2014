#include"arguments.hpp"


/**** FUNCIONES ****/

status_t read_argument(char const arg[])
{

		// Todos los parámetros de este programa deben
		// pasarse en forma de opciones. Encontrar un
		// parámetro no-opción es un error.
		//
		if (arg[0]== '-')
		{
            if(arg[1]=='i' && arg[2]==CHAR_VOID) //Con CHAR_VOID verifico que no se ingresen cosas como "-increible" y lo
                return OK_INPUT;            //valide, es decir el caracter seguid de "-i" sea vacio o blanco.
                //cout<<"entrada\n";
            else if(arg[1]=='o' && arg[2]==CHAR_VOID)
                return OK_OUTPUT;
                //cout<<"salida\n";

		}


    return ARG_ERR;
}

status_t route_verification(char arg[],char** route)
{
    if (arg[0]!= '-')
    {
        (*route)=arg; //Dejo apuntando route al string que posee el nombre de la ruta
        //ESTO ESTA MEDIO RARO. CUAL SERIA EL EJEMPLO DE USO?
        return ARG_OK;
    }

    return ARG_ERR;
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

   	for (int i = 1; i < argc; ++i)
	{
		if(read_argument(argv[i])==OK_INPUT && (i+1)!=argc)
        {
            if(route_verification(argv[i+1],&route_in)!=ARG_ERR)
                i+= SIG_ARG_POS;
            //El argumento siguiente debe contener la ruta del archivo, lo valido y lo apunto con la varuiable route
            else    return ERROR_INVALID_INPUT_ROUTE;
        }

        else if(read_argument(argv[i])==OK_OUTPUT && (i+1)!=argc)
        {
            if(route_verification(argv[i+1],&route_out)!=ARG_ERR)
                i+= SIG_ARG_POS;
            else    return ERROR_INVALID_OUTPUT_ROUTE;
        }

        else //if (read_argument(argv[i])==ARG_ERR)
            return ERROR_INVALID_ARG;
    }

    return OK;
}




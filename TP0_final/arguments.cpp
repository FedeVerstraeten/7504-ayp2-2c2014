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
            if(arg[1]=='i' && arg[2]==CHAR_VOID) //Con CHAR_VOID verifico que no se ingresen cosas como "-increible" y lo
                return OK_INPUT;            //valide, es decir el caracter seguid de "-i" sea vacio o blanco.
                //cout<<"entrada\n";
            else if(arg[1]=='o' && arg[2]==CHAR_VOID)
                return OK_OUTPUT;
                //cout<<"salida\n";

		}
		else if(string(arg)=="/dev/null")
		{
            cout<<"End Of File\n";
            return ERROR_NULL_FILE;
		}

    return ERROR_INVALID_ARGUMENT;
}

status_t route_verification(char arg[],char* &route)
{
    if (arg == NULL) //Valida que el nombre de la ruta no comience con el guión, utilizado para las opciones
    {
        return ERROR_NULL_POINTER;
    }


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

    status_t status;


   	for (int i = 1; i < argc; ++i)
	{
	    status=read_argument(argv[i]);
	    if((status!=OK_INPUT) && (status!=OK_OUTPUT)) return status;//validacion contra '-i' y '-o', salva por ejemplo '-increible'

		if(status==OK_INPUT && (i+1)!=argc)
        {
            if(route_verification(argv[i+1],route_in)==OK_ROUTE_NAME)
                i+= SIG_ARG_POS;
            //El argumento siguiente debe contener la ruta del archivo, lo valido y lo apunto con la varuiable route
            else    return ERROR_INVALID_INPUT_ROUTE;
        }

        else if(status==OK_OUTPUT && (i+1)!=argc)
        {
            if(route_verification(argv[i+1],route_out)==OK_ROUTE_NAME)
                i+= SIG_ARG_POS;
            else    return ERROR_INVALID_OUTPUT_ROUTE;
        }

        else //if (read_argument(argv[i])==ARG_ERR)
        return ERROR_ARG;
    }

    return OK;
}



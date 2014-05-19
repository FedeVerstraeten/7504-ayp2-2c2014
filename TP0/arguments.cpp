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
        return ARG_OK;
    }

    return ARG_ERR;
}

void close_all_stream_file(ifstream &file_in, ofstream &file_out)
{
    file_in.close();
    file_out.close();
}


int validateArgument(int argc,char *argv[],char* &route_in,char* &route_out)
{
	if(argc==1) 
	{
		cout<<"Error: no hay argumentos"<<endl;
		return 0;
	}
   	for (int i = 1; i < argc; ++i)
	{
		if(read_argument(argv[i])==OK_INPUT && (i+1)!=argc)
        	{
        
		if(route_verification(argv[i+1],&route_in)!=ARG_ERR) i = i + SIG_ARG_POS;
		//El argumento siguiente debe contener la ruta del archivo, lo valido y lo apunto con la varuiable route
        
		else
		{
		    cerr << "Ruta entrada inválida: "
		         << argv[i+1]
		         << endl;
		     //break;
		     return 0;
		 }

        }

        else if(read_argument(argv[i])==OK_OUTPUT && (i+1)!=argc)
        {
            if(route_verification(argv[i+1],&route_out)!=ARG_ERR) i = i + SIG_ARG_POS;

            else
            {
                cerr << "Ruta salida inválida: "
                 << argv[i+1]
                 << endl;
                //break;
		return 0;
            }

        }

        else //if (read_argument(argv[i])==ARG_ERR)
        {
            cerr << "Argumento inválido: "
			     << argv[i]
			     << endl;
            //break;
	    return 0;
        }

    }
    
    return 1;	
}




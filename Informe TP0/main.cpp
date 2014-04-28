
#include"common.hpp"

/**** DEFINICIONES ****/
#define SIG_ARG_POS 1
#define CHAR_VOID 0

using namespace std;





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

static size_t   n=0, i=0;


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

    if(f_==1)//route_in!=NULL && route_out!=NULL
    {
        ifstream file_in (route_in); //Flujo archivo file_in, abierto

        ofstream file_out (route_out,ios_base::out);//Flujo archivo file_out, abierto

       load_file_memory(file_in,&lines,number_lines);
	cout<< "Funciono el hibrido wachin jaja alto programa loro ahh y tenes " <<number_lines <<endl;
       /* for(i=0;i<number_lines;i++){
                file_out<<*lines[i]<<endl;
        }
	*/
	printNetworkName((*lines[0]),file_out); // esta tiene el contenido del nombre de la red
    	for(i=1;i<number_lines;i++)    processLine((*lines[i]));

    	printElements(number_of_elements, file_out);     //esta funcion printElements() es la que se encarga de la salida por pantalla.

	 close_all_stream_file(file_in,file_out);

    }
    else
    {
        cout<<"Error: no se pudieron abrir los stream correctamente"<<endl;
        if(route_in==NULL)
            cout<<"Error: stream entrada falso"<<endl;
        if(route_out==NULL)
            cout<<"Error: stream salida falso"<<endl;


    }
	erase_file_memory(&lines,number_lines);

	return 0;

}


/**** FUNCIONES ****/

status_t read_argument(char const arg[])
{

		// Todos los parametros de este programa deben
		// pasarse en forma de opciones. Encontrar un
		// parametro no-opcion es un error.
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



void uploadLine(string line, string** lines_array)
{

            lines_array[n]=new string;

            (*lines_array[n])=line;

            printLine((*lines_array[n]));

            n++;

}





void processLine(string text_line)
{

    istringstream iss(text_line);
    string word[3];

    iss >> word[0];
    if(word[0]==network_struct[1])
    {
        iss >> word[1];
        iss >> word[2];
        size_t i;
        for(i=0;i<4;i++)
        {
         if(word[2]==network_element_type[i]) number_of_elements[i]++;
        }
    }
    if(word[0]==network_struct[2])   number_of_elements[4]++;


}


void printLine(string line)
{

    cout << line << "\n";

}
/*
int  searchNetworkName(string* lines_array)
{

}*/

void printNetworkName(string name_line, ostream& os)
//esta funcion asume que se le pasa un string
//que contiene "NetworkName <nombre>",
//donde nombre es el nombre a imprimir
{
    string aux, network_name;
    istringstream iss(name_line);
    iss >> aux;
    if(aux == network_struct[0])
    {
        iss >> network_name;
        os << network_name << "\n";
    }
    else     cout << "no hay nombre de red" << "\n";
}


void printElements(int number_of_elements[], ostream& os)
{

	os << number_of_elements[0] << " Hubs"<<"\n";

	os << number_of_elements[1] << " Nodes"<<"\n";

	os << number_of_elements[2] << " Amps"<<"\n";

	os << number_of_elements[3] << " CMs"<<"\n";
	os << number_of_elements[4] << " Connections"<<"\n";

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
		    cerr << "Ruta entrada invalida: "
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
                cerr << "Ruta salida invalida: "
                 << argv[i+1]
                 << endl;
                //break;
		return 0;
            }

        }

        else //if (read_argument(argv[i])==ARG_ERR)
        {
            cerr << "Argumento invalido: "
			     << argv[i]
			     << endl;
            //break;
	    return 0;
        }

    }

    return 1;
}




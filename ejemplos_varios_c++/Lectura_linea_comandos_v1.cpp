/**************************************************************************************************
Domingo 06 de Marzo de 2014.
TP0 - Algoritmos II - Cátedra Calvo

Docentes: Lucio Santi, Leandro Santi

Federico Verstraeten <federico.verstraeten@gmail.com>

Título: Lectura mediante línea de comandos para apertura de archivos - utilización de argc y argv

NOTA:
El código siguiente a sido implementado de tipo monolítico, su objetivo es ralizar la lectura de la
línea de comandos de ordenes, y luego de su procesamiento y validación realizar la apertura de los
flujos de entrada y salida de archivos (stream), para que a posteriori sea procesado por los algorit-
mos de pasaje a memoria realizador por el Sr. Crisitan Aranda Cordero.
El código está funcional, es su primera versión probada. Se debe realizarle pruebas, ordenarlo y de-
purar errores que se puedan encontrar.
La sitaxis e implementación no se ha relizado siguiento los lineamientos del lenguaje C++ y está más
adaptado a cuestiones de C.

No dude en revisar y marcar los errores o mejores que considere.

Un cordial saludo.

***************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

/**** DEFINICIONES ****/
#define SIG_ARG_POS 1
#define CHAR_VOID 0

using namespace std;

typedef enum {OK_INPUT,OK_OUTPUT,ARG_ERR,ARG_OK}status_t;

/**** PROTOTIPOS ****/

status_t read_argument(const char  arg[]);
status_t route_verification(char arg[],char** r);


/**** MAIN ****/

int main(int argc,char *argv[])
{
    char *route_in=NULL, *route_out=NULL;
    string palabra;

    for (int i = 1; i < argc; ++i)
	{
	    if(read_argument(argv[i])==OK_INPUT)
        {
            if(route_verification(argv[i+1],&route_in)!=ARG_ERR) //El argumento siguiente debe contener la ruta del
            {                                                 //archivo, lo valido y lo apunto con la varuiable route
                i = i + SIG_ARG_POS;
            }
            else
            {
                cerr << "Ruta entrada inválida: "
			     << argv[i+1]
			     << endl;
                break;
            }

        }

        else if(read_argument(argv[i])==OK_OUTPUT)
        {
            if(route_verification(argv[i+1],&route_out)!=ARG_ERR)
            {
               i = i + SIG_ARG_POS;
            }
            else
            {
                cerr << "Ruta salida inválida: "
                 << argv[i+1]
                 << endl;
                break;
            }

        }

        else if (read_argument(argv[i])==ARG_ERR)
        {
            cerr << "Argumento inválido: "
			     << argv[i]
			     << endl;
            break;
        }

    }

    if(route_in!=NULL && route_out!=NULL)
    {
        ifstream file_in (route_in); //Flujo archivo file_in, abierto

        ofstream file_out (route_out,ios_base::out);//Flujo archivo file_out, abierto

        /*
        Código utilizado para hacer pruebas

        file_in>>palabra;                        Cargo en memoria la 1º líena del archivo
        cout<<palabra<<endl;                     La muestro por el stardard_output
        file_out<<palabra;                       Cargo la palabra al archivo de salida
        file_out<<"\nSalida super exitosa\n";    Un mensaje buena onda =)
        */

        file_in.close();
        file_out.close();
    }
	return 0;

}


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

status_t route_verification(char arg[],char** r)
{
    if (arg[0]!= '-' && arg[1]!=CHAR_VOID)
    {
        (*r)=arg; //Dejo apuntando route al string que posee el nombre de la ruta
        return ARG_OK;
    }

    return ARG_ERR;
}

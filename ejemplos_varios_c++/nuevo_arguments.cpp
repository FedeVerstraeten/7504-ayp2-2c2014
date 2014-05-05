//#include"arguments.hpp"

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
//#include <cmdline.h>

#define EXIT_SUCCESS	0
#define	EXIT_FAILURE	1
#define OPT_DEFAULT		0
#define OPT_SEEN		1

using namespace std;

static void opt_input(string const &);
static void opt_output(string const &);
static void opt_help(string const &);

/********************************************************* Clases y estructuras ********************************************************/


struct option_t 
{
	int has_arg;						// Cantidad de argumentos que acompañan la opción
	const char *short_name;				// Nombre corto, ejemplo i (entrada), o (salida)
	//const char *long_name;
	const char *def_value;				// En caso de recibir el símbolo (ej: "-" o NULL) selecciona opción por default
	void (*parse)(std::string const &); // Puntero a función de opciones. Las funciones reciben un string (por línea de comandos) como parametro
	int flags;
};

class cmdline 
{
	private:
	// Este atributo apunta a la tabla que describe todas
	// las opciones a procesar. Por el momento, sólo puede
	// ser modificado mediante contructor, y debe finalizar
	// con un elemento nulo.

		option_t *option_table;

	// El constructor por defecto cmdline::cmdline(), es
	// privado, para evitar construir "parsers" (analizador 
	// sintáctico, recibe una palabra y lo interpreta en 
	// una acción dependiendo su significado para el programa) 
	// sin opciones. Es decir, objetos de esta clase sin opciones.

		cmdline();

	// Estos métodos son privados ya que no se debería acceso desde
	// el main, otra función o método, a como se recorre la tabla de
	// opciones segundo lo ingresado por línea de comandos, que es el
	// objetivo de estos métodos.

	//	int do_long_opt(const char *, const char *);
		int do_short_opt(const char *, const char *);
	
	public:
		cmdline(option_t *);
		void parse(int, char * const []);
};


/********************************************************** Definición de los métodos ***************************************************/

cmdline::cmdline() { }


cmdline::cmdline(option_t *table)
{
	option_table = table;

	/*
	Siendo "option_table" un atributo de la clase cmdline
	y table un puntero al objeto o struct de "option_t".
	
	Se estaría contruyendo una instancia de la clase cmdline
	cargandole los datos que se hayan en table.
	*/
}


void cmdline::parse(int argc, char * const argv[])
{
#define END_OF_OPTIONS(p)	((p)->short_name == 0 /*&& (p)->long_name == 0*/ && (p)->parse == 0)
	if(argc==1)
	{
		cerr<<"Error: Invocación sin argumentos"<<endl;
		exit(EXIT_FAILURE);
	}	

	// Primer pasada por la secuencia de opciones: marcamos 
	// todas las opciones, como no procesadas. Ver código de
	// abajo.

	for (option_t *op = option_table; !END_OF_OPTIONS(op); ++op)
		op->flags &= ~OPT_SEEN; 
		// OPT_SEEN == 1; pone los flags en 0.

	// Recorremos el arreglo argv. En cada paso, vemos
	// si se trata de una opción corta, o larga. Luego,
	// llamamos a la función de parseo correspondiente.


	for (int i = 1; i < argc; ++i) 
	{
		// Todos los parámetros de este programa deben
		// pasarse en forma de opciones (prefijo '-'). 
		// Encontrar un parámetro no-opción es un error.
		
		if (argv[i][0] != '-') 
		{
			//Error por falta de argumentos

			cerr << "Invalid non-option argument: "
			     << argv[i]
			     << endl;
			exit(EXIT_FAILURE);
		}
	
		// Usamos "--" para marcar el fin de las
		// opciones; todo los argumentos que puedan
		// estar a continuación no son interpretados
		// como opciones.

		if (argv[i][1] == '-' && argv[i][2] == 0) break;

		// Finalmente, vemos si se trata o no de una
		// opción larga; y llamamos al método que se
		// encarga de cada caso.

		if (argv[i][0] == '-') 
			i += do_short_opt(&argv[i][1], argv[i + 1]);
	//	else
	//		i += do_long_opt(&argv[i][1], argv[i + 1]);
	
	}

	// Segunda pasada: procesamos aquellas opciones que:
	// (1) no hayan figurado explícitamente en la línea 
	// de comandos, y 
	// (2) tengan valor por defecto.

	for (option_t *op = option_table; !END_OF_OPTIONS(op); ++op)
	{
	//#define OPTION_NAME(op) (op->short_name ? op->short_name : op->long_name)
		
		if (op->flags & OPT_SEEN)	continue;

	/*
		En nuestro caso no se utilizará pero sería útil en
		donde es obligatorio el pasaje de un argumento a
		continuación de la opción. Ejemplo factor: -f 78 o
		-factor 78, el número es oligatorio.	

		if (op->flags & OPT_MANDATORY)
		{
			cout << "Option "
			     << "-"
			     << OPTION_NAME(op)
			     << " is mandatory."
			     << "\n";
			exit(EXIT_FAILURE);
		}

	*/
		if (op->def_value == 0)		continue;

		// Pasa a la función 'parse', de la estructura option_t, la opción por defecto ("-" o "NULL")
		op->parse(string(op->def_value));	
	}
}


int cmdline::do_short_opt(const char *opt, const char *arg) // *opt=="i" || *opt=="o"
{
	option_t *op;

	// Recorremos la tabla de opciones, y buscamos la
	// entrada corta que se corresponda con la opción de 
	// línea de comandos. De no encontrarse, indicamos el
	// error.
	
	for (op = option_table; op->short_name != 0; ++op) 
	{
		if (string(opt) == string(op->short_name)) 
		{
			// Marcamos esta opción como usada en
			// forma explícita, para evitar tener
			// que inicializarla con el valor por
			// defecto, haciendo lo siguiente:

			op->flags |= OPT_SEEN; // Seteo en 1 el flag

			if (op->has_arg == 1) 
			{
				// Como se trata de una opción
				// con argumento, verificamos que
				// el mismo haya sido provisto.
				
				if (arg == 0) 
				{
					cerr << "Option requires argument: "
					     << "-"
					     << opt
					     << "\n";
					exit(EXIT_FAILURE);
				}

				// Paso el argumento que acompaña a la opción para que se procese
				op->parse(string(arg)); 

				return 1;
			} 
			else 
			{
				// Opción sin argumento. Ejemplo: caso help o -h

				op->parse(string(""));
				return 0;
			}
		}
	}

	// Error: opción no reconocida. Imprimimos un mensaje
	// de error, y finalizamos la ejecución del programa.
	
	cerr << "Unknown option: "
	     << "-"
	     << opt
	     << endl;
	exit(EXIT_FAILURE);

	// Algunos compiladores se quejan con funciones que 
	// lógicamente no pueden terminar, y que no devuelven
	// un valor en esta última parte.

	return -1; // Podría ser otro valor que no sea -1 (?)
}


/********************************************************** Elementos globales *********************************************************/

/*
	Tabla (vector) de opciones del tipo option_t (posee 4 elementos)

	Describe las opciones a procesar:
	{ <Cantidad de argumentos>, <Tipo de opción>, <Valor para funcionar por defecto>, <Función de la opción>, <Flag: opción ingresada/defecto> }
*/
static option_t options[] = {
	{1, "i",/* "input",*/ "-", opt_input, OPT_DEFAULT},
	{1, "o",/* "output",*/ "-", opt_output, OPT_DEFAULT},
	{0, "h",/* "help",*/ NULL, opt_help, OPT_DEFAULT},
	{0, },
};

static istream *iss = 0;	// Input Stream (clase para manejo de los flujos de entrada)
static ostream *oss = 0;	// Output Stream (clase para manejo de los flujos de salida)
static fstream ifs; 		// Input File Stream (derivada de la clase ifstream que deriva de istream para el manejo de archivos)
static fstream ofs;			// Output File Stream (derivada de la clase ofstream que deriva de ostream para el manejo de archivos)



/******************************************* Funciones de la estructura de opciones (tabla) ********************************************/


static void opt_input(string const &arg) //AVERIGUAR: NO DEBERRÍAN SER STATIC SI SE VAN A LLAMAR DESDE OTRO ARCHIVO QUE NO SE EL MAIN (?)
{
	// Si el nombre del archivos es "-", usaremos la entrada
	// estándar. De lo contrario, abrimos un archivo en modo
	// de lectura.

	if (arg == "-") iss = &cin;		// Establezco la entrada estandar cin como flujo de entrada
	
	else 
	{
		ifs.open(arg.c_str(), ios::in); // c_str(): Returns a pointer to an array that contains a null-terminated 
		iss = &ifs;						// sequence of characters (i.e., a C-string) representing 
										// the current value of the string object.
	}

	// Verificamos que el stream este OK.
	// (iss->good)==0 si no hubo errores y se pudo abrir el stream

	if (!iss->good()) 
	{
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(EXIT_FAILURE);
	}
}

static void opt_output(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la salida
	// estándar. De lo contrario, abrimos un archivo en modo
	// de escritura.

	if (arg == "-") oss = &cout;	// Establezco la salida estandar cout como flujo de salida
	
	else 
	{
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	// Verificamos que el stream este OK.

	if (!oss->good()) {
		cout << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(EXIT_FAILURE);		// Terminación del programa?
	}
}

static void opt_help(string const &arg)
{
	cout << "cmdline  [-i file] [-o file] or [-o file] [-i file]"
	     << endl;

	exit(EXIT_SUCCESS);
}

/*********************************************** MAIN DE PRUEBA ***********************************************************/



int main(int argc, char * const argv[])
{
	cmdline cmdl(options);	// Objeto (struct) de la clase option_t declarado globalmente.
	cmdl.parse(argc, argv);
	
}






/******************************************************************************************************************************/


/**** FUNCIONES ****/
/*

status_t read_argument(char const arg[])
{

		/*  Todos los parámetros de este programa deben
            pasarse en forma de opciones, con el prefijo '-'.
            Encontrar un
            parámetro no-opción es un error.
		

		if (arg[0]== '-')
		{
            if(arg[1]=='i' && arg[2]==CHAR_VOID) //Con CHAR_VOID verifico que no se ingresen cosas como "-increible" y lo
                return OK_INPUT;            //valide, es decir el caracter seguid de "-i" sea vacio o blanco.
                //cout<<"entrada\n";
            else if(arg[1]=='o' && arg[2]==CHAR_VOID)
                return OK_OUTPUT;
                //cout<<"salida\n";

		}


    return ERROR_ARG;
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
         
			route_in = argv[i+1];        	     
			i+= SIG_ARG_POS;
        }

        else if(read_argument(argv[i])==OK_OUTPUT && (i+1)!=argc)
        {

 			route_out = argv[i+1];        	                  
			i+= SIG_ARG_POS;

        }

        else 
            return ERROR_INVALID_ARGUMENT;
    }

    return OK;
}
*/

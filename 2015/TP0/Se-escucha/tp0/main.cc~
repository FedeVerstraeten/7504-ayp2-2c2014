// ------------------------------------------------------------------------- //
// Facultad de Ingeniería de la Universidad de Buenos Aires
// Algoritmos y Programación II
// 1° Cuatrimestre de 2015
// Trabajo Práctico 0: Programación en C++
// 
// main1.cc
// Versión sin clase Buffer
// ------------------------------------------------------------------------- //

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include "complex.h"
#include "cmdline.h"
using namespace std;


#define DECIMATOR1_SIZE 11
#define DECIMATOR2_SIZE 4

#define FORMAT_OPTIONS 2
#define FORMAT_TEXT "txt"
#define FORMAT_U8 "U8"

/*typedef enum{
				
				FORMAT_OPTION_TEXT=0,
				FORMAT_OPTION_U8=1
				
} format_opt_t;*/

static void opt_input(string const &);
static void opt_output(string const &);
//static void opt_format(string const &);

static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_MANDATORY},
	{1, "o", "output", "-", opt_output, OPT_MANDATORY},
	//{1, "f", "format", "txt", opt_format, OPT_SEEN},
	//{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

// Tienen que ser globales por algún motivo?
// o se pueden declarar dentro del main?
static istream *iss;
static ostream *oss;
//static iss = &cin;
//static oss = &cout;
static fstream ifs;
static fstream ofs;

//format_opt_t format_opt = FORMAT_OPTION_TEXT;

/*string description_format_opt[] = {
	
  FORMAT_OPTION_TEXT,
  FORMAT_OPTION_U8
	
};*/

int main(int argc, char * const argv[])
{
  //- i := 0
  //- j := 0
  //- buffer1 := 0
  //- buffer2 := 0
  size_t i = 0;
  size_t j = 0;
  Complex buffer1 = 0;
  double buffer2 = 0;
  Complex input_complex;
  Complex x, x_prev;
  Complex aux;
  double output_phase;
  x_prev = 0;
  cmdline cmdl(options);
  cmdl.parse(argc, argv);
  
  

  //- Mientras haya complejos en la entrada
  while (*iss >> input_complex)
  {
  //	(Promediar 11 elementos)
  //	- buffer1 := buffer1 + complejo a la entrada
  //	- Si i < 11
  //		- i := i + 1
  //		- Continuar con el ciclo
  //	- x := buffer1 / 11
  //	- buffer1 := 0
  //	- i := 0
    buffer1 += input_complex;
    if (i < DECIMATOR1_SIZE-1) // Agregué el '-1', sino en vez de 11 hacía 12
    {
      i++;
      continue;
    }
    x = buffer1/DECIMATOR1_SIZE;
    buffer1 = 0;
    i = 0;


  //	(Obtener la derivada de la fase)
  //	- aux := x * conjugar(x_prev)
  //	- output_phase := fase(aux)
    aux = x * x_prev.conjugated();
    output_phase = aux.phase();

//    cerr << "output_phase = " << output_phase << endl;

  //	(Avanzar una muestra)
  // x_prev := x
    x_prev = x;


  //	(Promediar 4 elementos)
  //	- buffer2 := buffer2 + output_phase
  //	- Si j < 4
  //		- j := j + 1
  //		- Continuar con el ciclo
  //	- resultado := buffer2 / 4
  //	- buffer2 := 0
  //	- j := 0
    buffer2 += output_phase;
    if (j < DECIMATOR2_SIZE-1) // Lo mismo q en el caso anterior
    {
      j++;
      continue;
    }
    output_phase = buffer2/DECIMATOR2_SIZE;
    buffer2 = 0;
    j = 0;

  //	Esto creo q es solo opcional, en la especifiación dice que la 
  //  salida es (-1, 1)
  //	(LLevar al rango requerido)
  //	- resultado := (resultado + pi)*255/2pi 

  // !!! MAL !!!, cuando hace continue en el control de flujo del
  //              2° promediador no avanza de muestra!!
  //	(Avanzar una muestra)
  // x_prev := x
//    x_prev = x;

    // Esto es temporal, solo para probar:
    //cout << output_phase/3.1416 << endl;
	
	*oss << (unsigned char)((output_phase + 3.14159) * 255 / (2 * 3.14159));
	
  }

  return 0; // Se podrá usar un status_t como hacíamos en C?
}

static void
opt_input(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la entrada
	// estándar. De lo contrario, abrimos un archivo en modo
	// de lectura.
	//
	if (arg == "-") {
		iss = &cin;		// Establezco la entrada estandar cin como flujo de entrada
	}
	else {
		ifs.open(arg.c_str(), ios::in); // c_str(): Returns a pointer to an array that contains a null-terminated
										// sequence of characters (i.e., a C-string) representing
										// the current value of the string object.
		iss = &ifs;
	}

	// Verificamos que el stream este OK.
	//
	if (!iss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void
opt_output(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la salida
	// estándar. De lo contrario, abrimos un archivo en modo
	// de escritura.
	//
	if (arg == "-") {
		oss = &cout;	// Establezco la salida estandar cout como flujo de salida
	} else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	// Verificamos que el stream este OK.
	//
	if (!oss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);		// EXIT: Terminación del programa en su totalidad
	}
}

/*static void
opt_format(string const &arg)
{
  
  for(size_t i=0;i<FORMAT_OPTIONS;i++){
		
    if(arg == description_format_opt[i]){
		
	  format_opt=(format_opt_t)i;
			
	  break;
			
	}
	
  }
	
}*/

/*void
procces_data(const complex &input_complex)
{

  
  
}*/

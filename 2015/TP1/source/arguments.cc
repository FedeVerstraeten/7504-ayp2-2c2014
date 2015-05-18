// ------------------------------------------------------------------------- //
// Facultad de Ingeniería de la Universidad de Buenos Aires
// Algoritmos y Programación II
// 1er Cuatrimestre de 2015
// Trabajo Práctico 1: Recursividad
// Cálculo de DFT
// 
// arguments.cc
// Funciones a llamar para cada opción posible de la aplicación
// ------------------------------------------------------------------------- //

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>

#include "arguments.h"
#include "cmdline.h"
#include "types.h"

using namespace std;


// Opciones de argumentos de invocacion
option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_SEEN},
	{1, "o", "output", "-", opt_output, OPT_SEEN},
	{1, "m", "method", "fft", opt_method, OPT_SEEN},
	{0, },
};

// Nombres de los argumentos de la opcion "--method"
string description_method_option[] = {
	
    METHOD_DFT,
    METHOD_IDFT,
    METHOD_FFT,
    METHOD_IFFT,
    METHOD_FFT_ITER,
    METHOD_IFFT_ITER	
};

istream *iss;
ostream *oss;
fstream ifs;
fstream ofs;
method_option_t method_option;

void
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
		cerr << "Cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

void
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
		cerr << "Cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);		// EXIT: Terminación del programa en su totalidad
	}
}

void
opt_method(string const &arg)
{
  size_t i;
  // Recorremos diccionario de argumentos hasta encontrar uno que coincida
  for(i=0; i < METHOD_OPTIONS; i++) {
    if(arg == description_method_option[i]) {
      method_option = (method_option_t)i; // Casteo
      break;	
    }  
  }
  // Si recorrio todo el diccionario, el argumento no esta implementado
  if (i == METHOD_OPTIONS) {
    cerr << "Unknown format" << endl;
    exit(1);
  }
}

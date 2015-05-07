#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>

#include "arguments.h"
#include "cmdline.h"
#include "types.h"

using namespace std;



option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_SEEN},
	{1, "o", "output", "-", opt_output, OPT_SEEN},
	{1, "m", "method", "fft", opt_method, OPT_SEEN},
	{0, },
};

string description_method_option[] = {
	
    METHOD_DFT,
    METHOD_IDFT,
    METHOD_FFT,
    METHOD_IFFT
	
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
		cerr << "cannot open "
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
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);		// EXIT: Terminación del programa en su totalidad
	}
}

void
opt_method(string const &arg)
{
	
  for(size_t i=0;i<METHOD_OPTIONS;i++){
	  
    if(arg == description_method_option[i]){
		
	  method_option=(method_option_t)i;
	  
	  break;
	
	}
	  
  }
  
  return;
	
}

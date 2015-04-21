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

static void opt_input(string const &);
static void opt_output(string const &);
static void opt_format(string const &);
void print_phase_text(double);
void print_phase_U8(double);

void (*print_phase[])(double) = {
				
				print_phase_text,
				print_phase_U8
				
};

static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_MANDATORY},
	{1, "o", "output", "-", opt_output, OPT_MANDATORY},
	{1, "f", "format", "txt", opt_format, OPT_SEEN},
	{0, },
};

static istream *iss;
static ostream *oss;
static fstream ifs;
static fstream ofs;

format_opt_t format_opt;

string description_format_opt[] = {
	
  FORMAT_TEXT,
  FORMAT_U8
	
};

int main(int argc, char * const argv[])
{
  size_t i = 0;
  size_t j = 0;
  Complex buffer1 = 0;
  double buffer2 = 0;
  Complex x, x_prev;
  Complex aux;
  double output_phase;
  x_prev = 0;

  cmdline cmdl(options);
  cmdl.parse(argc, argv);

  Complex input_complex(format_opt);
  cout<<int(input_complex.format())<<endl;

  while (*iss >> input_complex)
  {
	
    buffer1 += input_complex;
    if (i < DECIMATOR1_SIZE-1)
    {
      i++;
      continue;
    }
    x = buffer1/DECIMATOR1_SIZE;
    buffer1 = 0;
    i = 0;

    aux = x * x_prev.conjugated();
    output_phase = aux.phase();

    x_prev = x;

    buffer2 += output_phase;
    if (j < DECIMATOR2_SIZE-1)
    {
      j++;
      continue;
    }
    output_phase = buffer2/DECIMATOR2_SIZE;
    buffer2 = 0;
    j = 0;
	
	
	(print_phase[format_opt])(output_phase);
	
  }

  return 0;
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

static void
opt_format(string const &arg)
{
  
  for(size_t i=0;i<FORMAT_OPTIONS;i++){
		
    if(arg == description_format_opt[i]){
		
	  format_opt=(format_opt_t)i;
			
	  break;
			
	}
	
  }
  
  return;
	
}

void
print_phase_text(double output_phase)
{
	
  *oss << output_phase/3.14159 << endl;
  
  return;
	
}

void
print_phase_U8(double output_phase)
{
	
  *oss << (unsigned char)((output_phase + 3.14159) * 255 / (2 * 3.14159));
  
  return;
	
}

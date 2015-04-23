// ------------------------------------------------------------------------- //
// Facultad de Ingeniería de la Universidad de Buenos Aires
// Algoritmos y Programación II
// 1° Cuatrimestre de 2015
// Trabajo Práctico 0: Programación en C++
// Demodulación de señal FM
// 
// main.cc
// Archivo principal donde se ejecuta el main.
// ------------------------------------------------------------------------- //

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>

#include "main.h"
#include "complex.h"
#include "cmdline.h"
#include "arguments.h"
#include "utilities.h"
#include "types.h"

using namespace std;


// Colección de funciones para imprimir en formatos distintos
void (*print_phase[])(double) = {
        
  print_phase_text,
  print_phase_U8
        
};

// Opciones de argumentos de invocación
static option_t options[] = {
  {1, "i", "input", "-", opt_input, OPT_SEEN},
  {1, "o", "output", "-", opt_output, OPT_SEEN},
  {1, "f", "format", "txt", opt_format, OPT_SEEN},
  {0, },
};

extern istream *iss;
extern format_option_t format_option;

int
main(int argc, char * const argv[])
{
  size_t i = 0;
  size_t j = 0;
  Complex buffer1 = 0;
  double buffer2 = 0;
  Complex x, x_prev;
  Complex aux;
  double output_phase;

  // Parsear argumentos de invocación
  cmdline cmdl(options);
  cmdl.parse(argc, argv);

  // Inicializar el complejo con el fomato especificado
  Complex input_complex(format_option);
  // cout<<int(input_complex.format_option())<<endl;

  // ( -- Condiciones Iniciales Nulas -- )
  x_prev = 0;

  // Mientras haya complejos en la entrada
  while (*iss >> input_complex)
  {
    // ( -- Promediar 11 elementos -- )
    buffer1 += input_complex;
    if (i < DECIMATOR1_SIZE-1)
    {
      i++;
      continue;
    }
    x = buffer1/DECIMATOR1_SIZE;
    buffer1 = 0;
    i = 0;

    // ( -- Obtener la derivada de la fase -- )
    aux = x * x_prev.conjugated();
    output_phase = aux.phase();

    // ( -- Avanzar una muestra -- )
    x_prev = x;

    // ( -- Promediar 4 elementos -- )
    buffer2 += output_phase;
    if (j < DECIMATOR2_SIZE-1)
    {
      j++;
      continue;
    }
    output_phase = buffer2/DECIMATOR2_SIZE;
    buffer2 = 0;
    j = 0;
  
    // ( -- Imprimir en el formato especificado -- )
    (print_phase[format_option])(output_phase);
  }
  return 0;
} // main

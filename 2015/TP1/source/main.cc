// ------------------------------------------------------------------------- //
// Facultad de Ingeniería de la Universidad de Buenos Aires
// Algoritmos y Programación II
// 1er Cuatrimestre de 2015
// Trabajo Práctico 1: Recursividad
// Cálculo de DFT
// 
// main.cc
// Archivo principal donde se ejecuta el main.
// ------------------------------------------------------------------------- //

#include <iostream>
#include <cstdlib>
#include <sstream>

#include "cmdline.h"
#include "arguments.h"
#include "complex.h"
#include "vector.h"
// En definitiva lo que calculamos en todos los casos es la DFT
// (incluso en el caso de la fft, es un algorítmo para calcular la DFT)
#include "dft_methods.h"
#include "utilities.h"
#include "types.h"

using namespace std;


// Coleccion de funciones para transformar con los distintos métodos
Vector<Complex> (*transform[])(Vector<Complex> const &) = {

    calculate_dft,
	  calculate_idft,
    calculate_fft,
	  calculate_ifft
    calculate_fft_iter,
    calculate_ifft_iter
	 
};

extern option_t options[];
extern istream *iss;
extern ostream *oss;
extern method_option_t method_option;

int main(int argc, char *argv[])
{	
  Complex input_complex;
  Vector<Complex> input;
  Vector<Complex> output;

  // Parsear argumentos de invocacion
  cmdline cmdl(options);
  cmdl.parse(argc, argv);
  
  // Mientras haya complejos a la entrada
  // Cargar vector de entrada
  while(*iss >> input_complex)
  {
    input.push_back(input_complex); 
  }
  
  // Si el tamaño de la entrada no es potencia de 2 se completa con ceros
  //hasta llevarla a la potencia de 2 más cercana (Zero-Padding)
  set_up_input(input);

  // Transformar
  output = (transform[method_option])(input);
  
  // Imprimir por la salida estándar
  for(int i=0; i<output.size(); i++)
  {
    *oss << output[i] << endl; 
  }


  return EXIT_SUCCESS;
  
}

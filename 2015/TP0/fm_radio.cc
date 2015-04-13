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
#include "Complex.h"
using namespace std;

#define DECIMATOR1_SIZE 11
#define DECIMATOR2_SIZE 4

// Tienen que ser globales por algún motivo?
// o se pueden declarar dentro del main?
istream *iss;
ostream *oss;

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

  iss = &cin; // Esto compila. No se si es la forma correcta.
  oss = &cout;

  //(Obtener primer promedio, x_prev)
  //- Repetir 11 veces:
  //	- buffer1 := buffer1 + complejo a la entrada
  //- x_prev := buffer1 / 11
  for(int k=0; k < DECIMATOR1_SIZE; k++)
  {
    *iss >> input_complex; // agregar validación
    buffer1 += input_complex;
  }
  x_prev = buffer1/DECIMATOR1_SIZE;
  buffer1 = 0;
  

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
    if (i < DECIMATOR1_SIZE)
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

  //	(Promediar 4 elementos)
  //	- buffer2 := buffer2 + output_phase
  //	- Si j < 4
  //		- j := j + 1
  //		- Continuar con el ciclo
  //	- resultado := buffer2 / 4
  //	- buffer2 := 0
  //	- j := 0
    buffer2 += output_phase;
    if (j < DECIMATOR2_SIZE)
    {
      j++;
      continue;
    }
    output_phase = buffer2/DECIMATOR2_SIZE;
    buffer2 = 0;
    j = 0;

  //	
  //	(LLevar al rango requerido)
  //	- resultado := (resultado + pi)*255/2pi 

  //	(Avanzar una muestra)
  // x_prev := x
    x_prev = x;
  }

  return 0; // Se podrá usar un status_t como hacíamos en C?
}

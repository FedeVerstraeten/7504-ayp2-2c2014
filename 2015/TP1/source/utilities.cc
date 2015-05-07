// ------------------------------------------------------------------------- //
// Facultad de Ingenieria de la Universidad de Buenos Aires
// Algoritmos y Programacion II
// 1er Cuatrimestre de 2015
// Trabajo Practico 0: Programacion en C++
// Demodulacion de senal FM
// 
// utilities.cc
// Funciones utilitarias para el proposito de la aplicacion
//  - Imprimir en formato texto
//  - Imprimir en formato binario U8
// ------------------------------------------------------------------------- //

#include <iostream>
#include <fstream>
#include <sstream>

#include "utilities.h"

using namespace std;



extern ostream *oss;

// Imprime en el rango [-1, 1] en formato texto (ASCII)
void
print_phase_text(double output_phase)
{
  
  *oss << output_phase/PI << endl;
  
  return;
  
}

// Imprime en el rango [0, 255] en formato U8 (binario)
void
print_phase_U8(double output_phase)
{
  
  *oss << (unsigned char)((output_phase + PI) * 255 / (2 * PI));
  
  return;
  
}

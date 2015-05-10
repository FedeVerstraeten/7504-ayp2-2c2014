// ------------------------------------------------------------------------- //
// Facultad de Ingeniería de la Universidad de Buenos Aires
// Algoritmos y Programación II
// 1° Cuatrimestre de 2015
// Trabajo Práctico 1: Recursividad
// Cálculo de DFT
// 
// utilities.h
// Funciones utilitarias para el propósito de la aplicación
// ------------------------------------------------------------------------- //

#ifndef _UTILITIES_H_INCLUDED_
#define _UTILITIES_H_INCLUDED_

#include <iostream>

#include "complex.h"
#include "vector.h"

void set_up_input(Vector<Complex> &);
Complex pow_complex(Complex const &, size_t);
size_t my_pow(size_t const &, size_t);

#endif

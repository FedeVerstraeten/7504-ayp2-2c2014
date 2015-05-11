// ------------------------------------------------------------------------- //
// Facultad de Ingeniería de la Universidad de Buenos Aires
// Algoritmos y Programación II
// 1° Cuatrimestre de 2015
// Trabajo Práctico 1: Recursividad
// Cálculo de DFT
// 
// dft_methods.h
// Interfaces de los distintos métodos de la transformada.
// ------------------------------------------------------------------------- //

#ifndef _DFT_METHODS_H_
#define _DFT_METHODS_H_

#include <iostream>

#include "complex.h"
#include "vector.h"

#define PI 3.14159265358979323846264338327950

Vector<Complex> calculate_dft(Vector<Complex> const &);
Vector<Complex> calculate_idft(Vector<Complex> const &);
Vector<Complex> calculate_fft(Vector<Complex> const &);
Vector<Complex> calculate_ifft(Vector<Complex> const &);

#endif

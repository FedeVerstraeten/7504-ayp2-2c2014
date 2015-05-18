// ------------------------------------------------------------------------- //
// Facultad de Ingeniería de la Universidad de Buenos Aires
// Algoritmos y Programación II
// 1er Cuatrimestre de 2015
// Trabajo Práctico 1: Recursividad
// Cálculo de DFT
// 
// arguments.h
// Funciones a llamar para cada opcion posible de la aplicacion
// Nombres de los argumentos de la opcion "--format"
// ------------------------------------------------------------------------- //

#ifndef _ARGUMENTS_H_INCLUDED_
#define _ARGUMENTS_H_INCLUDED_

#include <iostream>

#define METHOD_OPTIONS 6
#define METHOD_DFT "dft"
#define METHOD_IDFT "idft"
#define METHOD_FFT "fft"
#define METHOD_IFFT "ifft"
#define METHOD_FFT_ITER "fft-iter"
#define METHOD_IFFT_ITER "ifft-iter"

void opt_input(std::string const &);
void opt_output(std::string const &);
void opt_method(std::string const &);

#endif

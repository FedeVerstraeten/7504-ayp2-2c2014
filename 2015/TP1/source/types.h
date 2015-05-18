// ------------------------------------------------------------------------- //
// Facultad de Ingeniería de la Universidad de Buenos Aires
// Algoritmos y Programación II
// 1° Cuatrimestre de 2015
// Trabajo Práctico 1: Recursividad
// Cálculo de DFT
// 
// types.h
// Tipos definidos para el proposito de la aplicacion
//  - Opciones posibles de métodos de transformada.
// ------------------------------------------------------------------------- //

#ifndef _TYPES_H_INCLUDED_
#define _TYPES_H_INCLUDED_

#include <iostream>

typedef enum{

    METHOD_OPTION_DFT = 0,
    METHOD_OPTION_IDFT = 1,
    METHOD_OPTION_FFT = 2,
    METHOD_OPTION_IFFT = 3,
    METHOD_OPTION_FFT_ITER = 4,
    METHOD_OPTION_IFFT_ITER = 5
	
} method_option_t;

#endif

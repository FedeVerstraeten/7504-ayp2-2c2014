// ------------------------------------------------------------------------- //
// Facultad de Ingenieria de la Universidad de Buenos Aires
// Algoritmos y Programacion II
// 1er Cuatrimestre de 2015
// Trabajo Practico 0: Programacion en C++
// Demodulacion de senal FM
// 
// utilities.h
// Funciones utilitarias para el proposito de la aplicacion
//  - Imprimir en formato texto
//  - Imprimir en formato binario U8
// ------------------------------------------------------------------------- //


#ifndef _UTILITIES_H_INCLUDED_
#define _UTILITIES_H_INCLUDED_

#include <iostream>

#define PI 3.14159265359

// Imprime en el rango [-1, 1] en formato texto (ASCII)
void print_phase_text(double);
// Imprime en el rango [0, 255] en formato U8 (binario)
void print_phase_U8(double);

#endif

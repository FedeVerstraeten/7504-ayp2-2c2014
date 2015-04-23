// ------------------------------------------------------------------------- //
// Facultad de Ingeniería de la Universidad de Buenos Aires
// Algoritmos y Programación II
// 1° Cuatrimestre de 2015
// Trabajo Práctico 0: Programación en C++
// Demodulación de señal FM
// 
// arguments.h
// Funciones a llamar para cada opción posible de la aplicación
// Nombres de los argumentos de la opción "--format"
// ------------------------------------------------------------------------- //

#ifndef _ARGUMENTS_H_INCLUDED_
#define _ARGUMENTS_H_INCLUDED_

#include <iostream>

#define FORMAT_OPTIONS 2
#define FORMAT_TEXT "txt"
#define FORMAT_U8 "U8"

void opt_input(std::string const &);
void opt_output(std::string const &);
void opt_format(std::string const &);

#endif

// ------------------------------------------------------------------------- //
// Facultad de Ingeniería de la Universidad de Buenos Aires
// Algoritmos y Programación II
// 1° Cuatrimestre de 2015
// Trabajo Práctico 1: Recursividad
// Cálculo de DFT
// 
// vector.h
// Interface de la clase Vector
// ------------------------------------------------------------------------- //


#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <cstdlib>
using namespace std;


template <typename T>
class Vector
{
  public:
    Vector();
    Vector(int);
    Vector(const Vector<T> &);
    ~Vector();

    int size() const;
    const Vector<T> &operator=(const Vector<T> &); // operador asignacion
    const T &operator[](int) const;
    T &operator[](int);

    void push_back(const T &); // Alta al final
    void pop_back(); // Baja al final
    
  
  private:
    int size_;
    T *ptr_;
};

// Se incluye el .cc que contiene la implementación para que pueda 
// compilar bien y se mantenga la separación de interface-implementación
// en 2 archivos distintos. Esto se debe al uso de plantillas.
#include "vector.cc"

#endif // _VECTOR_H_

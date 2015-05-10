// ------------------------------------------------------------------------- //
// Facultad de Ingeniería de la Universidad de Buenos Aires
// Algoritmos y Programación II
// 1° Cuatrimestre de 2015
// Trabajo Práctico 1: Recursividad
// Cálculo de DFT
// 
// dft_methods.cc
// Implementación de los distintos métodos de la transformada.
// ------------------------------------------------------------------------- //

#include <iostream>
#include <cmath>

#include "dft_methods.h"
#include "complex.h"
#include "vector.h"
#include "utilities.h"

using namespace std;



Vector<Complex>
calculate_dft(Vector<Complex> const &x)
{
  Complex aux;
  size_t N;
  
  N = x.size();
  
  Vector<Complex> X(N);
  
  Complex W(cos((2*PI)/N),
            -sin((2*PI)/N));
  
  for(size_t k=0;k<N;k++){
	
	for(size_t n=0;n<N;n++){
	  
	  aux += x[n] * pow_complex(W, n*k);
	  
	}
	
	X[k] = aux;
    
	aux = 0;
	  
  }
  
  return X;
	
}

Vector<Complex>
calculate_idft(Vector<Complex> const &X)
{
  
  Complex aux;
  size_t N;
  
  N = X.size();
  
  Vector<Complex> x(N);
  
  Complex W(cos((2*PI)/N),
            -sin((2*PI)/N));
			
  for(size_t k=0;k<N;k++){
	
	for(size_t n=0;n<N;n++){
	  
	  aux += X[n] * (1 / pow_complex(W, n*k));
	  
	}
	
	x[k] = (1.0/N) * aux;
    
	aux = 0;
	  
  }
  
  return x;
  
}


// Algoritmo recursivo para calcular la DFT: FFT
Vector<Complex>
calculate_fft(Vector<Complex> const &x)
{
  size_t N;
  N = x.size();

  Vector<Complex> X(N);
  
  if (N > 1)
  {
    // Suponemos que la entrada es par y potencia de 2
    Vector<Complex> p(N/2);
    Vector<Complex> q(N/2);
    Vector<Complex> P(N/2);
    Vector<Complex> Q(N/2);
    for (size_t i=0; i<N/2; i++)
    {
      p[i] = x[2*i];
      q[i] = x[2*i+1];
    }
 
    P = calculate_fft(p);
    Q = calculate_fft(q);
    
    for (size_t k=0; k<N; k++)
    {
      Complex W(cos(k*(2*PI)/N),
               -sin(k*(2*PI)/N));
      // Para que se repitan los elementos cíclicamente, se utiliza la función módulo
      size_t k2 = k % (N/2);

      X[k] = P[k2] + W*Q[k2];
    } 
  }
  else
  {
    X = x;
  }
  
  return X;
}

  

Vector<Complex>
calculate_ifft(Vector<Complex> const &X)
{
  size_t N;
  N = X.size();

  Vector<Complex> x(N);
  
  if (N > 1)
  {
    // Suponemos que la entrada es par y potencia de 2
    Vector<Complex> p(N/2);
    Vector<Complex> q(N/2);
    Vector<Complex> P(N/2);
    Vector<Complex> Q(N/2);
    for (size_t i=0; i<N/2; i++)
    {
      p[i] = X[2*i];
      q[i] = X[2*i+1];
    }
 
    P = calculate_fft(p);
    Q = calculate_fft(q);
    
    for (size_t k=0; k<N; k++)
    {
      Complex W(cos(k*(2*PI)/N),
               -sin(k*(2*PI)/N));
      // Para que se repitan los elementos cíclicamente, se utiliza la función módulo
      size_t k2 = k % (N/2);

      x[k] = (1.0/N) * ((P[k2] + (1/W)*Q[k2]));
    } 
  }
  else
  {
    x = X;
  }
  
  return x;
  
}

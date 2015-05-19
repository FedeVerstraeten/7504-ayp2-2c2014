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

// ------- DFT --------
// Función genérica para calcular DFT o IDFT
// Oculta al cliente.
// Si el flag "inverse" es "true", se calcula la inversa (IDFT)
// Caso contrario, la DFT
// Algoritmo iterativo para calcular la DFT
// Versión que utiliza función "pow" en cada iteración
static Vector<Complex>
calculate_dft_generic(Vector<Complex> const &x, bool inverse)
{
  Complex aux;
  size_t N;
  
  N = x.size();
  
  // Por defecto se calcula la DFT con estos parámetros:
  double factor = 1;
  int W_phase_sign = -1;

  // En caso de tener que calcular la inversa,
  // modifico el factor de escala y el signo de la fase de W.
  if (inverse)
  {
    factor = 1.0/N;
    W_phase_sign = 1;
  }
  
  Vector<Complex> X(N);
  
  Complex W(cos((2*PI)/N),
            W_phase_sign*sin((2*PI)/N));
  
  for(size_t k=0;k<N;k++) {
    for(size_t n=0;n<N;n++) {
      aux += x[n] * pow_complex(W, n*k);
    }
    X[k] = factor * aux; 
    aux = 0;
  }
  return X;
}

// Máscara para la DFT
// Llama a la función genérica en modo "directa"
Vector<Complex>
calculate_dft(Vector<Complex> const &x)
{
  bool inverse = false;
  return calculate_dft_generic(x, inverse);
}

// Máscara para la IDFT
// Llama a la función genérica en modo "inversa"
Vector<Complex>
calculate_idft(Vector<Complex> const &X)
{
  bool inverse = true;
  return calculate_dft_generic(X, inverse);
}

// ------- FFT --------
// Función genérica para calcular FFT o IFFT
// Oculta al cliente.
// Si el flag "inverse" es "true", se calcula la inversa (IFFT)
// Caso contrario, la FFT
// Algoritmo recursivo para calcular la DFT: FFT
static Vector<Complex>
calculate_fft_generic(Vector<Complex> const &x, bool inverse)
{
  size_t N;
  N = x.size();

  Vector<Complex> X(N);

  // Por defecto se calcula la FFT con estos parámetros:
  double factor = 1;
  int W_phase_sign = -1;

  // En caso de tener que calcular la inversa,
  // modifico el factor de escala y el signo de la fase de W.
  if (inverse)
  {
    factor = 1.0/N;
    W_phase_sign = 1;
  }
  
  if (N > 1)
  {
    // Divido el problema en 2:
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
    
    // Combino las soluciones:
    for (size_t k=0; k<N; k++)
    {
      Complex W(cos(k*(2*PI)/N),
               W_phase_sign*sin(k*(2*PI)/N));
      // Para que se repitan los elementos cíclicamente, se utiliza la función módulo
      size_t k2 = k % (N/2);

      X[k] = factor * (P[k2] + W*Q[k2]);
    } 
  }
  else
  {
    X = x;
  }
  
  return X;
}

// Máscara para la FFT
// Llama a la función genérica en modo "directa"
Vector<Complex>
calculate_fft(Vector<Complex> const &x)
{
  bool inverse = false;
  return calculate_fft_generic(x, inverse);
}

// Máscara para la IFFT
// Llama a la función genérica en modo "inversa"
Vector<Complex>
calculate_ifft(Vector<Complex> const &X)
{
  bool inverse = true;
  return calculate_fft_generic(X, inverse);
}

// ------- FFT_iter --------
// Función genérica para calcular FFT o IFFT versiones iterativas
// Oculta al cliente.
// Si el flag "inverse" es "true", se calcula la inversa (IFFT)
// Caso contrario, la FFT
// Algoritmo recursivo para calcular la DFT: FFT
static Vector<Complex>
calculate_fft_iter_generic(Vector<Complex> const &x, bool inverse)
{
  size_t N;
  N = x.size();

  Vector<Complex> X(N);

  // Por defecto se calcula la FFT con estos parámetros:
  double factor = 1;
  int W_phase_sign = -1;

  // En caso de tener que calcular la inversa,
  // modifico el factor de escala y el signo de la fase de W.
  if (inverse)
  {
    factor = 1.0/N;
    W_phase_sign = 1;
  }
  
  if (N > 1)
  {
    // Divido el problema en 2:
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
 
    P = calculate_fft_iter(p);
    Q = calculate_fft_iter(q);
    
    // Combino las soluciones:
    for (size_t k=0; k<N; k++)
    {
      Complex W(cos(k*(2*PI)/N),
               W_phase_sign*sin(k*(2*PI)/N));
      // Para que se repitan los elementos cíclicamente, se utiliza la función módulo
      size_t k2 = k % (N/2);

      X[k] = factor * (P[k2] + W*Q[k2]);
    } 
  }
  else
  {
    X = x;
  }
  
  return X;
}
Vector<Complex>
calculate_fft_iter(Vector<Complex> const &x)
{
  bool inverse = false;
  return calculate_fft_iter_generic(x, inverse);
}

Vector<Complex>
calculate_ifft_iter(Vector<Complex> const &X)
{
  bool inverse = true;
  return calculate_fft_iter_generic(X, inverse);
}


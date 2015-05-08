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
  
  Vector<Complex> aux_x = x;
  size_t N;
  size_t l;
  N = aux_x.size();

  // Si el tamaño de la entrada no es potencia de 2 se completa con ceros
  //hasta llevarla a la potencia de 2 más cercana
  if (log2(N) - (int)log2(N)){
	  
    l = (int)log2(N) + 1;
	size_t last = my_pow(2,l) - aux_x.size();
	
	for(size_t i=0;i<last;i++){
	  
      aux_x.push_back(0);
	  
	}
	
	N = aux_x.size();
	  
  }

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
      p[i] = aux_x[2*i];
      q[i] = aux_x[2*i+1];
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
    X = aux_x;
  }
  
  return X;
}

  

Vector<Complex>
calculate_ifft(Vector<Complex> const &X)
{
  return X;
}

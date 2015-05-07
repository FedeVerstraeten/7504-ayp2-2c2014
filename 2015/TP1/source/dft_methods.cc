#include <iostream>
#include <cmath>

#include "dft_methods.h"
#include "complex.h"
#include "vector.h"

using namespace std;



Vector<Complex>
calculate_dft(Vector<Complex> const &in)
{
  Vector<Complex> out;
  Complex W;
  Complex aux;
  size_t N;
  
  N = in.size();
  W = calculate_W(N);
  
  for(size_t k=0;k<N;k++){
	
	for(size_t n=0;n<N;n++){
	  
	  aux += in[n] * pow_W(n*k, W);
	  
	}
	
	out.push_back(aux);
	
	aux = 0;
	  
  }
  
  return out;
	
}

Complex
calculate_W(size_t N)
{

  Complex w(cos((2*PI)/N),
            -sin((2*PI)/N));
  
  return w;
	
}

Complex
pow_W(size_t p, Complex const &W)
{
  
  if(!p) return 1;
  
  if(p == 1){
	
	return W;
	
  }
  else{
	  
	Complex aux = pow_W(p/2, W);
	if(!(p%2))
      return aux * aux;
    else
      return aux * aux * W;
  
  }

}


Vector<Complex>
calculate_idft(Vector<Complex> const &X)
{
  return X;
}


// Algoritmo recursivo para calcular la DFT: FFT
Vector<Complex>
calculate_fft(Vector<Complex> const &x)
{
  size_t N;
  N = x.size();

  // Si el tamaño de la entrada no es potencia de 2 se termina el programa
  if (log2(N) - (int)log2(N))
    exit(1);

  Vector<Complex> X(N);
  
  if ( N > 1)
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
  return X;
}


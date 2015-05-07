#include <iostream>
#include <vector>
#include <cmath>

#include "calculation_methods_for_fourier_transform.h"
#include "complex.h"

using namespace std;



vector<Complex>
calculate_method_dft(vector<Complex> const &in)
{
  vector<Complex> out;
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

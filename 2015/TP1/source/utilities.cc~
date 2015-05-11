#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

#include "utilities.h"
#include "complex.h"

using namespace std;



void
set_up_input(Vector<Complex> &input){
	
  size_t n = input.size();
  
  if (log2(n) - (int)log2(n)){
	  
    size_t l = (int)log2(n) + 1;
	size_t last = my_pow(2,l) - input.size();
	
	for(size_t i=0;i<last;i++){
	  
      input.push_back(0);
	  
	}
	  
  }
  
  return;
	
}

Complex
pow_complex(Complex const &z, size_t p)
{
  
  if(!p) return 1;
  
  if(p == 1){
	
	return z;
	
  }
  else{
	  
	Complex aux = pow_complex(z, p/2);
	if(!(p%2))
      return aux * aux;
    else
      return aux * aux * z;
  
  }

}

size_t
my_pow(size_t const &n, size_t p)
{
  
  if(!p) return 1;
  
  if(p == 1){
	
	return n;
	
  }
  else{
	  
	size_t aux = my_pow(n, p/2);
	if(!(p%2))
      return aux * aux;
    else
      return aux * aux * n;
  
  }

}

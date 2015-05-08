#include <iostream>
#include <fstream>
#include <sstream>

#include "utilities.h"
#include "complex.h"

using namespace std;



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

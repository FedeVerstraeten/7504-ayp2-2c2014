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

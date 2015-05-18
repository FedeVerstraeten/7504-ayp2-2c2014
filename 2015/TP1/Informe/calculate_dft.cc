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

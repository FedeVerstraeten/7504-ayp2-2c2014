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

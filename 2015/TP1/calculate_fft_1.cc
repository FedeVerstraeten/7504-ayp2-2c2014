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

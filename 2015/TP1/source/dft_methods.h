#ifndef _DFT_METHODS_H_
#define _DFT_METHODS_H_

#include <iostream>

#include "complex.h"
#include "vector.h"

//#define PI 3.14159 definida en utilities.h

Vector<Complex> calculate_dft(Vector<Complex> const &);
Vector<Complex> calculate_idft(Vector<Complex> const &);
Vector<Complex> calculate_fft(Vector<Complex> const &);
Vector<Complex> calculate_ifft(Vector<Complex> const &);
Vector<Complex> calculate_fft_iter(Vector<Complex> const &);
Vector<Complex> calculate_ifft_iter(Vector<Complex> const &);
Complex pow_complex(Complex const &, size_t);
size_t my_pow(size_t const &, size_t);

#endif

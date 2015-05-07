#ifndef _DFT_METHODS_H_
#define _DFT_METHODS_H_

#include <iostream>
using namespace std;

#include "complex.h"
#include "vector.h"

#define PI 3.14159

Vector<Complex> calculate_dft(Vector<Complex> const &);
Vector<Complex> calculate_idft(Vector<Complex> const &);
Vector<Complex> calculate_fft(Vector<Complex> const &);
Vector<Complex> calculate_ifft(Vector<Complex> const &);
Complex calculate_W(size_t);
Complex pow_W(size_t, Complex const &);

#endif

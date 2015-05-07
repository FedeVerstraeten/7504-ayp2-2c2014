#ifndef _CALCULATION_METHODS_FOR_FOURIER_TRANSFORM_H_
#define _CALCULATION_METHODS_FOR_FOURIER_TRANSFORM_H_

#include <iostream>
#include <vector>

#include "complex.h"

#define PI 3.14159

std::vector<Complex> calculate_method_dft(std::vector<Complex> const &);
Complex calculate_W(size_t);
Complex pow_W(size_t, Complex const &);

#endif
#ifndef _UTILITIES_H_INCLUDED_
#define _UTILITIES_H_INCLUDED_

#include <iostream>

#include "complex.h"
#include "vector.h"

void set_up_input(Vector<Complex> &);
Complex pow_complex(Complex const &, size_t);
size_t my_pow(size_t const &, size_t);

#endif

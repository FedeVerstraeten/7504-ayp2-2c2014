#ifndef _ARGUMENTS_H_INCLUDED_
#define _ARGUMENTS_H_INCLUDED_

#include <iostream>

#define METHOD_OPTIONS 4
#define METHOD_DFT "dft"
#define METHOD_IDFT "idft"
#define METHOD_FFT "fft"
#define METHOD_IFFT "ifft"

void opt_input(std::string const &);
void opt_output(std::string const &);
void opt_method(std::string const &);

#endif

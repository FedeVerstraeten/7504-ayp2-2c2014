#include <iostream>
#include <cstdlib>
#include <sstream>

#include "main.h"
#include "cmdline.h"
#include "arguments.h"
#include "complex.h"
#include "vector.h"
// En definitiva lo que calculamos en todos los casos es la DFT
// (incluso en el caso de la fft, es un algorítmo para calcular la DFT)
#include "dft_methods.h"
#include "types.h"

using namespace std;



Vector<Complex> (*transform[])(Vector<Complex> const &) = {

    calculate_dft,
	  calculate_idft,
    calculate_fft,
	  calculate_ifft

};

extern option_t options[];
extern istream *iss;
extern method_option_t method_option;

int main(int argc, char *argv[])
{	
  Complex input_complex;
  Vector<Complex> input;
  Vector<Complex> output;
  
  cmdline cmdl(options);
  cmdl.parse(argc, argv);
  
  while(*iss >> input_complex)
  {	  
    input.push_back(input_complex); 
  }

  output = (transform[method_option])(input);
  
  for(int i=0; i<output.size(); i++)
  {	  
    cout << output[i] << endl; 
  }
  
  /*for(vector<Complex> it = output.begin() ; it != output.end() ; it++){
	  
    cout << *it << endl;	  

  }*/
  

  return EXIT_SUCCESS;
  
}

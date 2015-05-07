#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>


#include "main.h"
#include "cmdline.h"
#include "arguments.h"
#include "complex.h"
// Esto se puede cambiar por:
// dft_methods.h
// porque en definitiva lo que calculamos en todos los casos es la DFT
// (incluso en el caso de la fft, es un algorítmo para calcular la DFT)
#include "calculation_methods_for_fourier_transform.h"
#include "types.h"

using namespace std;


// en vez de "calculate_method", puede ser "transformate" directamente
vector<Complex> (*calculate_method[])(vector<Complex> const &) = {
	
    // o bien calculate_dft más directo
    calculate_method_dft,
	//calculate_method_idft,
	//calculate_method_fft,
	//calculate_method_ifft

};

extern option_t options[];
extern istream *iss;
extern method_option_t method_option;

int main(int argc, char *argv[]){
	
  Complex input_complex;
  vector<Complex> input;
  vector<Complex> output;
  
  cmdline cmdl(options);
  cmdl.parse(argc, argv);
  
  while(*iss >> input_complex){
	  
    input.push_back(input_complex);
	  
  }

  output = (calculate_method[method_option])(input);
  
  for(size_t i=0;i<output.size();i++){
	  
    cout << output[i] << endl;
	  
  }
  
  /*for(vector<Complex> it = output.begin() ; it != output.end() ; it++){
	  
    cout << *it << endl;	  

  }*/
  

  return EXIT_SUCCESS;
  
}

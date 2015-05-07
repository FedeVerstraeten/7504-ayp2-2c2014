#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>


#include "main.h"
#include "cmdline.h"
#include "arguments.h"
#include "complex.h"
#include "calculation_methods_for_fourier_transform.h"
#include "types.h"

using namespace std;



vector<Complex> (*calculate_method[])(vector<Complex> const &) = {
	
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

// ------------------------------------------------------------------------- //
// Facultad de Ingeniería de la Universidad de Buenos Aires
// Algoritmos y Programación II
// 1° Cuatrimestre de 2015
// Trabajo Práctico 0: Programación en C++
// Sebastian Sampayo, Carlos Germán Carreño Romano, Rodrigo Bourbon
// main1.cc
// Versión sin clase Buffer
// ------------------------------------------------------------------------- //

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//#include <vector>
//#include <iterator>

#include "common.hpp"
#include "cmdline.h"
#include "options.hpp"
#include "complex.h"

#define DECIMATOR_IN 11
#define DECIMATOR_OUT 4
#define PI	3.14159

using namespace std;

istream *iss =0;
ostream *oss = 0;
fstream ifs, ofs;
int factor;

static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{1, "f", "factor", NULL, opt_factor, OPT_SEEN},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};


int
main(int argc, char * const argv[])
{

	cmdline cmdl(options);
	cmdl.parse(argc, argv);
	
	Complex	buffer_in = 0;
	double	buffer_out = 0;
	Complex	complex_in, complex_aux, complex_out;
	Complex	z1, z2=0,prod;
	double	phase_out;
	size_t i,j;	
	string str_aux;

	//- Mientras haya complejos en la entrada
	while (*iss >> complex_in)
	{ 
	//  (Promediar 11 elementos)
		buffer_in += complex_in;
		if (i < DECIMATOR_IN-1)
		{
		i++;
		continue;
		}
		z1 = buffer_in/DECIMATOR_IN;
		buffer_in = 0;
		i = 0;

	//(Obtener la derivada de la fase)
		prod	= z1 * z2.conjugated();
		phase_out = prod.phase();

		z2=z1; //x_prev=x;

	//(Promediar 4 elementos)
		buffer_out += phase_out;

		if (j < DECIMATOR_OUT-1)
		{
			j++;
			continue;	
		}
		phase_out = buffer_out/DECIMATOR_OUT;
		buffer_out = 0;
		j = 0;
		complex_out=(phase_out + PI) * 255 / (2 * PI); 
		*oss << complex_out << endl;
	}

	Complex z3(3,4);
	cout << "z3 = " << z3 << endl;
	cout << "z3.abs()= " << z3.abs() << endl;
	return 0;
}


//Create a buffer of SIZE_OF_BUFFER_INPUT complex elements
//Con vectores
//	vector<complex> complex_vector;
//	vector<complex>::iterator complex_vector_iterator;
//
//	string aux_str;
//

//	while(getline(*iss, aux_str)){
//	
//		istringstream	complex_istream(aux_str);
//		complex		complex_aux;
//		complex_istream >> complex_aux;
//
//		complex_vector.push_back(complex_aux);
//		if(complex_vector.length()==3) break;
//	}	
//Show content of the vector
//	for(complex_vector_iterator=complex_vector.begin();
//		complex_vector_iterator!=complex_vector.end();
//		complex_vector_iterator++){
//		cout<<*complex_vector_iterator<<endl;
//	}
//Process the input	
//	aux_complex=average();
//	decimador(11);
//	complex prod=










#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

#include "common.hpp"
#include "cmdline.h"
#include "options.hpp"
#include "complex.h"


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

int read_input(/*FILE &stream,*/ string str)
{
	cout<< "aca va la estrategia para leer y validar una entrada correcta del tipo (I,Q)"<<endl
		<<"se me ocurre utilizar getline con delimitadores, pero hay que considerar casos como (-2,3.14159...)"<<endl;
	return 1;
}

int validate_if_complex(string str)
{
	cout<<"esta funcion debe ir adentro de de read_input()"<<endl;
	return 1;
}


int
main(int argc, char * const argv[])
{

	cout << "hola" <<endl;
	cmdline cmdl(options);
	cmdl.parse(argc, argv);
/*
	//TEST of CMDLINE Class
	string str, str2="(0,0)";
	getline(*iss,str);
	ofs << str << endl;
	if(!str.compare(str2)) cout << "entrada OK" << endl;
	//END TEST of CMDLINE Class
*/
/*
	//TEST of COMPLEX Class
	complejo z1(1,1);
	cout << "La clase complejo compiló bien mirá:"<<endl;
	z1.emitir();
	//END TEST of COMPLEX Class
*/

	//Create a buffer of SIZE_OF_BUFFER_INPUT complex elements
	vector<complejo> complex_vector(SIZE_OF_BUFFER_INPUT);
	vector<complejo>::iterator complex_vector_iterator;

	string aux_str;
	read_input(/*iss,*/aux_str);
	if(validate_if_complex(aux_str)==0){
//		complejo aux_complex=string_to_complex(aux_str);
	}
	else{
		cerr << "Error reading from input stream, is not a valid (I,Q) complex number"<<endl;
	//Google C++ code style
	//fprintf(stderr, "Error reading from input stream\n %s\n is not a valid (I,Q) complex number",aux_str,strerror(errno));

	}
	
	//Show content of the vector
	for(complex_vector_iterator=complex_vector.begin();
		complex_vector_iterator!=complex_vector.end();
		complex_vector_iterator++){
		(*complex_vector_iterator).emitir();
	}

	
	return 1;

}










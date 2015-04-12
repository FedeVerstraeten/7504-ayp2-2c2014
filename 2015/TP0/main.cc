// Prueba de la clase cmdline: dado un factor entero pasado por la
// l�nea de comando, leemos una secuencia de n�meros que ingresan
// por la entrada est�ndar, los multiplicamos por ese factor, y
// luego mostramos el resultado por std::cout.
//
// $Id: main.cc,v 1.5 2012/09/15 12:23:57 lesanti Exp $

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

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

int
main(int argc, char * const argv[])
{

	cout << "hola" <<endl;
	cmdline cmdl(options);
	cmdl.parse(argc, argv);
	string str;
	getline(*iss,str);
	ofs << str << endl;
	complejo z1(1,1);
	cout << "La clase complejo compil� bien mir�:"<<endl;
	z1.emitir();
	return 1;

}

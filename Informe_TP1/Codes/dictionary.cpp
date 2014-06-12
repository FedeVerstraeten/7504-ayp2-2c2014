#include"dictionary.hpp"
#include"cmdline.h"
#include"options.hpp"

//Diccionarios: HAY QUE ACORDAR UNA NOMNECLATURA PARA STRINGS , VARIABLES y ARREGLOS.
//Diccionarios: HAY QUE ACORDAR UNA NOMNECLATURA PARA STRINGS , VARIABLES y ARREGLOS.

string network_struct[]   = {"NetworkName","NetworkElement","Connection"};
string network_element_type[] = {"Hub","Node","Amp","CM"};
string network_element_name[MAX_LINES_DEFAULT];

option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};



//extern static size_t   n, i;


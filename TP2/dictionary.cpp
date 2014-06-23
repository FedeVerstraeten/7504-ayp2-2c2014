#include"dictionary.hpp"
#include"cmdline.h"
#include"options.hpp"

//Diccionarios: HAY QUE ACORDAR UNA NOMNECLATURA PARA STRINGS , VARIABLES y ARREGLOS.
//Diccionarios: HAY QUE ACORDAR UNA NOMNECLATURA PARA STRINGS , VARIABLES y ARREGLOS.

string network_struct[]   = {"NetworkName","NetworkElement","Connection"};
string network_element_type[] = {"Hub","Node","Amp","CM"};
#define MAX_NET_ELS 4
string network_element_name[MAX_LINES_DEFAULT];
string network_faults[] = {"Query","Poll","Fault","Clear"};
#define MAX_FAULTS 4

option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_MANDATORY},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
    {1, "t", "topology", "-", opt_topology, OPT_MANDATORY},
	{1, "p", "print-topology", "-", opt_print_topology, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};



//extern static size_t   n, i;


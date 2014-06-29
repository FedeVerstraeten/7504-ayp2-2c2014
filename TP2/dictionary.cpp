#include"dictionary.hpp"
#include"cmdline.h"
#include"options.hpp"

string network_struct[]   = {"NetworkName","NetworkElement","Connection"};
string network_element_type[] = {"Hub","Node","Amp","CM"};
#define MAX_NET_ELS 4
string network_element_name[MAX_LINES_DEFAULT];
string network_faults[] = {"Query","Poll","Fault","Clear"};
#define MAX_FAULTS 4

option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
    {1, "top", "topology", "-", opt_topology, OPT_MANDATORY},
	{1, "ptop", "print-topology", "-", opt_print_topology, OPT_DEFAULT},
	{0,"h", "help", NULL, opt_help, OPT_DEFAULT},
	{1, "t", "threshold","5",opt_threshold,OPT_DEFAULT},// 5(cinco) valor por defecto
	{0, },
};

 // No funciona correctamente si pongo NULL como opcion corta, lo mismo sucede con la opcion larga.
 // se invalidan las opciones cortas (o largas) siguientes en la tabla, eso sucede porque las funciones
 // do_short_opt y do_long_opt, usan como parametro de iteracion recorrer la tabla de opciones
 // hasta encontrar un valor 0 (cero) o NULL. Por esto mismo no es valido poner NULL como opcion corta
 // (o larga) en el caso de que no se considere necesario; es obligatorio poner ambar opciones, o como
 // alternativa dejar un caracter vacio " ".


//extern static size_t   n, i;


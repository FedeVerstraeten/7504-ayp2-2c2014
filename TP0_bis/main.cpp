#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include"common.hpp"
#include "dictionary.hpp"
#include "process.hpp"
#include "printers.hpp"
#include "cmdline.h"
#include "options.hpp"


using namespace std;

istream *iss_net = 0;
ostream *oss_net = 0;
fstream ifs_net, ofs_net;
unsigned int configThreshold=0; //inicializo en cero

extern option_t options[];
extern string network_element_type[];
extern string network_faults[];
int number_of_elements[5];

string getNetName(string);
bool NetworkElementType(string);
size_t line=0;

/**** MAIN ****/

int main(int argc,char *argv[])
{
//OPTIONS AND ARGUMENTS VALIDATION
	cmdline cmdl(options);
	cmdl.parse(argc, argv);

	string str, str2, aux;
	string NetName;


/***************TOPOLOGY***************************/
    getline(*iss_net,str);
    istringstream ifs_nets(str);

//NetworkName
    if(getNetName(ifs_nets, NetName)==false){
        cerr << "error: missing NetworkName" << endl;
        return 1;
    }
//Vector of NetworkElements
    line=1;

    while( getline(*iss_net,str) )
    {
        line++;
        if(processLine(str)==-1) return 1;
    }

        *oss_net << "NetworkName "<<NetName << endl;
        printElements( number_of_elements , *oss_net);
/******************************************/

    return EXIT_SUCCESS;
}

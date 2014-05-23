#ifndef ARGUMENTS_HPP
#define ARGUMENTS_HPP
#include<fstream>
#include<iostream>
#include"common.hpp"
/**** DEFINICIONES ****/
#define SIG_ARG_POS 1
#define CHAR_VOID 0

/**** PROTOTIPOS ****/

status_t read_argument(const char  arg[]);
status_t route_verification(char arg[],char* &route);
void close_all_stream_file(fstream& ,fstream& );
status_t validateArgument(int argc,char *argv[],char* &route_in,char* &route_out);





#endif

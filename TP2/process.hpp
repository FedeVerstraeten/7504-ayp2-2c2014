#ifndef PROCESS_HPP_INCLUDED
#define PROCESS_HPP_INCLUDED

#include <string>
#include <sstream>
#include"common.hpp"
#include <vector>
#include "NetworkElementClass.hpp"

//Esta funcion encuentra el ROOT

int FindRoot(vector <NetworkElement>&);
int processVector(istream& , vector <NetworkElement> &, size_t& );
int processConnections(istream& , vector <NetworkElement> &);
bool NetworkElementType(string aux);
bool getNetName(istream& iss, string &NetName);
int processFaults(istream&, string[],vector <NetworkElement>& );

#endif // PROCESS_HPP_INCLUDED

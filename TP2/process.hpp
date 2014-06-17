#ifndef PROCESS_HPP_INCLUDED
#define PROCESS_HPP_INCLUDED

#include <string>
#include <sstream>
#include"common.hpp"
#include <vector>
#include "NetworkElementClass.hpp"

//Esta funcion encuentra el ROOT

int FindRoot(vector <NetworkElement>&);
int processVector(istream& iss, vector <NetworkElement> &v, size_t& i);
int processConnections(istream& ifss, vector <NetworkElement> &v);
bool NetworkElementType(string aux);
bool getNetName(istream& iss, string &NetName);

#endif // PROCESS_HPP_INCLUDED

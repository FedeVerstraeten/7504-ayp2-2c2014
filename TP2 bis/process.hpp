#ifndef PROCESS_HPP_INCLUDED
#define PROCESS_HPP_INCLUDED

#include <string>
#include <sstream>
#include"common.hpp"
#include <vector>
#include "NetworkElementClass.hpp"
#include "dictionary.hpp"
#include "TableHash.hpp"
#include "NodeTable.hpp"


//Esta funcion encuentra el ROOT

int processVector(istream& , TableHash &);
int processConnections(istream& , TableHash &);
bool NetworkElementType(string aux);
bool getNetName(istream& iss, string &NetName);
NetworkElement* processFaults(istream&, TableHash&);
int insertFault(const string,NetworkElement*,const string);

#endif // PROCESS_HPP_INCLUDED

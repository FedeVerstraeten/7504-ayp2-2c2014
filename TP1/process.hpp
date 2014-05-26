#ifndef PROCESS_HPP_INCLUDED
#define PROCESS_HPP_INCLUDED

#include <string>
#include <sstream>
#include"common.hpp"
status_t processLine(string);
status_t processLine(string line, string name1, string name2);
void inputFromConsole(void);
//void tokenLine(string);
//status_t checkTokens(string &name, string &type)

#endif // PROCESS_HPP_INCLUDED

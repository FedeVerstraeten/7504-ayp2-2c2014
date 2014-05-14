#ifndef PRINTERS_HPP
#define PRINTERS_HPP
#include"common.hpp"
#include<iostream>
#include <string>
#include <sstream>
#include<fstream>


void printElements(int *, ostream&);
void printNetworkName(status_t, string, ostream&);
void printErrorMessage(status_t, ostream&);
void printString(string, ostream&);
string saveNetworkName(string );

#endif // PRINTERS_HPP_INCLUDED

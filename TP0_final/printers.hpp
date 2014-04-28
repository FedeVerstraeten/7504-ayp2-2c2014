#ifndef PRINTERS_HPP
#define PRINTERS_HPP
#include"common.hpp"
#include<iostream>
#include <string>
#include <sstream>
#include<fstream>


void printElements(int *, ostream&);
void printNetworkName(string, ostream&);
void printErrorMessage(status_t, ostream&);
void printString(string, ostream&);

#endif // PRINTERS_HPP_INCLUDED

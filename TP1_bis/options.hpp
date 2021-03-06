#ifndef OPTIONS_HPP_INCLUDED
#define OPTIONS_HPP_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

void opt_input(string const &);
void opt_output(string const &);
void opt_help(string const &);
void opt_topology(string const &);
void opt_print_topology(string const &);
void opt_threshold(string const &);
#endif // OPTIONS_HPP_INCLUDED

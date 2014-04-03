#ifndef FILE_LOAD_HPP
#define FILE_LOAD_HPP

#include<iostream>
#include<fstream>
#include<string>
#include"common.hpp"
#define INIT_CHOP 30
#define CHOP_SIZE 20
//Prototipos
status_t load_file_memory(ifstream &file,string ***lines,size_t &size);
status_t erase_file_memory(string ***lines,size_t &size);
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include"file_load.hpp"
#include"common.hpp"
#include "printers.hpp"
#include "dictionary.hpp"
#include "process.hpp"
#include "arguments.hpp"
#include "NetworkElementClass.hpp"
#include "cmdline.h"
#include "options.hpp"

    //void stringMatrix(string *** matrix, size_t rows, size_t columns);

using namespace std;

istream *iss = 0;
ostream *oss = 0;
fstream ifs;
fstream ofs;
extern option_t options[];

/**** MAIN ****/

int main(int argc,char *argv[])
{

	cmdline cmdl(options);
	cmdl.parse(argc, argv);

    string **lines; //este lo usa loadFileMemory()
	size_t number_lines; //este lo usa loadFileMemory()
	status_t f_; //estos se usan
	string st1, st2;

	if(*iss==ifs)
	{
        f_=loadFileMemory( ifs , &lines , number_lines );
        if(f_==OK)
        {
            cout<<"piola"<<endl;

        }
        else
        {
                close_all_stream_file( ifs , ofs );
                eraseFileMemory( &lines , number_lines );
                cout << "nopiola"<<endl ;
        }
    }
	else if(*iss==cin)
	{
        inputFromConsole();
	}

    char * cstr[number_lines];
    for(size_t i=0 ; i<number_lines ; i++)
    {
        cstr[i] = new char [(*lines[i]).length()+1];
        strcpy (cstr[i], (*lines[i]).c_str());
    }

    #define MAX_WORDS_PER_LINE_DEFAULT 3
    string matrix[number_lines][MAX_WORDS_PER_LINE_DEFAULT];
    for(size_t i=0 ; i<number_lines ; i++)
    {
      char * p = strtok (cstr[i]," ");
      size_t j=0;
      while (p!=0)
      {
        matrix[i][j++]=string(p);
        p = strtok(NULL," ");

      }
    }
   //cout << matrix [0][1] << endl;
   return 0;
}

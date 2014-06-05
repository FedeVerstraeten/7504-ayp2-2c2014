//Cristian
//Esta es un main para ver como se invocan a las funciones load_file_memory() y erase_file_memory()
//a su ves ña misma puede ser invocada dependiendo de si la linea de comando de ordenes lo solicita
//y se puede acceder a cada linea desde lines[i]
//CUALQUIER DUDA O CAMBIO CONSULTE..!!!




#include<iostream>
#include"file_load.hpp"
#include"common.hpp"


int main(void){

ifstream in("texto.txt");


string **lines;
size_t number_lines;
size_t i;

        load_file_memory(in,&lines,number_lines);     

	for(i=0;i<number_lines;i++){ 
		cout<<*lines[i]<<endl;
	}

        cout<<"numero de lineas:   "  <<number_lines<<endl;
        erase_file_memory(&lines,number_lines);

return 0;
}






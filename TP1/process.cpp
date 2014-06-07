#include"process.hpp"
#include "printers.hpp"


/****************************************************************************************
 FindRoot:La funcion recibe el arreglo de objetos NetworkElement y retorna la posicion 
 del ROOT 

*****************************************************************************************/

int FindRoot(vector <NetworkElement> &v){
	int i;
	for(i=0;v.data()[i].getName()!="Hub1";i++);
	return i;
}

// Algoritmos y Programacion II - 95.02
// Cristian Aranda
// C++
// Clase (parcial) para manejo de vectores 
//Nota:
/*Esta clase se encarga de cargar en memoria cualquier archivo o datos que le ingresen ya sea desde un archivo o un flujo o datos que estan en memoria */


#ifndef CLASE_VECTOR_HPP
#define CLASE_VECTOR_HPP

template <typemane T>
class vector{

private:

	size_t size;
	T **vector;  

public:
	
	vector();
	vec
	status_t loadFileMemory(ifstream &file,string ***lines,size_t &size);
	status_t eraseFileMemory(string ***lines,size_t &size);
	
	

	








}











#endif

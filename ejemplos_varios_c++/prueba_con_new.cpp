//Cristian:
/*En este programa intente crear un arreglo de punteros a objetos string con 100 elementos staticos, que hace referencia   a 100 lineas de archivo. por otro lado para cada puntero a string se pidio  memoria dinamica y dentro del ciclo con getline()se hizo la lectura desde el archivo hacia el string ...y así ya tendriamos cargado en memoria la primer linea del string*/
/*trabajo pendiente*/

//armar un algoritmos con condicion de corte ("usando eof") para poder pedir la cantidad necesaria de punteros a string donde se guarda el archivo,donde por cada string se guarda una linea .

//pedir memoria dinamica realoacando con en C pero para c++





#include<iostream>
#include<fstream>
#include<string>
#define CHOP_SIZE 2
using namespace std; 

size_t cantidad_lineas=2;
int main(void){


size_t i;
ifstream in("Scopy.txt");
string *prueba[100],aux;	//Cristian: se declara un arreglo de punteros a objetos string de 100
			// unidades, la unica forma de perdir memoria en punteros
			// a objetos es con el operador new.
			
//analizar bien esta variable global para poder reallocar memoria de manera efectiva


	for(i=0;i<100 || getline(in,aux)!=0;i++){
		//tendria qe buscar una condicion de corte alternatica por si se acaba el archivo (eof) y que no llegue hasta 100
	//	getline(in,aux);//esta funcion recibe el archivo y el string donde guardar!!!
	/*	if(cantidad_lineas==i){
			
			cantidad_lineas+=CHOP_SIZE;
			
		} */
		prueba[i]=new string(aux);
	//	getline(in,aux);//esta funcion recibe el archivo y el string donde guardar!!! 
	}
	cout << *prueba[0] << "\n"; 


	//prueba[0]=new string("hola");// Cristian: Se puede usar el operador new para pedir memoria en el heap y además hacer la asignación
	//*(prueba[1])="mundo";

//	cout <<*(prueba[0]) << endl;

delete prueba[0];
return 0;
}

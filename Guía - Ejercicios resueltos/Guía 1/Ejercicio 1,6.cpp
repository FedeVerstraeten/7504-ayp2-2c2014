/********************************************************************
75.04 Algoritmos y Programación 2
Práctica 1: C++ Básico
Ejercicio Nº6

Autor: Federico Verstraeten
********************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
	/*********** DECLARACIONES ***********/
		
	int n=4;

	int const &r=n; // Es lo mismo que declarar: const int &r;
	
	/* int& const s=n; Error: los calificadores ‘const’ no se pueden aplicar a ‘int&’ */
	

	const int *p1;	// Variable de dato "tipo" constante, de un puntero p. Se le puede asignar una
					// dirección de memoria pero no modificar su contenido, es "solo lectura".				
	
	int const *p2;	// Idem p1, son declaraciones equvivalentes

	int* const p3=&n;	// Variable dato "tipo puntero" constante. Solo se puede asignar una dirección
						// de memoria en su declaración y no puede ser modificada luego en el programa.

	const int* const p4=NULL;


	/*********** PRUEBAS ***********/

	n=n+2;

	cout<<n<<endl;	
	/* r=r+2; Error compilación: asignación de la referencia de sólo lectura ‘r’ */

	cout<<r<<" "<<n<<endl;

	p1=&n; 
	p2=p1; 
	p3=&n;		// Error compilación: asignación de la variable de sólo lectura ‘p3’
	p4=p1;		// Error compilación: asignación de la variable de sólo lectura ‘p4’


	(*p1)++;	// Error compilación: incremento de la ubicación de sólo lectura ‘* p1’

	cout<<"p1:"<<p1
		<<"p2:"<<p2	
		<<"p3:"<<p3
		<<"p4:"<<p4;


	return 0;
}

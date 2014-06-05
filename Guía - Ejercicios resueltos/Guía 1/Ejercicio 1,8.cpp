/********************************************************************
75.04 Algoritmos y Programación 2
Práctica 1: C++ Básico
Ejercicio Nº8
Implementar una clase 'arreglo' para el código en el main propuesto.

Autor: Federico Verstraeten

Nota: Ver los apunter de la clase teórica del día 19/03/2014 sobre
el tema "Clase Vector". Manejo de clases de tipo array.
********************************************************************/

#include <iostream>

/************************** CLASES ********************************/

class arreglo
{
	private:
		int *v=NULL;

	public:
		arreglo();					// Constructor por defecto, sin argumentos.
		arreglo(int );				// Constructor con argumentos.
		arreglo(const arreglo &);	// Constructor por copia.

		arreglo& operator = (const arreglo&);
		const arreglo& operator + (const arreglo&);

		
};



/*****************************************************************/




/*************************** MAIN ********************************/

int main (void)
{
	arreglo a(7);

	a[0] = 3;
	a[1] = 6;
	a[2] = a[0] + a[1];

	arreglo b = a;
	std::cout << b[2] << std::endl;
	
	return 0;
}

/*****************************************************************/

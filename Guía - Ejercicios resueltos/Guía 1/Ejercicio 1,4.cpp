/********************************************************************
75.04 Algoritmos y Programación 2
Práctica 1: C++ Básico
Ejercicio Nº4: Comprobación de la precedencia de los operadores.

Autor: Federico Verstraeten
********************************************************************/

#include <iostream>

using namespace std;

int main(void)
{
	int a=0,b=0,c=0,d=0;
	
	/*********************
			ITEM A
	*********************/

	b=3;c=2;d=4;
		
	a=b+c*d<<2&8;	//a=( (b+(c*d)) <<2) & 8

	cout<<"RESULTADO: "<<a<<endl;

	/*********************
			ITEM B
	*********************/
	
	a=77;

	if(a & 077 !=0) cout<<"OK "<<"Valor a:"<<(a&77)<<endl;
	else cout<<"NOT OK "<<"Valor a:"<<(a&077)<<endl;;

	/*********************
			ITEM G
	*********************/
	/*
	b=1;

	a=-1 ++b-- - 5; //error compilación: se requiere un l-valor como un operando de incremento

	cout<<"RESULTADO: "<<a<<endl;
	*/

	/*********************
			ITEM 
	*********************/
	
	a=b=c=0;

		cout<<"RESULTADO: "<<a<<","<<b<<","<<c<<endl;

	return 0;
}

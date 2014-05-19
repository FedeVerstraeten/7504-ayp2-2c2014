/********************************************************************
75.04 Algoritmos y Programación 2
Práctica 1: C++ Básico
Ejercicio Nº3

Autor: Federico Verstraeten
********************************************************************/

#include <iostream>
#define N 50

using namespace std;

int main(void)
{
	char v[]={'a','b','c','d','e','g','f','g','h'};

	/*****************************************************
	Iteración aumentando directamente la variable puntero.
	*****************************************************/

	cout<<"Aumento variable puntero"<<endl;	

	for(char *p=v;*p;++p)
	{
		cout<<*p<<endl;
	}
	
	/*****************************************************
	Iteración aumentando una variable auxiliar y posicionar
	el array en la i-ésima posición.
	*****************************************************/

	cout<<"Aumento variable auxiliar de posicionamiento del array"<<endl;	

	for(int i=0;v[i];++i)
	{
		cout<<v[i]<<endl;
	}
}

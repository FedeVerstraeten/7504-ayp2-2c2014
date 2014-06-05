/********************************************************************
75.04 Algoritmos y Programación 2
Práctica 1: C++ Básico
Ejercicio Nº9
Verificar la salida del programa

Autor: Federico Verstraeten
********************************************************************/

#include <iostream>
using namespace std;

class foo
{
public:
	foo() {cout<<"foo::foo()"<<endl;}
	foo(const foo&) {cout<<"foo::foo(const foo&)"<<endl;}
	~foo() {cout<<"foo:~foo()"<<endl;}
};

void bar(foo A)
{
	cout<<"foo bar(foo)"<<endl;
	//return A;
}

int main(void)
{
	foo A;    //Llamada al constructor
	bar(A);	  //Llamada a la función bar( ) pasando el objeto A
}

/*******************************************************************
SALIDA DEL PROGRAMA AL EJECUTAR:

foo::foo()		Invocación del constructor si argumentos
foo::foo(const foo&)	Invocación del constructor copia

foo bar(foo)		Llamada al función bar()
foo::foo(const foo&)	Invocación al constructor copia, llamado por
			la función bar() al retornar el valor A

foo:~foo()		Finaliza la ejecución del Main, se invocan
foo:~foo()		los destructores de los objetos creados.
foo:~foo()

********************************************************************/

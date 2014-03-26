#include<iostream>
using namespace std;
//prototipos


void incream(int &t);


int main(void){

	int x=10;
	

	incream(x);// cuando se invoca la función automaticamente se inicializa la referencia
	//ya no tengo q pasarle la dir de memoria para modificar la variable,ni retonarla por nombre pues estoy manejando referencias
	//La "x" sale de la funcion ya modificada sin ser necesario pasar por copia o por direccion de memoria la variable
	std::cout << x << endl;//imprimo x ya modifcada 



}

void incream(int &t){

	t=t+1;
}


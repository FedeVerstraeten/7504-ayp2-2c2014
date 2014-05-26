#include "template.hpp"
#include <iostream>
using namespace std;


int main()
{
 int i;
 //en la siguiente instrucción, el objeto a se crea según la versión producida 
 // en tiempo de compilación a partir de la plantilla de clase vector
 // para un tipo int
 Array <int> a;
 for (i=0;i<10;i++)
    a[i]=i*2;
 for (i=0;i<10;i++)
    std::cout<<a[i]<<std::endl;
 //en la siguiente instrucción, el objeto b se crea según la versión producida 
 // en tiempo de compilación a partir de la plantilla de clase vector
 // para un tipo char  
 Array <char> b;
 for(i=0;i<5;i++)
    b[i]=(char)(i+65);
 for (i=0;i<5;i++)
    std::cout<<b[i]<<std::endl;
    
std::cout<<"Probando la excepción con try..catch"<<std::endl;
try 
{
  std::cout<<"emision de a[20]" <<a[20] <<std::endl;
    }
catch(errorsubindice &e)
{
 std::cout<<"excepcion atrapada por el catcher" <<std::endl;
 std::cout<<"la siguiente linea se emite usando un método de la clase exception" <<std::endl;  
 std::cout<< e.what()<<std::endl; //esta función esta en la clase exception; retorn aun string que identifica la excepcion
                 }
//system("pause");
return 0; 
 }

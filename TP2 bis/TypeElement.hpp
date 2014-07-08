#ifndef TYPE_ELEMENT_HPP
#define TYPE_ELEMENT_HPP

#include <iostream>

#include "common.hpp"

/******
Clase de prueba que posee un numero entero como clave
y un caracter (o cadena) como valor.
Con esta clase se probara el funcionamiento de la tabla.
*******/

class TypeElement
{
    private:
        string key;
        string name;

    public:
        TypeElement(){};
        TypeElement(string k,string n){ key=k; name=n; }
        TypeElement(const TypeElement &e){ key=e.key; name=e.name;}
        ~TypeElement(){}

        void setKey(string k){ key=k; }
        void setName(string n){ name=n; }

        const string getKey()const { return key; }
        const string getName()const { return name; }

};

 #endif

#include <iostream>

#include "common.hpp"
#include "TableHash.hpp"
#include "NodeTable.hpp"
#include "TypeElement.hpp"

int main(void)
{
    TableHash t_hash(2);
    TypeElement elemX;
    TypeElement elem1("1","uno"),elem2("2","dos"),elem3("3","tres"),elem123("123","ciento-veintitres");
    TypeElement elemB("B","Letra-B"), elemWord("hola","HOLA");

    /* Inserto elementos a la tabla */
    t_hash.insert(elem1);
    t_hash.insert(elem2);
    t_hash.insert(elem3);
    t_hash.insert(elem123);
    t_hash.insert(elemB);
    t_hash.insert(elemWord);

    /* Imprimo los elementos */
    cout<<"nombre elemento"<<endl;
    t_hash.print(elem1);
    t_hash.print(elem3);
    t_hash.print(elem2);
    t_hash.print(elemB);

    /* Imprimo toda la tabla hash */
    t_hash.printTable();

    elemX=(t_hash.searchNode("hola"))->getElement();
    cout<<elemX.getName()<<endl;
    cout<<t_hash.getNumElements()<<" "<<t_hash.getTableSize()<<endl;

    return 0;
}

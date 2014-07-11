#ifndef TABLE_HASH_HPP
#define TABLE_HASH_HPP

#include <iostream>

#include "common.hpp"
#include "NodeTable.hpp"
#include "NetworkElementClass.hpp"

/******
La CLAVE utilizada en esta tabla es del tipo numericas (int),
dado que se utiliza como nodo TypeElement cuyo campo clave es entero
Optaremos por la funcion de hash de Kernighan, la cual procesa
claves alfanumericas y lo transforma en un entero positivo.
*******/


class TableHash
{
    private:
            NodeTable** table;
            size_t tableSize;
            size_t numElements;

            unsigned int hashFunction(string)const;
            // Encargada de transformar la clave. Para NetworkElement el parametro debe ser
            // tipo char* (o string)

    public:
            TableHash();
            TableHash(size_t); // Parametro de ingreso, cantidad de buckets
            TableHash(const TableHash&);
            ~TableHash();


            void insert(const NetworkElement&); // iria el objeto NetworkElement como parametro

            /* El parametro representa el tipo de dato de la CLAVE*/
            NodeTable* searchNode(const string)const; //Retorna NULL si no encuentra el nodo del elemento
            //TypeElement find(const string); //devuelve la direccion de memoria del elemento
            void remove(const string);

            void print(const NetworkElement&);
            void printTable();

            const size_t getTableSize() const { return tableSize; }
            const size_t getNumElements() const { return numElements; }


            TableHash& operator = (const TableHash&);
};

 #endif

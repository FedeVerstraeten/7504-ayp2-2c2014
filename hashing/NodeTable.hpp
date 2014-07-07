#ifndef NODE_TABLE_HPP
#define NODE_TABLE_HPP

#include <iostream>

#include "common.hpp"
#include "TypeElement.hpp"

/*********
Nodos de la tabla de dato tipo TypeElement (elemento para
prueba). Para adaptar a NetworkElement se debe cambiar las
partes del codigo donde se hace referencia a TypeElement.
**********/


class NodeTable
{
    private:
        TypeElement element;
        NodeTable *next;

    public:
        NodeTable(){}
        NodeTable(TypeElement e){ element=e; next=NULL; }
        NodeTable(const NodeTable &node){ element=node.element; next=node.next;}
        ~NodeTable(){};

        void setElement(TypeElement e){ element=e; }
        void setNext(NodeTable *sig){ next=sig; }

        const TypeElement getElement()const { return element;}
        NodeTable* getNext()const {return next;}


};

 #endif

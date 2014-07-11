#ifndef NODE_TABLE_HPP
#define NODE_TABLE_HPP

#include <iostream>

#include "common.hpp"
#include "NetworkElementClass.hpp"

/*********
Nodos de la tabla de dato tipo NetworkElement (elemento para
prueba). Para adaptar a NetworkElement se debe cambiar las
partes del codigo donde se hace referencia a NetworkElement.
**********/


class NodeTable
{
    private:
        NetworkElement element;
        NodeTable *next;

    public:
        NodeTable(){}
        NodeTable(const NetworkElement &e){ element=e; next=NULL; }
        NodeTable(const NodeTable &node){ element=node.element; next=node.next;}
        ~NodeTable(){};

        void setElement(NetworkElement e){ element=e; }
        void setNext(NodeTable *sig){ next=sig; }

        NetworkElement& getElement() { return this->element;}
        NodeTable* getNext()const {return next;}


};

 #endif

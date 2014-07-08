#include <iostream>

#include "TableHash.hpp"
#include "common.hpp"

/***********************
hashFunction: h(k)-->(int)

la funcion toma la clave k, en este caso un valor entero
(o alfanumerico) y la transforma en un valor entero que
sera el indice donde el elemento se ubicara en la tabla

************************/
unsigned int TableHash :: hashFunction(const string k)const
{
    unsigned long int h=0;// Valor inicial h=0 y valor multiplicativo 31
    const char *word=NULL;

    // Transformo el string k a char*
    word=k.c_str();

    for( ; *word ; word++ )
    {
        h=31*h+(*word);
    }
    return (h%tableSize);

}


TableHash :: TableHash()
{
    table=NULL;
    tableSize=0;
    numElements=0;

}

TableHash :: TableHash(size_t buckets)
{
    table=new NodeTable* [buckets];
    tableSize=buckets;
    for(size_t i=0 ; i < tableSize ; i++)
        table[i]=NULL;
    numElements=0;
}

TableHash :: TableHash(const TableHash& auxTable)
{
    table=new NodeTable* [auxTable.tableSize];
    tableSize=auxTable.tableSize;
    for(size_t i=0 ; i < tableSize ; i++)
        table[i]=auxTable.table[i];
    numElements=auxTable.numElements;
}

TableHash :: ~TableHash()
{
 /* deberia impletementar la liberacion de los nodos de la lista*/
}

void TableHash :: insert(const NetworkElement &el)
{
    int position;
    NodeTable *newNode,*p;

    position=hashFunction(el.getName());
    p=searchNode(el.getName());

    if(!p)  //el elemento no se encuentra en la tabla
    {
        newNode=new NodeTable(el);
        newNode->setNext(table[position]);
        table[position]=newNode;
        numElements++;
    }
    else
        cerr<<"Elemento "<<el.getName()<<" repetido"<<endl;
}

NodeTable* TableHash :: searchNode(const string clave)const
{
    NodeTable *p=NULL;
    size_t position;

    position=hashFunction(clave);


    if(table[position]!=NULL)
    {
        p=table[position];

        while((p->getNext()!=NULL) && (p->getElement()).getName()!=clave)
        {
            // Avanza el puntero p por la lista mientras el elemento siguiente
            // sea distinto de nulo y mientras no encuentro el elemento con la clave
            p=p->getNext();
        }
        if((p->getElement()).getName()!=clave)
        {
            // Evaluo si llegue al ultimo elemento de la lista, si posee la clave
            p=NULL;
        }

    }

    return p;
}

void TableHash :: remove(const string clave)
{
    size_t position;

    position=hashFunction(clave);

    if(table[position]!=NULL) // No esta vacia
    {
        NodeTable *anterior, *actual;

        anterior=NULL;
        actual=table[position];
        while((actual->getNext()!=NULL) && (actual->getElement()).getName()!=clave)
        {
            anterior=actual;
            actual=actual->getNext();
        }

        if((actual->getElement()).getName()!=clave)
            cerr<<"No se encuentra el elemento en la tabla"<<endl;

        else
        {
            if(anterior==NULL) // Nodo a eleminar es el primero de la lista
                table[position]=actual->getNext();
            else
                anterior->setNext(actual->getNext());

            delete actual;

            numElements--;
        }
    }
}

void TableHash :: print (const NetworkElement &el)
{
    NodeTable *auxNode=NULL;

    auxNode=searchNode(el.getName());

    if(auxNode==NULL) cerr<<"Elemento <"<< el.getName() <<"> no encontrado en la tabla"<<endl;

    else
        cout<<(auxNode->getElement()).getName()<<endl;
}

void TableHash :: printTable ()
{
    NodeTable *p=NULL;

    cout<<"Cantidad total buckets: "<<tableSize<<endl;

    for(size_t i=0;i<tableSize;i++)
    {
        if(table[i]!=NULL)
        {
            cout<<"Posicion "<<i<<": ";
            p=table[i];

            while(p!=NULL)
            {
                cout<<(p->getElement()).getName()<<" ";
                p=p->getNext();
            }
            cout<<endl;
        }
    }
}

TableHash& TableHash :: operator = (const TableHash& auxTable)
{
    if(this==&auxTable) return *this;

    table=new NodeTable* [auxTable.tableSize];
    tableSize=auxTable.tableSize;
    for(size_t i=0 ; i < tableSize ; i++)
        table[i]=auxTable.table[i];
    numElements=auxTable.numElements;

    return *this;
}

/*
NetworkElement TableHash :: find(const string clave)
{
    NodeTable *auxNode;

    auxNode=searchNode(clave);

    if(auxNode==NULL)
    {
      cerr<<"Clave <"<<clave<<"> no encontrada en la tabla"<<endl;
      //return NULL;
    }

    return auxNode->getElement();
}
*/

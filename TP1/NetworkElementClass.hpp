#ifndef NETWORK_ELEMENT_CLASS_HPP
#define NETWORK_ELEMENT_CLASS_HPP

#include<iostream>

class NetworkElement
{
	private:

		string name;
		string type;
		NetworkElement *father_;
		NetworkElement *sons[];
		size_t numberSons;

	public:

        /*********************** CONSTRUCTORES *********************************/
		NetworkElement();
		NetworkElement(const string,const string);

		// ¿Debería poder copiarse los nodos?
		// Constructor por copia:
		NetworkElement(const NetworkElement&);
		~NetworkElement() { }

        /*************************** SET & GET *********************************/

		void setName(string n) {name=n;}

		const string getName()const {return name;}
		const string getType()const {return type;}
		const NetworkElement *getFather()const {return father;}
		const NetworkElement *getSons()const {return sons;}
		const size_t getNumberSons() const {return numberSons;}
		// getSons: (?) Retorna el puntero al arreglo de punteros a NetworkElement hijos

		/************************** OPERADORES *********************************/

        NetworkElement& operator = (const NetworkElement &); // operador asignacion
        bool operator ==(const NetworkElement&) const; // operador comparacion

        /************************** MÉTODOS ************************************/

        NetworkElement& connectToElement(NetworkElement&);


/*

		void SetIzq( Nodoarbol *i){izq=i;}
		void SetDer( Nodoarbol *d){der=d;}
	*/
};
 #endif

#ifndef NETWORK_ELEMENT_CLASS_HPP
#define NETWORK_ELEMENT_CLASS_HPP

#include<iostream>

class errorsubindice
{
	public:
		errorsubindice()
		{
			cout<<"Mensaje emitido al crearse el objeto para la excepción \n Error de subíndice"<<endl;
		}
};


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

		void setName (string n) {name=n;}
		void setType (string t) {type=t;}

		const string getName()const {return name;}
		const string getType()const {return type;}
		const NetworkElement* getFather()const {return father;}
		const size_t getNumberSons() const {return numberSons;}		
		const NetworkElement* getSons()const {return sons;}
		const NetworkElement* getSons(const int)const;
		

		// getSons(): Sin argumentos, retorna el puntero al arreglo de punteros a NetworkElement hijos
		// getSons(int): Con arguments, retorna el puntero de determinado hijo

		/************************** OPERADORES *********************************/

        NetworkElement& operator = (const NetworkElement &); // operador asignacion
        bool operator == (const NetworkElement&) const; // operador comparacion igualdad
		bool operator != (const NetworkElement&) const; // operador comparacion desigualdad

        /************************** MÉTODOS ************************************/

		// Se asume que se conecta al ingresar: hijo --> padre
        NetworkElement& connectToElement(NetworkElement&);
		
};
 #endif

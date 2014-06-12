#ifndef NETWORK_ELEMENT_CLASS_HPP
#define NETWORK_ELEMENT_CLASS_HPP

#include<iostream>
#include<vector>
#include "common.hpp"
#define EXIST 0
#define NOT_EXIST 1
#define BACK_TREE 0;
#define DETECT_CYCLE 1




class errorsubindice
{
	public:
	errorsubindice()
	{
		cout<<"Mensaje emitido al crearse el objeto para la excepcion \n Error de subindice"<<endl;
	}
};


class NetworkElement
{
	private:

		string name;
		string type;
		NetworkElement *father_;
		NetworkElement **sons; // Sera un punetro a un arreglo dinamico de punteros, lo declaro asi ya que genera error declarar *sons[]
		size_t numberSons;

	public:

        /*********************** CONSTRUCTORES *********************************/
		NetworkElement();
		NetworkElement(const string,const string); // (NOMBRE, TIPO)

		// (preg)Deberia poder copiarse los nodos(preg)
		// Constructor por copia:
		NetworkElement(const NetworkElement&);
		~NetworkElement() { }

        /*************************** SET & GET *********************************/

		void setName (string n) {name=n;}
		void setType (string t) {type=t;}

		const string getName()const {return name;}
		const string getType()const {return type;}
		const NetworkElement* getFather()const {return father_;}
		const size_t getNumberSons() const {return numberSons;}
		NetworkElement** getSons() const {return sons;} // Revisar no me deja el compilador retornar 'const NetworkElement**'
		const NetworkElement* getSons(const int)const;


		// getSons(): Sin argumentos, retorna el puntero al arreglo de punteros a NetworkElement hijos
		// getSons(int): Con argumentos, retorna el puntero de determinado hijo

		/************************** OPERADORES *********************************/

        NetworkElement& operator = (const NetworkElement &); // operador asignacion
        bool operator == (const NetworkElement&) const; // operador comparacion igualdad
		bool operator != (const NetworkElement&) const; // operador comparacion desigualdad
		NetworkElement& operator [ ](int);

        /************************** MeTODOS ************************************/

		// Se asume que se conecta al ingresar: hijo --> padre
        NetworkElement& connectToElement(NetworkElement&);

		void showContent(ostream&);


        /************************** MeTODOS  DE RECORRIDO DE ARBOL************************************/


		friend int recorrido(NetworkElement* ,int&,vector <NetworkElement*>&temp);
		friend int comparator(NetworkElement* ,int&,vector <NetworkElement*>&temp);
		void validateCycle();
		void validateIconnection(int);
		void isRepeaten();
};



 #endif

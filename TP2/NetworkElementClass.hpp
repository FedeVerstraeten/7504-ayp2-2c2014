#ifndef NETWORK_ELEMENT_CLASS_HPP
#define NETWORK_ELEMENT_CLASS_HPP

#include<iostream>
#include<vector>
#include "common.hpp"
#define EXIST 0
#define NOT_EXIST 1
#define BACK_TREE 0;
#define DETECT_CYCLE 1
#define ROOT 1
#define ONE 1//valida que no se repitan mas de un NetworkElement



class errorsubindice
{
	public:
	errorsubindice()
	{
		cerr<<"Error de subíndice"<<endl;
	}
};


class NetworkElement
{
	private:

		string name;
		string type;
		NetworkElement *father_;
		NetworkElement **sons; // Será un punetro a un arreglo dinamico de punteros, lo declaro así ya que genera error declarar *sons[]
		size_t numberSons;
		statusHFC_t status;
		size_t threshold;

	public:

        /*********************** CONSTRUCTORES *********************************/
		NetworkElement();
		NetworkElement(const string,const string); // (NOMBRE, TIPO)

		// ¿Debería poder copiarse los nodos?
		// Constructor por copia:
		NetworkElement(const NetworkElement&);
		~NetworkElement();

        /*************************** SET & GET *********************************/

		void setName (string n) {name=n;}
		void setType (string t) {type=t;}
		void setStatusOK();
		void setStatusFault();
		//void setInferenceFault() {status=FAULT_INFERENCE;} //Usar para hacer pruebas
		void setThreshold(size_t);

		const string getName()const {return name;}
		const string getType()const {return type;}
		const NetworkElement* getFather()const {return father_;}
		const size_t getNumberSons() const {return numberSons;}
		NetworkElement** getSons() const {return sons;} // Revisar no me deja el compilador retornar 'const NetworkElement**'
		const NetworkElement* getSons(const int)const;
		const statusHFC_t getStatus() const {return status;} // Retorna OK o algun tipo de falla
        const size_t getThreshold() const {return threshold;}

		// getSons(): Sin argumentos, retorna el puntero al arreglo de punteros a NetworkElement hijos
		// getSons(int): Con argumentos, retorna el puntero de determinado hijo

		/************************** OPERADORES *********************************/

        NetworkElement& operator = (const NetworkElement &); // operador asignacion
        bool operator == (const NetworkElement&) const; // operador comparacion igualdad
		bool operator != (const NetworkElement&) const; // operador comparacion desigualdad
		NetworkElement& operator [ ](int);

        /************************** MÉTODOS ************************************/

		// Se asume que se conecta al ingresar: hijo --> padre
        NetworkElement& connectToElement(NetworkElement&);

		// Funciones de impresion
		void showContent(ostream&);
		void showElements(ostream&);
		void showConnections(ostream&);
		void showStatus(ostream&);


		// Funciones gestor de fallas

		void propagateFaultManual(); //Propaga fallas manuales en profundidad del arbol
		void clearFaultManual(); // Elimina las fallas manuales progadas
        void inferenceFault();
        int Printconnection();
        int PrintElements();

        /************************** MÉTODOS  DE RECORRIDO DE ARBOL************************************/

		friend int recorrido(NetworkElement* ,int&,vector <NetworkElement*>&temp);
		friend int comparator(NetworkElement* ,int&,vector <NetworkElement*>&temp);
		bool validateCycle();
		bool validateIconnection(int);
		bool isRepeaten(vector <NetworkElement>&);
		// Funcion validacion de jerarquía de los elementos
		bool validateHierarchy(NetworkElement&);

};



 #endif

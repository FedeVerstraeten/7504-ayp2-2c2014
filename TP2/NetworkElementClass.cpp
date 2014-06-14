#include <iostream>
#include "NetworkElementClass.hpp"



/********************************** CONSTRUCTORES ***************************************/

NetworkElement :: NetworkElement()
{
	name=" ";
	type=" ";
	father_=NULL;
	sons=NULL;
	numberSons=0;
	status=true;
	//cout<<"Constructor sin argumentos"<<endl;
}

NetworkElement :: NetworkElement(const string n,const string t)
{
	name=n;
	type=t;
	father_=NULL;
	sons=NULL;
	numberSons=0;
	status=true;
	//cout<<"Constructor con argumentos"<<endl;
}

NetworkElement :: NetworkElement(const NetworkElement &element)
{
	name=element.name;
	type=element.type; // Por defecto dejo Cable Modem, luego se cambiará
	father_=element.father_;
	numberSons=0;
	sons=NULL;
	status=true;

	if(element.numberSons!=0)
	{
		numberSons=element.numberSons;

		// Pido memoria para un arreglo de punteros a NetworkElement segun
		// el largo indicado por element.numberSons
		sons=new NetworkElement* [element.numberSons];

		for(unsigned int i=0 ; i<numberSons ; i++)
		{
			sons[i]=element.sons[i];
			// verificar si esta es la notación correcta o sons[i]=element[i].sons;
		}
	}
	//  cout<<"Constructor por copia"<<endl;
}

NetworkElement :: ~NetworkElement()
{
	delete [] sons;
	//cout<< "Destruyendo elementos"<<endl;
}

/*************************************** SET & GET ********************************************/

const NetworkElement* NetworkElement :: getSons(const int subscript)const
{
	if( (subscript < 0) || (subscript > (int) numberSons) ) throw errorsubindice();
	// Esto no me convence, se los dejo para que busquen una idea mejor.
	// Lo saqué de un ejemplo que hizo la profesora. Arroja una excepción a la clase errorsubindice,
	// que está en NetworkElementClass.hpp

	else	return sons [subscript]; // Retorna el puntero del hijo indicado por el subíndice 'subscript', del vector sons

}

/************************************** OPERADORES ********************************************/

// ATENCIÓN: El operador '=' para los NetworkElement lo escribí pensando en que algún momento
// se precise guardar por lo que fuere un elemento en otro auxiliar donde no se ha guardado
// nada previamente ni inicalizado, ejemplo:
//
// NetworkElement cm1(CM1,CM); ----- creo el objeto y lo cargo con el constructor con argumentos
// NetworkElement aux; ------------- creo un objeto auxiliar, sin inicializar.
// aux = cm1; ---------------------- realizo la asignacion
// hacer_algo(aux); ---------------- realizo algo mediante una función con ese objeto
//
//
// Pero finalmente sea el aux o cm1 deben ser eliminados, dado el caracter del TP1 no puedo tener
// dos elementos que sean el mismo (mismo tipo, padres e hijos) pero con distinto nombre.
// Además hay que tener cuidado de hacerlo siguiente que puede ocasionar errores:
//
// NetworkElement cm1(CM1,CM), cm2(CM2,CM);
// cm1=cm2;
//

NetworkElement& NetworkElement :: operator = (const NetworkElement &Relement)
{
	// Relement: element a la derecha del operador asignación,
	// que asigna al objeto sobre el que actúa.

	// Se chequea que la dirección de memoria del objeto
	// pasado no sea la misma con el que estamos aplicando el
	// metodo, para evitar auto asignaciones. Ejemplo: a=a;

	if ( &Relement != this )
	{
		name=Relement.name;
		type=Relement.type;
		father_=Relement.father_;

		if ( numberSons != Relement.numberSons )
		{
			NetworkElement **auxSons; 	// Utilizo un elemento auxiliar para los punteros a los hijos. Será un arreglo dinámico de punteros

			auxSons = new NetworkElement* [Relement.numberSons]; //se pide espacio; si no se obtiene new lanza bad_alloc
			delete [] sons; 				 // Si llegó acá es que obtuvo el espacio; libera el anterior espacio
			numberSons = Relement.numberSons;
			sons = auxSons; 							// Apunta a la nueva zona

			for (unsigned int i = 0 ; i < numberSons ; i++ )
				sons[i] = Relement.sons[i]; 			// Copia el array en el nuevo objeto

			return *this; 						// Al retornar una referencia permite x = y = z;
		}



		else
		{
			for (unsigned int i = 0 ; i < numberSons ; i++ )
				sons[i] = Relement.sons[i];
			return *this;
		}

	}

	return *this;

}

bool NetworkElement :: operator == (const NetworkElement &element) const
{
	// Solo estoy considerando la igualdad si los campos de nombre
	// y tipo son los mismos. Se considera que nunca debería haber
	// dos elementos que se llamen iguales y que tengas hijos y
	// padres distintos.

	if (name == element.name && type == element.type) return true;

	else return false;
}

bool NetworkElement :: operator != (const NetworkElement& element) const
{
	// Idem que el caso del operador '==' pero comparando la desigualdad

	if (name != element.name && type != element.type) return true;

	else return false;
}

/************************************** MÉTODOS ********************************************/

// El método connectToElement lo supongo su funcionamiento como que previo a elanzar padres
// e hijos respectivamente se encuentran validadas los casos de jerarquía donde determinados
// elementos no se puede unir, como un "nodo óptico(node)" con un "cable modem (cm)"
//
// IMPORTANTE: Se supone que la conección correcta se realizará de la siguiente manera al
// invocar el método.
// 						padre.connectToElement ( hijo )

NetworkElement& NetworkElement :: connectToElement (NetworkElement &element)
{
	if(this != &element)
	{
		// Se chequea que la dirección de memoria del objeto
		// pasado no sea la misma con el que estamos aplicando el
		// metodo, para evitar auto asignaciones. Ejemplo: a=a;

		if(element.father_ ==NULL) // Valido que el nuevo elemento no tenga padre ya
		{
			// Enlace: padre <-- hijo

			element.father_ = this; // Asigno la dirección del objeto sobre el que trabajo, al campo padre del nuevo elemento (hijo)

			// Enlace: hijo --> padre

			NetworkElement **auxSons; 	// Utilizo un elemento auxiliar para los punteros a los hijos. Será un arreglo dinámico de punteros

			auxSons = new NetworkElement* [numberSons+1]; // Se pide espacio; si no se obtiene new lanza bad_alloc


			if(sons!=NULL)
			{
				for(unsigned int i=0 ; i<numberSons ; i++)
				{
					auxSons[i] = sons[i];
				}
			}
			auxSons[numberSons] = &element; // Guardo la dirección de memoria del que será el nuevo hijo

			delete [] sons; 	// Si llegó acá es que obtuvo el espacio; libera el anterior espacio para sons
			sons = auxSons;		// Asigno a sons el puntero que apunta al nuevo array de hijos
			
			numberSons++;
		}

		else
		{
			// Buscar que devolver en caso de que no se pueda unir, todavía no se me ocurrió
			cout<<"Imposible el elemento que se desea conectar ya tiene padre"<<endl;
		}
	}
	return *this;
}

/*	Funcion que valida la jerarquía, evita que se realicen conexiones prohibidas del tipo
	por ejemplo: CM1 --> CM2 ó HUB1 --> CM2
	
	padre.validateHierarchy(hijo)

*/
bool NetworkElement :: validateHierarchy(NetworkElement &element)
{
	
	if(type=="CM")
	{	if(element.type=="CM" || element.type=="Amp" || element.type=="Node" || element.type=="Hub" ) return false; }

	else if(type=="Amp" || type=="Node")
	{	if(element.type=="Hub" || element.type=="Node") return false; }

	else if(type=="Hub")
	{	if(element.type=="Hub" || element.type=="Amp" || element.type=="CM") return false; }
	
	
	return true;
}


void NetworkElement :: showContent(ostream& os)
{
	os  <<"***** Elemento de red *****"<<endl
		<<"NetworkElement "<<name//<<endl
		<<" "<<type<<endl
		<<"Cantidad de hijos: "<<numberSons<<endl;
	
	if(status) os<<"Estado: OK"<<endl;
	
	else os<<"Estado: Fault"<<endl;
		
	
	if(numberSons!=0)
	{
		for(unsigned int i=0 ; i < numberSons; i++)
		os<<"Connection " << sons[i]->name <<" "<<  name << endl;
	}

}

void NetworkElement :: showElements(ostream& os)
{
	os <<"NetworkElement "<<name
	   <<" "<<type<<endl;
}

void NetworkElement :: showConnections(ostream& os)
{
	if(numberSons!=0)
	{
		for(unsigned int i=0 ; i < numberSons; i++)
		os<<"Connection " << sons[i]->name <<" "<<  name << endl;
	}
}

//suponemos que la memoria es estatica hasta este punto del código

void NetworkElement ::validateCycle()
{

	int vertice=0;
	vector <NetworkElement*> temp;//usar la clase vector y push_back ,arreglo dinamico...
	if((recorrido(this,vertice,temp))==DETECT_CYCLE)
	{
		// asignarle elemento desde donde quieres recorrer
	    // vertice contiene la cantidad de nodos que
    	// que pudieron ser recorridos.
		
		cout<< "Se en encontro un ciclo en:\t "<<temp.data()[vertice]->getName()<<endl;

	}
	else
		cout<<"Arbol sin ciclos"<<endl;
}

void NetworkElement ::validateIconnection(int numberNodes)
{

	int vertice=0;
	vector <NetworkElement*> temp;//usar la clase vector y push_back ,arreglo dinamico...
	if((recorrido(this,vertice,temp))!=DETECT_CYCLE)
	{
		if(vertice + ROOT < numberNodes)
		{
			cout<< "Arbol inconexo."<<endl
				<< "Cantidad de vertices registrados:\t"<<vertice<<endl;
		}
		else
			cout<< "Arbol conexo"<<endl;
	}
}


// Recorrer vector de elementos y revisar si hay elementos repetidos
void NetworkElement :: isRepeaten(vector <NetworkElement>& vectorElement)
{
		
	int vertice=0,repeat=0;
	vector <NetworkElement*> temp;//usar la clase vector y push_back ,arreglo dinamico...
	if((recorrido(this,vertice,temp))!=DETECT_CYCLE)
	{
		for(size_t i=0;i<vectorElement.size();i++)
		{
			// En la posicion "vertice" del vector "temp" esta el elemento detectado como posible 
			// candidato a estar repetido, ya que la funcion "recorrido" lo detecta como un ciclo.
			
		//	NetworkElement *aux1;
		//	aux1=temp.data()[vertice];
		//	aux2=
			if(*(temp.data()[vertice])==vectorElement.data()[i]) repeat++;
		}
		if(repeat>ONE){
			cout<< "Elemento repetido:\t "<<temp.data()[vertice]->getName()<<endl;
		}
		
	}


}

/************************************** FUNCIONES FRIEND ********************************************/

//Está función es la que se encarga de recorrer el árbol creado previamente, recorre por profundidad,saliendo de la misma en caso de detectar ciclos
//o arboles inconexos.


//Recibe un entero  por referencia 'vertice' que guarda el numero de conexiones realizadas, y un arreglo de punteros a NetworkElement temporal,
//donde se guardan la direccion de memoria de los objetos recorridos.
//La función trabaja de manera recursiva e iterativa garanztizando que siempre que el arbol este armado puede vistar a todos los nodos del mismo
//La función recorre por hijos
//El valor final que queda guardado en la variable 'vertice' es la cantidad de nodos del arbol excepto la raiz (ver macro ROOT), luego de realizar la funcion "recorrido()".


int recorrido(NetworkElement *v,int &vertice,vector <NetworkElement*> &temp){

	if(comparator(v,vertice,temp)==EXIST){return DETECT_CYCLE;}
	temp.push_back(v);
	//cout<<"Nombres guardados: "<<v->getName()<<endl;
    if(temp[vertice]->numberSons==0){ return BACK_TREE;}
	else
        for(size_t i=0;i<v->numberSons;i++)
		{
			vertice++;
			if((recorrido(v->sons[i],vertice,temp))==DETECT_CYCLE){return DETECT_CYCLE;}
        }
		return BACK_TREE;
}

//Esta función verifica si el elemeto está repetido, entonces se deriva en un ciclo
int comparator(NetworkElement *v,int &vertice,vector<NetworkElement*>&temp){


	for(int i=0;i<vertice;i++){

		if(v->name==temp.data()[i]->name)
		{
			temp.push_back(v);

			return EXIST;
		}

	}

	return NOT_EXIST;
}



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
	//cout<<"Constructor sin argumentos"<<endl;
}

NetworkElement :: NetworkElement(const string n,const string t)
{
	name=n;
	type=t;
	father_=NULL;
	sons=NULL;
	numberSons=0;
	//cout<<"Constructor con argumentos"<<endl;
}

NetworkElement :: NetworkElement(const NetworkElement &element)
{
	name=element.name;
	type=element.type; // Por defecto dejo Cable Modem, luego se cambiara
	father_=element.father_;
	numberSons=0;
	sons=NULL;
	if(element.numberSons!=0)
	{
		numberSons=element.numberSons;

		sons=new NetworkElement* [element.numberSons];

		for(unsigned int i=0 ; i<numberSons ; i++)
		{
			sons[i]=element.sons[i];
		}
	}
	
}

NetworkElement :: ~NetworkElement()
{
	delete [] sons;
	
}

/*************************************** SET & GET ********************************************/

const NetworkElement* NetworkElement :: getSons(const int subscript)const
{
	if( (subscript < 0) || (subscript > (int) numberSons) ) throw errorsubindice();

	else	return sons [subscript]; 

}

/************************************** OPERADORES ********************************************/

NetworkElement& NetworkElement :: operator = (const NetworkElement &Relement)
{
	// Relement: element a la derecha del operador asignacion,
	// que asigna al objeto sobre el que actua.

	// Se chequea que la direccion de memoria del objeto
	// pasado no sea la misma con el que estamos aplicando el
	// metodo, para evitar auto asignaciones. Ejemplo: a=a;

	if ( &Relement != this )
	{
		name=Relement.name;
		type=Relement.type;
		father_=Relement.father_;

		if ( numberSons != Relement.numberSons )
		{
			NetworkElement **auxSons; 	// Utilizo un elemento auxiliar para los punteros a los hijos. Sera un arreglo dinamico de punteros

			auxSons = new NetworkElement* [Relement.numberSons]; //se pide espacio; si no se obtiene new lanza bad_alloc
			delete [] sons; 				 // Si llego aca es que obtuvo el espacio; libera el anterior espacio
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
	// y tipo son los mismos. Se considera que nunca deberia haber
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

/************************************** MeTODOS ********************************************/

// El metodo connectToElement lo supongo su funcionamiento como que previo a elanzar padres
// e hijos respectivamente se encuentran validadas los casos de jerarquia donde determinados
// elementos no se puede unir, como un "nodo optico(node)" con un "cable modem (cm)"
//
// IMPORTANTE: Se supone que la coneccion correcta se realizara de la siguiente manera al
// invocar el metodo.
// 						padre.connectToElement ( hijo )

NetworkElement& NetworkElement :: connectToElement (NetworkElement &element)
{
	if(this != &element)
	{
		// Se chequea que la direccion de memoria del objeto
		// pasado no sea la misma con el que estamos aplicando el
		// metodo, para evitar auto asignaciones. Ejemplo: a=a;

		if(element.father_ ==NULL) // Valido que el nuevo elemento no tenga padre ya
		{
			// Enlace: padre <-- hijo

			element.father_ = this; // Asigno la direccion del objeto sobre el que trabajo, al campo padre del nuevo elemento (hijo)

			// Enlace: hijo --> padre

			NetworkElement **auxSons; 	// Utilizo un elemento auxiliar para los punteros a los hijos. Sera un arreglo dinamico de punteros

			auxSons = new NetworkElement* [numberSons+1]; // Se pide espacio; si no se obtiene new lanza bad_alloc


			if(sons!=NULL)
			{
				for(unsigned int i=0 ; i<numberSons ; i++)
				{
					auxSons[i] = sons[i];
				}
			}
			auxSons[numberSons] = &element; // Guardo la direccion de memoria del que sera el nuevo hijo

			delete [] sons; 	// Si llego aca es que obtuvo el espacio; libera el anterior espacio para sons
			sons = auxSons;		// Asigno a sons el puntero que apunta al nuevo array de hijos
			
			numberSons++;
		}

		else
		{
			// Buscar que devolver en caso de que no se pueda unir, todavia no se me ocurrio
			cout<<"Imposible el elemento que se desea conectar ya tiene padre"<<endl;
		}
	}
	return *this;
}

/*	Funcion que valida la jerarquia, evita que se realicen conexiones prohibidas del tipo
	por ejemplo: CM1 --> CM2 o HUB1 --> CM2
	
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
		os//<<"***** Elemento de red *****"<<endl
		<<"NetworkElement "<<name//<<endl
		<<" "<<type<<endl;
		//<<"Cantidad de hijos: "<<numberSons<<endl;
//	os << "number of sons: " <<numberSons << endl;
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

void NetworkElement ::validateCycle()
{

	int vertice=0;
	vector <NetworkElement*> temp;
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
	vector <NetworkElement*> temp;
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
	vector <NetworkElement*> temp;
	if((recorrido(this,vertice,temp))!=DETECT_CYCLE)
	{
		for(size_t i=0;i<vectorElement.size();i++)
		{
			// En la posicion "vertice" del vector "temp" esta el elemento detectado como posible 
			// candidato a estar repetido, ya que la funcion "recorrido" lo detecta como un ciclo.

			if(*(temp.data()[vertice])==vectorElement.data()[i]) repeat++;
		}
		if(repeat>ONE){
			cout<< "Elemento repetido:\t "<<temp.data()[vertice]->getName()<<endl;
		}
		
	}


}



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

//Esta funcion verifica si el elemeto esta repetido, entonces se deriva en un ciclo
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



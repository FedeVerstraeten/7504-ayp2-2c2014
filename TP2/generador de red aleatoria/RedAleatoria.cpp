#include <iostream>
#include <cstdlib> 
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <fstream>

#define ELEMENTS_OF_RED 3//tipos elementos de la red
#define MAX_ELEMENTS_OF_RED 1000  
#define ELEMENT_HUB 0
using namespace std;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++Prototipos de funciones++++++++++++++++++++++++++++++++++++++++++++++++++++*/
string numberToString(int number);
void saveToNetworkElements(vector <string>&,int index,size_t v );
void printToNetwork(ostream &os,vector <string>& elements );
void randomindex(vector<int>& ,size_t size);
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************Diccionario de elementos*********************************************************/

string elementsOfRed[] = {"Hub","Node","Amp","CM"};

/**************************************************************************************************************************/


int main (void)
{

	ofstream os("Networking.txt");
	

	vector <string>arrayToAmp;
	vector <string>arrayToNode;
	vector <string>arrayToCM;
	size_t j=2,k=1,l=1,m=1;
	vector<string>arrayElements;
	vector<string>arrayConnections;


	srand(time(NULL));	


//Impresion del Hub	
	saveToNetworkElements(arrayElements,ELEMENT_HUB,j);

	//Creacion e Impresion de los NetworkElements
	for (size_t i=0 ; i<MAX_ELEMENTS_OF_RED ; i++)
	{
		
		int index =rand() % ELEMENTS_OF_RED; //guardo el valor aleatorio para generar el elemento de la red.
	
		if(elementsOfRed[index]==elementsOfRed[1]){
		
			arrayToNode.push_back(elementsOfRed[index]+numberToString(k++));
			saveToNetworkElements(arrayElements,index,k);
						
		}
		else if(elementsOfRed[index]==elementsOfRed[2]){
			arrayToAmp.push_back(elementsOfRed[index]+numberToString(l++));
			saveToNetworkElements(arrayElements,index,l);
			


    		}
		else if(elementsOfRed[index]==elementsOfRed[3]){
   
			arrayToCM.push_back(elementsOfRed[index]+numberToString(m++));
			saveToNetworkElements(arrayElements,index,m);


    		}

	}


	//Grabado de la nombre de la red
	os<<"NetworkName MyNetwork"<<endl;

	printToNetwork(os,arrayElements);
	
	//guardo las conexiones con Hub
	for(size_t i=0;i<arrayToNode.size();i++){
	
	
		string aux_1("Connection"),aux_2;
        	aux_2=aux_1+ " "+arrayToNode[i]+" "+elementsOfRed[ELEMENT_HUB]+"1";
	        arrayConnections.push_back(aux_2);
	
	}
	//guardo las conexiones con nodes
	vector<int>index_1(arrayToAmp.size());
	vector<int>index_2(arrayToNode.size());
	//Planto semilla
	srand(time(NULL));
	randomindex(index_1,arrayToAmp.size());
	randomindex(index_2,arrayToNode.size());
	

	for(size_t i=0;i<arrayToAmp.size();i++){
	

		string aux_1("Connection"),aux_2;
	        aux_2=aux_1+ " "+arrayToAmp[index_1[i]]+" "+arrayToNode[index_2[i]];
	        arrayConnections.push_back(aux_2);

	}
		

	//guardo las conexiones con Amps
	vector<int>index_3(arrayToCM.size());
	vector<int>index_4(arrayToAmp.size());
	//Planto semilla
	srand(time(NULL));
	randomindex(index_3,arrayToCM.size());
	randomindex(index_4,arrayToAmp.size());
	//salvo las conexiones
	for(size_t i=0;i<arrayToCM.size();i++){
	
		string aux_1("Connection"),aux_2;
        	aux_2=aux_1+ " "+arrayToCM[index_3[i]]+" "+arrayToAmp[index_4[i]];
	        arrayConnections.push_back(aux_2);
	}
		
	//Imprimo aleatoriamente sobre el archivo
	printToNetwork(os,arrayConnections);

  return 0 ;
} //fin de main.


//Esta funcion convierte el un entero en un string

string numberToString(int number){


	stringstream stream;
	string str;

	stream << number;
	str = stream.str(); 

	return str;
}

//Esta funcion guarda en un arreglo temporal los elementos de la red

void saveToNetworkElements(vector <string>&array,int index,size_t v ){

	string aux_1("NetworkElement"),aux_2;
	aux_2=aux_1+ " "+elementsOfRed[index]+numberToString(v-1)+" "+elementsOfRed[index];
	array.push_back(aux_2);			



}

//funcion que imprime los NetworkElements
void printToNetwork(ostream &os,vector <string>& elements ){

	srand(time(NULL));
	size_t number=elements.size();			
	vector<int>random(number);
	for(size_t i=0;i<elements.size();i++){
	
		randomindex(random,number);
		for(i=0;i<number;i++){

			os<<elements[random[i]]<<endl;
		}	


	}


}

//Esta funcion me devuelve un arreglo con enteros aleatorios sin repetirse

void randomindex(vector<int>&random,size_t size){
	
	int n=0;
	size_t c=0,j;
	
	for( j = 0; j < size; j++)
		random[j] = 0;

	srand( time(NULL) );

	while( c != size )
	{
		n = (rand()%size)+1;

		for( size_t i = 0; i < size; i++)
		{
			if(random[i] == n)
				break;

			if(random[i] == 0)
			{
				random[i] = n;
				c++;
				break;
			}
		}
	}

	for(j=0;j<size;j++){

		random[j]=random[j]-1;

	}
}

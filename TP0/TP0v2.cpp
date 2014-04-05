//HECHO: Si la cantidad de lineas es mayor a MAX_LINES_DEFAULT, entonces hay que hacer incremento de tamaño
//con alguna estrategia de crecimiento de memoria.---> ESTO LO RESLOVIÓ CRISTIAN: folder: Carga_de_archivos_en_memoria-->file_load.cpp, file_load.hpp.
//HECHO: Validar la primer línea con el nombre de la red.---> EStO LO RESOLVIÓ CHARLIE. Commit dae8280. Es la version inicial.
//PENDIENTE: Probar distintos archivos de texto para tener un mínimo de robusticidad.
//PENDIENTE: La funcion impresión printElements() debe imprimir por flujo de salida en vez de por pantalla-

#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;
#define MAX_LINES_DEFAULT 100

//Prototipos
void uploadLine(string, string **);
void printLine(string);
void processLine(string);
void printElements(int *);
void printNetworkName(string);
int  searchNetworkName(string**);

//Diccionarios: HAY QUE ACORDAR UNA NOMNECLATURA PARA STRINGS , VARIABLES y ARREGLOS.
string network_struct[]   = {"NetworkName","NetworkElement","Connection"};
string network_element_type[] = {"Hub","Node","Amp","CM"};
string network_element_nam[MAX_LINES_DEFAULT];

int number_of_elements[5];// = {"Number_of_Hubs","Number_of_Nodes", "Number_of_Amps","Number_of_CM", "Number_of_Connections"};
static size_t   n=0, i=0;

int main(void)
{
    string *lines_array[MAX_LINES_DEFAULT], line;

    ifstream in("Networking02.txt"); //NOTA: funciona como ruta relativa
    if (!in.is_open())
    {
            perror("error while opening file");
            cout << "Error opening file";
    }

    while(getline(in,line)) uploadLine(line,lines_array); // lines_array es el vector de punteros a string.

    cout<<endl<<"total de: "<<n<<"lineas."<<endl<<endl; // esta línea es un flag para ver si n se computó bien.

    if (in.bad()) perror("error while reading file");
    int founded=0;

    for(i=1;i<n;i++)
    {
            founded=searchNetworkName(lines_array);
    }
    printNetworkName((*lines_array[0])); // esta tiene el contenido del nombre de la red
    for(i=1;i<n;i++)    processLine((*lines_array[i]));
    printElements(number_of_elements);     //esta funcion printElements() es la que se encarga de la salida por pantalla.


    return 0;
}


void uploadLine(string line, string** lines_array)
{
            lines_array[n]=new string;
            (*lines_array[n])=line;
            printLine((*lines_array[n]));
            n++;
}


void processLine(string text_line)
{
    istringstream iss(text_line);
    string word[3];
    iss >> word[0];
    if(word[0]==network_struct[1])
    {
        iss >> word[1];
        iss >> word[2];
        size_t i;
        for(i=0;i<4;i++)
        {
         if(word[2]==network_element_type[i]) number_of_elements[i]++;
        }
    }
    if(word[0]==network_struct[2])   number_of_elements[4]++;

}

void printLine(string line)
{
    cout << line << "\n";
}

int  searchNetworkName(string* lines_array)
{

}

void printNetworkName(string name_line)
//esta funcion asume que se le pasa un string
//que contiene "NetworkName <nombre>",
//donde nombre es el nombre a imprimir
{
    string aux, network_name;
    istringstream iss(name_line);
    iss >> aux;
    if(aux == network_struct[0])
    {
        iss >> network_name;
        cout << network_name << "\n";
    }
    else     cout << "no hay nombre de red" << "\n";
}

void printElements(int number_of_elements[])
{
    cout << number_of_elements[0] << " Hubs"<<"\n";
    cout << number_of_elements[1] << " Nodes"<<"\n";
    cout << number_of_elements[2] << " Amps"<<"\n";
    cout << number_of_elements[3] << " CMs"<<"\n";
    cout << number_of_elements[4] << " Connections"<<"\n";
}

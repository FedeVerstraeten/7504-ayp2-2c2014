//HECHO: Si la cantidad de lineas es mayor a MAX_LINES_DEFAULT, entonces hay que hacer incremento de tamaño
//con alguna estrategia de crecimiento de memoria.---> ESTO LO RESLOVIÓ CRISTIAN: folder: Carga_de_archivos_en_memoria-->file_load.cpp, file_load.hpp.
//PENDIENTE: Validar la primer línea con el nombre de la red.
//PENDIENTE: Probar distintos archivos de texto para tener un mínimo de robusticidad.
//PENDIENTE: La funcion impresión print_elements() debe imprimir por flujo de salida en vez de por pantalla-

#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;
#define MAX_LINES_DEFAULT 100

//Prototipos
void process_line(string, string **);
void print_line(string);
void parse_line(string);
void print_elements(int *);
void printNetworkName(string);

//Diccionarios
string NetworkStruct[]   = {"NetworkName","NetworkElement","Connection"};
string NetworkElementType[] = {"Hub","Node","Amp","CM"};
string NetworkElementName[MAX_LINES_DEFAULT];

int Number_of_Elements[5];// = {"Number_of_Hubs","Number_of_Nodes", "Number_of_Amps","Number_of_CM", "Number_of_Connections"};
static size_t   n=0, i=0;

int main(void)
{
    string *lines_array[MAX_LINES_DEFAULT], line;

    ifstream in("Networking.txt"); //NOTA: funciona como ruta relativa
    if (!in.is_open()){
            perror("error while opening file");
            cout << "Error opening file";
    }

    while(getline(in,line)){
            process_line(line,lines_array); // lines_array es el vector de punteros a string.
            }
    cout<<endl<<"total de: "<<n<<"lineas."<<endl<<endl; // esta línea es un flag para ver si n se computó bien.
    if (in.bad())
        perror("error while reading file");

    printNetworkName((*lines_array[0])); // esta tiene el contenido del nombre de la red)
    for(i=1;i<n;i++)    parse_line((*lines_array[i]));
    print_elements(Number_of_Elements);     //esta funcion print_elements() es la que se encarga de la salida por pantalla.


    return 0;
}


void process_line(string line, string** lines_array)
{
            lines_array[n]=new string;
            (*lines_array[n])=line;
            print_line((*lines_array[n]));
            n++;
}


void parse_line(string text_line)
{
    istringstream iss(text_line);
    string word[3];
    iss >> word[0];
    if(word[0]==NetworkStruct[1])
    {
        iss >> word[1];
        iss >> word[2];
        size_t i;
        for(i=0;i<4;i++)
        {
         if(word[2]==NetworkElementType[i]) Number_of_Elements[i]++;
        }
    }
    if(word[0]==NetworkStruct[2])   Number_of_Elements[4]++;

}

void print_line(string line)
{
    cout << line << "\n";
}

void printNetworkName(string name_line)
{
    string aux, network_name;
    istringstream iss(name_line);
    iss >> aux;
    if(aux == NetworkStruct[0])
    {
        iss >> network_name;
        cout << network_name << "\n";
    }
    else     cout << "no hay nombre de red" << "\n";
}

void print_elements(int Number_of_Elements[]){
    cout << Number_of_Elements[0] << " Hubs"<<"\n";
    cout << Number_of_Elements[1] << " Nodes"<<"\n";
    cout << Number_of_Elements[2] << " Amps"<<"\n";
    cout << Number_of_Elements[3] << " CMs"<<"\n";
    cout << Number_of_Elements[4] << " Connections"<<"\n";
}

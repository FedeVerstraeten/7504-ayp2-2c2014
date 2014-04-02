//Charlie: Actualizo. El programa levanta el archivo de texto chequeando contra eofbit.
//En la variable n se cuenta la cantidad de lineas.
//PENDIENTE: Si la cantidad de lineas es mayor a MAX_LINES_DEFAULT, entonces hay que hacer incremento de tamaño
//con alguna estrategia de crecimiento de memoria.

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
//Diccionarios
string NetworkStructure[]   = {"NetworkName","NetworkElement","Connection"};
string NetworkElementType[] = {"Hub","Node","Amp","CM"};
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
            process_line(line,lines_array);
            }


    if (in.bad())
        perror("error while reading file");

    cout<<endl<<"total de: "<<n<<"lineas."<<endl<<endl;
    for(i=1;i<n;i++)    parse_line((*lines_array[i]));
    print_elements(Number_of_Elements);


    return 0;
}


void process_line(string line, string** lines_array){
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
    if(word[0]==NetworkStructure[1]){
        iss >> word[1];
        iss >> word[2];
        size_t i;
        for(i=0;i<4;i++){
         if(word[2]==NetworkElementType[i]) Number_of_Elements[i]++;
        }
    }
    if(word[0]==NetworkStructure[2]){
         Number_of_Elements[4]++;
     }

}

void print_line(string line){
    cout << line << "\n";
}

void print_elements(int Number_of_Elements[]){
    cout << Number_of_Elements[0] << " Hubs"<<"\n";
    cout << Number_of_Elements[1] << " Nodes"<<"\n";
    cout << Number_of_Elements[2] << " Amps"<<"\n";
    cout << Number_of_Elements[3] << " CMs"<<"\n";
    cout << Number_of_Elements[4] << " Connections"<<"\n";
}

//Charlie: Actualizo. El programa levanta el archivo de texto chequeando contra eofbit.
//En la variable n se cuenta la cantidad de lineas.
//PENDIENTE: Si la cantidad de lineas es mayor a MAX_LINES_DEFAULT, entonces hay que hacer incremento de tamaño
//con alguna estrategia de crecimiento de memoria.

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define MAX_LINES_DEFAULT 100

//Prototipos
void process_line(string, string **);
void print_line(string);
void parse_line(istream *);
void print_elements(int *);
//Diccionarios
string NetworkStructure[]   = {"NetworkName","NetworkElement","Connection"};
string NetworkElementType[] = {"Hub","Node","Amp","CM"};
int Number_of_Elements[sizeof(NetworkElementType)];// = {"Number_of_Hubs","Number_of_Nodes", "Number_of_Amps","Number_of_CM", "Number_of_Connections"};
static size_t   n=0, i=0;

int main(void)
{
    string *lines_array[MAX_LINES_DEFAULT], line;

    ifstream in("C:\Networking.txt"); //NOTA: funciona como ruta relativa
    if (!in.is_open()){
            perror("error while opening file");
            cout << "Error opening file";
    }

    while(getline(in,line)){
            process_line(line,lines_array);
             if(n) parse_line(&in);
        }

    if (in.bad())
        perror("error while reading file");

    cout<<"total de: "<<n<<"lineas."<<endl;
    print_elements(Number_of_Elements);
    return 0;
}


void process_line(string line, string** lines_array){ // se sugiere el uso de referencias
            lines_array[n]=new string;
            (*lines_array[n])=line;
            print_line((*lines_array[n]));
            delete lines_array[n];
            n++;
}


void parse_line(istream * file_1){
    string name, NetworkElement;
    size_t j;
     (*file_1) >> name; //cout<<name<<endl;//TEST_FLAG

     for(i=0;i<3;i++){
        if(name==NetworkStructure[i]){
            (*file_1) >> NetworkElement;
            }

         /*   for(j=0;j<3;j++){
                if(NetworkElement==NetworkElementType[j])
                    Number_of_Elements[j]++;
            }
        if(name==NetworkStructure[2]){
            (*file_1) >> NetworkElement;
        }*/
}
}

void print_line(string line){
    cout << line << "\n";
}
void print_elements(int Number_of_Elements[]){
    cout << Number_of_Elements[0] << " Hubs"<<"\n";
    cout << Number_of_Elements[1] << " Node"<<"\n";
    cout << Number_of_Elements[2] << " Amp"<<"\n";
    cout << Number_of_Elements[3] << " CM"<<"\n";
}

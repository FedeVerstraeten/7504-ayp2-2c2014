//Charlie: Actualizo. El programa levanta el archivo de texto chequeando contra eofbit.
//En la variable n se cuenta la cantidad de lineas.
//PENDIENTE: Si la cantidad de lineas es mayor a MAX_LINES_DEFAULT, entonces hay que hacer incremento de tamaño
//con alguna estrategia de crecimiento de memoria.

#include<iostream>
#include<fstream>
#include<string>

#define MAX_LINES_DEFAULT 100

using namespace std;

int main(void){

    size_t n=0;
    string *lines_array[MAX_LINES_DEFAULT], line;

    ifstream in("C:\Networking.txt"); //NOTA: funciona como ruta relativa
    if (!in.is_open()){
            perror("error while opening file");
            cout << "Error opening file";
    }

    while(getline(in,line)){
            lines_array[n]=new string;
            (*lines_array[n])=line;
            cout << (*lines_array[n]) << "\n";
            delete lines_array[n];
            n++;
        }
    if (in.bad())
        perror("error while reading file");
    cout<<"total de: "<<n<<"lineas."<<endl;
    return 0;
}

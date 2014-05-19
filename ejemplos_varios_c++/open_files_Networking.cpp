#include <iostream>
#include <fstream>
//using std::ifstream;
//using std::ios_base;
using namespace std;
//abrir archivo para escritura, si no existe, lo crea.

int main(void){

int number,i;

string NetworkStructure[]   = {"NetworkName","NetworkElement","Connection"};
string NetworkElementType[] = {"Hub","Node","Amp","CM"};

string name,Networkname, Networkelement;

ifstream file_1 ("C:\\Networking.txt"); //define el flujo de salida fich_1
if (!file_1) cout << "No se ha podido abrir el fichero";
else
{
     file_1 >> name;
     if(name==NetworkStructure[0]){
        file_1 >> Networkname;
     }
     else cout<<"Error en la primer palabra"<<endl;

     file_1 >> name; //cout<<name<<endl;//TEST_FLAG
     for(i=0;i<3;i++){
        if(name==NetworkStructure[i])
            file_1 >> Networkelement;
        }
}

cout<<Networkname<<endl;
cout<<Networkelement<<endl;
cout<<NetworkElementType[i]<<endl;//TEST_FLAG

 file_1.close();//Si un fichero no se cierra, es cerrado automáticamente cuando termina el programa
}

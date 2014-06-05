#include <iostream>
#include <fstream>
//using std::ifstream;
//using std::ios_base;
using namespace std;
//abrir archivo para escritura, si no existe, lo crea.

int main(void){

int number,i;

ifstream file_1 ("C:\\Networking.txt"); //define el flujo de salida fich_1
if (!file_1) cout << "No se ha podido abrir el fichero";
else{//do anything

}
 file_1.close();//Si un fichero no se cierra, es cerrado automáticamente cuando termina el programa
}

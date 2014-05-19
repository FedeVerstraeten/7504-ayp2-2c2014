#include <iostream>
#include <fstream>
using std::ofstream;
using std::ios_base;
//abrir archivo para escritura, si no existe, lo crea.

int main(void){
ofstream fich_1 ("C:\\Networking.txt"); //define el flujo de salida fich_1
ofstream fich_2 ("C:\\Networking.txt", ios_base::out); //define el flujo de salida fich_2
 if (fich_1)
 std::cout << "Apertura con éxito";
 else
 std::cout << "No se ha podido abrir el fichero";

 fich_1.close();//Si un fichero no se cierra, es cerrado automáticamente cuando termina el programa
}

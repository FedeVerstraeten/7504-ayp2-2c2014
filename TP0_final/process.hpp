#ifndef PROCESS_HPP_INCLUDED
#define PROCESS_HPP_INCLUDED

#include <string>
#include <sstream>
#include"common.hpp"
status_t processLine(string line, string name1, string name2);
void inputFromConsole(void);
//void tokenLine(string);
//status_t checkTokens(string &name, string &type)

#endif // PROCESS_HPP_INCLUDED

/*
status_t status;
string aux[2];
//carga en memoria
for(i=0; i<EOF ; i++)
{
   status=processLine(line[i], aux[1] , aux[2]);
    if(status==OK NetType)
    {
        //Crear objeto (aux[0]=name, aux[1]=type);
        //Asignar al vector de Objetos
    }
    if(status==OK Names)//aca se supone que ya se crearon TODOS los objetos necesarios
    {
        //buscar name 1
        //buscar name 2
        //Estan OK los nombres? (si estan mal, destruir todo y salir)
        //Crear conexiones(aux[0]=name1, aux[1]=name2);
    }
    if(status==ERROR_TEXT_LINE_INVALID)
    {
        //Delete todo lo creado para que no haya fugas de memoria
        //Imprimo errores
        //final del programa
}
}
*/

#include"process.hpp"
#include "printers.hpp"
//Diccionarios: HAY QUE ACORDAR UNA NOMNECLATURA PARA STRINGS , VARIABLES y ARREGLOS.
extern string network_struct[];
extern string network_element_type[];
extern string network_element_name[];
extern int number_of_elements[];// = {"Number_of_Hubs","Number_of_Nodes", "Number_of_Amps","Number_of_CM", "Number_of_Connections"};

//Esta funcion recibe una linea del texto de un archivo Networking.
//Si empieza con NetworkName, valida el nombre de red y lo guarda en st1. En st2 guarda NULL.
//Si empieza con NetworkElement, valida nombre, tipo de elemento y los guarda en st1 y st2 resp.
//Si empieza con Connection, valida que haya dos nombres y los guarda en st1 y st2.

status_t processLine(string text_line)
{
    string st1, st2;
    return processLine(text_line, st1, st2 );
}

status_t processLine(string text_line, string st1, string st2)
{
    status_t status;

    istringstream iss(text_line); //string text_line to stream iss
    iss >> st1;

    if( st1 == network_struct[0] )//network_struct[] es un diccionario global
    {
        status = OK_NETWORK_NAME;
        iss >> st1 ;
    }

    if( st1 == network_struct[1] )//network_struct[] es un diccionario global
    {
        status = OK_NETWORK_ELEMENT;
        iss >> st1;
        iss >> st2;

        for( size_t i=0;i<4;i++)
        {
            if(st2==network_element_type[i])
                return OK_NETWORK_TYPE;
            else
                return ERROR_NETWORK_TYPE_UNKNOWN;
        }
    }
    if(st1==network_struct[2])
    {
        //number_of_elements[4]++;
        status = OK_CONNECTION;
        iss >> st1;
        if(iss >> st2)
            return OK_NETWORK_NAMES;
        else
            return ERROR_CONNECTION;
    }
    if( (st1!=network_struct[1]) && (st1!=network_struct[2]) )
    {
        status = ERROR_TEXT_LINE_INVALID;
        printErrorMessage(status, cout);
        printString(st1, cout);
        return ERROR_PROCESS_LINE;
    }
    return status;
}

void inputFromConsole(void)
{
        string line;

        while(getline(cin, line))
        {
            processLine(line);

        }

}


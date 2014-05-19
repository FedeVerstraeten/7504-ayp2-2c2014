#include"process.hpp"
//Diccionarios: HAY QUE ACORDAR UNA NOMNECLATURA PARA STRINGS , VARIABLES y ARREGLOS.
extern string network_struct[];
extern string network_element_type[];
extern string network_element_name[];
extern int number_of_elements[];// = {"Number_of_Hubs","Number_of_Nodes", "Number_of_Amps","Number_of_CM", "Number_of_Connections"};

//Esta funcion recibe una linea del texto
//Networking asumiendo que viene 'bien escrita',
//esto es, que siempre que viene Networking
// vienen 2 palabras mas, y la última es
// la que se necesita computar. Si viene connection
// entonces solo se incrementa la cantidad de conexiones.

void processLine(string text_line)
{
    istringstream iss(text_line);
    string word[3];
    iss >> word[0];
    if(word[0]==network_struct[1])//network_struct[] es un diccionario global
    {
        iss >> word[1];
        iss >> word[2];
        size_t i;
        for(i=0;i<4;i++)
        {
         if(word[2]==network_element_type[i]) number_of_elements[i]++;
        }//number_of_elements[] es un array global que guarda las cantidades
    }
    if(word[0]==network_struct[2])   number_of_elements[4]++;

}


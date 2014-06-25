#include"printers.hpp"
extern string network_struct[];
//esta funcion asume que se le pasa un string
//que contiene "NetworkName <nombre>",
//donde nombre es el nombre a imprimir

void printNetworkName(status_t status, string name_line, ostream& os)
{/*
    string aux, network_name;

    istringstream iss(name_line);
    iss >> aux;

    if(aux == network_struct[0])
    {
        status = OK_NETNAME;
        iss >> network_name;
        os << network_name << "\n";
    }
    else
    {
        os << "error: missing NetworkName" << "\n";
        status=ERROR_NETNAME;
    }*/
}

void printElements(int number_of_elements[], ostream& os)
{
    os << number_of_elements[0] << " Hubs"<<"\n";
    os << number_of_elements[1] << " Nodes"<<"\n";
    os << number_of_elements[2] << " Amps"<<"\n";
    os << number_of_elements[3] << " CMs"<<"\n";
    os << number_of_elements[4] << " Connections"<<"\n";
}

void printErrorMessage(status_t error_type, ostream& os)
{/*
    switch(error_type){
        case OKK:
            break;
        case ERROR_NULL_POINTER:
            { os << "error " << error_type << ":ERROR_NULL_POINTER"<< "\n"; break; }
        case ERROR_MEMORY_NO_AVAILABLE:
            { os << "error " << error_type << ":ERROR_MEMORY_NO_AVAILABLE"<< "\n"; break; }
        case OK_INPUT:
            break;
        case OK_OUTPUT:
            break;
        case OK_INPUT_CIN:
            break;
        case OK_NETNAME:
            break;
        case ERROR_NETNAME:
            { os << "error " << error_type << ""<< " missing NetworkName\n"; break; }
        case OK_OUTPUT_COUT:
            break;
        case ERROR_TEXT_LINE_INVALID:
            { os << "error " << error_type << ":ERROR_TEXT_LINE_INVALID"<< "\n"; break; }
        case ERROR_ROUTE_NAME_INVALID:
            { os << "error " << error_type << ":ERROR_ROUTE_NAME_INVALID"<< "\n"; break; }
        case ERROR_ARG:
            { os << "error " << error_type << ":ERROR_ARG"<< "\n"; break; }
        case OK_ROUTE_NAME:
            break;
        case ERROR_NO_ARGS:
            { os << "error " << error_type << ":ERROR_NO_ARGS"<< "\n"; break; }
        case ERROR_INVALID_INPUT_ROUTE:
            { os << "error " << error_type << ":ERROR_INVALID_INPUT_ROUTE"<< "\n"; break; }
        case ERROR_INVALID_OUTPUT_ROUTE:
            { os << "error " << error_type << ":ERROR_INVALID_OUTPUT_ROUTE"<< "\n"; break; }
        case ERROR_INVALID_ARGUMENT:
            { os << "error " << error_type << ":ERROR_INVALID_ARG"<< "\n"; break; }
        case ERROR_STREAM_OUT:
            { os << "error " << error_type << ":ERROR_STREAM_OUT"<< "\n"; break; }
        case ERROR_NULL_FILE:
            { os << "error " << error_type << ":ERROR_NULL_FILE"<< "\n"; break; }
        case OK_INPUT_CIN_PROCESSING:
            break;


        default:break;
    }*/
}
void printString(string s, ostream& os){    os << s << "\n"; }

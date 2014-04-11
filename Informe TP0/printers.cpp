
void printNetworkName(string name_line, ostream& os)
//esta funcion asume que se le pasa un string
//que contiene "NetworkName <nombre>",
//donde nombre es el nombre a imprimir
{
    string aux, network_name;
    istringstream iss(name_line);
    iss >> aux;
    if(aux == network_struct[0])
    {
        iss >> network_name;
        os << network_name << "\n";
    }
    else     os << "no hay nombre de red" << "\n";
}



void printElements(int number_of_elements[], ostream& os)
{
    os << number_of_elements[0] << " Hubs"<<"\n";
    os << number_of_elements[1] << " Nodes"<<"\n";
    os << number_of_elements[2] << " Amps"<<"\n";
    os << number_of_elements[3] << " CMs"<<"\n";
    os << number_of_elements[4] << " Connections"<<"\n";
}


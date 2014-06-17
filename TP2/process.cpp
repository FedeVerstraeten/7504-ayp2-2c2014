#include "process.hpp"
#include "printers.hpp"

extern string network_element_type[];
extern string line;
/****************************************************************************************
 FindRoot:La funcion recibe el arreglo de objetos NetworkElement y retorna la posicion
 del ROOT

*****************************************************************************************/
bool getNetName(istream& iss, string &NetName)
{
    string aux;
    iss >> aux;
    if(aux=="NetworkName"){
        iss >> aux;
        NetName=aux;
        return true;
        }
    return false;
}

int processVector(istream& iss, vector <NetworkElement> &v, size_t& i)
{
    string aux;
    v.push_back(NetworkElement());
    iss >> aux;
    v[i].setName(aux);
    iss >> aux;
    if(!NetworkElementType(aux)){
            cerr << "error: unrecognized Networkelement " << aux << endl;
            return 1;
    }
    v[i].setType(aux);
    i++;
    return 0;
}


int FindRoot(vector <NetworkElement> &v)
{
	int i;
	for(i=0;v.data()[i].getName()!="Hub1";i++);
	return i;
}

int processConnections(istream& iss, vector <NetworkElement> &v)
{
    string aux1, aux2;
    size_t i1, i2;
    bool son=false,father=false;
    iss >> aux1;
    iss >> aux2;

    for(size_t i=0; i<v.size();i++){
        if(v[i].getName()==aux1){
            i1=i;
            if(son==false){son=true;}
            else {son=false;}
        }
        if(v[i].getName()==aux2){
            i2=i;
            if(father==false){father=true;}
            else {father=false;}
        }
    }

    if(son==false){
        cerr << "Son node isn't found or multiple found"<<endl
             << aux1 <<" Error at line: " << line << endl;
             return 1;
    }
    if(father==false){
        cerr << "Father node isn't found or multiple found"<<endl
             << aux2 <<" Error at line: " << line << endl;
             return 1;
    }

    if(son==true && father==true){
        if(v[i2].validateHierarchy(v[i1])==true)
            v[i2].connectToElement(v[i1]);
            return 0;
    }
    else{
        cerr <<"Failure hierarchy. Unable to connect the elements"<<endl
        << v[i2].getName() << "(father) with "<< v[i1].getName() << "(son)"<<endl
        << " Error at line: " << line << endl;
        return 1;
    }

}

#define NET_TYPES 4
bool NetworkElementType(string aux)
{
    for( size_t i=0;i<NET_TYPES;i++){
        if(aux==network_element_type[i])
            return true;
    }
    return false;
}

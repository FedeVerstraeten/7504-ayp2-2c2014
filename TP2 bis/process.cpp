#include "process.hpp"


extern string network_element_type[];
extern string network_faults[];
extern size_t line;
extern string root_name;
extern unsigned int configThreshold;

/*******************GESTOR DE FALLAS***********************/
NetworkElement* processFaults(istream& stream_faults, TableHash &t)
{
    string aux,doFault,Result;
    bool key=false, NetEl=false;
    NetworkElement* v_aux=NULL;
    //NetworkElement auxElement;
    NodeTable *auxNode=NULL;

    stream_faults >> aux; // Lectura de: Query, Fault, Poll, Clear

    //KEYS DICTIONARY
    for(size_t i=0;i<4;i++)
    {
        if(aux==network_faults[i])
        {
            key=true;
            doFault=network_faults[i];
        }
    }

    if(key==false)
    {//KEY NOT FOUND
        cerr<<"error:unknown operation " << aux << " in processFaults"<<endl;
        return NULL;
    }

    // Lectura del NetworkElement: CM,Amp,Hub,Node
    stream_faults >> aux;

    //Network_Element in table <t>
    auxNode=t.searchNode(aux);
    if(auxNode!=NULL)
    {
        NetEl=true;
        v_aux=&auxNode->getElement();
    }

    if(NetEl==false)
    {//NetworkElement not found
        cerr<<"error:NetworkElement " << aux << " not found in topology"<<endl;
        return NULL;
    }

    if(doFault=="Poll")
    {   // "Poll" tiene otro argumento mas.
        // Si la entrada es esta, leo una vez
        // mas de stream_faults.

        stream_faults >> aux;

        if(aux!="ok" && aux!="error")
        {
            cerr<<"error:invalid state of polling "<< aux << " in processFaults"<<endl;
            return NULL;
        }

        else
            Result=aux;
    }

    if(insertFault(doFault,v_aux,Result)) return NULL;

    return v_aux;
}

int insertFault(const string doFault,NetworkElement* v_aux,const string Result)
{
    if (doFault=="Query"){/* No debe hacer nada, es solo para consultar el estado*/}

    else if (doFault=="Fault") v_aux->propagateFaultManual();

    else if (doFault=="Clear") v_aux->clearFaultManual();

    else if (doFault=="Poll" && v_aux->getType()=="CM")
    {
        if(Result=="ok")
            v_aux->setStatusOK();

        else if(Result=="error")
            v_aux->setStatusFault();

    }

    else return 1;

    return 0;
}


/********************TOPOLOGIA****************************/
int processVector(istream& iss, TableHash &t)
{
    string name, type;

    iss >> name;
    iss >> type;

    if(!NetworkElementType(type))
    {
            cerr << "error: unrecognized Networkelement " << name << endl;
            return 1;
    }

    NetworkElement netEl(name, type); // Creo el objeto
    t.insert(netEl); // Lo inserto en la tabla
    ((t.searchNode(netEl.getName()))->getElement()).setThreshold(configThreshold); // Ingreso el umbral luego

    if(type == "Hub")
    { // Si el objeto a crear es el Hub, guardo su nombre de forma global
        if(root_name==" ") root_name=name;
        else
        {   // Validacion si se registra mas de un Hub
            cerr << "error: Two or more Hub registered."<<endl;
            return 1;
        }
    }


    return 0;
}

int processConnections(istream& iss, TableHash &t)
{
    string aux1, aux2; // Guarda los nombres de elementos a conectar
    NodeTable *auxNode1=NULL,*auxNode2=NULL;
    NetworkElement auxEl1,auxEl2;

    iss >> aux1; // Son
    iss >> aux2; // Father

    auxNode1=t.searchNode(aux1);
    auxNode2=t.searchNode(aux2);

    if(auxNode1==NULL)
    {
        cerr << "Son node isn't found"<<endl
             << aux1 <<" Error at line: " << line << endl;
        return 1;
    }

    if(auxNode2==NULL)
    {
        cerr << "Father node isn't found or"<<endl
             << aux2 <<" Error at line: " << line << endl;
        return 1;
    }


    if(auxNode1!=NULL && auxNode2!=NULL)
    {
        if((auxNode2->getElement()).validateHierarchy(auxNode1->getElement())==true)
            (auxNode2->getElement()).connectToElement(auxNode1->getElement());


        else
        {
            cerr <<"Failure hierarchy. Unable to connect the elements"<<endl
            <<  (auxNode2->getElement()).getName() << "(father) with "
            <<  (auxNode1->getElement()).getName() << "(son)"<<endl
            << " Error at line: " << line << endl;
            return 1;
        }
    }
    return 0;
}


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

#define NET_TYPES 4
bool NetworkElementType(string aux)
{
    for( size_t i=0;i<NET_TYPES;i++){
        if(aux==network_element_type[i])
            return true;
    }
    return false;
}

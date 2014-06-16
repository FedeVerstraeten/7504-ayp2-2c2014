/************************************* BIBLIOTECAS *************************************/
#include <iostream>
#include <string>
#include"NetworkElementClass.hpp"
#include"common.hpp"


using namespace std;


/************************************* MAIN *******************************************/

int main()
{


	NetworkElement hub("HUB1","HUB");
	NetworkElement node1("NODE1","NODE"), node2("NODE2","NODE");
	NetworkElement amp1("AMP1","AMP");
	//NetworkElement amp2("AMP2","AMP");
    NetworkElement cm1("CM1","CM");
    NetworkElement cm2("CM2","CM");
    NetworkElement cm3("CM3","CM");
    NetworkElement cm4("CM4","CM");
    //    NetworkElement cm5("CM5","CM");

    //Conecto
	hub.connectToElement(node1);
    hub.connectToElement(node2);
	node2.connectToElement(cm1);
	node2.connectToElement(amp1);
	amp1.connectToElement(cm2);
	amp1.connectToElement(cm3);
	amp1.connectToElement(cm4);

    //coloco estados

    cm2.setStatusFault();
    cm3.setStatusFault();
    amp1.setThreshold(2);

    //propago falla manual

    node2.propagateFaultManual();

    //muestro elementos

	hub.showContent(cout);
	node1.showContent(cout);
	node2.showContent(cout);
    amp1.showContent(cout);
    cm1.showContent(cout);
    cm2.showContent(cout);
    cm3.showContent(cout);
    cm4.showContent(cout);

    //pongo estado OK cm3

    cm3.setStatusOK();

    cm3.showContent(cout);
    amp1.showContent(cout);

    node2.clearFaultManual();

    hub.showContent(cout);
	node1.showContent(cout);
	node2.showContent(cout);
    amp1.showContent(cout);
    cm1.showContent(cout);
    cm2.showContent(cout);
    cm3.showContent(cout);
    cm4.showContent(cout);



/*

	node1.connectToElement(cm2);
    node1.connectToElement(cm3);

	amp1.connectToElement(amp2);
	amp2.connectToElement(cm5);

   //cm3.connectToElement(hub);

	int numberNodes=9; // Son 9 y no 10 porque no considero la RAIZ,en este caso HUB

	hub.validateCycle();
	hub.validateIconnection(numberNodes);

*/
/*
    Pruebas para mostras ciclos entre amp

	amp1.connectToElement(amp2);
	amp2.connectToElement(amp3);
	amp3.connectToElement(amp1);

*/
	return 0;
}



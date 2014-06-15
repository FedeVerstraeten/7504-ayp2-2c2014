/************************************* BIBLIOTECAS *************************************/
#include <iostream>
#include <string>
#include"NetworkElementClass.hpp"
#include"common.hpp"


using namespace std;


/************************************* MAIN *******************************************/

int main()
{


	NetworkElement hub("HUB1","HUB"),node1("NODE1","NODE"),node2("NODE2","NODE");
    NetworkElement cm1("CM1","CM"), amp1("AMP1","AMP");
    NetworkElement cm2("CM2","CM"), amp2("AMP2","AMP");
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
    amp1.setInferenceFault();
    node2.propagateFault();
/*
	hub.showContent(cout);
	node1.showContent(cout);
	node2.showContent(cout);
    amp1.showContent(cout);
    cm1.showContent(cout);
    cm2.showContent(cout);
    cm3.showContent(cout);
    cm4.showContent(cout);
*/
    cm3.showContent(cout);
    amp1.showContent(cout);
    cm3.setStatusOK();
    cm3.showContent(cout);
    amp1.showContent(cout);

    node2.clearFault();

    hub.showContent(cout);
	node1.showContent(cout);
	node2.showContent(cout);
    amp1.showContent(cout);
    cm1.showContent(cout);
    cm2.showContent(cout);
    cm3.showContent(cout);
    cm4.showContent(cout);


	/*
	hub.setStatusFault();
	hub.showContent(cout);
	hub.setStatusOK();
	hub.showContent(cout);
	*/



/*


        //
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
	//NetworkElement cm1;
	NetworkElement hub1("HUB1","HUB"),node1("NODE1","NODE"),node2("NODE2","NODE");
	NetworkElement cm1("CM1","CM"), amp1("AMP1","AMP");
	NetworkElement cm2("CM2","CM"), amp2("AMP2","AMP"), amp3("AMP3","AMP");
	NetworkElement cm3("CM3","CM");
	NetworkElement cm4("CM4","CM");
	NetworkElement cm5("CM5","CM");





	amp1.connectToElement(amp2);
	amp2.connectToElement(amp3);
	amp3.connectToElement(amp1);



*/
	return 0;
}



/************************************* BIBLIOTECAS *************************************/
#include <iostream>
#include <string>
#include"NetworkElementClass.hpp"
#include"common.hpp"


using namespace std;




/************************************* MAIN *******************************************/

int main()
{


	NetworkElement hub("HUB","HUB"),node1("NODE1","NODE"),node2("NODE2","NODE");
        NetworkElement cm1("CM1","CM"), amp1("AMP1","AMP");
        NetworkElement cm2("CM2","CM"), amp2("AMP2","AMP");
        NetworkElement cm3("CM3","CM");
        NetworkElement cm4("CM4","CM");
        NetworkElement cm5("CM5","CM");

	
	hub.connectToElement(node1);
        hub.connectToElement(node2);
        node1.connectToElement(cm1);
	node1.connectToElement(cm2);
        node1.connectToElement(cm3);
        node2.connectToElement(amp1);
	amp1.connectToElement(amp2);
	amp2.connectToElement(cm5);
        amp1.connectToElement(cm4);
        cm3.connectToElement(hub);

	hub.validateCycle();






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

	
	amp3.validateCycle();
*/	
	return 0;
}

	

/************************************* BIBLIOTECAS *************************************/
#include <iostream>
#include <string>
#include"NetworkElementClass.hpp"
#include"common.hpp"

using namespace std;


















/************************************* MAIN *******************************************/

int main()
{
	//NetworkElement cm1;
	NetworkElement hub1("HUB1","HUB"),node1("NODE1","NODE"),node2("NODE2","NODE");
	NetworkElement cm1("CM1","CM"), amp1("AMP1","AMP");
	NetworkElement cm2("CM2","CM"), amp2("AMP2","AMP");
	NetworkElement cm3("CM3","CM");
	NetworkElement cm4("CM4","CM");
	NetworkElement cm5("CM5","CM"); 





//NetworkElement aux(amp1);

//	cm2.showContent();
//	amp1.showContent();

	hub1.connectToElement(node1);
	hub1.connectToElement(node2);
	node1.connectToElement(cm1);
	node1.connectToElement(cm2);
	node1.connectToElement(cm3);
	node2.connectToElement(amp1);
	amp1.connectToElement(amp2);
	amp1.connectToElement(cm4);
	amp2.connectToElement(cm5);
	
	

//	cm2.showContent();
//	amp1.showContent();
//	amp2.connectToElement(cm3);

/*	
	if(cm1==cm2) {cout<<"Elementos iguales"<<endl;}
	if(cm1!=cm2) {	cout<<"Elementos distintos"<<endl;}
	
	cm1=cm2;
	cout<<"asignación elementos"<<endl;
	if(cm1==cm2) {cout<<"Elementos iguales"<<endl;}
	if(cm1!=cm2) {	cout<<"Elementos distintos"<<endl;}
		
	cm1.showContent();	
	cm2.showContent();
	aux.showContent();

*/	

/*	hub1.showContent();
	node1.showContent();
	node2.showContent();
	amp1.showContent();
	amp2.showContent();
	cm1.showContent();
	cm2.showContent();
	cm3.showContent();
	cm4.showContent();
	cm5.showContent();*/

	int vertice=0;

	recorrido(&hub1,vertice);
	cout<<vertice<<endl;





	
	return 0;
}



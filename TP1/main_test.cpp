/************************************* BIBLIOTECAS *************************************/
#include <iostream>
#include <string>
#include"NetworkElementClass.hpp"
#include"common.hpp"


/************************************* MAIN *******************************************/

int main()
{
	//NetworkElement cm1;
	NetworkElement cm2("CM2","CM"), amp1("AMP1","AMP");
	NetworkElement cm3("CM3","CM"), amp2("AMP2","AMP");//,node1("NODE1","NODE");
	//NetworkElement aux(amp1);

//	cm2.showContent();
//	amp1.showContent();

	amp1.connectToElement(cm2);
	amp1.connectToElement(cm3);	

//	cm2.showContent();
	amp1.showContent();
	amp2.connectToElement(cm3);

/*	
	if(cm1==cm2) {cout<<"Elementos iguales"<<endl;}
	if(cm1!=cm2) {	cout<<"Elementos distintos"<<endl;}
	
	cm1=cm2;
	cout<<"asignación elementos"<<endl;
	if(cm1==cm2) {cout<<"Elementos iguales"<<endl;}
	if(cm1!=cm2) {	cout<<"Elementos distintos"<<endl;}
		
	cm1.showContent();	
	cm2.showContent();
	amp1.showContent();
	aux.showContent();

*/	

	

	return 0;
}

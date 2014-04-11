#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    char e='a',d='b';
    string key;
    cin >> key;
    e=d ^ key[2]; // probar con ingresar por cin numeros, ejemplo 0000, 1234, etc.
    cout << e <<endl ;
         cout<< d << endl;
}

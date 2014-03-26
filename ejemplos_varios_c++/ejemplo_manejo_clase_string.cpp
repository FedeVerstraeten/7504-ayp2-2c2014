//: C02:HelloStrings.cpp
// The basics of the Standard C++ string class
#include <string>
#include <iostream>
using namespace std;
int main() {
string s1, s2; // Empty strings (strings vacios)
string s3 = "Hello, World."; // Initialized (inicializado)
string s4("I am"); // Also initialized (también inicializados)
s2 = "Today"; // Assigning to a string (asignacion a un string)
s1 = s3 + " " + s4; // Combining strings (combinación de string)
s1 += " 8 "; // Appending to a string (adjuntar a un string)
cout << s1 + s2 + "!" << endl;
} ///:~


#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector
#include <string>
using namespace std;
int main () {
  string myints[] = { "CM1", "CM2", "CM3" ,"CM4" };
  string * p;

 // pointer to array element:
  p = find (myints,myints+4,"CM2");
  ++p;
  cout << "The element following 30 is " << *p << '\n';

  vector<string> myvector (myints,myints+4);
  vector<string>::iterator it;

  // iterator to vector element:
  it = find (myvector.begin(), myvector.end(),"CM2");
  ++it;
  cout << "The element following 30 is " << *it << '\n';

  return 0;
}

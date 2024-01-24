#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;
  list.push_back("a");
  list.push_back("b");
  list.push_back("c");
  list.push_back("d");
  list.push_back("e");
  list.push_back("f");
  list.push_back("g");
  list.push_back("h");
  list.push_back("i");
  list.push_back("j");
  cout << list.back()<<endl;
  list.pop_back();
  cout << list.back()<<endl;
  list.pop_back();
  cout << list.back()<<endl;
  list.pop_back();
  cout << list.back()<<endl;
  list.pop_back();
  cout << list.back()<<endl;
  list.pop_back();
  cout << list.back()<<endl;
  list.pop_back();
  cout << list.back()<<endl;
  list.pop_back();
  cout << list.back()<<endl;
  list.pop_back();
  cout << list.size()<<endl;
  cout << list.back()<<endl;
  cout << list.front()<<endl;
}

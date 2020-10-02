#include "List.h"
#include <iostream>
#include <string>
#include <vector>
#include "cs225/PNG.h"
#include "tests/tests_helper.h"
using std::cout;
using std::endl;
using namespace cs225;
int main() {
  
  
  List<string> list;


  list.insertBack("c");
  list.insertBack("b");
  list.insertBack("a");

  list.sort();

  list.print();
  return 0;
}

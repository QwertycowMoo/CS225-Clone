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

  
  list.print();
  list.reverse();
  list.print();

  return 0;
}

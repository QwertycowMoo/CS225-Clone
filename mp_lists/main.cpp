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
  
  
    List<int> list;

    
    list.insertBack(1);
    list.insertBack(2);
    /*
    list.insertBack(3);
    list.insertBack(4);
    */

    list.print();
    list.reverse();
    list.print();
  return 0;
}

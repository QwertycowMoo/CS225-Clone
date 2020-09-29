#include "List.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
int main() {


  List<int> list;
  
  for (int i = 1; i <=6; i++) {
    list.insertFront(i);
  }
  list.print();
  list.reverse();
  list.print();


  return 0;
}

#include "List.h"
#include <iostream>
using std::cout;
using std::endl;
int main() {
  List<int>* intList = new List<int>() ;
  int yuh = 3;
  intList->insertBack(yuh);
  delete intList;
  return 0;
}

#include "List.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
int main() {


  List<int> list1;
  List<int> list2;
  for (int i = 6; i >=1; i--) {
    if (i%2 != 0) {
      list1.insertFront(i);
    } else {
      list2.insertFront(i);
    }
    
  }
  list1.print();
  list2.print();
  list1.mergeWith(list2);
  list1.print();

  return 0;
}

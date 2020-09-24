#include "List.h"
#include <iostream>
using std::cout;
using std::endl;
int main() {
  List<unsigned> list;
    list.insertFront(1);
    list.insertFront(2);
    list.insertFront(3);

   cout << (bool) (list.begin() != list.end()) << endl;
  return 0;
}

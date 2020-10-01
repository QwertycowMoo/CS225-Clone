#include "List.h"
#include <iostream>
#include <string>
#include <vector>
#include "cs225/PNG.h"
using std::cout;
using std::endl;
using namespace cs225;
int main() {


  List<int> list1;
  for (int i = 0; i <= 5; i++) {
      list1.insertBack(i);
  }
  list1.print();
  list1.reverseNth(3);
  list1.print();

  return 0;
}

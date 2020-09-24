#include "List.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
int main() {
  List<int> list;

  for (int i = 1; i <= 9; i++)
      list.insertBack(i);

  list.tripleRotate();

    list.print();

  return 0;
}

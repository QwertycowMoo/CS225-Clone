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
  /*
  List<int> list1;
  
  for (int i = 1; i <= 6; i++) {
    list1.insertBack(i);
  }
  list1.print();
  list1.reverseNth(5);
  list1.print();
*/

    PNG in;        in.readFromFile("tests/alma.png");
  PNG expected;  expected.readFromFile("tests/expected-reverseN_2.png");

  List<HSLAPixel> list = imageToList(in);
  list.reverseNth(in.height() * 61);

  PNG out = listToImage(list, in.width(), in.height());
  out.writeToFile("actual-reverseN_2.png");
  
  return 0;
}

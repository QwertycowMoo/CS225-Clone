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
  List<int> list2;
  /*
  PNG im1;       im1.readFromFile("tests/merge1.png");
  PNG im2;       im2.readFromFile("tests/merge2.png");
  PNG expected;  expected.readFromFile("tests/expected-merge.png");

  PNG out(600, 400);

  vector<HSLAPixel> v1;
  for (unsigned i = 0; i < im1.width(); i++)
      for (unsigned j = 0; j < im1.height(); j++)
          v1.push_back(im1.getPixel(i, j));

  cout << v1.size() << endl;
  vector<HSLAPixel> v2;
  for (unsigned i = 0; i < im2.width(); i++)
      for (unsigned j = 0; j < im2.height(); j++)
          v2.push_back(im2.getPixel(i, j));
  cout << v2.size() << endl;
  List<HSLAPixel> l1(v1.begin(), v1.end());
  List<HSLAPixel> l2(v2.begin(), v2.end());
  cout << "merging" << endl;
  l1.mergeWith(l2);

  vector<HSLAPixel> merged(l1.begin(), l1.end());
  unsigned x = 0;
  for (unsigned i = 0; i < merged.size(); i++) {
      int y = i % 400;
      out.getPixel(x, y) = merged[i];
      if (y == 399)
          x++;
  }

  out.writeToFile("actual-merge.png");
    */

    for (int i = 0; i <= 100; i++) {
        if (i%3==0) {
            list1.insertFront(i);
        } else {
            list2.insertFront(i);
        }
    }

    list1.mergeWith(list2);
    list1.print();
  

  return 0;
}

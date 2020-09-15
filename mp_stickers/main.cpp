#include "Image.h"
#include "StickerSheet.h"
using std::cout;
using std::endl;
using namespace cs225;


int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
  Image alma; alma.readFromFile("tests/alma.png");
  Image i;    i.readFromFile("tests/i.png");
  Image expected; expected.readFromFile("tests/expected.png");
  Image expected2; expected2.readFromFile("tests/expected-2.png");

  StickerSheet s1(alma, 5);
  s1.addSticker(i, 20, 200);
  s1.addSticker(i, 40, 200);

  StickerSheet s2(alma, 5);
  s2 = s1;
  s2.removeSticker(1);

  Image render = s1.render();
  Image render2 = s2.render();
  render.writeToFile("myImage-1.png");
  render2.writeToFile("myImage-2.png");
  return 0;
}

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

  StickerSheet sheet(alma, 5);

  sheet.addSticker(i, 20, 200);

  Image expected;
  expected.readFromFile("tests/expected.png");
  Image render = sheet.render();

  render.writeToFile("myImage.png");
  return 0;
}

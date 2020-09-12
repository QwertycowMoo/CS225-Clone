#include "Image.h"
#include "StickerSheet.h"
using std::cout;
using std::endl;
using namespace cs225;

Image createRainbowImage() {
    Image png;
    png.resize(360, 100);

    for (unsigned x = 0; x < png.width(); x++) {
      for (unsigned y = 0; y < png.height(); y++) {
        HSLAPixel & pixel = png.getPixel(x, y);
        pixel.h = x;
        pixel.s = y / 100.0;
        pixel.l = y / 100.0;
      }
    }
    return png;
  }
int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
  Image img = createRainbowImage();
  img.writeToFile("oldPNGScale.png");
  img.scale(240, 50);
  img.writeToFile("newPNGScale.png");
  cout << img.width() << " " << img.height() << endl;
  cout << img.getPixel(100, 20).h << endl;
  return 0;
}

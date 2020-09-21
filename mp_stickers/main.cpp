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
  Image pusheen; pusheen.readFromFile("pusheen.png");
  Image music;    music.readFromFile("music.png");
  Image dnd; dnd.readFromFile("dndD20.png");
  Image background; background.readFromFile("846697.png");

  StickerSheet s1(background, 7);
  s1.addSticker(pusheen, 20, 200);
  s1.addSticker(pusheen, 70, 500);
  s1.addSticker(music, 200, 200);
  s1.addSticker(music, 1000, 600);
  s1.addSticker(pusheen, 1250, 400);
  s1.addSticker(dnd, 600, 100);
  s1.addSticker(dnd, 1350, 0);



  Image render = s1.render();
  render.writeToFile("myImage.png");

  return 0;
}

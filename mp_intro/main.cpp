#include <iostream>
#include <stdlib.h>

#include "intro.h"
#include "cs225/PNG.h"

#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc == 2) {
    unsigned int width = (unsigned int)atoi(argv[1]);
    std::cout << "Calling myArt(" << width << ", " << width << ") and saving it as `art.png`." << std::endl;

    cs225::PNG png = myArt(width, width);
    png.writeToFile("art.png");
  } else {
    std::cout << "Rotating `in_01.png` as `out_01.png`" << std::endl;
    rotate("in_01.png", "out_01.png");
  }
  
  return 0;
}

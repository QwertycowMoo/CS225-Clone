#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
  //should be a candy cane texture;
  double h,s,l;
  if (((x+y) % 5) == 0 || ((x+y) % 6) == 0) {
    h = 0;
    s = 1.0;
    l = 1.0;
  } else {
    h = 0;
    s = 1.0;
    l = .5;
  }
  return HSLAPixel(h,s,l);
}

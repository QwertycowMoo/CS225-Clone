#include "cs225/PNG.h"
#include <list>
#include <iostream>
#include <type_traits>

#include "colorPicker/ColorPicker.h"
#include "imageTraversal/ImageTraversal.h"

#include "Point.h"
#include "Animation.h"
#include "FloodFilledImage.h"

using namespace cs225;

/**
 * Constructs a new instance of a FloodFilledImage with a image `png`.
 * 
 * @param png The starting image of a FloodFilledImage
 */
FloodFilledImage::FloodFilledImage(const PNG & png): _png(png) {
  /** @todo [Part 2] */

}

/**
 * Adds a FloodFill operation to the FloodFillImage.  This function must store the operation,
 * which will be used by `animate`.
 * 
 * @param traversal ImageTraversal used for this FloodFill operation.
 * @param colorPicker ColorPicker used for this FloodFill operation.
 */
void FloodFilledImage::addFloodFill(ImageTraversal & traversal, ColorPicker & colorPicker) {
  /** @todo [Part 2] */
  _traversals.push_back(&traversal);
  _colorpickers.push_back(&colorPicker);
}

/**
 * Creates an Animation of frames from the FloodFill operations added to this object.
 * 
 * Each FloodFill operation added by `addFloodFill` is executed based on the order
 * the operation was added.  This is done by:
 * 1. Visiting pixels within the image based on the order provided by the ImageTraversal iterator and
 * 2. Updating each pixel to a new color based on the ColorPicker
 * 
 * While applying the FloodFill to the image, an Animation is created by saving the image
 * after every `frameInterval` pixels are filled.  To ensure a smooth Animation, the first
 * frame is always the starting image and the final frame is always the finished image.
 * 
 * (For example, if `frameInterval` is `4` the frames are:
 *   - The initial frame
 *   - Then after the 4th pixel has been filled
 *   - Then after the 8th pixel has been filled
 *   - ...
 *   - The final frame, after all pixels have been filed)
 */ 
Animation FloodFilledImage::animate(unsigned frameInterval) const {
  PNG tempPNG = _png;
  Animation animation;
  /** @todo [Part 2] */
  animation.addFrame(tempPNG);
  for (unsigned i = 0; i < _traversals.size(); ++i) {
    unsigned frame = 0;
    ImageTraversal * _traversal = _traversals[i];
    ColorPicker * _colorpicker = _colorpickers[i];
    for (auto it = _traversal->begin(); it != _traversal->end(); ++it) {
      Point toFill = *it;
      //need to do this because we don't have a "=" operator for HSLAPixel or a copy constructor
      HSLAPixel & toChangePixel = tempPNG.getPixel(toFill.x, toFill.y);
      HSLAPixel colorPixel = _colorpicker->getColor(toFill.x, toFill.y);
      toChangePixel.h = colorPixel.h;
      toChangePixel.s = colorPixel.s;
      toChangePixel.l = colorPixel.l;
      toChangePixel.a = colorPixel.a;
      frame++;
      if (frame % frameInterval == 0) {
        animation.addFrame(tempPNG);
      }
    }
  }
  
  animation.addFrame(tempPNG);
  return animation;
}

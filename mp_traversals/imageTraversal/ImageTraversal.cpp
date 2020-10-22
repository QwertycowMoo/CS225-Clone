#include <cmath>
#include <iterator>
#include <iostream>
#include <vector>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}



/** @todo [Part 1] */
/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator(): _traversal(NULL) {
  
}

ImageTraversal::Iterator::Iterator(ImageTraversal* traversal, Point & start, PNG & png, double tolerance): 
_start(start), _tolerance(tolerance), _traversal(traversal), _png(png) {
  //std::cout << "iterator constructor reached" << std::endl;
  _current = traversal->peek();
  _traversed = std::vector<std::vector<bool>>(png.width());
  for (unsigned i = 0; i < png.width(); i++) {
    _traversed[i] = std::vector<bool>(png.height());
    for (unsigned j = 0; j < png.height(); j++) {
      _traversed[i][j] = false;
    }
  }
  _traversed[_current.x][_current.y] = true;
}


/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  
  if (!_traversal->empty()) {
    //std::cout << "not empty" << std::endl;

    _current = _traversal->pop();

    //std::cout << "current is: " << _current.x << _current.y << std::endl;
    //add first then check if repeat
    if (_current.x + 1 < _png.width()) {
      Point rightNeighbor(_current.x + 1, _current.y);
      //std::cout << "adding : " << rightNeighbor.x << rightNeighbor.y << std::endl;
      _traversal->add(rightNeighbor);
    }

    if (_current.y + 1 < _png.height()) {
      Point bottomNeighbor(_current.x, _current.y + 1);
      //std::cout << "adding : " << bottomNeighbor.x << bottomNeighbor.y << std::endl;
      _traversal->add(bottomNeighbor);
    }

    if (_current.x > 0) {
      Point leftNeighbor(_current.x - 1, _current.y);
      //std::cout << "adding : " << leftNeighbor.x << leftNeighbor.y << std::endl;
      _traversal->add(leftNeighbor);
    }

    if (_current.y > 0) {
      Point topNeighbor(_current.x, _current.y - 1);
      //std::cout << "adding : " << topNeighbor.x << topNeighbor.y << std::endl;
      _traversal->add(topNeighbor);
    }
    _current = _traversal->peek();


    while (calculateDelta(_png.getPixel(_start.x, _start.y), _png.getPixel(_current.x, _current.y)) > _tolerance ||
     _traversed[_current.x][_current.y] == true) {
       
      _traversal->pop();
      _current = _traversal->peek();
      //std::cout << "current: " << _current.x << _current.y << std::endl;
      if (_traversal->empty()) {
        _traversal = NULL;
        return *this;
      }
    }


     _traversed[_current.x][_current.y] = true;
    
    //std::cout << "outside delta loop: " << calculateDelta(_png.getPixel(_start.x, _start.y), _png.getPixel(_current.x, _current.y)) << std::endl;
    //std::cout << "traversed boolean table: " << _traversed[_current.x][_current.y] << std::endl;
    //std::cout << std::endl;
    return *this;
  }
  _traversal = NULL;
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return _current;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  if (_traversal == other._traversal) {
    return false;
  }
  return true;
}


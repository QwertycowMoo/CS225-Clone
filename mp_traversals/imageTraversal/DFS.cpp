#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"


/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * 
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance): _png(png), _start(start), _tolerance(tolerance) {  
  /** @todo [Part 1] */
  add(_start);
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator(this, _start, _png, _tolerance);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */

  if (ImageTraversal::calculateDelta(png.getPixel(_start.x, _start.y), png.getPixel(point.x, point.y)) < _tolerance) {
    stack.push(point);
    if (_current.x + 1 < _png.width()) {
      Point rightNeighbor(_current.x + 1, _current.y);
      add(rightNeighbor);
    }

    if (_current.y + 1 < _png.height()) {
      Point bottomNeighbor(_current.x, _current.y + 1);
      add(bottomNeighbor);
    }

    if (_current.x > 0) {
      Point leftNeighbor(_current.x - 1, _current.y);
      add(leftNeighbor);
    }

    if (_current.y > 0) {
      Point topNeighbor(_current.x, _current.y - 1);
      add(topNeighbor);
    }
  }
  
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  Point toReturn = stack.top();
  stack.pop();
  return toReturn;
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  if (!empty()) {
    return stack.top();
  } else {
    return _start;
  }

}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  if (stack.empty()) {
    return true;
  } else {
    return false;
  }

}

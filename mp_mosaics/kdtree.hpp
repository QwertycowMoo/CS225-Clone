/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
     if (first[curDim] < second[curDim]) { //hopefully don't have to check for indexoutofbounds
       return true;
     } else {
       if (first[curDim] == second[curDim]) {
         return first < second;
       }
       return false;
     }
    
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    int currDistance = 0;
    int potenDistance = 0;
    for (int i = 0; i < Dim; i++) {
      double toSquare = (target[i] - currentBest[i]);
      currDistance += toSquare * toSquare;
    }

    for (int i = 0; i < Dim; i++) {
      double toSquare = (target[i] - potential[i]);
      potenDistance += toSquare * toSquare;
    }
    if (potenDistance < currDistance) {
      return true;
    } else {
      if (potenDistance == currDistance) {
        return potential < currentBest;
      }
    }

     return false;
}
template <int Dim>
vector<Point<Dim>> partition(vector<Point<Dim>>& toPart, int l, int r, int pivotIndex) {
  Point<Dim> partValue = toPart[pivotIndex];
  int stored = 0; //keeps track of what to swap
  for (int i = l; i < r; i++) {
    if (toPart[i] < partValue) {
      Point<Dim> tempStore = toPart[stored];
      toPart[stored] = toPart[i];
      toPart[i] = tempStore;
      ++stored;
    }
  }
  return stored;
}

template <int Dim>
Point<Dim> quickselect(const vector<Point<Dim>> points, int l, int r, int k) {
  if (l == r) {
    return points[l];
  }
  vector<Point<Dim>> mutablePoints = points;
  int pivotIndex = r;
  pivotIndex = partition(mutablePoints, l, r, pivotIndex);
  if (k == pivotIndex) {
    return mutablePoints[k];
  } else if (k < pivotIndex) {
    return quickselect(mutablePoints, l, pivotIndex - 1, k);
  } else {
    return quickselect(mutablePoints, pivotIndex + 1, r, k);
  }
}
template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
    */
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * 
   * @todo Implement
   */
}
template<int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */

  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */

    return Point<Dim>();
}


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
Point<Dim> KDTree<Dim>::quickselect(const vector<Point<Dim>> points, int l, int r, int k, int dimension) {
  if (l == r) {
    return points[l];
  }
  dimension = dimension % (Dim > 1 ? Dim - 1: Dim);
  int pivotIndex = r;
  vector<Point<Dim>> mutPoints = points;
  pivotIndex = partition(mutPoints, l, r, pivotIndex, dimension);
  if (k == pivotIndex) {
    return mutPoints[k];
  } else if (k < pivotIndex) {
    //std::cout << "less than pivot index" << std::endl;
    return quickselect(mutPoints, l, pivotIndex - 1, k, dimension);
  } else {
    //std::cout << k << " is greater than pivot index " << pivotIndex << std::endl;
    return quickselect(mutPoints, pivotIndex + 1, r, k, dimension);
  }
}

template <int Dim>
void KDTree<Dim>::buildTree(KDTreeNode* subroot, vector<Point<Dim>>& mutPoints, int l, int r, int dimension) {
  if (l == r) {
    std::cout << "built a leaf node" << std::endl;
    subroot = new KDTreeNode(quickselect(mutPoints, l, r, (l + r) / 2, dimension));
    return;
  } else {
    if (dimension < 10) {
      std::cout << "building a node with quickselect: " << quickselect(mutPoints, l, r, (l + r) / 2, dimension) << std::endl;
      subroot = new KDTreeNode(quickselect(mutPoints, l, r, (l + r) / 2, dimension));
      std::cout << "building left with " << 0 << " " << ((l+r)/2) - 1<< " " << dimension + 1<< std::endl; //this goes to -1 when l = 0 and r = 1
      buildTree(subroot->left, mutPoints, 0, ((l+r)/2) - 1, dimension + 1);
      std::cout << "building right with " << ((l+r)/2) + 1 << " " << r << " " << dimension + 1 << std::endl;
      buildTree(subroot->right, mutPoints, ((l+r)/2) + 1, r, dimension + 1);

    }

  }
  
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
    */
  if (newPoints.size() != 0) {
    for (Point<Dim> point: newPoints) {
      std::cout << "printing point" << std::endl;
      std::cout << point << std::endl;
    }

    vector<Point<Dim>> mutPoints = newPoints;
    //remember that k is 0 indexed, we go through the points from the beginning to the end, set k as the median index, and split along the 0th dimension
    std::cout << "building tree" << std::endl;
    buildTree(root, mutPoints, 0, mutPoints.size() - 1, 0);
  }
  

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


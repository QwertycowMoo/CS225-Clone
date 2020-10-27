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
void KDTree<Dim>::buildTree(KDTreeNode*& subroot, vector<Point<Dim>>& mutPoints, int l, int r, int dimension) {
  if (l == r) {
    //std::cout << "built a leaf node" << std::endl;
    subroot = new KDTreeNode(quickselect(mutPoints, l, r, (l + r) / 2, dimension));
    return;
  } else {
    if (dimension < 10) {
      //std::cout << "building a node with quickselect: " << quickselect(mutPoints, l, r, (l + r) / 2, dimension) << std::endl;
      subroot = new KDTreeNode(quickselect(mutPoints, l, r, (l + r) / 2, dimension));
      
      if (l != (l+r)/2) {
        //std::cout << "building left under " << subroot->point << " with " << l << " " << ((l+r)/2) - 1<< " " << dimension + 1<< std::endl;
        buildTree(subroot->left, mutPoints, l, ((l+r)/2) - 1, dimension + 1);
      }
      //std::cout << "building right under " << subroot->point << " with " << ((l+r)/2) + 1 << " " << r << " " << dimension + 1 << std::endl;
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
  if (other.root) {
    copyCtorHelper(root, other.root);
  } else {
    root = nullptr;
  }
  
}

template <int Dim>
void KDTree<Dim>::copyCtorHelper(KDTreeNode*& subroot, const KDTreeNode* otherRoot) {
  subroot = new KDTreeNode(otherRoot->point);
  if (otherRoot->left) {
    copyCtorHelper(subroot->left, otherRoot->left);
  }
  if (otherRoot->right) {
    copyCtorHelper(subroot->right, otherRoot->right);
  }
}
template<int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  if (rhs->root) {
    copyCtorHelper(root, rhs->root);
  } else {
    root = nullptr;
  }
  
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
    Point<Dim> maxPoint;
    for (size_t i = 0; i < Dim; i++) {
      maxPoint[i] = LONG_MAX;
    }
    Point<Dim> nonRootClosest = findNearestNeighbor(query, root, maxPoint, 0);
    // if (shouldReplace(query, nonRootClosest, root->point)) {
    //   return root->point;
    // }
    return nonRootClosest;
}
template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query, KDTreeNode* subroot, Point<Dim> closest, int dimension) const
{

 
  if (subroot->left == nullptr && subroot->right == nullptr) {
    return subroot->point;
  }
   dimension = dimension % (Dim > 1 ? Dim - 1: Dim);
   //checks whether to go left or right
  if (smallerDimVal(query, subroot->point, dimension)) {
    //checks for existence of left
    //std::cout << "goin left" << std::endl;
    if (subroot->left) {
      //finds the nearest neighbor of the left
      Point<Dim> compareClosest = findNearestNeighbor(query, subroot->left, closest, dimension + 1);
        //sees if it should replace with basically infinity
      //std::cout << "compareclosest is: " << compareClosest << std::endl;
      if (shouldReplace(query, subroot->point, compareClosest)) {
        //std::cout << "compareClosest is closer than the subroot" << std::endl;

        //checks if the right exists
        if (subroot->right) {

          //then compares with the right branch
          Point<Dim> branchClosest = findNearestNeighbor(query, subroot->right, compareClosest, dimension + 1);
        
          if (shouldReplace(query, compareClosest, branchClosest)) {
            //std::cout << "branchClosest is closer" << std::endl;
            return branchClosest;
          } else {
            //std::cout << "compareClosest is closer" << std::endl;
            return compareClosest;
          }
        } else {
          //returns this if no right;
          return compareClosest;
        }
        
      } else { //lesser of the two is already checked in the shouldReplace

        return subroot->point;
      }

    } else {
      return subroot->point;
    }
    
  } else {
    if (subroot->right) {
      std::cout << "goin right" << std::endl;
      //finds the nearest neighbor of the left
      Point<Dim> compareClosest = findNearestNeighbor(query, subroot->right, closest, dimension + 1);
        //sees if it should replace with basically infinity

      if (shouldReplace(query, subroot->point, compareClosest)) {
        if (subroot->left) {
          Point<Dim> branchClosest = findNearestNeighbor(query, subroot->left, compareClosest, dimension + 1);
          if (shouldReplace(query, compareClosest, branchClosest)) {
            return branchClosest;
          } else {
            return compareClosest;
          }
        } else {
          return compareClosest;
        }
        
      } else { //lesser of the two is already checked in the shouldReplace
        return subroot->point;
      }

    } else {
      return subroot->point;
    }
  }

}


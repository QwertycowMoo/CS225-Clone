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
    int currDistance = squaredDistance(target, currentBest);
    int potenDistance = squaredDistance(target, potential);
    
    std::cout << "potential distance: " << potenDistance << std::endl;
    std::cout << "curr distance: " << currDistance << std::endl;
    if (potenDistance < currDistance) {
      return true;
    } else {
      if (potenDistance == currDistance) {
        std::cout << "potential distance is same as the current one" << std::endl;
        std::cout << "currentBest" << currentBest << std::endl;
        std::cout << "potential" << potential << std::endl;
        std::cout << (potential < currentBest) << std::endl;
        return potential < currentBest;
      }
    }

     return false;
}
template <int Dim>
double KDTree<Dim>::squaredDistance(Point<Dim> p1, Point<Dim> p2) const {
  int distance = 0;
  for (int i = 0; i < Dim; i++) {
    double toSquare = (p1[i] - p2[i]);
    distance += toSquare * toSquare;
  }
  return distance;
}

template <int Dim>
Point<Dim> KDTree<Dim>::quickselect(vector<Point<Dim>>& points, int l, int r, int k, int dimension) {
  if (l == r) {
    return points[l];
  }

  dimension = dimension % Dim;
  int pivotIndex = r;
  pivotIndex = partition(points, l, r, pivotIndex, dimension);
  //std::cout << "pivotIndex: " << pivotIndex << std::endl;
  if (k == pivotIndex) {
    return points[k];
  } else if (k < pivotIndex) {
    //std::cout << "less than pivot index" << std::endl;
    return quickselect(points, l, pivotIndex - 1, k, dimension);
  } else {
    //std::cout << k << " is greater than pivot index " << pivotIndex << std::endl;
    return quickselect(points, pivotIndex + 1, r, k, dimension);
  }
}

template <int Dim>
void KDTree<Dim>::buildTree(KDTreeNode*& subroot, vector<Point<Dim>>& mutPoints, int l, int r, int dimension) {
  if (l == r) {
    //std::cout << "built a leaf node" << std::endl;
    subroot = new KDTreeNode(quickselect(mutPoints, l, r, (l + r) / 2, dimension));
    return;
  } else {
      //std::cout << "building a node with quickselect: " << std::endl;
      //std::cout << "left is : " << mutPoints[l] << "right is : " << mutPoints[r] << "l+r/2 " << (l+r)/2 << std::endl;
      subroot = new KDTreeNode(quickselect(mutPoints, l, r, (l + r) / 2, dimension));
      
      if (l != (l+r)/2) {
        //std::cout << "building left under " << subroot->point << " with " << l << " " << ((l+r)/2) - 1<< " " << dimension + 1<< std::endl;
        buildTree(subroot->left, mutPoints, l, ((l+r)/2) - 1, dimension + 1);
      }
      //std::cout << "building right under " << subroot->point << " with " << ((l+r)/2) + 1 << " " << r << " " << dimension + 1 << std::endl;
      buildTree(subroot->right, mutPoints, ((l+r)/2) + 1, r, dimension + 1);

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
    //std::cout << "building tree" << std::endl;
    buildTree(root, mutPoints, 0, mutPoints.size() - 1, 0);
  } else {
    root = nullptr;
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
  if (root) {
    destroyHelper(root);
  }
  
}

template<int Dim>
void KDTree<Dim>::destroyHelper(KDTreeNode* root) {
  if (root) {
    destroyHelper(root->left);
    destroyHelper(root->right);
    delete root;
  }
  
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
   dimension = dimension % Dim;
   //checks whether to go left or right
  if (smallerDimVal(query, subroot->point, dimension)) {
    //checks for existence of left
    //std::cout << "goin left" << std::endl;
    if (subroot->left) {
      //finds the nearest neighbor of the left
      Point<Dim> compareClosest = findNearestNeighbor(query, subroot->left, closest, dimension + 1);
        //sees if it should replace with basically infinity
      //std::cout << "compareclosest is: " << compareClosest << std::endl;
      if (shouldReplace(query, compareClosest, subroot->point)) {
        //std::cout << "compareClosest is closer than the subroot" << std::endl;

        //checks if the right exists
        if (subroot->right) {

          //then compares with the right branch
          Point<Dim> branchClosest = findNearestNeighbor(query, subroot->right, compareClosest, dimension + 1);
        
          if (shouldReplace(query, subroot->point, branchClosest) ) {
            //std::cout << "branchClosest is closer" << std::endl;
            return branchClosest;
          } else {
            //std::cout << "compareClosest is closer" << std::endl;
            return subroot->point;
          }
        } else {
          //returns this if no right;
          return subroot->point;
        }
        
      } else { //lesser of the two is already checked in the shouldReplace

        return compareClosest;
      }

    } else {
      return subroot->point;
    }
    
  } else {
    if (subroot->right) {
      //std::cout << "goin right" << std::endl;
      //finds the nearest neighbor of the left
      Point<Dim> compareClosest = findNearestNeighbor(query, subroot->right, closest, dimension + 1);
        //sees if it should replace with basically infinity

      if (root == subroot) {
        std::cout << "At the root of :" << root->point << std::endl;
        std::cout << subroot->point <<std::endl;
        std::cout << compareClosest <<std::endl;
        std::cout << "should replace: " << shouldReplace(query, compareClosest, subroot->point) << std::endl;
        std::cout << std::endl;
      }
      if (shouldReplace(query, compareClosest, subroot->point)) {

        if (subroot->left) {
          Point<Dim> branchClosest = findNearestNeighbor(query, subroot->left, compareClosest, dimension + 1);
          if (shouldReplace(query, subroot->point, branchClosest)) {
            return branchClosest;
          } else {
            return subroot->point;
          }
        } else {
          return subroot->point;
        }
        
      } else { //lesser of the two is already checked in the shouldReplace
        return compareClosest;
      }

    } else {
      return subroot->point;
    }
  }

}


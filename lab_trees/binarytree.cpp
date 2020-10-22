/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout << std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    std::cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
    template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    mirror(root);
}
template <typename T>
void BinaryTree<T>::mirror(Node* subRoot) {
    if (subRoot== nullptr) {
        return;
    }
    mirror(subRoot->left);
    mirror(subRoot->right);
    Node *tempLeft = subRoot->left;
    subRoot->left = subRoot->right;
    subRoot->right = tempLeft;
}

/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    InorderTraversal<T> t (root);
    T min;
    BinaryTree<T>::Node* tempRoot = root;
    while(tempRoot->left != nullptr) {
        tempRoot = tempRoot->left;
    }
    min = tempRoot->elem;
    //std::cout << min << std::endl;
    for (auto it = t.begin(); it != t.end(); ++it) {   
        if ((*it)->elem < min) {
            return false;
        }
        min = (*it)->elem;
    }
     return true;
}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    // your code here
    return isOrderedRecursive(root, root->elem, true) && isOrderedRecursive(root->right, root->elem, false);
}

template <typename T>
bool BinaryTree<T>::isOrderedRecursive(Node* subRoot, T toCompare, bool isLeft) const
{
    if (subRoot == nullptr) {
        return true;
    } 
    if (isLeft){
        if (subRoot->elem <= toCompare) {
            return isOrderedRecursive(subRoot->left, subRoot->elem, true) && isOrderedRecursive(subRoot->right, subRoot->elem, false); 
        } else {
            return false;
        }
        
    } else {
        if (isOrderedRecursive(subRoot->left, subRoot->elem, true)) {
            if (subRoot->elem >= toCompare) {
                return isOrderedRecursive(subRoot->left, toCompare, false) && isOrderedRecursive(subRoot->right, subRoot->elem, false);
            } else {
                return false;
            }
        } else {
            return false;
        }
        
    
        
    }
}


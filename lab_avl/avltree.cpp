/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
 #include <algorithm>

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node* tempT = t;
    Node* rightChild = t->right;
    t->right = rightChild->left;
    rightChild->left = tempT;
    t->height = std::max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
    t = rightChild;
    

}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    Node* tempT = t;
    Node* leftChild = t->left;
    t->left = leftChild->right;
    leftChild->right = tempT;
    t->height = std::max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
    t = leftChild;

}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    // if (subtree->right == NULL || subtree->left == NULL) {
    //     std::cout << "nope" << subtree->key << std::endl;
    //     return;
    // }
    int balance = heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left);
    if (balance == 2) {
        int rightBalance = heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left);
        if (rightBalance == 1) {
            rotateLeft(subtree);
        } else {
            rotateRightLeft(subtree);
        }
    } else if (balance == -2) {
        int leftBalance = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left);
        if (leftBalance == -1) {
            rotateRight(subtree);
        } else {
            rotateLeftRight(subtree);
        }
    }
    subtree->height = std::max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if (subtree == NULL) {
        subtree = new Node(key, value);
    }
    if (key < subtree->key) {insert(subtree->left, key, value);}
    if (key > subtree->key) {insert(subtree->right, key, value);}
    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    bool didDelete = false;
    if (subtree == NULL) {
        return;
    }
    if (key < subtree->key) {
        // your code here
        remove(subtree->left, key);
    } else if (key > subtree->key) {
        remove(subtree->right, key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            Node* toDelete = subtree;
            subtree = nullptr;
            didDelete = true;
            delete toDelete;
           
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node* iop = findIOP(subtree->left);
            if (subtree->left == iop) {
                //left should stay the same
                Node* toDelete = subtree;
                iop->right = subtree->right;
                subtree = iop;
                didDelete = true;
                delete toDelete;
                //update height
                subtree->height = std::max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) + 1;
            } else {
                Node* iopTop = findIOPTop(subtree->left);
                iop->right = subtree->right;
                iop->left = subtree->left;
                
                iopTop->right = nullptr;
                //iopTop->height = heightOrNeg1(iopTop->left) + 1;
                Node* toDelete = subtree;
                subtree = iop;
                didDelete = true;
                delete toDelete;
                //update height
                subtree->height = std::max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) + 1;

            }
        } else {
            /* one-child remove */
            // your code here
            Node* toDelete = subtree;
            if (subtree->left != NULL) {
                subtree = subtree->left;
            } else {
                subtree = subtree->right;
            }
            didDelete = true;
            delete toDelete;
            subtree->height = std::max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) + 1;
            
        }
    }
    //This is broken
    //std::cout << "trying to rebalance" << subtree->key <<std::endl;
    if (!didDelete) {
        rebalance(subtree);
    }
    
    
}


template <class K, class V>
typename AVLTree<K,V>::Node* AVLTree<K, V>::findIOP(Node*& root){
    if (root->right == nullptr) { 
        return root;
    }
    return findIOP(root->right);
}

template <class K, class V>
typename AVLTree<K,V>::Node* AVLTree<K, V>::findIOPTop(Node*& root){
    if (root->right->right == nullptr) {
        return root;
    }
    return findIOPTop(root->right);
}
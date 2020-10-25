/**
 * @file btree.cpp
 * Implementation of a B-tree class which can be used as a generic dictionary
 * (insert-only). Designed to take advantage of caching to be faster than
 * standard balanced binary search trees.
 */

/**
 * Finds the value associated with a given key.
 * @param key The key to look up.
 * @return The value (if found), the default V if not.
 */
template <class K, class V>
V BTree<K, V>::find(const K& key) const
{
    return root == nullptr ? V() : find(root, key);
}

/**
 * Private recursive version of the find function.
 * @param subroot A reference of a pointer to the current BTreeNode.
 * @param key The key we are looking up.
 * @return The value (if found), the default V if not.
 */
template <class K, class V>
V BTree<K, V>::find(const BTreeNode* subroot, const K& key) const
{
    /* TODO Finish this function */
    size_t first_larger_idx = insertion_idx(subroot->elements, key);
    
    /* If first_larger_idx is a valid index and the key there is the key we
     * are looking for, we are done. */
    if (first_larger_idx < subroot->elements.size()){
        if (subroot->elements[first_larger_idx].key == key) {
            return subroot->elements[first_larger_idx].value;
        }
    }

    /* Otherwise, we need to figure out which child to explore. For this we
     * can actually just use first_larger_idx directly. E.g.
     * | 1 | 5 | 7 | 8 |
     * Suppose we are looking for 6. first_larger_idx is 2. This means we want to
     * explore the child between 5 and 7. The children vector has a pointer for
     * each of the horizontal bars. The index of the horizontal bar we want is
     * 2, which is conveniently the same as first_larger_idx. If the subroot is
     * a leaf and we didn't find the key in it, then we have failed to find it
     * anywhere in the tree and return the default V.
     */
    if (!subroot->is_leaf){
        return find(subroot->children[first_larger_idx], key);
    } else {
        return V();
    }
    
}

/**
 * Inserts a key and value into the BTree. If the key is already in the
 * tree do nothing.
 * @param key The key to insert.
 * @param value The value to insert.
 */
template <class K, class V>
void BTree<K, V>::insert(const K& key, const V& value)
{
    /* Make the root node if the tree is empty. */
    if (root == nullptr) {
        root = new BTreeNode(true, order);
    }
    insert(root, nullptr, DataPair(key, value), -1);
    /* Increase height by one by tossing up one element from the old
     * root node. */
    if (root->elements.size() >= order) {
        BTreeNode* new_root = new BTreeNode(false, order);
        new_root->children.push_back(root);
        split_child(new_root, 0);
        root = new_root;
    }
}

/**
 * Splits a child node of a BTreeNode. Called if the child became too
 * large.
 * @param parent The parent whose child we are trying to split.
 * @param child_idx The index of the child in its parent's children
 * vector.
 */
template <class K, class V>
void BTree<K, V>::split_child(BTreeNode* parent, size_t child_idx)
{
    /* Assume we are splitting the 3 6 8 child.
     * We want the following to happen.
     *     | 2 |
     *    /     \
     * | 1 |   | 3 | 6 | 8 |
     *
     *
     * Insert a pointer into parent's children which will point to the
     * new right node. The new right node is empty at this point.
     *     | 2 |   |
     *    /     \
     * | 1 |   | 3 | 6 | 8 |
     *
     * Insert the mid element from the child into its new position in the
     * parent's elements. At this point the median is still in the child.
     *     | 2 | 6 |
     *    /     \
     * | 1 |   | 3 | 6 | 8 |
     *
     * Now we want to copy over the elements (and children) to the right
     * of the child median into the new right node, and make sure the left
     * node only has the elements (and children) to the left of the child
     * median.
     *     | 2 | 6 |
     *    /   /     \
     * | 1 | | 3 | | 8 |
     *
     */

    /* The child we want to split. */
    BTreeNode* child = parent->children[child_idx];
    /* The "left" node is the old child, the right child is a new node. */
    BTreeNode* new_left = child;
    BTreeNode* new_right = new BTreeNode(child->is_leaf, order);

    /* E.g.
     * | 3 | 6 | 8 |
     * Mid element is at index (3 - 1) / 2 = 1 .
     * Mid child (bar) is at index 4 / 2 = 2 .
     * E.g.
     * | 2 | 4 |
     * Mid element is at index (2 - 1) / 2 = 0 .
     * Mid child (bar) is at index 2 / 2 = 1 .
     * This definition is to make this BTree act like the visualization
     * at
     * https://www.cs.usfca.edu/~galles/visualization/BTree.html
     */
    size_t mid_elem_idx = (child->elements.size() - 1) / 2;
    size_t mid_child_idx = child->children.size() / 2;

    /* Iterator for where we want to insert the new child. */
    auto child_itr = parent->children.begin() + child_idx + 1;
    /* Iterator for where we want to insert the new element. */
    auto elem_itr = parent->elements.begin() + child_idx;
    /* Iterator for the middle element. */
    auto mid_elem_itr = child->elements.begin() + mid_elem_idx;
    /* Iterator for the middle child. */
    auto mid_child_itr = child->children.begin() + mid_child_idx;


    /* TODO Your code goes here! */

    //add the midpoint child element to the parent
    //when the parent is full something goes wrong
    //std::cout << "mid_elem_itr" << (*mid_elem_itr).key << std::endl;
    //this feels very wrong
    unsigned i = 0;
    for (auto it = parent->elements.begin(); it != elem_itr; it++, i++) {}
    
    parent->elements.insert(elem_itr, *mid_elem_itr);
    parent->children.insert(child_itr, new_right);
    //std::cout << "elem_itr" << (*elem_itr).key << std::endl;

    //set pointer to the new right because left is already pointing there
    *child_itr = new_right;


    
    //add all the children on the right side to the new right
    
    //std::cout << "child: " << *child << std::endl;
    for (auto it = mid_child_itr; it != child->children.end(); ++it) {
        new_right->children.push_back(*it);
    }
    //add all the elements on the right side that are after the mid point
    for (auto it = ++mid_elem_itr; it != child->elements.end(); ++it) {
        new_right->elements.push_back(*it);
    }
    //std::cout << "new right side : " << *new_right << std::endl;
    
    //std::cout << "mid element: " << (*mid_elem_itr).key << std::endl;
    new_left->elements.erase(--mid_elem_itr, child->elements.end()); //we don't want the middle element so --
    if (!new_left->is_leaf) {
        new_left->children.erase(mid_child_itr, child->children.end());
    }
    
    //std::cout << "new left: " << *new_left << std::endl;

    //std::cout << "parent is now: " << std::endl << *parent << std::endl;

    // for (auto element : parent->children) {
    //     std::cout << "element in parent: " << *element <<std::endl;
    //     std::cout << "size " << (*element).elements.size() << std::endl;
    // }

    //std::cout << "----------------------------------------" << std::endl;

}

/**
 * Private recursive version of the insert function.
 * @param subroot A reference of a pointer to the current BTreeNode.
 * @param pair The DataPair to be inserted.
 * Note: Original solution used std::lower_bound, but making the students
 * write an equivalent seemed more instructive.
 */
template <class K, class V>
void BTree<K, V>::insert(BTreeNode* subroot, BTreeNode* parent, const DataPair& pair, size_t pathTo)
{
    /* There are two cases to consider.
     * If the subroot is a leaf node and the key doesn't exist subroot, we
     * should simply insert the pair into subroot.
     * Otherwise (subroot is not a leaf and the key doesn't exist in subroot)
     * we need to figure out which child to insert into and call insert on it.
     * After this call returns we need to check if the child became too large
     * and thus needs to be split to maintain order.
     */

    //maybe need to do operations on subroot child so we can keep track of parent?
    //std::cout << "trying to insert at " << *subroot << std::endl;
    size_t first_larger_idx = insertion_idx(subroot->elements, pair);
    //std::cout << "first_larger_idx " << first_larger_idx << std::endl;
    //std::cout << "index for key: " << pair.key << " is " << first_larger_idx << std::endl;

    /* TODO Your code goes here! */
    //std::cout << "subroot is a leaf: " << (subroot->is_leaf?"yes":"no" )<< std::endl;
    if (subroot->is_leaf) {
        subroot->elements.insert(subroot->elements.begin() + first_larger_idx, pair);
        //std::cout << *subroot << std::endl;
        //std::cout << std::endl;
    } else {
        insert(subroot->children[first_larger_idx], subroot, pair, first_larger_idx);
    }

    //check for valid
    //Need a way to pass in the parent, maybe change the helper function to also take a parent TreeNode
    if (parent != nullptr) {
        if (parent->children[pathTo]->elements.size() + 1 > order) {
            //std::cout << "splitting child at " << std::endl << *parent;
            //splitting this child is trying to get the index 2 node which is wrong, it needs to get index 0
            //I dont want to pass in another thing but maybe i will?
            split_child(parent, pathTo);
        }
    }
    
    
}

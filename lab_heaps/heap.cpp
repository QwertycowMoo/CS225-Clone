
/**
 * @file heap.cpp
 * Implementation of a heap class.
 */


template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    // @TODO Update to return the index you are choosing to be your root.
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the left child.
    return 2 * currentIdx;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the right child.
    return (2 * currentIdx) + 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    // @TODO Update to return the index of the parent.
    return currentIdx / 2;
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    // @TODO Update to return whether the given node has a child
    if (currentIdx * 2 > _elems.size() - 1) {
        return false;
    }
    return true;
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
    //check for has a child before calling this function
        size_t idxLeft = currentIdx * 2;
        size_t idxRight = currentIdx * 2 + 1;
        if (higherPriority(_elems[idxLeft], _elems[idxRight])) {
            return idxLeft;
        }
        if (idxRight < _elems.size()) {
            return idxRight;
        }
        return idxLeft;
    
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    // @TODO Implement the heapifyDown algorithm.
    if (hasAChild(currentIdx)) {
        size_t priority = maxPriorityChild(currentIdx);
        if (_elems[currentIdx] >= _elems[priority]) {
            //swap max priority with the current index
            std::swap(_elems[currentIdx], _elems[priority]);
            heapifyDown(priority);
        }
        
    }
    
    
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    // @TODO Depending on your implementation, this function may or may
    ///   not need modifying
    _elems.push_back(T()); //I think we do this to get something at the first index
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems) 
{
    // @TODO Construct a heap using the buildHeap algorithm
    _elems.push_back(T());
    size_t sizeElems = elems.size();
    for (T elem: elems) {
        _elems.push_back(elem);
    }
    
    // for (auto it = _elems.begin(); it != _elems.end(); ++it) {
    //     std::cout << *it;
    // }
    for (size_t i = _elems.size() - 1; i >= root(); i--) {
        if (hasAChild(i)) {
            heapifyDown(i);
        }
    }
}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    
    // @TODO Remove, and return, the element with highest priority
    T toReturn = _elems[root()];
    //std::cout << "returning: " << toReturn << std::endl;
    //get the last thing then heapify down
    //std::cout << "swapping" << _elems[root()] << "," <<  _elems[_elems.size() - 1] << std::endl;
    std::swap(_elems[root()], _elems[_elems.size() - 1]);
    //std::cout << "erasing: " << *(_elems.begin() + _elems.size() - 1) << std::endl;
    _elems.pop_back();
    
    
    //std::cout << *this << std::endl;
    
    heapifyDown(root());
    //std::cout << *this << std::endl;
    return toReturn;
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    // @TODO Return, but do not remove, the element with highest priority
    return _elems[root()];
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    // @TODO Add elem to the heap
    _elems.push_back(elem);
    heapifyUp(_elems.size() - 1);
}

template <class T, class Compare>
void heap<T, Compare>::updateElem(const size_t & idx, const T& elem)
{
    // @TODO In-place updates the value stored in the heap array at idx
    // Corrects the heap to remain as a valid heap even after update
    //std::cout << "before update called with:" << idx << ", " << elem << std::endl << *this << std::endl;
    _elems[idx] = elem;
    if (hasAChild(idx)) {
        size_t priority = maxPriorityChild(idx);
        if (higherPriority(_elems[priority], elem)) {
            heapifyDown(idx);
        } else {
            heapifyUp(idx);
        }
    } else {
        heapifyUp(idx);
    }
    

    //std::cout << "after update :" << std::endl << *this << std::endl;
}


template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    // @TODO Determine if the heap is empty
    if (_elems.size() == 1) {
        return true;
    }
    return false;
    
}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}

/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */
#include <iostream>
template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
    ListNode* head_ = NULL;
    ListNode* tail_ = NULL;
    length_ = 0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(tail_ -> next);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  ListNode * toDelete = head_;
  ListNode * nextDelete = head_;
  for (int i = 0; i < length_; i++) { //need to check whether this is done the correct amount of times
    if (i < length_ - 1) { //need this so that we don't try to access the next of a null pointer
      nextDelete = nextDelete->next;  
    }
    delete toDelete;
    toDelete = nextDelete;
  }
  
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  
    
    if (length_ != 0) {
      newNode -> next = head_;
      newNode -> prev = NULL;
      head_ -> prev = newNode;
      head_ = newNode;
    } else {
      newNode -> next = nullptr;
      newNode -> prev = nullptr;
      head_ = newNode;
      tail_ = newNode;
    }
  length_++;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode *newNode = new ListNode(ndata);

  if (length_ != 0) {
    newNode->next = nullptr;
    newNode->prev = tail_;
    tail_->next = newNode;
    tail_ = newNode;
  } else {
    newNode->next = nullptr;
    newNode->prev = nullptr;
    head_ = newNode;
    tail_ = newNode;
  }
  length_++;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  ListNode * curr = start;

  for (int i = 0; i < splitPoint && curr != NULL; i++) {
    curr = curr->next;
  }

  if (curr != NULL) {
    curr->prev->next = NULL;
    curr->prev = NULL;  
  }

  return curr;
}

/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a set of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */
template <typename T>
void List<T>::tripleRotate() {
  //needs to be done backwards
  // @todo Graded in MP3.1
  unsigned numRotations = length_ / 3;
  unsigned leftover = length_ % 3;
  ListNode * currCenter = tail_->prev;
  ListNode * nextCenter = currCenter;
  if (length_ > 3) {
    for (unsigned i = 0; i < leftover; i++) {
    currCenter = currCenter -> prev;
  }
  }
  
    for (unsigned i = 1; i <= numRotations; ++i) {
      ///Need to be redone
      if (i < numRotations) {
        nextCenter = nextCenter->prev->prev->prev;  
      }
      
      ListNode * tempNext = currCenter->next->next;
      currCenter->prev->prev = currCenter->next;
      if (i == 1) {
        currCenter->prev->next = NULL;
        tail_ = currCenter->prev;
      } else {
        currCenter->prev->next = currCenter->next->next->prev->prev; //is this the same as the nextcenter prev next? no because i < numRotations
      }
      currCenter->next->next = currCenter->prev;
      
      
      //needs to be separate from the nextcenter because we're playing with the currCenter
      if (i < numRotations) {
        currCenter->prev = nextCenter->prev;
        nextCenter->prev->next = currCenter;
      } else {
        head_ = currCenter;
        currCenter->prev = NULL;
      }
    
      

      
     

      //some segfault happening with the second try of rotations
      currCenter = nextCenter;
      
    }
     //the three are now done, but now the two surrounding this cell are not pointing to the right ones
      
  
}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
  ListNode *tempStart = startPoint;
  while (startPoint != endPoint) {
    ListNode *tempNext = startPoint->next;
    startPoint->next = startPoint->prev;
    startPoint->prev = tempNext;
    // if (startPoint->prev == endPoint) {
    //   break;
    // }
    startPoint = startPoint->prev;
  }
  ListNode *tempNext = startPoint->next;
  startPoint->next = startPoint->prev;
  startPoint->prev = tempNext;
  endPoint = tempStart;
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
  ListNode *toSwap = head_;
  ListNode *nextSwap = head_;
  ListNode *tempStart = toSwap;
  ListNode *farNext = nextSwap;
  ListNode *prevNextSwap = toSwap;
  int counter = 0;
  bool doesSwap = true;
  while(doesSwap) {
    for (int i = 0; i < n - 1; i++) {
      if (nextSwap == nullptr){
        doesSwap = false;
        break;
      }
      nextSwap = nextSwap->next;
      if (farNext != nullptr) {
        farNext = farNext->next;
        if (farNext != nullptr){
          farNext = farNext->next;
        }
      }
      
    }
    if (farNext != nullptr) {
      farNext = farNext->next;
    }

    if (doesSwap) {
      reverse(toSwap, nextSwap); 

      if (counter == (length_/n) && length_%n == 0) {
        //last swap
        tail_ = nextSwap;
      } else if (counter == (length_/n) - 1 && length_%n != 0) {
        //last swap but there's still things left
        nextSwap->next = toSwap->prev;
      } else {
        //last swap and farNext is an actual pointer
        nextSwap->next = farNext; 
      }

      if (counter == 0){
        //first swap, set head
        head_ = toSwap;
        ListNode *tempToSwap = toSwap;
        toSwap = toSwap->prev;
        tempToSwap->prev = nullptr;
      } else {
        //other swaps, set toSwap(last element now) 
        ListNode *tempToSwap = toSwap;
        toSwap = toSwap->prev;
        tempToSwap->prev = prevNextSwap;
      }

      prevNextSwap = nextSwap;
      nextSwap = toSwap;
      farNext = toSwap;
      
    }
    counter++;
  }
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2

  ListNode * secondNext;
  ListNode * tFirst = first;
  int i = 0;
  while(first != nullptr && second != nullptr) {
    
    if (first->next != nullptr) {
      //first still has data and needs the next thing to have a backpointer to the second
      if (first->data < second->data && second->data < first->next->data) {
        //second should go between first and first->next
        secondNext = second->next;
        second->next = first->next;
        first->next->prev = second;
        first->next = second;
        second->prev = first;
       
        
        second = secondNext;
        first = first->next;

      } else if (second->data < first->data) {
        //second should go before first 
        secondNext = second->next;
        ListNode * tempFirstPrev = first->prev;
        first->prev = second;
        second->next = first;
        second->prev = tempFirstPrev;

        //set head to be correct if its the first thing in the list
        if (tempFirstPrev == nullptr) {
          tFirst = second;
        } else {
          tempFirstPrev->next = second;
        }
        second = secondNext;
        
      } else {
        //nothing happens, move on
        first = first->next;
      }
      
      
    } else {
      //first has run out of things, this one is the last item
      if (second->data < first->data) {
        //second still has data that needs to be put behind first
        secondNext = second->next;
        ListNode * tempFirstPrev = first->prev;
        first->prev = second;
        second->next = first;
        second->prev = tempFirstPrev;
         if (tempFirstPrev == nullptr) {
          tFirst = second;
        } else {
          tempFirstPrev->next = second;
        }
        second = secondNext;
      } else {
        //first is the smallest thing, add the second and then let it go to null pointer so we get the rest of second
        first-> next = second;
        second->prev = first;
        break;
      }         
    }   
  }
  
  return tFirst;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  return NULL;
}

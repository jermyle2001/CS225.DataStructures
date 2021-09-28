#include <iostream>


/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
    head_ = NULL;
    tail_ = NULL;
    length_ = 0; //Initializing empty list, length == 0
/*
-Set length, which maintains the length of the list
-In an empty list, head and tail == NULL
*/

}

//---------------END OF List()-------------------------------
//-------------BEGINNING OF begin()--------------------------

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
  


  return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1

while(head_ != tail_){
 ListNode* nextptr = head_->next;
 delete head_;
 head_ = nextptr;
}

//All nodes except tail deleted. Now we need to delete tail.
 delete tail_; 
//Set head and tail to NULL just in case
 head_ = NULL;
 tail_ = NULL;

} //EoF 

//----------------END OF destroy() FUNCTION---------------------------------

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
  newNode -> next = head_;
  newNode -> prev = NULL;
  
  if (head_ != NULL) { //If headnode exists, we need to set its prev value
    head_ -> prev = newNode;
  }
  if (tail_ == NULL) {
    tail_ = newNode;
  }
  head_ = newNode; //head_ needs to be set to newNode

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

  ListNode * newNode = new ListNode(ndata); 
  newNode -> next = NULL;
  newNode -> prev = tail_; 

  if(tail_ != NULL){ //If tail is not empty, we need to set its next
   tail_ -> next = newNode;
  }

  tail_ = newNode; //Set tail to new tail which is newNode

  if(head_ == NULL){ //Set to new head if empty list
   head_ = newNode;
  }

  length_++;

} //EoF

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
  ListNode * temp = curr;

/*
-	CASES TO ACCOUNT FOR
- 1. splitPoint + start exceeds list boundaries
-    a. Would need to return NULL as head; operation was not
-       successful
- 2. splitPoint + start does NOT exceed list boundaries
-    a. Set tail_ 
-    b. Set tail_->next to NULL
-    c. Set newhead->prev to NULL
-    d. Return newhead
- 3. splitPoint == 0
-    a. Honestly no clue where to split, maybe just nowhere 
*/
  if(splitPoint == 0){
   return NULL;
  }




  //1. Check if splitPoint exceeds boundaries of list
  for(int i = 0; i < splitPoint; i++){
   //Create a temp pointer to help keep track of previous location
   //-is a contingency for if splitPoint == NULL
   temp = curr;
   curr = curr->next; //Increment curr to next place 
   if(curr == NULL){
   /*
	If at any point curr == NULL, that means that splitPoint exceeds
	the boundaries of the list. Thus we will return NULL.
  */
    return NULL;
    }
  } //End of FOR loop
  /*
	At this point.... 
         temp = tail_
	 curr = head2

	We also need to set the value of next for the tail_ to be NULL.
  */ 
  tail_ = temp;
  tail_->next = NULL;
  curr->prev = NULL;
  
  return curr;

  /*for (int i = 0; i < splitPoint || curr != NULL; i++) {
    curr = curr->next;
  }

  if (curr != NULL) {
      curr->prev->next = NULL;
      curr->prev = NULL;
  }

  return NULL;*/
} //EoF

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
  // @todo Graded in MP3.1
/*
- 1. Check to see if multiple of 3
-    a. If not, terminate (end of list)
-    b. If so, perform operation
- 2. Change next/prev pointers of list
- 123->231
*/

ListNode* iterate = head_;
ListNode* node1;
ListNode* node2;
ListNode* node3;
int i = 0;
for(i = 0; i < length_ / 3; i++){ //Divide length_ by 3, that's how many times we will iterate
 std::cout << "Iterating..." << std::endl;
 node1 = iterate; //Get node1's pointer
 iterate = iterate->next; //Increment iterate to get next value of node2
 node2 = iterate; //Get node2's pointer
 iterate = iterate->next; //Increment iterate to get next value of node3
 node3 = iterate; //Get node3's pointer
 //We don't have to check if next will be NULL - the length_/3 does that for us
//123->231
 if(node1->prev == NULL){
  head_ = node2;
  node2->prev = NULL;
 }
 else{
  node2->prev = node1->prev;
  node1->prev->next = node2;
 }

 node1->next = node3->next;
 node3->next->prev = node1;
 node1->prev = node3;
 node3->next = node1;
 
 iterate = iterate->next;

} //End of FOR Loop



return;
} //EoF


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
  return NULL;
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

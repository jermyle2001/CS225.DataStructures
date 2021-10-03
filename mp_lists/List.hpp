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

while(head_ != NULL){
 ListNode* nextptr = head_->next;
 delete head_;
 head_ = nextptr;
}

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

} //EoF

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
if(length_ < 3){
  return;
}
ListNode* iterate = head_;
ListNode* node1;
ListNode* node2;
ListNode* node3;
int i = 0;
for (i = 0; i < length_/3; i++){
  /*
  - Rotates in intervals of 3, so divide length by 3
  - <123> -> <231>
  */ 
  node1 = iterate;
  node2 = iterate->next;
  node3 = node2->next;
  iterate = node3->next;
  node1->next = iterate;
  if(i == 0){
    node2->prev = NULL;
    head_ = node2;
  }
  else{
    node2->prev = node1->prev;
    node2->prev->next = node2;
  }
  node1->next = node3->next;
  node3->next = node1;
  node1->prev = node3;
  if(node1->next != NULL){
    node1->next->prev = node1;
  }
  tail_ = node1;
} //Eo FOR Loop
//Do NOT Shift remaining elements if not multiple of 3
iterate = head_;
for(i = 0; i < length_ - 1; i++){//Make sure prev elements are correct
  node1 = iterate;
  node1->next->prev = node1;
  iterate = iterate->next;
}
tail_ = node1;

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
  
  //Check to see if endPoint and startPoint are actually valid
  if(startPoint == NULL || endPoint == NULL){
    if(endPoint == NULL){
      endPoint = tail_;
    }
    else{
      return;
    }
  }
  /*
  - The following stores the information for the nodes on the edges
  - of the list, in addition to the pointer "iterate" which we will
  - use to iterate throughout the list
  */
  
  ListNode* startPrev = startPoint->prev;
  ListNode* endNext = endPoint->next; 
  ListNode* iterate = startPoint;
  ListNode* temp;
  ListNode* oldIterate;
  while(iterate != endPoint){ 
  /*
    While loop should iterate through list until designed endPoint. When
    endPoint is reached, loop will terminate. Afterwards, set endPoint to
    be next head.
    This loop effectively switches the next and previous pointers of the
    list.
  */

		if(iterate == NULL){
			std::cout << "Iterate is 'NULL'" << std::endl;
			break;
		}
		temp = iterate->next; //Switch next and prev pointers
		iterate->next = iterate->prev;
		iterate->prev = temp;
		oldIterate = iterate;
		iterate = temp; //Increment iterate to next node on list
		
  } //End of WHILE loop
  /*
    After the While loop, we need to set our last node before the 
    the endPoint, in addition to setting the endPoint and startPoint and 
    their respective edges.
  */
	//TAKE INTO ACCOUNT NULL POINTERS!
	
	//1. Set endPoint's pointers
	//Switch endPoint and startPoint's next/prevs and edge nodes
	endPoint->next = oldIterate;
	endPoint->prev = startPrev;

	startPoint->next = endNext;
	if(endNext != NULL)
	startPoint->next->prev = startPoint;
	oldIterate->prev = endPoint;
  if(head_ == startPoint){
	head_ = endPoint;
  }
  if(tail_ == endPoint){
	tail_ = startPoint;
  }
	return;
} //EoF

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
  ListNode* prev = NULL;
  ListNode* curr = head_;
  ListNode* temp = NULL;
  ListNode* tail = NULL;
  ListNode* newHead = NULL;
  ListNode* join = NULL;
  int count = 0;
  int count2 = 0;
  while(curr != NULL){
    //Iterate through whole list, in groups of k
    count = n;  //Set count to n for iteration
    join = curr; //Join is the node b/w groups
    prev = NULL; //Reset prev every time


    while(curr != NULL && count--){ //Loop terminates if end reached, OR group finished
      temp = curr->next;
      curr->next = prev; //Sets curr->next to prev, but is NULL on first iteration
      prev = curr;
      curr = temp;
    } //End of INNER While loop

    if(newHead == NULL){
      newHead = prev; //Sets new head
      
      if(count2 == 0){
        head_ = newHead;
        newHead->prev = NULL;
      }
    }

    if(tail != NULL){
      tail->next = prev;
    }
    tail = join;
    //tail_ = tail;
    count2++;


  } //End of OUTER While loop
  //Now set the prev pointers
  curr = head_;
  head_->prev = NULL;
  while(curr!= NULL){
    if(curr->next != NULL)
    curr->next->prev = curr;
    if(curr->next == NULL)
    break;
    curr = curr->next;
  }
  tail_ = curr;

  return;
} //EoF

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
  /*
  - Merges two lists together AND sorts them
  - Not judged on time, can just do whatever
  - Approach: Bubble sort list, can just merge both lists and return once larger list
  -   is sorted
  - Approach 2: Get node, compare data (if node1 > node2, insert node2 in front of node1),
  -   also change node to left of node1's next, change prev pointers later
  */
  std::cout << "Running merge" << std::endl;
  ListNode* node1 = first;
  ListNode* node2 = second;
  ListNode* node1prev = first->prev; //Potentially NULL
  ListNode* node1next = first->next;

  while(node2 != NULL){ //Outer WHILE Loop, iterates through second list
    //Don't need to update node1 b/c lists are presorted, BUT need to update node2 to get
    //node data for comparison 
    node2 = second;
    node1next = first->next;
    while(node1 != NULL){ //Inner WHILE Loop, iterates through first list
      if(!(node1->data < node2->data)){ //Compare data. Put node2 in front if node1 > node2
        //node2 < node1, place in front, update first if first node
        if(node1 != first){ 
          //If node1 is NOT at the head, update normally
          node1->prev->next = node2;
          node2->prev = node1->prev;
        }
        else{ //Update first if node1 was 'first'
          first = node2;
          node2->prev = NULL;
        }

        //node2 < node1, so node2->next = node1
        node2->next = node1;
        //node1 will continue pointing where it did originally
        node1->prev = node2;  
        break; //Exit loop, node2 has been placed, need to grab new node2
      } //Eo data comparison
      //Iterate node1
      node1 = node1->next;

    } //Eo Inner WHILE
    //Iterate node2/second and get next node of second list
    second = second->next;

  } //Eo Outer WHILE
  std::cout << "Exiting merge and returning first" << std::endl;
  return first;
  




 /*
  if(first == NULL || second == NULL){
    if(first == NULL && second == NULL){
      return NULL;
    }
    else if(first == NULL){
      return first;
    }
    else{
      return second;
    }
  }

  //Combine lists into one larger list
  ListNode* curr1 = first;
  while(curr1->next != NULL){
    curr1 = curr1->next;
  }

  std::cout << "Combining list" << std::endl;
  //curr1 is now the end of the list, link two lists together
  second->prev = curr1;
  curr1->next = second;

  //Now bubble sort list
  int swapcount = 0;
  curr1 = first;
  ListNode* curr2 = NULL;
  do{
    swapcount = 0;
    curr1 = first; //Effective head of list, make sure to change it!
    std::cout << "curr1 set to first" << std::endl;
    while(curr1->next != curr2){ //Iterate through list until curr1 == curr2
      std::cout << "Sorting..." << std::endl;
      if(curr1 == NULL || curr1->next == NULL){
        std::cout << "curr1 is NULL!" << std::endl;
        break;
      }
      if(!(curr1->data < curr1->next->data)){ //Compare data, statement says if curr1 is NOT less than curr1->next, i.e. curr1->next is less than curr1/curr1 is LARGER than curr2
        //Swap pointers, check if it's at effective head
        std::cout << "Entering if statements" << std::endl;
        ListNode* node1 = curr1;
        ListNode* node2 = curr1->next;
        ListNode* rightNode = node2->next; //Effective right edge
        ListNode* leftNode = node1->prev;
        if(curr1 == first){ //Case of head (first)
          //first (head) is larger than passed in value, so we need to swap places
          //Swap positions of node 1 and node2
          rightNode = node2->next;
          node1->next = rightNode;
          leftNode = node1->prev;
          node1->prev = node2;
          node2->prev = NULL; //node2 is new first
          node1->next->prev = node1;
          node2->next = node1;
          //Set new head (first) to node2, which is smaller
          first = node2;
          if(first == NULL){
            std::cout << "first is NULL!" << std::endl;
          }
          swapcount = 1;
        }
        else{ //Else swap pointers normally 1 2 -> 2 1
          rightNode = node2->next;
          node1->next = rightNode;
          leftNode = node1->prev;
          node1->prev = node2;
          node2->prev = leftNode;
          leftNode->next = node2;
          if(rightNode != NULL){
            rightNode->prev = node1;
          }
          swapcount = 1;
        }
      }
      std::cout << "Iterating curr1" << std::endl;
      curr1 = curr1->next; //iterate curr
      std::cout << "curr1 iterated" << std::endl;
      if(curr1 == NULL){
        std::cout << "curr1 is NULL!" << std::endl;
        break;
      }
    } //End of Inner WHILE Loop
    std::cout << "Setting curr2 == curr1" << std::endl;
    if(curr1->next == NULL){
      break;
    }
    curr2 = curr1;
  } //End of DO
  while(swapcount);
  std::cout << "Exited while loop" << std::endl;
  return first; //INSERT THE HEAD HERE
*/
  
} //EoF



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
  //Recursive merge 




  return NULL;
}

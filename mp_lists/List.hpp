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
  //Edge cases: if splitpoint is <= 0, and if splitpoint > length_.
  if(splitPoint <= 0){
    //Here, our splitPoint is a number that is negative or 0. Thus, we set to zero.
    splitPoint = 0;
  }
  if(splitPoint > length_){
    //Here, we will return an empty list, since we split outside the boundaries and thus the 
    //second list would technically be empty. We can call the default constructor.
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

  if(head_ == startPoint){
	  //If startPoint was the head, then the reset the head
    head_ = endPoint;
  }
  if(tail_ == endPoint){
    //If endPoint was the tail, then reset the tail
	  tail_ = startPoint;
  }
  if(head_ != startPoint){
    //If startPoint is not the head, then node on left's next needs to be changed
    startPrev->next = iterate;
  }
  if(tail_ != endPoint){
    //If endPoint is not tail, then node on right's prev needs to be changed
    startPoint->next->prev = startPoint;
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
  
  ListNode* head = first;
  ListNode* node1 = first;
  ListNode* node2 = second;
  ListNode* iterator;
  //Decide if we want to make a new head or not
  if(first->data < second->data){ 
    //first is smaller, set it as head
    head = first;
    node1 = node1->next; //Iterate node1
  }
  else{
    //second is smaller, set it as head
    head = node2;
    node2 = node2->next; //Iterate node2
  }
  iterator = head;
  while(node1 != NULL && node2 != NULL){ //Iterate until either list is full
    //Constantly compare data via if statement - stop iterating when we find 1 < 2
    //Basically just build a new list, comparing nodes until one list runs out
    if(!(node2->data < node1->data)){
      //Reset links b/w nodes, iterate node1
      iterator->next = node1;
      node1->prev = iterator; 
      node1 = node1->next;
    } //Eo IF statement
    else{
      iterator->next = node2;
      node2->prev = iterator;
      node2 = node2->next;
    }
    //Iterate new list
    iterator = iterator->next;
  } //Eo WHILE Loop
  //Either node1 or node2 is NULL, figure out which one ran out first and add remaining nodes
  if(node1 == NULL && node2 != NULL){
    //First list ran out, add in second list
    iterator->next = node2;
    node2->prev = iterator;
  }
  if(node2 == NULL && node1 != NULL){
    iterator->next = node1;
    node1->prev = iterator;
  }
  return head;

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
  //Base case: when start->next == NULL, since our list is as small as possible
  if(start->next == NULL){
    return start; //Return/recurse
  }
  int halfChain;
  halfChain = chainLength/2; //Recursive statement divides problem into two, so chainLength/2
  ListNode* secondList;
  secondList = split(start, halfChain);
  //Now we have to recurse, but one of our base cases will have 
  return merge(mergesort(start, halfChain), mergesort(secondList, (chainLength % 2) + halfChain));
}

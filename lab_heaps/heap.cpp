#include <cmath>
#include <iostream>
// #include <assert.h>

/**
* @file heap.cpp
* Implementation of a heap class.
*/

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
   // @TODO Update to return the index you are choosing to be your root.
   /*
        We choose to use 1 based indexing - makes it a little easier when 
        calculating the very first set of parent/children (don't have to worry
        about multiplying by 0.
   */
   return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
   // @TODO Update to return the index of the left child.
   /*
        Follows basic heap idea
   */
   return 2 * currentIdx;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
   // @TODO Update to return the index of the right child.
   /*
        Follows basic heap idea
   */
   return 2 * currentIdx + 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
   // @TODO Update to return the index of the parent.
   /*
        Follows basic heap idea
   */
   return std::floor(currentIdx/2);
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
   // @TODO Update to return whether the given node has a child
   /*
        If there will be at least one child, it will be the left child, as
        the left child is pushed first. Thus, check if the left child 
        exists at all - we do this by checing it against the size
        of the vector.
   */
   return leftChild(currentIdx) < _elems.size();
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
   // @TODO Update to return the index of the child with highest priority
   ///   as defined by higherPriority()
   
   /*
        We use the higherPriority() function to determine whether the first 
        element passed through the function has a higher priority (or has a lower 
        value) than the second element passed through. 

        Since we're comparing the left and right children and checking to see which
        has the higher priority, we need to confirm that the right child exists, as
        the function assumes that at least one child exists. Thus, if the right child
        does not exist, we will return the left child.

        The const modifiers are added to prevent any unwanted modifications.
   */

   const T leftElem = _elems[leftChild(currentIdx)];

   // Has no right child
   if(rightChild(currentIdx) >= _elems.size()) { return leftChild(currentIdx); }

   const T rightElem = _elems[rightChild(currentIdx)];

   // Find higher priority child and return it's index
   if(higherPriority(leftElem, rightElem))  { return leftChild(currentIdx); }

   else { return rightChild(currentIdx); }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
   // @TODO Implement the heapifyDown algorithm.
   /*
        heapifyDown is implemented recursively using the heapifyDown algorithm. 
        As long as we're not at the leaf, we find the smallest child (or in other words,
        the child with higher priority) and determine whether we want to swap it with our
        current node, or parent node basically. We continue down the tree until we hit/go
        past a leaf, at which point we just return and terminate the operation.
   */
   if(!hasAChild(currentIdx)) {
       return;
   }

   size_t higherPriorityIdx = maxPriorityChild(currentIdx);
   if(higherPriority(_elems[higherPriorityIdx], _elems[currentIdx]))
   {
       std::swap(_elems[currentIdx], _elems[higherPriorityIdx]);
       heapifyDown(higherPriorityIdx);
   }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
   if (currentIdx == root())
   {
       return;
   }

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
   /*
        Because of the fact that we chose to do 1-based indexing, we need
        to push an initial point into our elements vector to make the indexing
        accurate.
   */
   _elems.push_back(T());
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems)
{
   // @TODO Construct a heap using the buildHeap algorithm
   /*
        We construct the heap using the buildHeap algorithm. We first push back our dummy
        value into our 0 index to make sure we are consistent with 1-based indexing. Next,
        we push our new elements into our elements vector, and heapifyDown from the 
        very bottom of our tree, turning our subtrees into heaps as we move up to make it
        consistent with our defintion of a minHeap.
   */
   _elems.push_back(T());

   for(size_t i = 0; i < elems.size(); i++)
   {
       _elems.push_back(elems[i]);
   }

   for(size_t i = _elems.size() - 1; i >= 1; i--)
   {
       heapifyDown(i);
   }

}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
   // @TODO Remove, and return, the element with highest priority
   /*
        If we want to pop an element, we need to ensure the heap maintains
        its key property. 

        Our base case, with a vector of size 2, does not need to worry about
        maintaining the tree, since there are only 2 elements.

        Otherwise, we need to remove the root, and swap the very last
        element in our vector with our root, popping out the root afterwards.
        Then, we will heapifyDown until the tree has been restored and 
        return the element we popped out.
   */
   if(_elems.size() == 2)
   {
       T rootElem = _elems.back();
       _elems.pop_back();
       return rootElem;
   }

   if(!empty())
   {
       T rootElem = _elems[root()];
       std::swap(_elems[root()], _elems.back());
       _elems.pop_back();
       heapifyDown(root());
       return rootElem;
   }

   return T();
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
   // @TODO Return, but do not remove, the element with highest priority
   /*
        All we need to do is return the element with the highest priority, 
        or the root of our heap.
   */
   if(!empty())
   {
       return _elems[root()];
   }

   return T();
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
   // @TODO Add elem to the heap
   /*
        After pushing our new element into our heap, we need to
        heapifyUp from the bottom of our heap to maintain its
        property.
   */
   _elems.push_back(elem);
   heapifyUp(_elems.size() - 1);
}

template <class T, class Compare>
void heap<T, Compare>::updateElem(const size_t & idx, const T& elem)
{
   // @TODO In-place updates the value stored in the heap array at idx
   // Corrects the heap to remain as a valid heap even after update
   /*
        This is basically an insert at the given index. We first check to
        see if our new element we want to insert is a lower value than our current
        element. If so, then we need to make sure that our heap property will not
        be disrupted by inserting, and thus we need to compare it with the parent
        and heapify accordingly. We heapifyUp, since everything below the index is
        still going to be larger.

        Otherwise, we insert the element as normal, but ensure that the values below 
        it are consistent with our minheap property. Here, we heapifyDown instead of up,
        since we making sure the trees below our index are accurate, as we already know
        that the tree above our node are accurate.
   */
   if(_elems[idx] == elem) return;

   if(higherPriority(elem, _elems[idx]))
   {
       _elems[idx] = elem;

       if(idx == root()) return;

       if(higherPriority(elem, _elems[parent(idx)]))
       {
           heapifyUp(idx);
       }
   }
   else
   {
       _elems[idx] = elem;

       if(!hasAChild(idx)) return;

       if(higherPriority(_elems[maxPriorityChild(idx)], elem))
       {
           heapifyDown(idx);
       }
   }
}


template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
   // @TODO Determine if the heap is empty
   /*
        The heap will be empty if our size is less than our indexing. 
   */
   return _elems.size() <= root();
}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
   for (size_t i = root(); i < _elems.size(); i++) {
       heaped.push_back(_elems[i]);
   }
}
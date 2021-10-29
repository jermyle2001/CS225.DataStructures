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

    if(second[curDim] < first[curDim]){
      return false;
    }
    else if(first[curDim] < second[curDim]){
      return true;
    }
    else{
      return(first < second);

    }

} //EoF

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    //Sum squared dim value differences
    double currentSum = 0;
    double potentialSum = 0;
    for(int i = 0; i < Dim; i++){
      double currentDistance = (target[i] - currentBest[i]) * (target[i] - currentBest[i]);
      double potentialDistance = (target[i] - potential[i]) * (target[i] - potential[i]);
      currentSum = currentSum + currentDistance;
      potentialSum = potentialSum + potentialDistance;
    }
    if(potentialSum < currentSum){
      return true;
    }
    else if(currentSum < potentialSum){
      return false;
    }
    else{
      return (potential < currentBest);
    }
} //EoF

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */

    /*
      We are passed in a vector of points that is Const (cannot be changed). We need to organize the tree/vector
        to be consistent with our definition of a k-d tree.
    */
   //Set size to 0, since we are constructing a new tree
   size = 0;
   //We want to use the points in newPoints to create our new tree, but it's passed through with a const. Thus,
   // we need to copy the vector over using the .assign() feature.
   vector<Point<Dim>> pointsVector;
   //Assign all values in vector by using .begin() and .end()
   pointsVector.assign(newPoints.begin(), newPoints.end());
   //Now build new tree using helper function. We start at dimension 0, with left being at the very start
   // and right being at the very end, which is the same as pointsVector.size() - 1
   root = buildTree(pointsVector, 0, 0, pointsVector.size() - 1);
   size = newPoints.size();
   if(root == NULL){
     std::cout << "The root is NULL!" << std::endl;
   }
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */

  /*
    We need to copy the KDTree passed in. We can implement a helper function to achieve this, as a helper function
      would provide us the flexibility needed to pass in whatever values we need to achieve via recursion.
  */
  //The root of this class is our functional root, pass in this->root and the root of the other tree
  //  and begin copying via our subroutine. We should also update the size to be consistent.

  //Copy over tree via our copy subroutine
  copy(this->root, other.root);
  //Update the size of our tree
  size = other.size;
} //EoF

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  /*
    This operator should delete the existing KDTree stored within this class and copy over 
      the KDTree stored in rhs.
  */
  //Delete tree at root - don't need to check if NULL or not, since the deletion function does that already
  if(this != &rhs){
    KDTreeDeletion(root);
    //Now copy over the new tree
    copy(this->root, rhs.root);
    //Also update the size of our root
    size = rhs.size;
  }
  if(root == NULL){
     std::cout << "The root is NULL!" << std::endl;
   }
  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
  /*
    Similar to the copy function, we need to add in a helper function to let us recursively 
      delete each node as we go along.
  */
  KDTreeDeletion(root); //Delete from root using helper function, detailed below
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */

    /*
      The findNearestNeighbor functions as follows:
        The function recursively traverses down the tree. At each level, the function must choose 
        the subtree that contains the search element. It will recurse right or left based on the 
        splitting dimension of the current level.
        Once the lowest-bound hyperrectangle is reached, the node in that rectangle is effectively the 
        "current best" neighbor.

        Afterwards, the function will begin traversing back up the tree to the parent node, checking to see if
          any other nodes along the way would be better matches for our element. We can compare distances, or radii
          to the parent node, to see if the new radii is smaller than the old one. If so, we replace the radii and 
          "current best" point/match.

        Next, we need to check to see if the "current splitting plane's distance from search node is within the
          current radius". Essentially, we check to see if our plane's distance from the search node is low enough
          to be considered, as thus we would have to consider the opposite subtree and search it recursively.
          (Note: this is how I interpret it, it may or may not be correct).

        Additionally, during back-tracking we only consider subtrees within the current radius, as checking
          subtrees with larger radii is pointless and inefficient.
    */

    //Note: we need to create a helper function to pass through the appropriate variables for recursion.
    //  It will be included directly below.

    return FNNHelper(query, root, 0);
}

/*
  Helper functions included below!
*/

//Below is the helper function for findNearestNeighbor
template <int Dim>
Point<Dim> KDTree<Dim>::FNNHelper(const Point<Dim> & query, KDTreeNode* subRoot, int dimension) const
{
  /*
    Follow AMA Slides
  */
  
  //Step 1: Base Case
  if(subRoot->right == NULL && subRoot->left == NULL){
    return subRoot->point;
  }

  /*
    Step 2: Check if Query is on left or right side of subRoot[dim]. 
      We will recurse onto whichever side it's on.
  */

  //Initialize a "nearest" point, set it to subRoot's point just in case recursion fails on both sides
  Point<Dim> nearest = subRoot->point;
  
  //Also initialize a flag to indicate whether we (attempted) to traverse down the left subtree
  bool leftFlag = false;


  //Check if query is on left side or subRoot 
  if(smallerDimVal(query, subRoot->point, dimension)){
    //Note: we know that at LEAST one subroot exists. The code got past the base case.
    if(subRoot->left == NULL){ //If our left subtree doesn't exist, recurse down right side
      nearest = FNNHelper(query, subRoot->right, (dimension + 1) % Dim);
    }
    else{ //Otherwise recurse down left
      nearest = FNNHelper(query, subRoot->left, (dimension + 1) % Dim);  
    }
    //Indicate that we attempted to traverse down left side, set bool
    leftFlag = true;
  }
  else{
    if(subRoot->right == NULL){
      nearest = FNNHelper(query, subRoot->left, (dimension + 1) % Dim);
    }
    else{
      nearest = FNNHelper(query, subRoot->right, (dimension + 1) % Dim);
    }
    leftFlag = false;
  }
  /*
    Step 3: Now we check to see if our current point at our subRoot is closer than the "nearest" 
      point that we have recursed to find, i.e. if any other points lower in the tree are a 
      better fit than the point rooted at our subRoot.
  */
  //Now check if current point at subRoot is closer than our "nearest" point that we found
  if(shouldReplace(query, nearest, subRoot->point)){
    nearest = subRoot->point;
  }
  /*
    Step 4: We want to check if any other subtrees exist within the "radius" of our nearest and query.
      If so, then those subTrees could also potentially contain better points, and we need to search 
      them too. We compare the radius to the splitting distance.
  */
  double radius = 0; 
  for(int i = 0; i < Dim; i++){
    radius = radius + (query[i] - nearest[i]) * (query[i] - nearest[i]);
  }
  double splitDistance = (query[dimension] - subRoot->point[dimension]) * (query[dimension] - subRoot->point[dimension]);

  Point<Dim> otherPoint;
  if(radius >= splitDistance){
    /*
      Our radius is larger than our splitDistance, indicating that the splitDistance is INCLUDED within
        the radius and thus requiring us to check the opposite subtree. Check to see if the opposite subtree
        exists before attempting to find the point down the subtree. We can also determine beforehand which
        subtree we need to traverse.
    */
    KDTreeNode* otherSubtree;
    Point<Dim> otherBest;
    if(leftFlag == true){
      otherSubtree = subRoot->right;
    }
    else{
      otherSubtree = subRoot->left;
    }
    if(otherSubtree != NULL){
      otherBest = FNNHelper(query, otherSubtree, (dimension + 1) % Dim);
      if(shouldReplace(query, nearest, otherBest)){
        nearest = otherBest;
      }
    }
    else{
      return nearest;
    }
  }
  return nearest;


} //EoF



template <int Dim>
unsigned KDTree<Dim>::partition(vector<Point<Dim>>& list, unsigned dimension, unsigned left, unsigned right, unsigned pivotIndex)
{
  /*
    The partition helper function is part of the QuickSelect function. It divides a list into two parts, grouped
      by values lower than the pivotValue and values higher than the pivotValue. It's used as a subroutine in 
      QuickSelect.

    First we want to swap our values at pivotIndex and Right (move value in pivotIndex to the end of our list).
      Thus we get our values and swap.
  */

  //Get value at pivotIndex in list
  auto pivotValue = list[pivotIndex];
  //Get value on right side of list
  auto rightValue = list[right];
  //Swap the values in each index
  list[right] = pivotValue;
  list[pivotIndex] = rightValue;

  //Now we want to store our index 
  auto storeIndex = left;
  //Iterate through entire list, sorting the values into two groups
  for(auto i = left; i < right - 1; i++){
    //Check if current value is less than the pivotValue. If so, we will swap it
    //with the value at storeIndex.
    if(smallerDimVal(list[i], pivotValue, dimension)){
      //Swap values at index storeIndex and index i
      auto storeVal = list[storeIndex];
      auto iVal = list[i];
      list[storeIndex] = iVal;
      list[i] = storeVal;
      //Now increment storeIndex
      storeIndex++;
    } //End of IF Loop
  } //End of FOR Loop
  
  //List has been partitioned, move pivot to its final place by swapping
  //  list[right] and list[storeIndex] (list[right] previously held the pivotValue)

  //Swap list[storeIndex] and list[right]
  rightValue = list[right];
  auto storeVal = list[storeIndex];
  list[storeIndex] = rightValue;
  list[right] = storeVal;
  
  //Now return storeIndex - storeIndex is essentially the index at which the list has been 
  //  partitioned at
  return storeIndex;

} //EoF

template <int Dim>
Point<Dim>& KDTree<Dim>::quickSelect(vector<Point<Dim>>& list, unsigned dimension, unsigned left, unsigned right, unsigned k)
{
  /*
    The following helper function selects/returns the smallest k-th dimension element of the list 
      within [left, right] inclusive. Why do we do this? Will update later honestly I have no clue.

    We will implement this function recursively, following the AMA slides
  */

  //Base case: left == right
  if(left == right){
    //We have narrowed down our elements to the smallest element by reducing the margins recurisvely.
    //Thus, our smallest element is the only one remaining - return either list[left] or list[right].
    return list[left]; 
  } //Eo IF 

  //k is our pivot index, follow AMA slides...
  unsigned pivotIndex = (left + right)/2;
  //Reassign the pivotIndex to be the output of our partition helper function
  //By calling partition, we sort the list within our bounds and return the index which divides the two groups
  pivotIndex = partition(list, dimension, left, right, pivotIndex);

  //We now chevector<Point<Dim>>& pointsList, int dimension, unsigned left, unsigned rightck to see if our returned pivotIndex matches our original pivotIndex. If that's the case, then 
  //  it indicates that our partition has sorted the list? k is thus the the smallest value? (Not really sure about)
  //  how to make sense of this tbh
  if(k == pivotIndex){
    return list[k];
  }
  else if(k < pivotIndex){
    right = pivotIndex - 1; //We increment our margins to narrow down the location of our smallest element
  }
  else{
    left = pivotIndex + 1;
  }
  return quickSelect(list, dimension, left, right, k);

} //EoF

//Implement a treebuilder function
template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::buildTree(vector<Point<Dim>>& pointsList, int dimension, unsigned left, unsigned right)
{
  /*
    Function will operate recursively, following AMA slide. In essence, we continue building the tree until there
      are no points left. A list of points was created earlier, pointsList, which will be continuously passed 
      through. 

    The algorithm functions as follows:
      0. We need to check our bounds/include our base case, which is when we have points left in the vector.

      1. Check if left <= right. 
          If left<= right, then we know that our margins are still large enough to operate and sort/build
            the tree with.
          If so, we recalculate our middle index/pivotIndex and rearrange our points according to the 
          quickSelect algorithm/function. 
      2. Create a new node
          We create a new node that functionally acts as our "subroot". This node is created at our middle
          point, partially determined by our quickSelect algorithm. 
        2.a Update parameters
          We also need to update our parameters, like our size and dimension
      3. Recursion
          We then recurse through our left and right subtrees, dividing up the values in our list
          by manipulating the left and right margins.
  */

  //Base cases:
  //Check if the vector is empty, OR if our left and right bounds are valid. If so, we return NULL to indicate
  //  that an error occurred when constructing the tree.
  if(pointsList.empty() == true /* check to see if we have any points left */
     || left < 0 /* if left < 0, then our bounds have broken */
     || left >= pointsList.size()  /* 
                                     if either or bounds exceeds the size of our vector, then something wrong has 
                                     occurred.
                                   */
     || right < 0
     || right >= pointsList.size()
    ){
     return NULL; //Base case reached, return NULl to indicate either that we are done or an error occurred
  }

  /*
    Additionally check to see if our right and left bounds are valid - i.e. that right > left
  */
  if(left > right){
    return NULL; //Bounds are broken, return NULL
  }
  //Base cases established, now continue with algorithm outlined in AMA slides

  //Calculate median index
  auto medianIndex = (left + right) / 2;
  //Create new node at middle/median of quickSelected list
  KDTreeNode* newSubroot = new KDTreeNode(quickSelect(pointsList, dimension % Dim, left, right, medianIndex));
  //Update parameters of our KDTree
  //Update the size of our tree, since we just added a new node
  size = size + 1;
  //Update / reset the dimension of the tree that we have been constructing on
  auto newDimension = dimension + 1;
  newDimension = newDimension % Dim;

  //Set the node's left and rights via recursion
  /*
    We will split our left and right trees using the median index and the left and right bounds. We do not include
      our medianIndex because it was used as our subRoot.
  */
 newSubroot->left = buildTree(pointsList, newDimension, left, medianIndex - 1);
 newSubroot->right = buildTree(pointsList, newDimension, medianIndex + 1, right);
 return newSubroot;

} //EoF

template <int Dim>
void KDTree<Dim>::KDTreeCopy(KDTreeNode* thisSubroot, KDTreeNode* otherSubroot)
{
  /*
    Our function operates as follows:
      1. It creates a new node as a subroot. This will be what gets returned, so we need to set our passed in
          variable thisSubroot our newly created node in order for us to be able to return it later.
      2. The new subroot then copies over the data from the other subroot at the same position
      3. The new subroot then sets its left and right subroots, traversing until it gets to the end of each 
          series of lefts and rights
  */
  thisSubroot = new KDTreeNode(); //Constructed treenode is empty, need to copy over data
  thisSubroot->point = otherSubroot->point; //Copy over data 
  //Now we set our left and rights via recursion. We pass in subroot->left/right to set our pointers
  copy(thisSubroot->left, otherSubroot->left);
  copy(thisSubroot->right, otherSubroot->right);
}

template <int Dim>
void KDTree<Dim>::KDTreeDeletion(KDTreeNode* subRoot)
{
  /*
    This function will operate similarly to the copy function, where it traverses each side deleting nodes as it goes.
      We want to traverse down the tree as far as possible, and then delete our way upwards. 
  */
  //Base case: if our subRoot is NULL, we are at the bottom of our tree
  if(subRoot == NULL){
    return;
  }
  //We want to recurse left first, then right. If a node has neither a left nor a right node, then it is 
  //  a leaf node and we can delete it, but we need to traverse down both sides first before deleting the
  //  node.
  if(subRoot->left != NULL){
    KDTreeDeletion(subRoot->left);
  }
  if(subRoot->right != NULL){
    KDTreeDeletion(subRoot->right);
  }
  //Both sides are NULL, i.e. our current node/subRoot is a leaf node now. Delete it.
  //Clear reserved memory associated with the memory pointed to at subRoot
  delete subRoot;
  //Now we need to set subRoot to NULL in order to achieve recursion / update our pointers to be accurate
  subRoot = NULL;
} //EoF

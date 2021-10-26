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
    else{
      return true;
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
    int currentSum = 0;
    int potentialSum = 0;
    for(int i = 0; i < Dim; i++){
      int currentDistance = (target[i] - currentBest[i]) * (target[i] - currentBest[i]);
      int potentialDistance = (target[i] - potential[i]) * (target[i] - potential[i]);
      currentSum = currentSum + currentDistance;
      potentialSum = potentialSum + potentialDistance;
    }
    if(potentialSum < currentSum){
      return true;
    }
    else if(potentialSum == currentSum){
      if(potential < currentBest){
        return true;
      }
      else{
        return false;
      }
    }
    else{
      return false;
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
  KDTreeDeletion(root);
  //Now copy over the new tree
  copy(this->root, rhs.root);
  //Also update the size of our root
  size = rhs.size;
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

    return Point<Dim>();
}

/*
  Helper functions included below!
*/

//Below is the helper function for findNearestNeighbor
template <int Dim>
Point<Dim> KDTree<Dim>::FNNHelper(const Point<Dim> & query, KDTreeNode* subRoot, int dimension)
{
  /*
    We pass through the subroot we look at, the point we wish to find the closest neighbor to ("query"), and 
      the dimension we're currently analyzing.
  */

  //First we create a point which is our subroot's point. We will use this in comparison later.
  Point<Dim> currentBest = subRoot->point;
  //Check to see if current our current point has any children/bounds are valid - if not, then we
  //  can recurse with our remaining point, which may not necessarily be the best point.
  if(subRoot->left == NULL && subRoot->right == NULL){
    return subRoot->point;
  }

  /*
    Next, we decide whether or not we should traverse each tree. Specifically, we will consider whether 
      the left tree is worth traversing first, and then the right. We compare with respect to our current
      dimension.

    Additionally, we create a "flag" to help us determine which direction we have traverse in. This flag will 
      vary b/w 1 and 0, with 1 representing "true" or we have traversed the left tree, and 0 being otherwise.
      The flag will be used later on when checking for opposite subtrees to point us in the right direction of
      traversal. As you read this code the role of the flag will become clearer.
  */
  int leftFlag = 0;
  if(smallerDimVal(query, currentBest, dimension) == true){
    /*
      Comparing the values at our current dimension with smallerDimVal, we determine whether or not we want to 
        traverse the left subtree. If the currentBest is smaller, then we do not traverse the left. Otherwise, 
        we traverse left.
    */
    //We need to check if the left subtree even exists, so...
    if(subRoot->left == NULL){ //If left subtree does NOT exist, then we traverse right
      /*
        We want to pass through our same query, but this time we iterate/traverse down our tree with the right side.
          We also need to increment the dimension but keep it within the bounds of Dim.
      */
      currentBest = FNNHelper(query, subRoot->right, (dimension + 1) % Dim);
      //leftFlag = 0;
    }
    else{ //Otherwise, we traverse down the left
      currentBest = FNNHelper(query, subRoot->left, (dimension + 1) % Dim);
      //Since we're traversing left, we also need to set our flag to be true
      //leftFlag = 1;
    }
    leftFlag = 1;
  }
  else { //Else, we decide to traverse right
    //Check to see if right side even exists
    if(subRoot->right == NULL){
      //Right subroot does not exist, so traverse left
      currentBest = FNNHelper(query, subRoot->left, (dimension + 1) % Dim);
      //leftFlag = 1;
    }
    else{
      //Right subroot exists, so traverse right
      currentBest = FNNHelper(query, subRoot->right, (dimension + 1) % Dim);
      //leftFlag = 0;
    }
    leftFlag = 0;
  }

  /*
    At this point, we have found the "current best" neighbor, or the point bound by the lowest-bound 
      hyperrectangle. We now work our way back up and keep comparing distances using Euclidian Distance.

    Currently, currentBest is the lowest-bound point in the hyperrectangle, but not necessarily the actual 
      "best" point for our query. However, since we're traversing back upwards we compare our "current best"
      to the point stored in our subRoot, which is effectively our "current point".
  */

  if(shoudReplace(query, currentBest, subRoot->point) == true){
    //We replace our "current best" with our "current point" if we find it to be necessary
    currentBest = subRoot->point;
  }

  //Now we want to calculate the radius of our point to compare it with any other points. Achieve this using
  //  Euclidian distance method
  int radius = 0;
  //Iterate through each dimension, get the square of the distance in that dimension to calculate the radius
  //  of that dimension
  for(int i = 0; i < Dim; i++){
    radius = radius + (query[i] - currentBest[i]) * (query[i] - currentBest[i]);
  }

  /*
    We also want to calculate the splitting distance to check if it could contain another subtree. If the splitting
      distance is lower than the radius, then we also need to check the opposite subtree to see if any points
      would be more viable.
  */

  auto splitDistance = (subRoot->point[dimension] - query[dimension]) * (subRoot->point[dimension] - query[dimension]);

  /*
    Now we check if the splitDistance is less than the radius. If that's true, then subtree contained within the
      splitDistance could hold better points, and we woud need to search those trees too.
  */
  if(splitDistance <= radius){
    /*
      This is where our flag comes in handy: we use it to check which subtree we have already traversed, and
        traverse the opposite subtree instead. We create a pointer to our new subtree called "newSubTree", and
        set it according to our flag.
    */
    KDTreeNode* newSubTree = NULL;
    if(leftFlag == 1){ 
      /*
        If this is true, that means we previously traversed down the left side. Perform the same checks and 
          traverse recursively.
      */
      newSubTree = subRoot->right;
    }
    else{
      newSubTree = subRoot->left;
    }

    //We need to check if the newSubTree is NULL. If so, then we can just return currentBest, as there are no other
    //  subtrees to check and currentBest is the best possible point.
    if(newSubTree == NULL){
      return currentBest;
    }
    else{ 
      //newSubTree is NOT null, indicating that another subTree exists, thus we need to traverse that subTree and
      //  get whatever point is the most viable out of it using our helper function's recursive functionality.
      Point<Dim> otherTreeBest = FNNHelper(query, newSubTree, (dimension + 1) % Dim);
      //Now that we've gotten the another viable point, we finally compare our two points and see if 
      //  the new point is more viable than the first point.
      if(shouldReplace(query, currentBest, otherTreeBest) == true){
        currentBest = otherTreeBest;
      }
    }
    return currentBest;
  }

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
  unsigned pivotIndex = k;
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
}

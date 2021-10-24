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
    if(subroot == NULL){
        return V();
    }
    size_t first_larger_idx = insertion_idx(subroot->elements, key);

    /* If first_larger_idx is a valid index and the key there is the key we
     * are looking for, we are done. */

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

    if(subroot->elements[first_larger_idx] == key && first_larger_idx < subroot->elements.size()){ //Check to see if element's key matches
        return subroot->elements[first_larger_idx].value; //If so, return its value
    }
    if(subroot->is_leaf == true){
        return V();
    }
    return find(subroot->children[first_larger_idx], key);
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
    insert(root, DataPair(key, value));
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
    /*
    - By calling this function, we know that we want to split the child at set index.
    - child_itr is where we want to insert the new child
    - elem_itr is where we want to insert the new element
    - mid_elem_itr is where the middle element is
    - mid_child_itr is where the middle child is
    - new_left is the old child, or points to our old node. This will contain the left
    -   half of the values in the left child.
    - new_right is the new child, which is going to contain half of the. This will contain
    -   the right half of the values in the right child.
    - We're splitting our child into two. Knowing this, we can split our childNode into two.
    -   We need to insert the pointer to our new child at the given index, and the value
    -   that we threw up from the split into the given element in our parents' vectors,
    -   specifically the children and element vectors.
    - Afterwards, we want to copy over the values from our original, unsplit child into the 
    -   new left and right children that it was split into. 
    */
   //Insert the element into the given index in the parent's vector
   //Dereference mid_elem_itr to get the element/value we are trying to insert at given place
   parent->elements.insert(elem_itr, *mid_elem_itr); 
   //Insert the new child into the given index in the parent's vector. Our new child is new_right
   parent->children.insert(child_itr, new_right);
   //Assign the elements of the right side of our childNode into new_right
   new_right->elements.assign(mid_elem_itr + 1, child->elements.end());
   //Check if new_right is a leaf, otherwise we could segfault upon trying to assign its children
   if(child->is_leaf == false){ //child is not a leaf, we can assign children
    //Assign the right half of the child's children to new_right's vector - must overlap in the middle!
    new_right->children.assign(mid_child_itr, child->children.end());
   }
   //Repeat for left side
   new_left->elements.assign(child->elements.begin(), mid_elem_itr);
   if(child->is_leaf == false){
    new_left->children.assign(child->children.begin(), mid_child_itr);
   }
} //EoF

/**
 * Private recursive version of the insert function.
 * @param subroot A reference of a pointer to the current BTreeNode.
 * @param pair The DataPair to be inserted.
 * Note: Original solution used std::lower_bound, but making the students
 * write an equivalent seemed more instructive.
 */
template <class K, class V>
void BTree<K, V>::insert(BTreeNode* subroot, const DataPair& pair)
{
    /* There are two cases to consider.
     * If the subroot is a leaf node and the key doesn't exist subroot, we
     * should simply insert the pair into subroot.
     * Otherwise (subroot is not a leaf and the key doesn't exist in subroot)
     * we need to figure out which child to insert into and call insert on it.
     * After this call returns we need to check if the child became too large
     * and thus needs to be split to maintain order.
     */

    size_t first_larger_idx = insertion_idx(subroot->elements, pair); 
    //Returns first largest index for insertion

    /* TODO Your code goes here! */
    /*Base case 1: Subroot is a leaf node, key doesn't exist in subroot
    -  -Insert key into subroot, check if subroot needs to be split
    - Base case 2: Subroot is not a leaf, and key doesn't exist in subroot
    -  -Figure out which child to insert into
    */
    //Check to see if pair already exists within node
    /*
    if(first_larger_idx < subroot->elements.size()){
        if(subroot->elements[first_larger_idx] == pair){
            return; //Pair exists, don't need to re-insert
        }
    }*/
    //Base case 1: the subroot is a leaf node, containing no children. 
    if(subroot->is_leaf == true){ //Check if subroot is leaf node
        /*
        - Subroot is a leaf node, insert key into subroot at given index
        - Elements is a vector, so we can insert it in using vector's insert function
        - Insert at index in vector by calling begin() on elements, add index to iterator
        - to get where we are inserting our key datapair
        */
       auto insertionIterator = subroot->elements.begin();
       insertionIterator = insertionIterator + first_larger_idx;
       subroot->elements.insert(insertionIterator, pair);
    }
    /*
    - Base case 2: the subroot is NOT a leaf node, but the key does not exist in the current
    -  subroot/node we are looking at. Figure out which child to insert to and call insert on 
    -  appropriate child node.
    -  Additionally, check to see if we need to split the child, and perform operation as 
    -  necessary.
    */
    else{ 
        BTreeNode* childNode = subroot->children[first_larger_idx];
        insert(childNode, pair);
        if(childNode->elements.size() >= order){ //Check to see if we need to split the child
            //The number of elements exceeds the order - split the childNode.
            split_child(subroot, first_larger_idx);
        }
    }
}

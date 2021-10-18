/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
int AVLTree<K, V>::updateHeight(Node* subtree){
    //Recusive function, updates the height of our current node
    if(subtree == NULL){
        return -1; //Base case: recurse if NULL, height is -1
    }
    //Otherwise, return larger height of both trees
    return 1 + std::max(updateHeight(subtree->left), updateHeight(subtree->right));
} //Eof

template <class K, class V>
void AVLTree<K, V>::calculateHeight(Node*& subtree){
    if(subtree->left == NULL && subtree->right == NULL){ //Base case: both left and right are NULL
        subtree->height = 0; //No nodes below it, our height is 0
    }
    else if(subtree->left == NULL){ //Check right side if left side is NULL
        subtree->height = 1 + subtree->right->height;
    }
    else if(subtree->right == NULL){ //Check left side if right side is NULL
        subtree->height = 1 + subtree->left->height;
    }
    else{
        subtree->height = std::max(subtree->right->height, subtree->left->height) + 1; 
        //Else the height is the greater of both of its subtrees
    }
} //EoF

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node* roota;
    Node* rootb;
    Node* bleftorig;

    //Check if operation is possible
    if(t == NULL || t->right == NULL){
        return;
    }

    //becomes root, b left points to a
    //Root a is the old root
    //Root b is the new root
    //bleftorig is the child we will move
    roota = t;
    rootb = roota->right;
    bleftorig = rootb->left;
    rootb->left = roota;
    roota->right = bleftorig;
    t = rootb;

    //Update heights
    roota->height = 1 + std::max(heightOrNeg1(roota->left), heightOrNeg1(roota->right));
    rootb->height = 1 + std::max(heightOrNeg1(rootb->left), heightOrNeg1(rootb->right));

}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
} //EoF

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{

    functionCalls.push_back("rotateRightLeft");
    rotateRight(t->right);
    rotateLeft(t);
}
template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    //b is on top a is on bottom
    if(t == NULL || t->left == NULL){
        return;
    }
    Node* roota; //New root
    Node* rootb; //Old root
    Node* arightorig; //Child we will move

    rootb = t;
    roota = rootb->left;
    arightorig = roota->right;
    roota->right = rootb;
    rootb->left = arightorig;
    t = roota;

    roota->height = 1 + std::max(heightOrNeg1(roota->left), heightOrNeg1(roota->right));
    rootb->height = 1 + std::max(heightOrNeg1(rootb->left), heightOrNeg1(rootb->right));

} //EoF

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree){
    //Base cases: make sure the operation is valid
    if(subtree == NULL){
        return;
    }
    
    //Get the balance of the tree
    int balance = heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left);

    //Four cases divided into two sets:
    //Set 1: Left heavy
    if(balance == -2){ //Negative number indicates a left heavy tree
        //Calculate balance of subtree, check if right or left heavy
        int subtreebalance = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left);
        //Case 1: tree is left heavy, subtree is right heavy (elbow)
        if(subtreebalance == 1){ //If > 0, subtree is right heavy (elbow), rotate rightleft
            rotateLeftRight(subtree);
        }
        //Case 2: tree is left heavy, subtree is left heavy (stick)
        else{
            rotateRight(subtree);
        }
    }
    //Set 2: Right heavy
    else if(balance == 2){
        //Calculate balance of subtree, check if right or left heavy
        int subtreebalance = heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left);
        //Case 3: tree is right heavy, subtree is left heavy (elbow)
        if(subtreebalance == -1){ //If < 0, subtree is elbow, rotate leftright
            rotateRightLeft(subtree);
        }
        //Case 4: tree is right heavy, subtree is right heavy (stick)
        else{
            rotateLeft(subtree);
        }
    }
    subtree->height = 1 + std::max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
} //EoF

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{

   insert(root, key, value);

}



template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if(subtree == NULL){ //Base case, create new node
        Node* newNode = new Node(key, value);
        subtree = newNode;
    }
    else if(key < subtree->key){
        insert(subtree->left, key, value);
    }
    else if(key > subtree->key){
        insert(subtree->right, key, value);
    }
    else{
        subtree->value = value;
    }
    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left, key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right, key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree;
            subtree = NULL;
            return;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            //key is contained within subtree->left->right somewhere, need to find it
            //Get right most node of tree
            Node* rightMostNode = subtree->left;
            while(rightMostNode->right != NULL){
                rightMostNode = rightMostNode->right;
            }
            //All we need to do is swap the IOP(right most node of left subtree) and subtree
            //Swap function swaps the keys and values, doesn't change the nodes and what they're pointing to
            swap(rightMostNode, subtree);
            //Subtree and rightMostNode have been swapped, delete node pointed to by rightMostNode 
            //(which is actually contains node subtree's values)
            remove(subtree->left, rightMostNode->key);
        }
         else {
            /* one-child remove */
            // your code here
            if(subtree->right != NULL){
                //Right subtree exists, delete it and reset pointers
                Node* tempnode = subtree->right;
                swap(subtree, tempnode);
                delete tempnode;
                tempnode = NULL;
                subtree->right = NULL;
            }
            else{
                //Else left subtree exists, same as above
                Node* tempnode = subtree->left;
                swap(subtree, tempnode);
                delete tempnode;
                tempnode = NULL;
                subtree->left = NULL;
            }
            
        }
        rebalance(subtree);
    }
    subtree->height = std::max(updateHeight(subtree->left), updateHeight(subtree->right));
    rebalance(subtree);
} //EoF

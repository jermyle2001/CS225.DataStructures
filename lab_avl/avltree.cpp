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
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node* roota;
    Node* rootb;
    Node* bleftorig;

    //becomes root, b left points to a
    //a right becomes b left orig
    if(t == root){
        root = t->right;
    }
    roota = t;
    rootb = roota->right;
    bleftorig = rootb->left;
    rootb->left = roota;
    roota->right = bleftorig;
    t = rootb;

    roota->height = getHeight(roota);
    rootb->height = getHeight(rootb);

}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    //b is on top a is on bottom
    if(t == root){
        root = t->left;
    }
    Node* roota;
    Node* rootb;
    Node* arightorig;

    rootb = t;
    roota = rootb->left;
    arightorig = roota->right;
    roota->right = rootb;
    rootb->left = arightorig;
    t = roota;

    roota->height = getHeight(roota);
    rootb->height = getHeight(rootb);
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    //Rotate subtree so that it is balanced. You can assume that node->left and node->right are both balanced.
    //Four cases to take into account:: ll, lr, rl, and rr 

    //First, find the balance factor (figure out what kind of rotations we need to perform)
    int balancefactor = getHeight(subtree->right) - getHeight(subtree->left);

    //Check if right or left heavy
    if(balancefactor == -2){ //Left heavy, either rotate right or rotate left right

        int leftbalance = getHeight(subtree->left->right) - getHeight(subtree->left->left); 
        if(leftbalance < 0){ //Stick case: 
            rotateRight(subtree);
        }
        else{
            rotateLeftRight(subtree);
        }
    }
    else if(balancefactor == 2){ //Right heavy, either rotate left or rotate rigth left
        int rightbalance = getHeight(subtree->right->right) - getHeight(subtree->right->left);
        if(rightbalance > 0){ //Stick case, similar to above
            rotateLeft(subtree);
        }
        else{
            rotateRightLeft(subtree);
        }
    }

}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{

   insert(root, key, value);

}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if(!subtree){
        subtree = new Node(key, value);
    }

    if(key < subtree->key){
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

        }
         else {
            /* one-child remove */
            // your code here
            if(subtree->right != NULL){
                //Right subtree exists, delete it
                Node* tempnode = subtree->right;
                delete tempnode;
                tempnode = NULL;
                subtree->right = NULL;
            }
            else{
                //Else left subtree exists
                Node* tempnode = subtree->left;
                delete tempnode;
                tempnode = NULL;
                subtree->left = NULL;
            }
        }
    }
    subtree->height = std::max(getHeight(subtree->left), getHeight(subtree->right));
    rebalance(subtree);
} //EoF

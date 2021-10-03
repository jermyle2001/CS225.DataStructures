/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout << std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    std::cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
    template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    /*
    - We want to mirror the tree vertically, i.e. switch the left and
    - right branches.
    - Create a helper function - mirror() is void
    */
    return mirror(root);
    
    
    
} //Eof

template <typename T>
void BinaryTree<T>::mirror(Node* subRoot){
	/*
	- HELPER FUNCTION FOR mirror() - needed because mirror() is void by 
	- default, but we want to recursively pass through a subtree
	*/
	//Base Case: reached bottom of tree/no children, recurse
	if(subRoot == NULL){
		return;
	}
	else{
	Node* tempNode;
	
	//Call the function on the subtrees, swapping the left and rights
	mirror(subRoot->right);
	mirror(subRoot->left);
	
	//Swap the nodes
	tempNode = subRoot->right; //Store right node
	subRoot->right = subRoot->left; //Set right node == left node
	subRoot->left = tempNode; //Set left node == right node	
	
	}
	return;
} //EoF




/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    // your code here
    /*
    - Iterate throughout tree, seeing if an Inorder Traversal would
    - print out not in order
    */
   InorderTraversal<T> s(root);
   auto itr = s.begin();
   int check = (*itr)->elem;
   ++itr;
   while(itr != s.end()){
       if((*itr)->elem < check){
           return false;
       }
       check = (*itr)->elem;
       ++itr;
   }

    return true;
}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    // your code here
    return false;
}


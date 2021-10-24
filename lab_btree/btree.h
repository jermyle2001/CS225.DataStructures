/**
 * @file btree.h
 * Definition of a B-tree class which can be used as a generic dictionary
 * (insert-only). Designed to take advantage of caching to be faster than
 * standard balanced binary search trees.
 */

#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

/**
 * BTree class. Provides interfaces for inserting and finding elements in
 * B-tree.
 *
 * @author Matt Joras
 * @date Winter 2013
 */
template <class K, class V>
class BTree
{
  private:
    /**
     * A fancy key-value pair which acts as elements in the BTree.
     * Can be compared with <, >, ==. Additionally they can be compared against
     * a K with <, > and == based on its key.
     * */
    struct DataPair {
        K key;
        V value;

        /**
         * Constructs a DataPair from the given key and value.
         * @param key The key of the pair.
         * @param value The value of the pair.
         */
        DataPair(K key, V value) : key(key), value(value)
        {
        }

        /**
         * Less than operator for a DataPair. The object is less than another
         * if its key is less than the other's key.
         * @param rhs The right hand of the < operator.
         * @return true if the object's key is less than rhs' key, false
         * otherwise.
         */
        inline bool operator<(const DataPair& rhs) const
        {
            return this->key < rhs.key;
        }

        /**
         * Less than operator for a DataPair and a K.
         * @param rhs The right hand side (K) of the < operator.
         * @return true if the object's key is less than rhs, false otherwise.
         */
        inline bool operator<(const K& rhs) const
        {
            return this->key < rhs;
        }

        /**
         * Less than operator for a K and a DataPair.
         * @param lhs The left hand side (K) of the < operator.
         * @param rhs The right hand side (DataPair) of the < operator.
         * @return true if lhs is less than rhs's key, false otherwise.
         */
        inline friend bool operator<(const K& lhs, const DataPair& rhs)
        {
            return lhs < rhs.key;
        }

        /**
         * Greater than operator for a DataPair. DataPair is greater than another
         * if its key is greater than the other's key.
         * @param rhs The right hand of the > operator.
         * @return true if the object's key is greater than rhs's key, false otherwise.
         */
        inline bool operator>(const DataPair& rhs) const
        {
            return this->key > rhs.key;
        }

        /**
         * Greater than operator for a K and a DataPair.
         * @param lhs The left hand side (K) of the > operator.
         * @param rhs The right hand side (DataPair) of the > operator.
         * @return true if lhs is greater than rhs's key, false otherwise.
         */
        inline friend bool operator>(const K& lhs, const DataPair& rhs)
        {
            return lhs > rhs.key;
        }

        /**
         * Greater than operator for a DataPair and a K.
         * @param rhs The right hand side (K) of the > operator.
         * @return true if the object's key is greater than rhs, false otherwise.
         */
        inline bool operator>(const K& rhs) const
        {
            return this->key > rhs;
        }

        /**
         * Equality operator for a DataPair. One is equal to another
         * if its key is equal to the other's key.
         * @param rhs The right hand of the == operator.
         * @return true if the object's key is greater than rhs's key, false otherwise.
         */
        inline bool operator==(const DataPair& rhs) const
        {
            return this->key == rhs.key;
        }

        /**
         * Equality operator for a DataPair and a K.
         * @param rhs The right hand side (K) of the == operator.
         * @return true if the object's key is equal to rhs, false otherwise.
         */
        inline bool operator==(const K& rhs) const
        {
            return this->key == rhs;
        }

        /**
         * Equality operator for a K and a DataPair.
         * @param lhs The left hand side (K) of the == operator.
         * @param rhs The right hand side (DataPair) of the == operator.
         * @return true if lhs is equal to rhs's key, false otherwise.
         */
        inline friend bool operator==(const K& lhs, const DataPair& rhs)
        {
            return lhs == rhs.key;
        }
    };

    /**
     * A class for the basic node structure of the BTree. A node contains
     * two vectors, one with DataPairs representing the data, and one of
     * BTreeNode*s, representing the node's children.
     */
    struct BTreeNode {
        bool is_leaf;
        std::vector<DataPair> elements;
        std::vector<BTreeNode*> children;

        /**
         * Constructs a BTreeNode. The vectors will reserve to avoid
         * reallocations.
         */
        BTreeNode(bool is_leaf, unsigned int order) : is_leaf(is_leaf)
        {
            elements.reserve(order + 1);
            children.reserve(order + 2);
        }

        /**
         * Constructs a BTreeNode based on another. Only copies over
         * the elements and is_leaf information.
         */
        BTreeNode(const BTreeNode& other)
            : is_leaf(other.is_leaf), elements(other.elements)
        {
        }

        /**
         * Printing operator for a BTreeNode. E.g. a node containing 4, 5, 6
         * would look like:
         * <pre>
         * | 4 | 5 | 6 |
         * *   *   *   *
         * </pre>
         * The stars below the bars represent non-null child pointers. Null
         * child pointers are represented by an "N". If there are no children
         * then "no children" is displayed instead.
         * @param out The ostream to be written to.
         * @param n The node to be printed.
         * @return The modified ostream.
         */
        inline friend std::ostream& operator<<(std::ostream& out,
                                               const BTreeNode& n)
        {
            std::string node_str;
            node_str.reserve(2 * (4 * n.elements.size() + 1));
            for (auto& elem : n.elements) {
                std::stringstream temp;
                temp << elem.key;
                node_str += "| ";
                node_str += temp.str();
                node_str += " ";
            }
            if (!n.elements.empty()) {
                node_str += "|";
            }
            node_str += "\n";
            for (auto& child : n.children) {
                if (child == nullptr) {
                    node_str += "N   ";
                } else {
                    node_str += "*   ";
                }
            }
            if (n.children.empty()) {
                node_str += "no children";
            }

            out << node_str;
            return out;
        }
    };

    unsigned int order;
    BTreeNode* root;

  public:
    /**
     * Constructs a default, order 64 BTree.
     */
    BTree();

    /**
     * Constructs a BTree with the specified order. The minimum order allowed
     * is order 3.
     * @param order The order of the constructed BTree.
     */
    BTree(unsigned int order);

    /**
     * Constructs a BTree as a deep copy of another.
     * @param other The BTree to copy.
     */
    BTree(const BTree& other);

    /**
     * Performs checks to make sure the BTree is valid. Specifically
     * it will check to make sure that an in-order traversal of the tree
     * will result in a sorted sequence of keys. Also verifies that each
     * BTree node doesn't have more nodes than its order.
     * @return true if it satisfies the conditions, false otherwise.
     */
    bool is_valid(unsigned int order = 64) const;

    /**
     * Destroys a BTree.
     */
    ~BTree();

    /**
     * Assignment operator for a BTree.
     * @param rhs The BTree to assign into this one.
     * @return The copied BTree.
     */
    const BTree& operator=(const BTree& rhs);

    /**
     * Clears the BTree of all data.
     */
    void clear();

    /**
     * Inserts a key and value into the BTree. If the key is already in the
     * tree do nothing.
     * @param key The key to insert.
     * @param value The value to insert.
     */
    void insert(const K& key, const V& value);

    /**
     * Finds the value associated with a given key.
     * @param key The key to look up.
     * @return The value (if found), the default V if not.
     */
    V find(const K& key) const;

  private:
    /**
     * Private recursive version of the insert function.
     * @param subroot A reference of a pointer to the current BTreeNode.
     * @param pair The DataPair to be inserted.
     */
    void insert(BTreeNode* subroot, const DataPair& pair);

    /**
     * Private recursive version of the find function.
     * @param subroot A reference of a pointer to the current BTreeNode.
     * @param key The key we are looking up.
     * @return The value (if found), the default V if not.
     */
    V find(const BTreeNode* subroot, const K& key) const;

    /**
     * Splits a child node of a BTreeNode. Called if the child became too
     * large. Modifies the parent such that children[child_idx] contains
     * half as many elements as before, and similarly for
     * children[child_idx + 1] (which is a new BTreeNode*).
     * @param parent The parent whose child we are trying to split.
     * @param child_idx The index of the child in its parent's children
     * vector.
     */
    void split_child(BTreeNode* parent, size_t child_idx);

    /**
     * Private recursive version of the clear function.
     * @param subroot A pointer to the current node being cleared.
     */
    void clear(BTreeNode* subroot);

    /**
     * Private recursive version of the copy function.
     * @param subroot A pointer to the current node being copied.
     */
    BTreeNode* copy(const BTreeNode* subroot);

    /**
     * Private recursive version of the is_valid function.
     * @param subroot A pointer to the current node being checked for
     * validity.
     * @return true if the node's subtree is valid, false otherwise.
     */
    bool is_valid(const BTreeNode* subroot, std::vector<DataPair>& data,
                  unsigned int order) const;
};

/**
 * Generalized function for finding the insertion index of a given element
 * into a given sorted vector.
 * @param elements A sorted vector of some type.
 * @param val A value which represents something to be inserted into the vector.
 * Must either be the same type as T, or one that can compare to it. E.g. for
 * the elements of a BTreeNode we might pass in either a DataPair value or a
 * K value (the key).
 * @return The index at which val could be inserted into elements to maintain
 * the sorted order of elements. If val occurs in elements, then this returns
 * the index of val in elements.
 */


template <class T, class C>
size_t insertion_idx(const std::vector<T>& elements, const C& val, size_t l, size_t h){ //l is low, h is high
    //Note: this is a helper function that was added in! Read the original function's approach first.
    //Also, include this function above the original function, otherwise it will break.
    /*
    - Our value falls somewhere in our tree/array. We have 4 cases to consider (again).
    - We pass through a lower end and higher end of our node/array, getting the middle
    -  and continuously splitting our node into halves. 
    - The following details the 4 cases we consider:
    - 1. Base case: if the lower index == higher index, then that means we only have one index
    -    remaining. Thus, we have found our index for insertion, and return either l or h.
    - 2. If our value is greater than the value in the middle of our node then the value is located in 
    -    the second half of the node. To avoid recomparing the same values, add 1 to the middle index
    -    and evaluate b/w m + 1 and h.
    - 3. If our value is less than the value in the middle of our node, similar to case 2 but we evaluate b/w 
    -    first half of the node and m - 1.
    - 4. If the value is equal to the value in the middle, then our middle is our insertion index
    -    and thus we return m.
    */
    if(l == h){ //Base case is when l == h
        return l;
    }
    size_t m = (l + h)/2; //Store middle index, we're going to compare halves and recurse
    if(val > elements[m]){
        return insertion_idx(elements, val, m+1, h); //Val is in higher half, add 1 to m to avoid reusing m
    } 
    else if(val < elements[m]){
        return insertion_idx(elements, val, l, m-1); //Val is in lower half, subtract 1 from m to avoid reusing m
    }
    else{
        return m;
    }
}

template <class T, class C>
size_t insertion_idx(const std::vector<T>& elements, const C& val)
{
    /* TODO Your code goes here! */
    /*
    - This function returns the index that an insertion would take place in.
    - We have four initial base cases, with the fourth one being recursive:
    - 1. If the vector of elements is empty, i.e. there are no nodes/keys, then
    -    our index is zero, since there are no elements.
    - 2. If our value is less than the first element, then we need to insert in 
    -    front of our current array, i.e. index 0.
    - 3. If our value is greater than the largest value in our node, i.e. the last
    -    value in our node, then we insert at the end of our array, i.e. index of the
    -    size of the array, since our array indexes start at 0.
    - 4. Otherwise, the value falls somewhere in our array. We will compare values 
    -    of the lower and higher ends of subtree/subnodes to see where we want 
    -    to insert our node.
    -
    - SIDENOTE: based on the find function's convention, it appears that the index
    -  that gets returned is actually the first valid index for insertion?
    */

    for(unsigned i = 0; i < elements.size(); i++){
        if(elements[i] > val){
            return i;
        }
        else if(elements[i] == val){
            return i;
        }
    }
    return elements.size();
}




#include "btree_given.cpp"
#include "btree.cpp"

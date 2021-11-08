/* Your code here! */
#include "dsets.h"
#include <vector>
#include <iostream>


void DisjointSets::addelements(int num)
{
    /*
        Function addelements adds the # of elements specified
        by num. It initializes the elements to be -1, since they
        don't currently point to anything.
    */
    for(int i = 0; i < num; i++)
    {
        elemsVect.push_back(-1);
    }
    
} //EoF

int DisjointSets::find(int elem)
{
    /*
        The find function finds the index of our root, where
        its value is -1, and compresses paths along the way, 
        i.e. points our nodes to the root. We change the 
        number within the vector to point towards the index
        of the root as we go along.
    */
    if(elemsVect[elem] < 0)
    {
        /* 
            Base case: if our value is less than one, then we
            have reached a root node. Thus, we can return
            the index of our 
        */
        return elem;
    }
    else
    {
        /*
            We need to implement path compression - we need to 
            make our paths throughout our tree point to our
            root node as we go through.
        */
        int rootIndex = find(elemsVect[elem]);
        elemsVect[elem] = rootIndex;
        return rootIndex;
    }
} //EoF

void DisjointSets::setunion(int a, int b)
{
    /*
        setunion implements a union-by-size. Thus, the smaller
        of the two sets should point to the larger of the two
        sets. 

        YOU SHOULD NOT ASSUME the arguments are roots of existing
        uptrees. Thus, your arguments should find the roots of its
        arguments BEFORE combining the trees.

        If the two sets are the same size, the tree contained by
        the second argument points to the first.
    */
    //std::cout << "Running union!" << std::endl;
    //cout << "Running find..." << endl;
    int roota = find(a);
    //cout << "Running find 2..." << endl;
    int rootb = find(b);
    //cout << "Passed find!" << endl;
    int newSize = elemsVect[roota] + elemsVect[rootb];

    if(elemsVect[roota] <= elemsVect[rootb])
    {   
        elemsVect[rootb] = roota;
        elemsVect[roota] = newSize;
        //std::cout << "Exiting union..." << std::endl;
    }
    else
    {
        elemsVect[roota] = rootb;
        elemsVect[rootb] = newSize;
        //std::cout << "Exiting union..." << std::endl;
    }


} //EoF

int DisjointSets::size(int elem)
{
    /*
        The size function should return the number of nodes
        in the up-tree that contain the element as its root. 
        That information should be already stored within the
        root node, so we just need to find the index and return
        its size.
    */

    int treeSize = find(elem);
    return (-1) * elemsVect[treeSize];
} //EoF
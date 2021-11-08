/* Your code here! */
#pragma once
#include <vector>

using std::vector;

class DisjointSets
{
    private: 
        

    public:
        void addelements(int num);
        int find(int elem);
        void setunion(int a, int b);
        int size(int elem);
        vector<int> elemsVect;

};


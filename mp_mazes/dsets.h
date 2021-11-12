/* Your code here! */
#pragma once
#include <vector>

using std::vector;

class DisjointSets
{
    private: 
        vector<int> elemsVect;

    public:
        void addelements(int num);
        int find(int elem);
        void setunion(int a, int b);
        int size(int elem);

};


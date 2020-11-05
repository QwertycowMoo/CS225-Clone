/* Your code here! */
#pragma once

#include <vector>

using std::vector;

class DisjointSets {
    private: 
        vector<int> _data;
    public:
        //Creates n unconnected root nodes at the end of the vector. 
        void addelements (int num);
        //This function should compress paths and works as described in lecture. 
        //     Returns
        // the index of the root of the up-tree in which the parameter element resides. 
        int find(int elem);
        //This function should be implemented as union-by-size. 
        void setunion(int a, int b);
        // This function should return the number of nodes in the up-tree containing the element. 
        int size(int elem);
};
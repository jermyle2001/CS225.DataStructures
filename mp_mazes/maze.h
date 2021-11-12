/* Your code here! */
#pragma once
#include <vector>
#include <queue> //Used for BFS
#include <utility>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "dsets.h"

using namespace std;
using namespace cs225;

class SquareMaze
{
    private:
        /*
            Here, we have three things we want to keep track of:
            1. The dimensions of the maze
            2. A collection of disjointed sets for cycle detection
               (if two elements are contained in the same set, then
                we cannot remove the wall between them)
            3. A vector that keeps track of our walls - we only have to
               keep track of the left and down walls, so we can utilise the
               pair container to store pairs of bools
        */
        int mazeWidth;
        int mazeHeight;
        DisjointSets cycleDetector;
        vector<pair<bool, bool>> wallsVect;
        /*
            In our wallsVect, the first bool represents the left wall, and
            the second bool represents the right wall. It is "true" if a 
            wall exists between the two.
        */

    public:
        void makeMaze(int width, int height);
        bool canTravel(int x, int y, int dir) const;
        void setWall(int x, int y, int dir, bool exists);
        vector<int> solveMaze();
        PNG* drawMaze();
        PNG* drawMazeWithSolution();

};

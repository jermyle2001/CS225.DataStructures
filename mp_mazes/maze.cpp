/* Your code here! */
#include "maze.h"
#include <vector>
#include <iostream>
#include <queue>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "dsets.h"

using namespace std;

SquareMaze::SquareMaze()
{
    /*
      Default Constructor:
      Intialize width and height of maze to 0.
    */
    mazeWidth = 0;
    mazeHeight = 0;
} //EoF

bool SquareMaze::canTravel(int x, int y, int dir) const
{

} //EoF

PNG* SquareMaze::drawMaze() const
{

} //EoF

PNG* SquareMaze::drawMazeWithSolution()
{

} //EoF

void SquareMaze::makeMaze(int width, int height)
{
    /*
        If the maze already exists, delete it
        Construct a maze with all the walls in place
        Randomly select walls to delete
        - Check if wall is on perimeter of maze (don't delete)
        - Check for cycles (use of disjointed sets)
         - If two elements are in same disjointed set, then we
           cannot remove its wall else it will create a cycle
        - If neither is violated, delete wall
        - Repeat until every cell is connected to the maze (one 
          big disjointed set)
    */

    mazeWidth = width;
    mazeHeight = height;

    /*
        Initialize DisjointedSets to size of maze, so we can detect cycles.
        Also initialize wallsVector to be true, adding walls to all elements.
    */
    int newSize = width * height;
    cycleDetector.addelements(newSize);
    for(int i = 0; i < newSize; i++)
    {
      wallsVect.push_back(pair<bool, bool> (true, true));
    }

    /*
        Now that we have initialized our cycleDetector and wallsVector, we can
        start deleting walls randomly throughout our maze. We perform operations
        until every 
    */


} //EoF

void SquareMaze::setWall(int x, int y, int dir, bool exists)
{

} //EoF

vector<int> SquareMaze::solveMaze()
{

} //EoF
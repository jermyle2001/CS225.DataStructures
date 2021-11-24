/* Your code here! */
#include "maze.h"
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <utility>
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
  /*
    Function determines whether we can travel in the direciton indicated.
    0 - right
    1 - bottom 
    2 - left 
    3 - up

    First check if we are trying to move outside of the maze's boundaries. 
    With a zero-based index, the boundaries are [constraint - 1].
  */
 if(dir == 0)
 {
   if(x >= mazeWidth - 1)
   {
     return false;
   }
   return !wallsVect[x + y * mazeWidth].first;
 }
 if(dir == 1)
 {
   if(y >= mazeHeight - 1)
   {
     return false;
   }
   return !wallsVect[x + y * mazeWidth].second;
 }
 if(dir == 2)
 {
   if(x < 1)
   {
     return false;
   }
   return !wallsVect[x - 1 + y * mazeWidth].first;
 }
 if(dir == 3)
 {
   if(y < 1)
   {
     return false;
   }  
   return !wallsVect[x + (y - 1) * mazeWidth].second;
 }
  return false;
} //EoF

PNG* SquareMaze::drawMaze() const
{
  /*
    drawMaze draws the maze with no solution. The function checks if
    the coordinates correspond to walls or not, also outlining the wall
    in the process. The maze has been scaled up by 10 to make it 
    visible.

    Remember to use unsigned coordinates to be compatible with HSLAPixel's
    parameters.

    Note that we opt to draw the walls and not the paths, as drawing the paths
    would be much more complicated than drawing the walls.
  */
  PNG* out = new PNG(mazeWidth * 10 + 1, mazeHeight * 10 + 1);
  for(int y = 0; y < mazeHeight; y++)
  {
    for(int x = 0; x < mazeWidth; x++)
    {
      if(y == 0)
      {
        /*
          When our height is zero, we need to draw out the entrance, or rather
          the walls around it. We opt to draw walls instead of the paths themselves.
        */
        for(unsigned k = 0; k < 10; k++)
        {
          if((x * 10 + k < 1) || (x * 10 + k > 9))
          {
            HSLAPixel & pixel = out->getPixel(x * 10 + k, 0);
            pixel.l = 0;
          }

        }

      }
      /*
        Do the same thing for left side border (x = 0), except we don't need to worry
        about drawing an entrance - only making the wall.
      */
      if(x == 0)
      {
        for(unsigned k = 0; k < 10; k++)
        {
          HSLAPixel & pixel = out->getPixel(0, y * 10 + k);
          pixel.l = 0;
        }
      }
      /*
        Now we check to see if we can travel in either direction based on our wallsVect.
        The canTravel function is implemented to accomplish this - it determines whether
        the walls in the given direction can be traversed, and takes the borders of the
        maze into account as well.

        Check if we can travel in the right direction and the bottom direction.
      */
      if(!canTravel(x, y, 0))
      {
        for(unsigned k = 0; k <= 10; k++)
        {
          HSLAPixel & pixel = out->getPixel((x + 1) * 10, y * 10 + k);
          pixel.l = 0;
        }
      }
      if(!canTravel(x, y, 1))
      {
        for(unsigned k = 0; k <= 10; k++)
        {
          HSLAPixel & pixel = out->getPixel(x * 10 + k, (y + 1) * 10);
          pixel.l = 0;
        }
      }

    }


  }


  return out;
} //EoF

PNG* SquareMaze::drawMazeWithSolution()
{
  PNG* withSol = drawMaze();
  vector<int> solutionVect = solveMaze();
  /*
    Given in the Dxoygen, our solution starts at pixel (5,5). Each direction in
    the solution vector corresponds do a trail of 11 red pixels in the direction 
    indicated. We also need to keep track of our current x and y values, so that
    we know where to draw our exit.
  */
  int x = 5;
  int y = 5;
  unsigned solSize = solutionVect.size();
  for(unsigned i = 0; i < solSize; i++)
  {
    if(solutionVect[i] == 0)
    {
      for(int j = 0; j < 10; j++)
      {
        HSLAPixel & pixel = withSol->getPixel(x + j, y);
        pixel.l = 0.5;
        pixel.h = 0;
        pixel.s = 1;
      }
      x = x + 10;
    }
    if(solutionVect[i] == 1)
    {
      for(int j = 0; j < 10; j++)
      {
        HSLAPixel & pixel = withSol->getPixel(x, y + j);
        pixel.l = 0.5;
        pixel.h = 0;
        pixel.s = 1;
      }
      y = y + 10;
    }
    if(solutionVect[i] == 2)
    {
      for(int j = 0; j < 10; j++)
      {
        HSLAPixel & pixel = withSol->getPixel(x - j, y);
        pixel.l = 0.5;
        pixel.h = 0;
        pixel.s = 1;
      }
      x = x - 10;
    }
    if(solutionVect[i] == 3)
    {
      for(int j = 0; j < 10; j++)
      {
        HSLAPixel & pixel = withSol->getPixel(x, y - j);
        pixel.l = 0.5;
        pixel.h = 0;
        pixel.s = 1;
      }
      y = y - 10;
    }
  }
  /*
    Now that we have finished with our solutionVector, we need to
    print our final pixel for our solution, and make the exit wall open.
  */
  HSLAPixel & pixel = withSol->getPixel(x, y);
  pixel.l = 0.5;
  pixel.h = 0;
  pixel.s = 1;
  pixel.a = 1;
  int wallx = x - 4;
  int wally = y + 5;
  for(int i = 0; i < 9; i++)
  {
    HSLAPixel & wallPixel = withSol->getPixel(wallx + i, wally);
    wallPixel.l = 1;
    wallPixel.a = 1;
  }
  return withSol;
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
        We will aim to delete walls randomly as we go, performing at least
        one operation on the walls of each cell.
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
        until every cell has one wall deleted.

        We iterate through our size of our maze. Thus it's newSize - 1, since it's
        a 0 based indexed vector.

        Note that our walls vector basically represents our 2x2 graph with a 1-dimensional
        vector. Thus to calculate a cell's index, we need to do x + y * width.
    */
    int i = 0;
    while(i < newSize - 1)
    {
      int x = rand() % width;
      int y = rand() % height;
      int index = x + y * width;
      //Due to 0 based indexing, our borders are -1 of the given constraints.
      int xborder = width - 1;
      int yborder = height - 1;
      int wall = rand() % 2;
      /*
        Our "wall" value indicates randomly which wall, either left or down, that we
        want to delete. If the wall exists and the wall is NOT a border wall, then we
        can delete the wall.

        Additionally, we need to make sure we don't create any cycles. Thus we check
        if the two cells affected by the wall are in the same set.
      */
      if(wall == 1)
      {
        //Check if right wall can be deleted. Affects next element directly after current.
        if((wallsVect[index].first == true) && (x < xborder) && (cycleDetector.find(index) != cycleDetector.find(index + 1)))
        {
          wallsVect[index].first = false;
          cycleDetector.setunion(cycleDetector.find(index), cycleDetector.find(index + 1));
          i++;
        }
      }
      else{
        //Check if bottom wall can be deleted. Affects element in next row after current.
        if((wallsVect[index].second == true) && (y < yborder) && (cycleDetector.find(index) != cycleDetector.find(index + width)))
        {
          wallsVect[index].second = false;
          cycleDetector.setunion(cycleDetector.find(index), cycleDetector.find(index + width));
          i++;
        }

      }

    }



} //EoF

void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
  /*
    Function sets whether a wall exists or not, but does not prevent cycles
    from occurring. Dir 0 is right, Dir 1 is bottom. Pretty self explanatory.
  */
  if(dir == 0)
  {
    wallsVect[x + y * mazeWidth].first = exists;
  }
  if(dir == 1)
  {
    wallsVect[x + y * mazeWidth].second = exists;
  }
} //EoF

vector<int> SquareMaze::solveMaze()
{
  /*
    Return sequence of nodes that we will take to solve the maze. We will 
    keep track of which nodes we have already visited, and traverse our maze
    finding the longest possible path to the bottom. If multiple longest paths
    of the same length exist, return the path with the far most x value.

    The maze will always start in the top left corner, however its end is determined
    by the paths themselves.

    We also include a vector of nodes that are at the bottom of our maze to compare
    the path's lengths and tiebreak if necessary. We also map our possible nodes
    that we can travel to.
  */
  vector<int> solution;
  vector<bool> visited;
  for(int i = 0; i < mazeWidth * mazeHeight; i++)
  {
    visited.push_back(false);
  }
  visited[0] = true;
  queue<int> nodeMap;
  nodeMap.push(0);
  vector<int> bottomNodes;
  map<int, int> possibleNodes;

  /*
    Since this is a BFS, we will use the queue data struct. Work through the whole 
    graph, looping until our traversal no longer has any nodes to work with.
  */
  while(!nodeMap.empty())
  {
    int curNode = nodeMap.front();
    nodeMap.pop();
    /*
      We we want to use the canTravel function to determine whether we want to push
      nodes to our traversal/map or not. However, the canTravel funciton uses an x
      and y coordinate. Based on the index of the node, we can actually determine
      the coordinates of a node by performing the following computations.
    */
    int x = curNode % mazeWidth;
    int y = curNode / mazeHeight;
    /*
      Loop through the maze until all nodes that can be traveled to are added to our
      queue nodeMap and our possibleNodes map. Also add any nodes that can be traveled
      to that are at the very bottom of our maze.
    */
    if(y == mazeHeight - 1)
    {
      bottomNodes.push_back(curNode);
    }
    /*
      Check if we can travel in all four directions, while avoiding adding any nodes that
      we have already visited. Add nodes that can be visited to the nodeMap queue, while
      associating new nodes within our map struct possibleNodes with the node previous.
    */
    if(canTravel(x, y, 0) && (visited[curNode + 1] == false))
    {
      possibleNodes.insert(pair<int, int>(curNode + 1, curNode));
      visited[curNode + 1] = true;
      nodeMap.push(curNode + 1);
    }
    if(canTravel(x, y, 1) && (visited[curNode + mazeWidth] == false))
    {
      possibleNodes.insert(pair<int, int>(curNode + mazeWidth, curNode));
      visited[curNode + mazeWidth] = true;
      nodeMap.push(curNode + mazeWidth);
    }if(canTravel(x, y, 2) && (visited[curNode - 1] == false))
    {
      possibleNodes.insert(pair<int, int>(curNode - 1 , curNode));
      visited[curNode - 1] = true;
      nodeMap.push(curNode - 1);
    }if(canTravel(x, y, 3) && (visited[curNode - mazeWidth] == false))
    {
      possibleNodes.insert(pair<int, int>(curNode - mazeWidth, curNode));
      visited[curNode - mazeWidth] = true;
      nodeMap.push(curNode - mazeWidth);
    }
    
  } //Eo WHILE loop
  //Include stack to sequentially mark out path
  stack<int> pathStack;
  int node = bottomNodes[bottomNodes.size() - 1];
  /*
    Set the start of our maze traversal to be the last "bottom" node in our bottomNodes
    vector.
  */
  while(node != 0)
  {
    int prevNode = possibleNodes[node];
    /*
      Based on the way that we stored our nodes in the possibleNodes map, there is only
      one possible way per bottom y to go to the start: thus, all we need to do is check
      what direction of movement was taken to get to the end, working backwards. 
    */
    if(node == prevNode + 1)
    {
      pathStack.push(0);
    }
    else if(node == prevNode + mazeWidth)
    {
      pathStack.push(1);
    }
    else if(node == prevNode - 1)
    {
      pathStack.push(2);
    }
    else if(node == prevNode - mazeWidth)
    {
      pathStack.push(3);
    }
    node = prevNode;
  }

  /*
    Now we just need to push the stack's contents into the vector that we will be returning.
  */
  int stackSize = pathStack.size();
  for(int i = 0; i < stackSize; i++)
  {
    solution.push_back(pathStack.top());
    pathStack.pop();
  }
  return solution;
} //EoF
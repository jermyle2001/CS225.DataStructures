#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"


/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * 
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {  
  /** @todo [Part 1] */
  //Create and set our tolerance, png, and start
  DFStolerance = tolerance;
  DFSpng = png;
  DFSstart = start;
  //Push first value to our stack, as it's a depth-first traversal
  DFStraversal.push(DFSstart);
  //Resize visited's parameters
  //DO NOT use auto, will set width as int or whatever idk it didn't work 
  unsigned width = png.width();
  unsigned height = png.height();
  visited.resize(width);
  for(unsigned i = 0; i < width; i++){
    //Need to resize each column to accomodate for image size
    visited[i].resize(height);
    //Resized columns in vector, now update every point to be not-visited (0)
    //Vector is how we keep track of whether or not we visited a point
    for(unsigned j = 0; j < height; j++){
      visited[i][j] = 0;
    }
    
  }
  //Mark first point as "visited" so we don't accidentally go over it
  auto startx = DFSstart.x;
  auto starty = DFSstart.y;
  //visited[startx][starty] = 1;
} //EoF

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  //Return iterator starting at first point
  //Iterator contains identical info, but needs 'this' to be passed in so it knows
  //What it wants to iterate on
  return ImageTraversal::Iterator(this, DFSpng, DFSstart, DFStolerance);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
  //lmfao just push it to the stack
  DFStraversal.push(point);
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  //Get value at top of stack, pop, return
  Point returnPoint = DFStraversal.top();
  if(DFStraversal.empty()){
    return Point(-1, -1);
  }
  DFStraversal.pop();
  return returnPoint;
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  //Just return the top
  if(DFStraversal.empty()){
    return Point(-1, -1);
  }
  return DFStraversal.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  return DFStraversal.empty();
}

int DFS::getVisited(Point visitPoint){
  return visited[visitPoint.x][visitPoint.y];
}

void DFS::setVisited(Point visitPoint){
  visited[visitPoint.x][visitPoint.y] = 1;
}

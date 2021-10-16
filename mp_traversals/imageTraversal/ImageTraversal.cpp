#include <cmath>
#include <iterator>
#include <iostream>
#include <vector>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  currentPoint = Point(-1, -1); //End iterator, outside is (-1, -1)
}

ImageTraversal::Iterator::Iterator(ImageTraversal* traversal, PNG png, Point start, double tolerance, std::vector<std::vector<int>> visited) {
  IteratorPNG = png;
  IteratorStart = start;
  IteratorTolerance = tolerance;
  TraversalRef = traversal;
  currentPoint = TraversalRef->peek(); //currentPoint should contain the point we're looking at
  IteratorVisited = visited;
  //meaning we would want to "peek" at whatever's at the top of the stack
} //EoF

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  //Add potential future point in this order: right down left up
  //Do it from current point, already set up in constructor
  //Pop from whatever it's from first/remove from list, mark as visited (1)

  Point poppedpoint = TraversalRef->pop();  //Pop off top, pop function also returns what it popped so
  //we don't need to peek
  //Set point to visited
  TraversalRef->setVisited(poppedpoint);
  //Create a pixel for start, we will use the delta operation but that only takes in HSLAPixels
  //and not points
  
  HSLAPixel & startPixel = IteratorPNG.getPixel(poppedpoint.x, poppedpoint.y);


  //For following functions, ignore if not w/in bounds
  //Check right point (x+1, y)
  Point right(poppedpoint.x + 1, poppedpoint.y);
  if(right.x < IteratorPNG.width() && right.x >= 0 && right.y < IteratorPNG.height() && right.y >= 0){ //Assumes y is valid
    //Create a second pixel for comparison
    if(IteratorVisited[right.x][right.y] == 0){ //Only add pixel if not visited already
    HSLAPixel & otherPixel = IteratorPNG.getPixel(right.x, right.y);
    Point otherPoint(right.x, right.y);
    //Don't want to revisit, check if point is visited
      //Calculate delta and compare
      if(calculateDelta(otherPixel, startPixel) <= IteratorTolerance){
        //IF w/in tolerance, add point to traversal
        //Add only accepts Points, create a temporary point
        TraversalRef->add(otherPoint);
      }
    }
  }
  
  //Check down
  Point down(poppedpoint.x, poppedpoint.y + 1);
    //Same as right but point is below
    if(down.x < IteratorPNG.width() && down.x >= 0 && down.y < IteratorPNG.height() && down.y >= 0){
    if(IteratorVisited[down.x][down.y] == 0){
    HSLAPixel & otherPixel = IteratorPNG.getPixel(down.x, down.y);
    Point otherPoint(down.x, down.y);
      //Calculate delta and compare
      if(calculateDelta(otherPixel, startPixel) <= IteratorTolerance){
        //Add point to traversal if w/in tolerance
        TraversalRef->add(otherPoint);
      }
    }
  }

  //Check left
  Point left(poppedpoint.x - 1, poppedpoint.y);
  if(left.x < IteratorPNG.width() && left.x >= 0 && left.y < IteratorPNG.height() && left.y >= 0 ){
    //Same as right but point is left
    if(IteratorVisited[left.x][left.y] == 0){
    HSLAPixel & otherPixel = IteratorPNG.getPixel(left.x, left.y);
    Point otherPoint(left.x, left.y);
      if(calculateDelta(otherPixel, startPixel) <= IteratorTolerance){
        TraversalRef->add(otherPoint);
    } 
    }
  }

  Point up(poppedpoint.x, poppedpoint.y - 1);
  if(up.x < IteratorPNG.width() && up.x >= 0 && up.y < IteratorPNG.height() && up.y >= 0){
    //Same as right but point is up
    if(IteratorVisited[up.x][up.y] == 0){
    Point otherPoint(up.x, up.y);
    HSLAPixel & otherPixel = IteratorPNG.getPixel(up.x, up.y);
      if(calculateDelta(otherPixel, startPixel) <= IteratorTolerance){
        TraversalRef->add(otherPoint);
    }
    }
  }
  //All available neighboring points added to traversal, set current point to visited as well
  IteratorVisited[poppedpoint.x][poppedpoint.y] = 1;
  //Iterate currentPoint to next top of list
  currentPoint = TraversalRef->peek();
  //Find next non-visited point, popping off any points that have been visited
  while(TraversalRef->empty() == false && IteratorVisited[TraversalRef->peek().x][TraversalRef->peek().y]){
    currentPoint = TraversalRef->pop();
    currentPoint = TraversalRef->peek();
  }
  if(TraversalRef->empty() == true){
    return *this;
  }
  currentPoint = TraversalRef->peek();
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return this->currentPoint;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  if(this->currentPoint == other.currentPoint){ //If currentPoint == other.currentPoint, then statement is false
    return false;
  }
  else{
    return true;
  }
}

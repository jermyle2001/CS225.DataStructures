#include <cmath>
#include <iterator>
#include <iostream>

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

ImageTraversal::Iterator::Iterator(ImageTraversal* traversal, PNG png, Point start, double tolerance) {
  IteratorPNG = png;
  IteratorStart = start;
  IteratorTolerance = tolerance;
  TraversalRef = traversal;
  currentPoint = TraversalRef->peek(); //currentPoint should contain the point we're looking at
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

  currentPoint = TraversalRef->pop();  //Pop off top, pop function also returns what it popped so
  //we don't need to peek

  //Create a pixel for start, we will use the delta operation but that only takes in HSLAPixels
  //and not points
  
  HSLAPixel & startPixel = IteratorPNG.getPixel(IteratorStart.x, IteratorStart.y);


  //For following functions, ignore if not w/in bounds
  //Check right point (x+1, y)
  if(currentPoint.x + 1 < IteratorPNG.width()){ //Assumes y is valid
    //Create a second pixel for comparison
    HSLAPixel & otherPixel = IteratorPNG.getPixel(currentPoint.x + 1, currentPoint.y);
    //Don't want to revisit, check if point is visited
    Point otherPoint(currentPoint.x + 1, currentPoint.y);
    if(TraversalRef->getVisited(otherPoint) == 0){ //Check if point was visited
      //Calculate delta and compare
      if(calculateDelta(startPixel, otherPixel) <= IteratorTolerance){
        //IF w/in tolerance, add point to traversal
        //Add only accepts Points, create a temporary point
        TraversalRef->add(otherPoint);
      }
    }
  }
  
  //Check down
  if(currentPoint.y + 1 < IteratorPNG.height()){ //Assumes x is valid
    //Same as right but point is below
    HSLAPixel & otherPixel = IteratorPNG.getPixel(currentPoint.x, currentPoint.y + 1);
    Point otherPoint(currentPoint.x, currentPoint.y + 1);
    if(TraversalRef->getVisited(otherPoint) == 0){
      //Calculate delta and compare
      if(calculateDelta(startPixel, otherPixel) <= IteratorTolerance){
        //Add point to traversal if w/in tolerance
        TraversalRef->add(otherPoint);
      }
    }
  }

  //Check left
  if(currentPoint.x - 1 >= 0){ //Can technically be zero, assumes x was valid and y is valid
    //Same as right but point is left
    HSLAPixel & otherPixel = IteratorPNG.getPixel(currentPoint.x - 1, currentPoint.y);
    Point otherPoint(currentPoint.x - 1, currentPoint.y);
    if(TraversalRef->getVisited(otherPoint) == 0){
      if(calculateDelta(startPixel, otherPixel) <= IteratorTolerance){
        TraversalRef->add(otherPoint);
      }
    } 
  }

  if(currentPoint.y - 1 >= 0){ //Can technically be zero, assumes y was valid and x is valid
    //Same as right but point is up
    HSLAPixel & otherPixel = IteratorPNG.getPixel(currentPoint.x, currentPoint.y - 1);
    Point otherPoint(currentPoint.x, currentPoint.y - 1);
    if(TraversalRef->getVisited(otherPoint) ==  0){
      if(calculateDelta(startPixel, otherPixel) <= IteratorTolerance){
        TraversalRef->add(otherPoint);
      }
    }
  }
  //All available neighboring points added to traversal, set current point to visited as well
  TraversalRef->setVisited(currentPoint);
  //Iterate currentPoint to next top of list
  currentPoint = TraversalRef->peek();
  //Find next non-visited point, popping off any points that have been visited
  while(!TraversalRef->empty()){//While list is not empty, find next non-visited point
    if(TraversalRef->getVisited(currentPoint) == 1){
      currentPoint = TraversalRef->pop(); //Pop off visited point from list
      currentPoint = TraversalRef->peek(); //Set currentPoint as next point
    }
    else{
      break; //Break loop once non-visited point found
    }
  } 

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


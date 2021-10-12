/**
 * @file DFS.h
 */

#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

using namespace cs225;

/**
 * A depth-first ImageTraversal.
 * Derived from base class ImageTraversal
 */
class DFS : public ImageTraversal {
public:
  DFS(const PNG & png, const Point & start, double tolerance);

  ImageTraversal::Iterator begin();
  ImageTraversal::Iterator end();

  void add(const Point & point);
  Point pop();
  Point peek() const;
  bool empty() const;

private:
	/** @todo [Part 1] */
	/** add private members here*/
  double DFStolerance;
  PNG DFSpng;
  Point DFSstart;
  //Stack for point storage
  std::stack<Point> DFStraversal;
  //We want to store where we visited, implement a vector
  //Array is too unwieldly, would require to copy every time
  //Vector needs to be nested
  std::vector<std::vector<int>> visited;
};

/**
 * @file FloodFilledImage.h
 * Definition for a class to do flood fill on an image
 */
#pragma once

#include "cs225/PNG.h"
#include <list>
#include <iostream>

#include "colorPicker/ColorPicker.h"
#include "imageTraversal/ImageTraversal.h"

#include "Point.h"
#include "Animation.h"
#include <vector>

using namespace cs225;
/**
 * This class is used to do flood fill on an image.
 * One or more FloodFill operations will be added and executed in the order they
 * are added in. Each operation should flood-fill the entire image. Each operation
 * should have its own traversal method and color picker.
 */
class FloodFilledImage {
public:
  FloodFilledImage(const PNG & png);
  void addFloodFill(ImageTraversal & traversal, ColorPicker & colorPicker);
  Animation animate(unsigned frameInterval) const;

private:
	/** @todo [Part 2] */
	/** add private members here*/
  PNG imagePNG;
  //Following vector holds pointers to imageTraversals - animate uses multiple imagetraversals to achieve its
  //desired effect, essentially by traversing the image several times (in the order that it specifies) updating
  //its pixels as it goes
  std::vector<ImageTraversal*> animateTraversal;
  //Create a second vector that stores the corresponding colorpicker
  std::vector<ColorPicker*> animateColor;
};

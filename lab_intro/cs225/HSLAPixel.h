/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#pragma once

#include <iostream>
#include <sstream>

namespace cs225 {
 class HSLAPixel {
  public:
	HSLAPixel();
	HSLAPixel(double hue, double saturation, double luminance);
	HSLAPixel(double hue, double saturatioh, double luminance, double alpha);
	double h; //Hue value for the new pixel, in degree [0,360)
	double s; //Saturation value for the new pixel, [0,1]
	double l; //Luminance value for the new pixel, [0,1]
	double a; //Alpha value for the new pixel, [0,1]


 };
}

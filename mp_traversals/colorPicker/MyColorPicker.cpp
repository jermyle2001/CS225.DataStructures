#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
MyColorPicker::MyColorPicker(double hue) : hue(hue), flip(false) { }

HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
  HSLAPixel pixel(hue, 1, 0.5);
  if(flip == true){
    if(hue + 180 > 360){
      hue = hue + 180 - 360;
    }
    else{
      hue = hue + 180;
    }
    flip = false;
  }
  else{
    if(hue - 180 < 0){
      hue = 360 - (180 - hue);
    }
    else{
      hue = hue - 180;
    }
    flip = true;
  }
  return pixel;
}

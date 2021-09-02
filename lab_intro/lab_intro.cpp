/**
 * @file lab_intro.cpp
 * Implementations of image manipulation functions.
 */

#include <iostream>
#include <cmath>
#include <cstdlib>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "lab_intro.h"

using cs225::HSLAPixel;
using cs225::PNG;

/* ITERATION TEMPLATE
 for(unsigned x = 0; x < image.width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < image.height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = image.getPixel(x, y); //Get pixel information

  }
 }



*/
/**
 * Returns an image that has been transformed to grayscale.
 *
 * The saturation of every pixel is set to 0, removing any color.
 *
 * @return The grayscale image.
 */
PNG grayscale(PNG image) {
  /// This function is already written for you so you can see how to
  /// interact with our PNG class.
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      // `pixel` is a pointer to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly.  No need to `set`
      // the pixel since you're directly changing the memory of the image.
      pixel.s = 0;
    }
  }

  return image;
}



/**
 * Returns an image with a spotlight centered at (`centerX`, `centerY`).
 *
 * A spotlight adjusts the luminance of a pixel based on the distance the pixel
 * is away from the center by decreasing the luminance by 0.5% per 1 pixel euclidean
 * distance away from the center.
 *
 * For example, a pixel 3 pixels above and 4 pixels to the right of the center
 * is a total of `sqrt((3 * 3) + (4 * 4)) = sqrt(25) = 5` pixels away and
 * its luminance is decreased by 2.5% (0.975x its original value).  At a
 * distance over 160 pixels away, the luminance will always decreased by 80%.
 * 
 * The modified PNG is then returned.
 *
 * @param image A PNG object which holds the image data to be modified.
 * @param centerX The center x coordinate of the crosshair which is to be drawn.
 * @param centerY The center y coordinate of the crosshair which is to be drawn.
 *
 * @return The image with a spotlight.
 */
PNG createSpotlight(PNG image, int centerX, int centerY) {
 //Loop through all of the pixels of the PNG (width x height)
 for (unsigned int x = 0; x < image.width(); x++){ //Iterate through width of PNG
  for(unsigned int y = 0; y < image.height(); y++){ //Iterate through height of PNG
  HSLAPixel & pixel = image.getPixel(x, y); //Get pixel information
  double distance = sqrt((centerX - x) * (centerX - x) + (centerY - y) * (centerY - y)); //Calculate distance from center
  if(distance > 160){ //If distance > 160, then we need to reduce luminance to 20% by default)
   pixel.l = 0.2 * pixel.l; //Reduce luminance to 20% of original (decrease by 80%)
   }
  else{ //Else, we reduce luminance of pixel by 0.5% per 1 pixel away 
   pixel.l = pixel.l * (1.0 - (0.005 * distance)); //Convert reduction to a percentage via (0.5 * distance)/100, subtract from 1 to get multiplier, apply to pixel 
   } 
  }
 }
  return image;
 
}
 

/**
 * Returns a image transformed to Illini colors.
 *
 * The hue of every pixel is set to the a hue value of either orange or
 * blue, based on if the pixel's hue value is closer to orange than blue.
 *
 * @param image A PNG object which holds the image data to be modified.
 *
 * @return The illinify'd image.
**/
PNG illinify(PNG image) {
 for(unsigned x = 0; x < image.width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < image.height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = image.getPixel(x, y); //Get pixel information
   /* if(abs(pixel.h - 11) < abs(pixel.h - 216)){ //If the hue is closer to orange than blue, then...
    pixel.h = 11; //Hue closer to orange than blue. Set to orange.
   }
   else{
    pixel.h = 216; //Hue closer to blue than orange. Set to blue.
   } */
    if(pixel.h > 320.5 || pixel.h <= 113.5) //Orange's hue values are between (320.5, 360]U[0, 140.5]. Test if either is true.
     pixel.h = 11;
    else
     pixel.h = 216;
  }
 }

  return image;
}
 

/**
* Returns an image that has been watermarked by another image.
*
* The luminance of every pixel of the second image is checked, if that
* pixel's luminance is 1 (100%), then the pixel at the same location on
* the first image has its luminance increased by 0.2.
*
* @param firstImage  The first of the two PNGs to be averaged together.
* @param secondImage The second of the two PNGs to be averaged together.
*
* @return The watermarked image.
*/
PNG watermark(PNG firstImage, PNG secondImage) {
 for(unsigned x = 0; x < secondImage.width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < secondImage.height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = secondImage.getPixel(x, y); //Get pixel information of second image
   if(pixel.l == 1){ //Check if luminance of second image is 1 (100%) - otherwise, do nothing
    HSLAPixel & pixel = firstImage.getPixel(x, y); //Get pixel information of first image
    if((pixel.l + 0.2) <= 1)
     pixel.l = pixel.l + 0.2; //Increase luminance on first image by 0.2 (within bounds)
    else //Bounds exceeded when luminance increased, set luminance to max (1)
     pixel.l = 1; 
   }
    
  }
 }
  return firstImage;
}

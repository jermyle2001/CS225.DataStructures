#include "cs225/PNG.h"
#include <list>
#include <iostream>
#include <vector>

#include "colorPicker/ColorPicker.h"
#include "imageTraversal/ImageTraversal.h"

#include "Point.h"
#include "Animation.h"
#include "FloodFilledImage.h"

using namespace cs225;

/**
 * Constructs a new instance of a FloodFilledImage with a image `png`.
 * 
 * @param png The starting image of a FloodFilledImage
 */
FloodFilledImage::FloodFilledImage(const PNG & png) {
  /** @todo [Part 2] */
  //Constructor: only image passed through so set image equal
  imagePNG = png;
}

/**
 * Adds a FloodFill operation to the FloodFillImage.  This function must store the operation,
 * which will be used by `animate`.
 * 
 * @param traversal ImageTraversal used for this FloodFill operation.
 * @param colorPicker ColorPicker used for this FloodFill operation.
 */
void FloodFilledImage::addFloodFill(ImageTraversal & traversal, ColorPicker & colorPicker) {
  /** @todo [Part 2] */
  //Implement vector to store pointers to traversals
  //Store said traversal/colorpicker into corresponding vectors
  animateTraversal.push_back(&traversal);
  animateColor.push_back(&colorPicker);

}

/**
 * Creates an Animation of frames from the FloodFill operations added to this object.
 * 
 * Each FloodFill operation added by `addFloodFill` is executed based on the order
 * the operation was added.  This is done by:
 * 1. Visiting pixels within the image based on the order provided by the ImageTraversal iterator and
 * 2. Updating each pixel to a new color based on the ColorPicker
 * 
 * While applying the FloodFill to the image, an Animation is created by saving the image
 * after every `frameInterval` pixels are filled.  To ensure a smooth Animation, the first
 * frame is always the starting image and the final frame is always the finished image.
 * 
 * (For example, if `frameInterval` is `4` the frames are:
 *   - The initial frame
 *   - Then after the 4th pixel has been filled
 *   - Then after the 8th pixel has been filled
 *   - ...
 *   - The final frame, after all pixels have been filed)
 */ 
Animation FloodFilledImage::animate(unsigned frameInterval) const {
  Animation animation;
  /** @todo [Part 2] */
  //Add first frame, which is starting image
  PNG animatePNG = imagePNG;
  unsigned i = 0;
  unsigned traversalSize = animateTraversal.size();
  int framecounter = 0;
  framecounter++;
  for(i = 0; i < traversalSize; i++){ //Iterate through the traversals specified by vector
    //Utilise iterator we created earlier to iterate throughout png to change its appearance based on 
    //frame rate
    ImageTraversal::Iterator animateIterator = animateTraversal[i]->begin();
    animation.addFrame(animatePNG);
    for(animateIterator = animateTraversal[i]->begin(); animateIterator != animateTraversal[i]->end(); ++animateIterator){
      unsigned x = (*animateIterator).x; //Dereference iterator/pointer turning it into reference, dereference such
      unsigned y = (*animateIterator).y;
      HSLAPixel & animatePixel = animatePNG.getPixel(x, y);
      HSLAPixel colorPixel = animateColor[i]->getColor(x, y); //Can't use reference here - won't work because nonpermanent..?
      animatePixel = colorPixel;
      if(framecounter % frameInterval == 0){
        animation.addFrame(animatePNG);
      }
      framecounter++;
    }
    //Now add final frame if needed
    animation.addFrame(animatePNG);
    framecounter = 1;

  }
  //Return animation after going through all iterators and colorPickers

  return animation;
}

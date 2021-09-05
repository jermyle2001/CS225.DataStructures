#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>

using cs225::HSLAPixel;
using cs225::PNG;

void rotate(std::string inputFile, std::string outputFile) {
  /*
1. Read inputFile (is a PNG, but presented as a string..?)
2. Rotate image 180 degrees
3. Write the rotated image out as outputFile

(i,j) becomes (width - i, height - j)

  */

PNG readFile; //Creates new PNG file to read inputFile
readFile.readFromFile(inputFile); //Reads inputFile, stores into readFile
PNG writeFile(readFile.width(), readFile.height()); //Creates new PNG file to write to outputFile using same dimensions


for(unsigned int x = 0; x < readFile.width(); x++){ //Iterate throughout entire image
 for(unsigned int y = 0; y < readFile.height(); y++){
   HSLAPixel & pixel_in = readFile.getPixel(x,y); //Create reference to inputFile pixel at (x,y) and get pixel information
   HSLAPixel & pixel_out = writeFile.getPixel(readFile.width() - 1 - x, readFile.height() - 1 - y); //Create reference to corresponding outputFile pixel at (Image width - x, Image height - y) and get pixel information
   pixel_out.h = pixel_in.h; //Copy pixel information to outputFile
   pixel_out.s = pixel_in.s;
   pixel_out.l = pixel_in.l;
   pixel_out.a = pixel_in.a;
  }
 }

writeFile.writeToFile(outputFile); //Image rotated, now write to outputFile
return;
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3
int c1 = 45;
int c2 = 90;
int c3 = 135;

int count = 0; //Create a counter variable for deciding which color to use
for(unsigned int x = 0; x < width; x++){
 for(unsigned int y = 0; y < height; y++){
  HSLAPixel & pixel = png.getPixel(x,y);
  if(count == 0){ //Use first color if count == 0 - copy pixel data
  pixel.h = c1;
  pixel.s = 1;
  pixel.l = 1;
  pixel.a = 1; 
  }
  if(count == 1){ //Use second color if count == 1 - copy pixel data
  pixel.h = c2;
  pixel.s = 0.7;
  pixel.l = 0.7;
  pixel.a = 0.7;
  }
  if(count == 2){ //Use third color is count == 2 - copy pixel data
  pixel.h = c3;
  pixel.s = 0.5;
  pixel.l = 0.5;
  pixel.a = 0.5;
  }
  count = count + 1;
  count = count % 3;
 }
}
  return png;
}


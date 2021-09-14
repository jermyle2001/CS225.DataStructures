#include "Image.h"
using cs225::HSLAPixel;
using cs225::PNG;

/* ITERATION TEMPLATE
 for(unsigned x = 0; x < image.width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < image.height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = image.getPixel(x, y); //Get pixel information

  }
 }
*/
//Image is a child class of PNG - treat IMAGe as I would a PNG 
//getpixel
void Image::darken(){
 for(unsigned x = 0; x < width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = getPixel(x, y); //Get pixel information
   if(pixel.l < 0.1){ //Check if pixel.l exceeds bounds when darkened. If so, set to 0.
    pixel.l = 0;
   }
   else{ //When darkened pixel.l does not exceed bounds. Apply formula.
    pixel.l = pixel.l - 0.1; 
   }
  }
 } 
return;
}

void Image::darken(double amount){
 for(unsigned x = 0; x < width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = getPixel(x, y); //Get pixel information
   if((pixel.l - amount) > 0){ //Check if pixel.l exceeds bounds when darkened. If so, set to 0.
    pixel.l = pixel.l - amount;
   }
   else{ //pixel.l exceeds bounds when darkened. Set to 0.
    pixel.l = 0;
   }
  }
 }
return;
}

void Image::desaturate(){
 for(unsigned x = 0; x < width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = getPixel(x, y); //Get pixel information
   if(pixel.s < 0.1){ //Check if pixel.s exceeds bounds when desaturated. If so, set to 0.
    pixel.s = 0;
   }
   else{ //When desaturated pixel.s does not exceed bounds. Apply formula.
    pixel.s = pixel.s - 0.1; 
   }
  }
 }
return; 
}

void Image::desaturate(double amount){
 for(unsigned x = 0; x < width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = getPixel(x, y); //Get pixel information
   if((pixel.s - amount) > 0){ //Check if value exceeds bounds when operation is applied. Otherwise, set to zero.
    pixel.s = pixel.s - amount;
   }
   else{ //pixel.s exceeds bounds when darkened. Set to 0.
    pixel.s = 0;
   }
  }
 }
return;
}

void Image::grayscale(){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel & pixel = getPixel(x, y);
      pixel.s = 0;
    }
  }
return;
}

void Image::illinify(){
 for(unsigned x = 0; x < width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = getPixel(x, y); //Get pixel information
    if(pixel.h > 320.5 || pixel.h <= 113.5) //Orange's hue values are between (320.5, 360]U[0, 140.5]. Test if either is true.
     pixel.h = 11;
    else
     pixel.h = 216;
  }
 }
return;
}

void Image::lighten(){
 for(unsigned x = 0; x < width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = getPixel(x, y); //Get pixel information
   if(pixel.l <= 0.9){ //Check if pixel.l will exceed bounds when lightened
    pixel.l = pixel.l + 0.1; //Doesn't exceed bounds, add 0.1
   }
   else{ //Exceeds bounds, set to 1
    pixel.l = 1;
   }
  }
 }
return;
}

void Image::lighten(double amount){
 for(unsigned x = 0; x < width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = getPixel(x, y); //Get pixel information
   if((pixel.l + amount) > 1){ //Check to see if operation will exceed bounds when applied. 
    pixel.l = 1;
   }
   else{ //Value does not exceed bounds when operation applied, apply operation
    pixel.l = pixel.l + amount; 
   }
  }
 }
return;
}

void Image::rotateColor(double degrees){ //Increase hue by "degrees" degrees
 for(unsigned x = 0; x < width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = getPixel(x, y); //Get pixel information
   if((pixel.h + degrees) > 360){ //Check to see if hue value exceeds bounds
    pixel.h = pixel.h + degrees - 360; //Value exceeds bounds after operation. Thus, add together and subtract from 360. Note: degrees % 360 is included to account for cases where degrees > 360
   }
  }
 }
return;
}

void Image::saturate(){
 for(unsigned x = 0; x < width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = getPixel(x, y); //Get pixel information
   if(pixel.s <= 0.9){ //Check if value will exceed bounds when operation applied
    pixel.s = pixel.s + 0.1; //Doesn't exceed bounds, add 0.1
   }
   else{ //Exceeds bounds, set to 1
    pixel.s = 1;
   }
  }
 }
return;
}

void Image::saturate(double amount){
 for(unsigned x = 0; x < width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = getPixel(x, y); //Get pixel information
   if((pixel.s + amount) > 1){ //Check to see if operation will exceed bounds when applied. 
    pixel.s = 1;
   }
   else{ //Value does not exceed bounds when operation applied, apply operation
    pixel.s = pixel.s + amount; 
   }
  }
 }
return;
}

void Image::scale(double factor){ //Scale by factor - both size and image
//Copy current image into a new PNG file so we don't lose any data
if(factor == 1){
return; //Return if factor = 1, as it does nothing
}
int w;
int h;
w = width();
h = height();
PNG copy(w, h); //Create empty PNG
HSLAPixel & pixelcopy = copy.getPixel(w, h); //Get pixel information of
 for(unsigned x = 0; x < width(); x++){ //Iterate throughout PNG's width
  for(unsigned y = 0; y < height(); y++){ //Iterate through PNG's height
   HSLAPixel & pixel = getPixel(x, y); //Get pixel information of original image
   HSLAPixel & pixelcopy = copy.getPixel(x, y); //Get pixel information of copy image
   pixelcopy.h = pixel.h;
   pixelcopy.s = pixel.s;
   pixelcopy.l = pixel.l;
   pixelcopy.a = pixel.a;
  }
 }
//Image data copied into copy PNG, now scale
resize(factor * w, factor * h); //First, resize image
/*
Two cases:
1. Factor <  1.0. In this case, the image becomes scaled down. 

2. Factor > 1.0. In this case, the image becomes scaled up. 
*/


/*
 for(unsigned i = 0; i < width(); i++){ //Iterate through re-scaled image's dimensions - i iterates through width, j iterates through height
   y = 0; //Reset y for reiteration throughout height
  for(unsigned j = 0; j < height(); j++){
   pixel = getPixel(i, j); //Get pixel reference of rescaled image
   pixelcopy = getPixel(x, y); 


  }
 }
*/

/*
if(factor < 1.0) {
 double distance1 = 0;
 double distance2 = 0;
 for(x = 0; x < pixelcopy.width(); x++){ //Iterate throughout original image's dimensions, compare distances, finding nearest neighbor and setting to such
  for(y = 0; y < pixelcopy.height(); y++){
   


  }
 }
} */


if(factor < 1.0){ //Factor < 1.0. Thus, we can just multiply by factor for every value of x and apply to resized image.
 for(unsigned x = 0; x < copy.width(); x++){
  for(unsigned y = 0; y < copy.height(); y++){
   HSLAPixel & pixelcopy = copy.getPixel(x, y);
   HSLAPixel & pixel = getPixel(x * factor, y * factor); //Multiply x and y values by factor for scaling
   pixel.h = pixelcopy.h; //Copy data from original PNG
   pixel.s = pixelcopy.s; 
   pixel.l = pixelcopy.l;
   pixel.a = pixelcopy.a;
  }
 }
}
else{ //Factor > 1.0. We multiply by the factor, but need to apply the pixel to multiple pixels
for(unsigned x = 0; x < copy.width(); x++){
 for(unsigned y = 0; y < copy.height(); y++){
  HSLAPixel & pixelcopy = copy.getPixel(x, y);
//Make a case for edge cases
if(x * factor + 1 <= width() || y * factor + 1 <= height()){
 for(unsigned i = x; i < x * factor + 1; i++){
   for(unsigned j = y; j < y * factor + 1; j++){
    HSLAPixel & pixel = getPixel(i, j);
    pixel.h = pixelcopy.h; //Copy data from original PNG
    pixel.s = pixelcopy.s; 
    pixel.l = pixelcopy.l;
    pixel.a = pixelcopy.a;
    }
   }
}
else{} //Edge case, so...
 for(unsigned i = x; i < width(); i++){
   for(unsigned j = y; j < height(); j++){
    HSLAPixel & pixel = copy.getPixel(i, j);
    pixel.h = pixelcopy.h; //Copy data from original PNG
    pixel.s = pixelcopy.s; 
    pixel.l = pixelcopy.l;
    pixel.a = pixelcopy.a;
    }
   }
  }
 }
}
return;
}

void Image::scale(unsigned w, unsigned h){ //Find factor, apply to previous function 
//If either dimension is smaller, scale down. If otherwise, scale up.
if(w < width() || h < height() ){ //If either is smaller, scale down.
double factorwidth = w / width(); //Find factor of width 
double factorheight = h / height(); //Find factor of height
 if(factorwidth > factorheight){ //Choose smaller factor, implement
 scale(factorheight);
 return;
 }
 else{
 scale(factorwidth);
 return;
 }
} 
else{
double factorwidth = w / width(); //Find factor of width 
double factorheight = h / height(); //Find factor of height
 if(factorwidth > factorheight){ //Choose smaller factor, implement
 scale(factorheight);
 return;
 }
 else{
 scale(factorwidth);
 return;
 }
}
return;
}

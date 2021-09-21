#include "StickerSheet.h"
#include "cs225/HSLAPixel.h"
#include <iostream>
#include <vector>

using std::vector;
using cs225::HSLAPixel;
using cs225::PNG;

StickerSheet::StickerSheet(const Image &picture, unsigned max){
 svector.resize(max);
 svector.clear();
 x_val.resize(max);
 y_val.resize(max);
 std::cout << "svector.size() = " << svector.size() << std::endl;
 unsigned w = picture.width();
 unsigned h = picture.height();
 baseImage.resize(w, h);
 for(unsigned i = 0; i < w; i++){
  for(unsigned j = 0; j < h; j++){
   HSLAPixel &pixel = baseImage.getPixel(i, j);
   pixel = picture.getPixel(i, j);
  }
 }
} //End of constructor

StickerSheet::~StickerSheet(){
 unsigned s = svector.size();
 for(unsigned i = s; i >= 0 ; i--){
  if(svector[i] != NULL){
   delete svector[i];
   svector.pop_back();
  }
 }
} //End of deconstructor

StickerSheet::StickerSheet(const StickerSheet &other){
 unsigned s = other.svector.size();
 svector.resize(s);
 svector.clear();
 x_val.resize(s);
 y_val.resize(s);
 unsigned w = other.baseImage.width();
 unsigned h = other.baseImage.height();
 baseImage.resize(w, h);
 for(unsigned i = 0; i < s; i++){
  if(other.svector[i] != NULL){
   svector.push_back(new Image);
   w = other.svector[i]->width();
   h = other.svector[i]->height();
   svector[i]->resize(w, h);
   for(unsigned x = 0; x < w; x++){
    for(unsigned y = 0; y < h; y++){
     HSLAPixel & pixel = svector[i]->getPixel(x,y);
     pixel = other.svector[i]->getPixel(x,y);
    }
   }
   x_val[i] = other.x_val[i];
   y_val[i] = other.y_val[i];
  }
 }
//Now copy base picture
 w = baseImage.width();
 h = baseImage.height();
 for(unsigned x = 0; x < w; x++){
  for(unsigned y = 0; y < h; y++){
    HSLAPixel & pixel = baseImage.getPixel(x,y);
    pixel = other.baseImage.getPixel(x,y);
   }

  } 
 
}; //End of copy constructor

const StickerSheet& StickerSheet::operator=(const StickerSheet & other){
 if(this != &other){
 unsigned s = other.svector.size();
 for(unsigned i = 0; i < s; i++){
  delete svector[i];
 }
 svector.resize(s);
 svector.clear();
 x_val.resize(s);
 y_val.resize(s);
 unsigned w = other.baseImage.width();
 unsigned h = other.baseImage.width();
 baseImage.resize(w, h);
 for(unsigned i = 0; i < s; i++){
  if(other.svector[i] != NULL){
  svector.push_back(new Image);
  w = other.svector[i]->width();
  h = other.svector[i]->height();
  svector[i]->resize(w, h);
  for(unsigned x = 0; x < w; x++){
   for(unsigned y = 0; y < h; y++){
    HSLAPixel & pixel = svector[i]->getPixel(x,y);
    pixel = other.svector[i]->getPixel(x,y);
   }
  }
  x_val[i] = other.x_val[i];
  y_val[i] = other.y_val[i];
 }
 }
}
/*
 w = baseImage.width();
 h = baseImage.height();
 for(unsigned x = 0; x < w; x++){
  for(unsigned y = 0; y < h; y++){
   HSLAPixel & pixel = baseImage.getPixel(x,y);
   pixel = other.baseImage.getPixel(x,y);
  }
 } 
*/

return *this;
} //End of assignment operator

void StickerSheet::changeMaxStickers(unsigned max){
 unsigned s = svector.size();
 if(max < s){
  while(s > max){
  if(svector[s] != NULL){
  delete svector[s-1];
  svector.pop_back();
  s--;
  }
  }
 }
 svector.resize(max);
 x_val.resize(max);
 y_val.resize(max);

} //End of changeMaxStickers

int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y){
 std::cout << "addSticker: original size() = " << svector.size() << std::endl;
 unsigned s = svector.size();
 unsigned cap = svector.capacity();
 if(s == cap){
 std::cout << "addSticker: vector full. Terminating operation." << std::endl;
  return -1;
 }
 svector.push_back(new Image);
 unsigned w = sticker.width();
 unsigned h = sticker.height();
 svector[s]->resize(w, h);
 x_val[s] = x;
 y_val[s] = y;
 for(unsigned i = 0; i < w; i++){
  for(unsigned j = 0; j < h; j++){
  HSLAPixel & pixel = svector[s]->getPixel(i, j);
  pixel = sticker.getPixel(i, j);
  }
 }
 std::cout << "addSticker: new size() = " << svector.size() << std::endl;
 return s;
} //End of addSticker

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
 unsigned s = svector.size();
 if(index > s-1){ //Zero-based index
  return false;
 }
 x_val[index] = x;
 y_val[index] = y;

 return true;
} //End of translate

void StickerSheet::removeSticker(unsigned index){
 unsigned s = svector.size();
 delete svector[index];
 for(unsigned i = index; i < s-1; i++){
 svector[i] = svector[i + 1];
 x_val[i] = x_val[i + 1];
 y_val[i] = y_val[i + 1];
 }
 svector.pop_back();
} //End of removeSticker

Image* StickerSheet::getSticker(unsigned index){
 unsigned s = svector.size();
 if(index > s - 1){
  return NULL;
 }
 return svector[index];


} //End of getSticker

Image StickerSheet::render() const{ 
 std::cout << "Creating base image..." << std::endl;
 Image finalImage;
 unsigned w = baseImage.width();
 unsigned h = baseImage.height();
 finalImage.resize(w, h);
 for(unsigned x = 0; x < w; x++){
  for(unsigned y = 0; y < h; y++){
   HSLAPixel & pixel = finalImage.getPixel(x,y);
   pixel = baseImage.getPixel(x,y);
  } //End of inner loop
 } //End of outer loop (baseImage)

 std::cout << "Base image created. Creating stickers..." << std::endl;
 unsigned s = svector.size();
 for(unsigned int z = 0; z < s; z++){
  //Resize baseImage if necessary
  if(svector[z] == NULL){
   std::cout << "svector at index [" << z << "] is empty. Breaking loop..." << std::endl;
   break;
  }
  std::cout << "Gathering border data..." << std::endl;
  unsigned stickw = svector[z]->width();
  unsigned stickh = svector[z]->height();
  unsigned xcoord = x_val[z];
  unsigned ycoord = y_val[z];
  std::cout << "stickw = " << stickw << " | stickh = " << stickh << " | xcoord = " << xcoord << " | ycoord = " << ycoord << " | w = " << w << " | h = " << h << std::endl;
  if(xcoord + stickw > w){
   if(ycoord + stickh > w){
    finalImage.resize(xcoord + stickw, ycoord + stickh);
   std::cout << "Resizing baseImage to fit stickers" << std::endl;
   }
   else{
    finalImage.resize(xcoord + stickw, h);
   std::cout << "Resizing baseImage to fit stickers" << std::endl;
   }
  }
  else if(ycoord + stickh > w){
   finalImage.resize(w, ycoord + stickh);
   std::cout << "Resizing baseImage to fit stickers" << std::endl;
  }
  std::cout << "baseImage resized. Printing stickers..." << std::endl; 
  w = finalImage.width();
  h = finalImage.height();
std::cout << "stickw = " << stickw << " | stickh = " << stickh << " | xcoord = " << xcoord << " | ycoord = " << ycoord << " | w = " << w << " | h = " << h << std::endl;
  for(unsigned x = 0; x < stickw; x++){
   for(unsigned y = 0; y < stickh; y++){
   HSLAPixel & pixel = finalImage.getPixel(x + xcoord, y + ycoord);
   HSLAPixel & spixel = svector[z]->getPixel(x, y);
   if(spixel.a == 0){
    continue;
    }
   pixel = spixel;
   } //End of inner loop
  } //End of middle loop
 } //End of outer loop

 return finalImage;

} //End of render()








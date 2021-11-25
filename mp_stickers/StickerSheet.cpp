#include "StickerSheet.h"
#include "cs225/HSLAPixel.h"
#include <iostream>
#include <vector>

using std::vector;
using cs225::HSLAPixel;
using cs225::PNG;

StickerSheet::StickerSheet(const Image &picture, unsigned max){
 baseImage = new Image(picture);
 svector.resize(max, NULL);
 x_val.resize(max, 0);
 y_val.resize(max, 0);
 sheetSize = 0;
} //End of constructor

/*
  We actually want to use a helper function clear to achieve the
   = operator, so that we can minimize the amount
  of work that we need to do.
*/
void StickerSheet::clearSheet()
{
 for(unsigned i = 0; i < svector.size(); i++)
 {
   if(svector[i] != NULL)
   {
     delete svector[i];
     svector[i] = NULL;
   }
 }
 delete baseImage;
}

StickerSheet::~StickerSheet(){
 clearSheet();
} //End of deconstructor

/*
  We actually want to use a helper function copy to achieve the
  copy constructor and = operator, so that we can minimize the amount
  of work that we need to do.
*/

void StickerSheet::copy(const StickerSheet & other)
{
  baseImage = new Image(*(other.baseImage));
  svector.resize(other.svector.size(), NULL);
  x_val.resize(other.x_val.size(), 0);
  y_val.resize(other.y_val.size(), 0);
  for(unsigned i = 0; i < other.svector.size(); i++)
  {
    if(other.svector[i] == NULL)
    {
      continue;
    }
    //Copy over sticker and its coordinates
    Image* sticker = new Image(*(other.svector[i]));
    svector[i] = sticker;
    x_val[i] = other.x_val[i];
    y_val[i] = other.y_val[i];
 }
 sheetSize = other.sheetSize;
}

StickerSheet::StickerSheet(const StickerSheet &other){
 copy(other);
}; //End of copy constructor

const StickerSheet& StickerSheet::operator=(const StickerSheet & other){
 clearSheet();
 copy(other);
 return *this;
} //End of assignment operator

void StickerSheet::changeMaxStickers(unsigned max){
 if(max == svector.size())
 {
   return;
 }
 else if(max < svector.size())
 {
   unsigned size = svector.size();
   for(unsigned i = size - 1; i > max - 1; i--)
   {
     if(svector[i] != NULL)
     {
       delete svector[i];
     }
     svector.pop_back();
     x_val.pop_back();
     y_val.pop_back();
   }
 }
 else
 { 
   unsigned size = svector.size();
   for(unsigned i = 0; i < max - size; i++)
   {
     svector.push_back(NULL);
     x_val.push_back(0);
     y_val.push_back(0);
   }
 }

} //End of changeMaxStickers

int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y){
 if(svector.size() >= svector.max_size())
 {
   return -1;
 }
 //Find available index for insertion
 unsigned i;
 for(i = 0; i < svector.size(); i++)
 {
   if(svector[i] == NULL)
   {
     break;
   }
 }
 Image* newSticker = new Image(sticker);
 svector[sheetSize] = newSticker;
 x_val[sheetSize] = x;
 y_val[sheetSize] = y;
 sheetSize++;
 return i;
} //End of addSticker

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
 if(svector[index] == NULL)
 {
   return false;
 }
 x_val[index] = x;
 y_val[index] = y;
 return true;
} //End of translate

void StickerSheet::removeSticker(unsigned index){
 if(index >= svector.size())
 {
   return;
 }
 delete svector[index];
 for(unsigned i = index + 1; i < svector.size(); i++)
 {
   svector[i - 1] = svector[i];
   x_val[i - 1] = x_val[i];
   y_val[i - 1] = y_val[i];
 }
 svector.pop_back();
 svector.push_back(NULL);
 x_val.pop_back();
 x_val.push_back(0);
 y_val.pop_back();
 y_val.push_back(0);
} //End of removeSticker

Image* StickerSheet::getSticker(unsigned index){
 if(index >= svector.size())
 {
   return NULL;
 }
 return svector[index];
} //End of getSticker

Image StickerSheet::render() const{ 
 /*
    Create base image, and then paste stickers onto base image.
 */
  Image out(*baseImage);
  for(unsigned i = 0; i < svector.size(); i++)
  {
    Image* sticker = svector[i]; 
    if(sticker != NULL){
    unsigned stickerX = x_val[i];
    unsigned stickerY = y_val[i];
    if(stickerX + sticker->width() >= out.width())
    {
      out.resize(stickerX + sticker->width(), out.height());
    }
    if(stickerY + sticker->height() >= out.height())
    {
      out.resize(out.width(), stickerY + sticker->height());
    }
    for(unsigned offsetX = 0; offsetX < sticker->width(); offsetX++)
    {
      for(unsigned offsetY = 0; offsetY < sticker->height(); offsetY++)
      {
        HSLAPixel & pixel = out.getPixel(stickerX + offsetX, stickerY + offsetY);
        if(sticker->getPixel(offsetX, offsetY).a != 0){
          pixel = sticker->getPixel(offsetX, offsetY);
        }
      }
    }
  }
  }
  return out;

} //End of render()
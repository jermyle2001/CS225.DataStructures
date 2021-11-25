/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "Image.h"
#include <iostream>
#include <vector>

using namespace std;


class StickerSheet
{
 public:
//Constructors and Destructor
  StickerSheet(const Image & picture, unsigned max);
  ~StickerSheet();
  StickerSheet(const StickerSheet & other);
//Member functions
  const StickerSheet & operator= (const StickerSheet & other);
  void changeMaxStickers(unsigned max);
  int addSticker(Image &sticker, unsigned x, unsigned y);
  bool translate(unsigned index, unsigned x, unsigned y);
  void removeSticker(unsigned inex);
  void copy(const StickerSheet & other);
  void clearSheet();
  Image* getSticker(unsigned index);
  Image render() const;

 private:
  std::vector<Image*> svector; //Declare a vector for storing pointers
  vector<unsigned int> x_val; //Declare vectors for x and y coordinates
  vector<unsigned int> y_val; //In order to maintain where to print images
  Image* baseImage; 	      //We also need to include a base image to 
			      //print on. 
  unsigned sheetSize;
};

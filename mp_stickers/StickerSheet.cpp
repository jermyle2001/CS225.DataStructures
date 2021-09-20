#include "StickerSheet.h"
#include "cs225/HSLAPixel.h"
#include <vector>
using std::vector;
using cs225::HSLAPixel;
using cs225::PNG;


//Constructors and Destructor------------------------------------------------
StickerSheet::StickerSheet(const Image & picture, unsigned max){
/*
  Intialize w a deep copy of the base picture and ability to hold a 
  max # of stickers(Image) with indices 0 through max - 1.
*/
/*
  1. We need to resize our vectors svector, x, and y to accomodate for the
     changing size of our array.
     -Achieve using resize function of vector
*/
  x.resize(max);
  svector.resize(max);
  y.resize(max);
/*
  2. Next, we need to store a deep copy of the base image, meaning that 
     we need to copy the image using its reference
*/
  unsigned w = picture.width(); //Store picture width/heights for use in resize
  unsigned h = picture.height();
  baseImage.resize(w, h);       //Resize base image to fit dimensions of image
				//being copied
  for(unsigned i = 0; i < w; i++){ //Iterate throughout image's width
   for(unsigned j = 0; j < h; j++){ //Iterate throughout image's height
    HSLAPixel & pixel = baseImage.getPixel(i,j); /* 
						    Create reference and 
						    getPixel information
						    to store on baseImage
						 */
    pixel = picture.getPixel(i,j);  //Copy pixels onto baseImage via reference
   }
  }
} //End of constructor

StickerSheet::~StickerSheet(){ //NOTE GET RID OF X Y VECTOR TOO
//We need to delete the pointers on the inside of each element in the vector
//Utilise a for loop
 for(int i = 0; i < svector.size(); i++){
  delete svector[i];
 }
}

StickerSheet::StickerSheet(const StickerSheet & other){
 /*
	We want to make a copy of the StickerSheet INDEPENDENT of the
	StickerSheet referenced as "other". Find constraints and copy
	over.
 */
//1. Find vector sizes for each of our vectors and resize

  x.resize(other.svector.size());
  svector.resize(other.svector.size());
  y.resize(other.svector.size());
  
//2. Resize baseImage to fit the baseImage passed through
  
  unsigned w = other.baseImage.width(); //Find width and height, store in vars
  unsigned h = other.baseImage.height();
  baseImage.resize(w, h);

//3. Copy the base image using a reference to each pixel and iteration

  for(unsigned i = 0; i < w; i++){
   for(unsigned j = 0; j < h; j++){ 
    HSLAPixel & pixel = baseImage.getPixel(i,j); //Reference pixel on baseImage
    pixel = other.baseImage.getPixel(i,j); //Get data on other Image, copy 
   }
  }

/*
- 4. 
- Now we want to copy the images and elements of our vectors into the copy
- vectors. We achieve this by iterating throughout the vector and using for
- loops.
*/

  for(unsigned i = 0; i < other.size(); i++){ //Iterate throughout vector
   svector[i] = new Image; //Allocate memory for new image, store pointer in 
			   // vector

   //Next, we need to resize the image to be consistent w other.
   w = other.svector[i]->width(); //Store values of height and widths of images
   h = other.svector[i]->height(); //That are being passed through
   svector[i]->resize(w, h); //Resize image in element i to be same size
   
   //Next we want to copy the image into our new vector's element
   for(unsigned j = 0; j < w; j++){
    for(unsigned k = 0; k < h; k++){
     HSLAPixel & pixel = svector[i]->getPixel(j,k); 
/* ^^Get pixel data of other image and create a reference to the data^^ */
     pixel = other.svector[i]->getPixel(j,k);
    }
   }
   //We also want to copy our x and y coordinates
   x[i] = other.x[i];
   y[i] = other.y[i];
  } //Done copying elements within StickerSheet passed through
} //End of Copy Constructor - elements and base image copied in full

//Member Functions-----------------------------------------------------------
int StickerSheet::addSticker(Image & sticker, unsigned x, unsigned y){
 //Check to see if sheet is at capacity.
 if(svector.size() == svector.capacity()){
  return -1;
 } //Sheet is not at capacity - proceed with operations
 
 unsigned index = svector.size(); //Sets index to # of elements
 svector[index] = new Image; //Allocate memory for a new sticker
 unsigned w = sticker.width(); //Get width and height of added sticker
 unsigned h = sticker.height(); 
 svector[index]->resize(w, h); //Resize image at index to fit sticker
 for(unsigned i = 0; i < w; i++){ //Iterate throughout image/sticker dimensions
  for(unsigned j = 0; j < h; j++){
   HSLAPixel & pixel = svector[index]->getPixel(i, j); //Create ref to pixel
   pixel = sticker.getPixel(i,j); //Set pixel = to pixel at corresponding loc
  } 
 }
 
 //Sticker's image added to vector. Now we need to include its location
 x[index] = x;
 y[index] = y;

return index-1; //Return zero-based layer index
}

void StickerSheet::changeMaxStickers(unsigned max){
/*
- We need to check if the new max is smaller than the old max, as we will need
- to delete any memory stored in the the elements that are being excluded as
- a result of the change in max.
*/
  if(max < svector.size()){
   //Max is smaller - we need to delete excess elements
  unsigned capacity = svector.capacity(); //Get # of elements
  unsigned index = max-1;
  for(index; index < capacity; index++){
   if(svector[i] != NULL){
     delete svector[i];
    }
   else{
    break;
    }
   }
  }
  //Deleted elements if necessary - now we can resize our vectors.
  x.resize(max);
  y.resize(max);
  svector.resize(max);
  
  return;
}

Image * StickerSheet::getSticker(unsigned index){
 //Check if index is invalid (no pointer or our of constraints)
 unsigned validindex = svector.size() - 1; //Subtract 1 from # of elements to 
					   //get # of elements as an index
 if(index > validindex){ //Check to see if index is valid
  return NULL; //Index is invalid, return NULL
 }
 
 //The index is valid, return the pointer at said index
 return svector[index];
}

const StickerSheet & StickerSheet::operator= (const StickerSheet & other){
return;
}

void StickerSheetremoveSticker(unsigned index){
/*
- We need to remove the sticker at the given index. Thus, we would need to
- delete any associated memory with the pointer at the index, and move all
- of our elements behind it.
*/
  if(svector[index] == NULL){ //Check to see if a sticker exists at index
   return; //No sticker exists at index - return
  }
 delete svector[index]; //Delete memory at index location
 unsigned maxsize = svector.capacity();
 unsigned currentsize = svector.size();
 //Now we need to move all elements down the stack/layer index
 for(unsigned i = index; i < maxsize; i++){
  if(svector[index + 1] == NULL){
   break;
  }
  svector[i] = svector[i + 1];
  x[i] = x[i + 1];
  y[i] = y[i + 1];
 }
return;
}

Image StickerSheet::render() const{
return ;
}

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
  //Change x and y coordinates of sticker at specified zero-based index

  //First, check if sticker exists at index
  if(svector[index] == NULL){
   return false;
  }

  //Sticker exists - now change its x and y coordinates  
  x[index] = x;
  y[index] = y;


return 0;
}



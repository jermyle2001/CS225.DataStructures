#include "StickerSheet.h"
#include "cs225/HSLAPixel.h"
#include <iostream>
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
  x_val.resize(max);
  svector.resize(max);
  y_val.resize(max);
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
 for(unsigned i = 0; i < svector.size(); i++){
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

  x_val.resize(other.svector.size());
  svector.resize(other.svector.size());
  y_val.resize(other.svector.size());
  
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

  for(unsigned i = 0; i < other.svector.size(); i++){ //Iterate throughout vector
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
   x_val[i] = other.x_val[i];
   y_val[i] = other.y_val[i];
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
 x_val[index] = x;
 y_val[index] = y;

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
  for(unsigned i = index; i < capacity; i++){
   if(svector[i] != NULL){
     delete svector[i];
    }
   else{
    break;
    }
   }
  }
  //Deleted elements if necessary - now we can resize our vectors.
  x_val.resize(max);
  y_val.resize(max);
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
/*
- Assignment operator assigns / copies other sticker sheet into this
- sticker sheet. It needs to check if the sticker sheets are equivalent 
- and if not, copy the sticker sheet passed through into the current
- sticker sheet via deep copy, copying pointers, images, and other data.
*/

//1. Check if stickers are the same. We can do this via pointer/reference

 if(this != &other){ //Pointers are not the same, create copy
  unsigned size = svector.size();
  for(unsigned i = 0; i < size; i++){
   delete svector[i]; //We need to delete any associated memory and
		      //reassign elements
  }
  //Memory cleared up/freed, now reallocate and reassign elements
  unsigned sizemax = other.svector.capacity(); //We also want to resize
  svector.resize(sizemax);		       //our existing vectors
  x_val.resize(sizemax);			       //to match the incoming
  y_val.resize(sizemax);			       //reference
  size = other.svector.size(); //Get the # of elements for iteration
  for(unsigned i = 0; i < size; i++){ //Iterate throughout &other elements
   svector[i] = new Image; //Allocate new memory previously deleted
   unsigned w = other.svector[i]->width(); //Get height and width of 
   unsigned h = other.svector[i]->height(); //stickers
   svector[i]->resize(w, h);
   //Image resized, now copy image
   for(unsigned k = 0; k < w; k++){
    for(unsigned j = 0; j < h; j++){
     HSLAPixel & pixel = svector[i]->getPixel(k, j); 
     /* ^^Create a reference to our own image for edit^^ */
     pixel = other.svector[i]->getPixel(k, j); //Copy pixel over
    }
   }
   //Sticker has been copied into svector, also need to copy x and y 
   //coords
   x_val[i] = other.x_val[i];
   y_val[i] = other.y_val[i];
  }	
 }








return *this;
}

void StickerSheet::removeSticker(unsigned index){
/*
- We need to remove the sticker at the given index. Thus, we would need to
- delete any associated memory with the pointer at the index, and move all
- of our elements behind it.
*/

  unsigned i = index;

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
  x_val[i] = x_val[i + 1];
  y_val[i] = y_val[i + 1];
 }
return;
}

Image StickerSheet::render() const{
/*
- This function prints the stickers onto the base image and returns 
- the entire image. It indexs through the layers and prints the stickers
- one by one.
*/

 unsigned w = baseImage.width(); //Get image and height of baseImage
 unsigned h = baseImage.height();
 Image finalImage; //Create an empty PNG w baseImage's constraints
 finalImage.resize(w, h);//Resize finalImage
 for(unsigned i = 0; i < w; i++){ //Iterate throughout baseImage's 
  for(unsigned j = 0; j < h; j++){ //boundaries
  //Copy image data from baseImage into finalImage
   HSLAPixel & pixel = finalImage.getPixel(i, j);
   pixel = baseImage.getPixel(i, j);
  }
 }
 for(unsigned i = 0; i < svector.size(); i++){
 std::cout << "Checking for null pointers at index [" << i << "]. " << std::endl;
  if(svector[i] == NULL){
  std::cout << "There is a NULL pointer at index [" << i << "]. " << std::endl;
  break;

  }


 }
 std::cout << "baseImage printed onto finalImage" << std::endl;
 //BaseImage printed within finalImage. Now print each sticker.
 unsigned sussy = svector.size();
 std::cout << "Entering first FOR loop" << std::endl;
 for(unsigned i = 0; i < sussy; i++){
  //Check to see if sticker's boundaries exceed baseImage
  std::cout << "The value of i is: " << i << std::endl;
  w = svector[i]->width(); //Gather boundary information
  std::cout << "Passed line 1" << std::endl;
  h = svector[i]->height();
  std::cout << "Passed line 2" << std::endl;
  unsigned xcoord = x_val[i];
  std::cout << "Passed line 3" << std::endl;
  unsigned ycoord = y_val[i];
  std::cout << "Passed line 4" << std::endl;
  unsigned basew = finalImage.width();
  std::cout << "Passed line 5" << std::endl;
  unsigned baseh = finalImage.height();
  std::cout << "for loop [" << i << "]: boundaries gathered." << std::endl;
  if(xcoord + w > basew && ycoord + h > baseh){ //baseWidth is too small, resize.
   std::cout << "Resizing entire image..." << std::endl;
   finalImage.resize(xcoord + w, ycoord + h);
  }
  else if(xcoord + w > basew){
   std::cout << "Resizing only width..." << std::endl;
   finalImage.resize(xcoord + w, baseh);
  }
  else if(ycoord + h > baseh){
   std::cout << "Resizing only height..." << std::endl;
   finalImage.resize(basew, ycoord + h);
  }
  //finalImage now fit sticker, print sticker onto image
  std::cout << "finalImage adjusted to fit sticker. Printing sticker..." << std::endl;
  for(unsigned j = 0; j < w; j++){
   for(unsigned k = 0; k < h; k++){
   //Check if alpha is 1. If not, then we can print.
   HSLAPixel & pixelprint = finalImage.getPixel(xcoord + i, ycoord + k);
   HSLAPixel & stickerpixel = svector[i]->getPixel(k, j);
   if(stickerpixel.a == 1){ //If sticker's alpha is 1, don't print
    continue;
    }
   else{ //Sticker's alpha is NOT 1, so we can print the sticker
    pixelprint = stickerpixel;
    }
   }
  std::cout << "Sticker [" << i+1 << "] printed. Continuing..." << std::endl;
  }


 }


return finalImage;
}

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
  //Change x and y coordinates of sticker at specified zero-based index

  //First, check if sticker exists at index
  if(svector[index] == NULL){
   return false;
  }

  //Sticker exists - now change its x and y coordinates  
  x_val[index] = x;
  y_val[index] = y;


return 0;
}



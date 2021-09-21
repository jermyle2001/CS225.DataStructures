#include "Image.h"
#include "StickerSheet.h"
#include <iostream>

int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  //Create baseImage
  std::cout << "Creating empty images..." << std::endl;
  Image sticker1;
  Image sticker2;
  Image sticker3;
  Image baseimage;

  std::cout << "Reading images from file..." << std::endl;
   
  sticker1.readFromFile("Sticker1.png");
  sticker2.readFromFile("Sticker2.png");
  sticker3.readFromFile("Sticker3.png");
  baseimage.readFromFile("BaseImage.png");
  
  std::cout << "Files have been read. Writing to test files..." << std::endl;
  std::cout << "Attempting to create baseimage..." << std::endl;

  sticker1.writeToFile("test1.png");
  sticker2.writeToFile("test2.png");
  sticker3.writeToFile("test3.png");
  baseimage.writeToFile("basetest.png");

  std::cout << "Images written to test files." << std::endl;

  Image & baseimageref = baseimage;
  StickerSheet CanIGoHome(baseimageref, 3);

  std::cout << "baseimage added. Adding sticker1..." << std::endl;


  Image & sticker1ref = sticker1;
  CanIGoHome.addSticker(sticker1ref, 10, 10);

  std::cout << "baseimage added. Adding sticker2..." << std::endl;

  Image & sticker2ref = sticker2;
  CanIGoHome.addSticker(sticker2ref, 10, 0);

  std::cout << "baseimage added. Adding sticker3..." << std::endl;

  Image & sticker3ref = sticker3;
  CanIGoHome.addSticker(sticker3ref, 200, 30);

  std::cout << "stickers added. Attempting to render..." << std::endl;

  Image result;

  std::cout << "Image 'result' initially created." << std::endl;
  std::cout << "Attempting to render..." << std::endl;

  result = CanIGoHome.render();

  std::cout << "Image rendered. Writing to file..." << std::endl;  

  result.writeToFile("result.png");

  std::cout << "Result image written to file. Terminating program." << std::endl;

  return 0;
}

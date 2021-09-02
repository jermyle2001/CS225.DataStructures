/**
 * @file sketchify.cpp
 * Implementation of the sketchify function.
 */
#pragma GCC diagnostic ignored "-Wuninitialized"
#include <cstdlib>
#include <cmath>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace cs225;

/**
 * Creates a new output image.

 * @param w width of the image
 * @param h height of the image

 * @return a pointer to the newly-created image
 */
PNG* setupOutput(unsigned w, unsigned h) {
    PNG* image = new PNG(w, h);
    return image;
}

/**
 * Used to customize the color of the sketchified image.

 * @return a pointer to the color to use when sketchifying
 */
HSLAPixel* myFavoriteColor() { 
    return new HSLAPixel(117, 1, 0.46); //Creates new memory, returns pointer of color, stores on HEAP instead of STACK
}

void sketchify(std::string inputFile, std::string outputFile) {
    // Load in.png
    PNG* original = new PNG; //Creates pointer of type PNG named "original", allocates memory and sets to memory
    std::cout << "Reached line " << __LINE__ << std::endl;
    original->readFromFile(inputFile); //
    std::cout << "Reached line " << __LINE__ << std::endl;
    unsigned width = original->width(); //Sets
    std::cout << "Reached line " << __LINE__ << std::endl;
    unsigned height = original->height();
    std::cout << "Reached line " << __LINE__ << std::endl;

    // Create out.png
    PNG* output;
    std::cout << "Reached line " << __LINE__ << std::endl;
    std::cout << "The value of width is: " << width << std::endl << "The value of height is: " << height << std::endl;
    output = setupOutput(width, height);
    std::cout << "Reached line " << __LINE__ << std::endl;
    
    // Load our favorite color to color the outline
    HSLAPixel* myPixel = myFavoriteColor();
    std::cout << "Reached line " << __LINE__ << " - Entering FOR loops" << std::endl;

    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output
    for (unsigned y = 1; y < height; y++) {
    //std::cout << "Reached line " << __LINE__ << "- Outer loop y = " << y << std::endl;
        for (unsigned x = 1; x < width; x++) {
    	//std::cout << "Reached line " << __LINE__ << "- Inner loop x = " << x << std::endl;
            // Calculate the pixel difference
            HSLAPixel& prev = original->getPixel(x - 1, y - 1);
    	//std::cout << "Reached line " << __LINE__ << std::endl;
            HSLAPixel& curr = original->getPixel(x, y);
    	//std::cout << "Reached line " << __LINE__ << std::endl;
            double diff = std::fabs(curr.h - prev.h);
    	//std::cout << "Reached line " << __LINE__ << std::endl;

            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
            HSLAPixel & currOutPixel = (*output).getPixel(x, y);
    //std::cout << "Reached line " << __LINE__ << std::endl;
            if (diff > 20) {
    //std::cout << "Reached line " << __LINE__ << std::endl;
                currOutPixel = *myPixel;
            }
        }
    }

    // Save the output file
    output->writeToFile(outputFile);

    // Clean up memory
    delete myPixel;
    delete output;
    delete original;
}

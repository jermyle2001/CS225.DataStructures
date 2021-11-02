/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */

    /*
        The SourceImage class is essentially just a PNG with the function getRegionColor.

    */
    MosaicCanvas* canvasPointer = new MosaicCanvas(theSource.getRows(), theSource.getColumns());

    /*
        For every region on MosaicCanvas, take the TileImage with the closest 
        average color and place that image into MosaicCanvas' corresponding
        spot. We will use the featured <map> class to structure our Canvas. The
        map class stores typeDef pairs, which are <key, value>. The declaration
        of the map class in this scenario uses our points as our "key", and 
        a pointer to the corresponding TileImage, containg the closest average
        color, as its "value". 
    */
    map<Point<3>, TileImage*> colorMap;
    vector<Point<3>> colorsVector;
    
    /*
        Map out points and corresponding tileImages based on average color. 
        Use featured functions to determine such. We iterate through the
        provided TileImage vector to convert out individual images into 
        point form, pairing the tile with a point.

        The loop below iterates throughout our TileImage class. It first gets the
        average color at each element of the class, converts into an XYZ equivalent,
        which in this case is a LUV point, and pushes it into a vector for KDTree
        construction. Afterwards, we map the point and the pointer, or pair the 
        image at the element we just looked at in TileImage, with a corresponding
        LUV point, represented in 3D (XYZ) space.
    */
    for(auto tileIterator = theTiles.begin(); tileIterator != theTiles.end(); tileIterator++){
        LUVAPixel pixelColor = tileIterator->getAverageColor();
        Point<3> color = convertToXYZ(pixelColor);
        colorsVector.push_back(color);
        colorMap[color] = &*tileIterator;
    }

    /*
        At this point, we have mapped out our TileImage class to a map of of 
        3D points representing our colors, with pointers to the appropriate 
        image with the corresponding LUV values. Now we need to create a 
        canvas that uses the corresponding region color to map an appropriate
        image to the region. We need to create a KDTree, which has mapped
        out our colors, and use its functions to find the best nearest
        color to our source image.
    */

    KDTree<3> colorTree(colorsVector);

    for(auto i = 0; i < canvasPointer->getRows(); i++){
        for(auto j = 0; j < canvasPointer->getColumns(); j++){
            /*
                Get the point specified, get the corresponding color point, 
                find the next best color point, and map it into our 
                canvas.
            */
           Point<3> originalColor = convertToXYZ(theSource.getRegionColor(i, j));
           Point<3> bestColor = colorTree.findNearestNeighbor(originalColor);
           /*
                We find the corresponding "bestcolor" - don't have to worry about
                the point not existing, since we already paired it off earlier.
           */
           TileImage* correspondingTile = colorMap[bestColor];
           canvasPointer->setTile(i, j, correspondingTile);
        }
    }

    return canvasPointer;
}


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
    std::cout << "tiles size: " << theTiles.size() << std::endl;
    std::map<Point<3>, TileImage*> pixelToImage;
    std::vector<Point<3>> pointVector;

    for(size_t i = 0; i < theTiles.size(); i++) {
        LUVAPixel avgColor = theTiles[i].getAverageColor();
        Point<3> pointColor = convertToXYZ(avgColor);
        //std::cout << pointColor << " is mapped to " << it->getAverageColor() << std::endl;
        pixelToImage.insert(std::pair<Point<3>, TileImage*>(pointColor, &theTiles[i]));
        pointVector.push_back(pointColor);
    }
    std::cout << "pointVector size: " << pointVector.size() << std::endl;
    KDTree<3> kdTree(pointVector);


    MosaicCanvas* mosaic = new MosaicCanvas(theSource.getRows(), theSource.getColumns());
    for (int i = 0; i < mosaic->getRows(); i++) {
        for (int j = 0; j < mosaic->getColumns(); j++) {
            LUVAPixel srcPixel = theSource.getRegionColor(i,j);
            Point<3> kdPixel = convertToXYZ(srcPixel);
            Point<3> nearestNeighbor = kdTree.findNearestNeighbor(kdPixel);
            TileImage* nearestImage = pixelToImage.find(nearestNeighbor) -> second; //gets the image based on the nearest neighbor point
            mosaic->setTile(i,j,nearestImage);
            
        }
    }

    return mosaic;
}


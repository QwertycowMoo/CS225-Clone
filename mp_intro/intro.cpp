#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>
#include <cmath>
using cs225::PNG;
using cs225::HSLAPixel;

void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 2
  PNG inputPng;
  inputPng.readFromFile(inputFile);
  if (inputPng.readFromFile(inputFile)) {
    int inputWidth = inputPng.width();
    int inputHeight = inputPng.height();
    PNG outputPng = PNG(inputWidth, inputHeight);
    for (int x = 0; x < inputWidth; x++) {
      for (int y = 0; y < inputHeight; y++) {
        
        HSLAPixel inPixel = inputPng.getPixel(inputWidth - 1 - x, inputHeight - 1 -y);
        
        outputPng.getPixel(x, y) = inPixel;
      }
    }

    outputPng.writeToFile(outputFile);
  }
}

 cs225::PNG makeWave(unsigned int startX, unsigned int startY, PNG png) {
  PNG wavePNG = png;
  for (unsigned int x = startX; x < startX + 100; x++) {
    for (unsigned int y = startY; y < startY + 100; y++) {
      //small right lower triangle
      if (y > 1.75 * (x - startX) - 80 + startY && y < startY + 80 && x > startX + 60) {
        wavePNG.getPixel(x,y).h = 221;
        wavePNG.getPixel(x,y).s = 1;
        wavePNG.getPixel(x,y).l = .49;
      }

      //biggest circle of light blue with circle cut out of it
      if (y < sqrt(1600 - (x - (38 + startX))*(x - (38 + startX))) + 58 + startY //top half
          && y > -sqrt(1600 - (x - (38 + startX))*(x - (38 + startX))) + 58 + startY //bottom half
          && x < startX + 79 && y < startY + 80 //line that comes out because of asymptotes
          && x > sqrt(850 - (50 - y + startY) * (50 - y + startY)) + 5 + startX) { //cut out of circle
            wavePNG.getPixel(x,y).h = 221;
            wavePNG.getPixel(x,y).s = 1;
            if (y < startY + 30 || x < startX + 20) {
              wavePNG.getPixel(x,y).l = .89;
            } else {
              wavePNG.getPixel(x,y).l = .59;
            }
            
        
        
        

        
      }
      
      
    
      
    }
  }
  return wavePNG;
}



cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3
  //background
  for (unsigned int x = 0; x < width; x++) {
    for (unsigned int y = 0; y < height; y++) {
        png.getPixel(x, y) = cs225::HSLAPixel(234, .73, .33);
    }
  }

  //wave somthing that can repeat over a screen with light blue and white
  for (unsigned int y = 0; y < height; y += 100) {
    for (unsigned int x = 0; x < width; x += 100) {
      png = makeWave(x, y, png);
    }
  }
  return png;
}




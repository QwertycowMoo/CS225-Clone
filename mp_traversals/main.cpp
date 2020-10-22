
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;


int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.
  PNG toFill;
  toFill.readFromFile("./tests/i.png");
  FloodFilledImage myFloodFill(toFill);
  DFS dfs1(toFill, Point(40, 40), 0.05); //inside orange part of the I
  MyColorPicker cp;
  BFS bfs1(toFill, Point(0, 0), 0.05);
  RainbowColorPicker rainbow(.02);  //outside blue part of the I

  myFloodFill.addFloodFill(dfs1, cp);
  myFloodFill.addFloodFill(bfs1, rainbow);

  Animation animation = myFloodFill.animate(1000);
  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");
  
  return 0;
}

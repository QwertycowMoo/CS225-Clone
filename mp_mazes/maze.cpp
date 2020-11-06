/* Your code here! */
#include "maze.h"
#include <time.h>
#include <iostream>

    SquareMaze::SquareMaze() {
        
    }

    void SquareMaze::makeMaze(int width, int height) {
        //create the vector storing all the squares
        for (int i = 0; i < width; ++i) {
            mazeSquares.push_back(vector<std::pair<bool, bool>>());
            for (int j = 0; j < height; ++j) {
                mazeSquares[i].push_back(std::pair<bool, bool>(true, true));
            }
        }
        //disjoint set is going to be encoded as a single integer that is width coordinate + height coordinate * max width where both are indexed at 0
        //to check for right element, add 1. To check for bottom element, add width
        dset.addelements(width * height);
        srand(time(NULL));
        //calls setWall 
        //loop this eventually
        int randomX = rand() % width; //in range [0, width);
        int randomY = rand() % height;
        int dir = rand() % 2;
        int currCell = randomX + randomY * width;

        //No more walls can be removed when everything is part of one set
        while(dset.size(currCell) != width * height) {
        //checks for edge of map
            //std::cout << "looking at: " << currCell << ": (" << randomX << ", " << randomY << ") direction: " << dir << std::endl;

            if (!(randomX == width - 1 && dir == 0) && !(randomY == height - 1 && dir == 1)) {
                //sees if we can go that way (restricted to only right or bottom)
                //std::cout << "checking direction" << std::endl;
                if (!canTravel(randomX, randomY, dir)) {
                    //std::cout << "can't go that way, looking to remove the wall" << std::endl;
                    if (dir) {
                        //going down
                        if (dset.find(currCell) != dset.find(currCell + width)){
                            //the cells are not part of the same collection so we can union them
                            std::cout << "setting : " << currCell << " that has size: " << dset.size(currCell) << " with dir " << dir << std::endl;
                            setWall(randomX, randomY, dir, false);
                            dset.setunion(currCell, currCell+width);
                        }
                        
                    } else {
                        //going right
                        if (dset.find(currCell) != dset.find(currCell + 1)){
                            //the cells are not part of the same collection so we can union them
                            std::cout << "setting : " << currCell << " that has size: " << dset.size(currCell) << " with dir " << dir << std::endl;
                            setWall(randomX, randomY, dir, false);
                            dset.setunion(currCell, currCell+1);
                        }
                        
                    }
                    
                }
            }
            randomX = rand() % width; //in range [0, width);
            randomY = rand() % height;
            dir = rand() % 2;
            currCell = randomX + randomY * width;
        }


    }

    bool SquareMaze::canTravel(int x, int y, int dir) const {
        //cannot go outside perimeter
        /*
            dir = 0 represents a rightward step (+1 to the x coordinate)
            dir = 1 represents a downward step (+1 to the y coordinate)
            dir = 2 represents a leftward step (-1 to the x coordinate)
            dir = 3 represents an upward step (-1 to the y coordinate)
        */
       if (x == 0 && dir == 2) {
           //trying to go left at the left edge
           return false;
       } else if ((unsigned) x == mazeSquares.size() - 1 && dir == 0) {
           //trying to go right at the right edge
            return false;
       } else if ( (unsigned) y == mazeSquares[0].size() - 1 && 1) {
           //trying to go down at bottom edge
           return false;
       } else if (y == 0 && dir == 3) {
           //trying to go up at top edge
           return false;
       }
       if (dir == 0) {
           //trying to go rightward
           if (mazeSquares[x][y].first == true) {
               return false;
           } 
       } else if (dir == 1) {
           if (mazeSquares[x][y].second == true) {
               return false;
           }
       } else if (dir == 2) {
           if (mazeSquares[x-1][y].first == true) {
               return false;
           }
       } else if (dir == 3) {
           if (mazeSquares[x][y-1].second == true) {
               return false;
           }
       }

       //having this return true out here is going to return true for anything that doesn't have a valid dir
       return true;
    }

    void SquareMaze::setWall(int x, int y, int dir, bool exists){
        //only really need to count the right or bottom because they share walls
        if (dir == 0) {
            //right
            mazeSquares[x][y].first = exists;
        } else if (dir) {
            //bottom
            mazeSquares[x][y].second = exists;
        }
        
    }

    vector<int> SquareMaze::solveMaze(){
        //use dfs on the set since that should be in a tree-like fashion and we pick a point, find its neighbors, then run bfs recursively?
        return vector<int>(10);
    }

    PNG * SquareMaze::drawMaze() const {
        return new PNG();
    }

    PNG * SquareMaze::drawMazeWithSolution() {
        return new PNG();
    }
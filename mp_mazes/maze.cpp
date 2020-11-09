/* Your code here! */
#include "maze.h"
#include <time.h>
#include <iostream>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <queue>

    SquareMaze::SquareMaze() {
        
    }

    void SquareMaze::makeMaze(int width, int height) {
        //create the vector storing all the squares
        _height = height;
        _width = width;
        for (int i = 0; i < width; ++i) {
            mazeSquares.push_back(vector<std::pair<bool, bool>>());
            for (int j = 0; j < _height; ++j) {
                mazeSquares[i].push_back(std::pair<bool, bool>(true, true));
            }
        }
        //disjoint set is going to be encoded as a single integer that is width coordinate + height coordinate * max width where both are indexed at 0
        //to check for right element, add 1. To check for bottom element, add width
        dset.addelements(_width * _height); 

        //seeding random based on nanoseconds
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        srand((time_t)ts.tv_nsec);
        //calls setWall 
        //loop this eventually
        int randomX = rand() % _width; //in range [0, width);
        int randomY = rand() % _height;
        int dir = rand() % 2;
        int currCell = randomX + randomY * _width;

        //No more walls can be removed when everything is part of one set
        while(dset.size(currCell) != _width * _height) {
        //checks for edge of map
            //std::cout << "looking at: " << currCell << ": (" << randomX << ", " << randomY << ") direction: " << dir << std::endl;

            if (!(randomX == _width - 1 && dir == 0) && !(randomY == _height - 1 && dir == 1)) {
                //sees if we can go that way (restricted to only right or bottom)
                //std::cout << "checking direction" << std::endl;
                if (!canTravel(randomX, randomY, dir)) {
                    //std::cout << "can't go that way, looking to remove the wall" << std::endl;
                    if (dir) {
                        //going down
                        if (dset.find(currCell) != dset.find(currCell + _width)){
                            //the cells are not part of the same collection so we can union them
                            //std::cout << "setting : " << currCell << " that has size: " << dset.size(currCell) << " with dir " << dir << std::endl;
                            setWall(randomX, randomY, dir, false);
                            dset.setunion(currCell, currCell+_width);
                        }
                        
                    } else {
                        //going right
                        if (dset.find(currCell) != dset.find(currCell + 1)){
                            //the cells are not part of the same collection so we can union them
                            //std::cout << "setting : " << currCell << " that has size: " << dset.size(currCell) << " with dir " << dir << std::endl;
                            setWall(randomX, randomY, dir, false);
                            dset.setunion(currCell, currCell+1);
                        }
                        
                    }
                    
                }
            }
            randomX = rand() % _width; //in range [0, width);
            randomY = rand() % _height;
            dir = rand() % 2;
            currCell = randomX + randomY * _width;
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

       if (dir == 0) {
           //trying to go rightward
           if (mazeSquares[x][y].first == true || (unsigned) x == mazeSquares.size() - 1) {
               return false;
           } 
       } else if (dir == 1) {
           if (mazeSquares[x][y].second == true || (unsigned) y == mazeSquares[0].size() - 1) {
               return false;
           }
       } else if (dir == 2) {
           if (mazeSquares[x-1][y].first == true || x == 0) {
               return false;
           }
       } else if (dir == 3) {
           if (mazeSquares[x][y-1].second == true || y == 0) {
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

        /*
            dir = 0 represents a rightward step (+1 to the x coordinate)
            dir = 1 represents a downward step (+1 to the y coordinate)
            dir = 2 represents a leftward step (-1 to the x coordinate)
            dir = 3 represents an upward step (-1 to the y coordinate)
        */

        vector<int> solution;
        int x = 0;
        int y = 0;

        std::queue<std::pair<std::pair<int, int>, vector<int>>> q; //encode the xy coordinate as an integer of x + y*width, path is going to be stored as a vector
        //q

        //array of visited points
        vector<vector<bool>> visited;
        for (int i = 0; i < _width * _height - 1; i++) {
            visited.push_back(vector<bool>());
            for (int j = 0; j < _width; j++) {
                visited[i].push_back(false);
            }
        }
        visited[0][0] = true;
        //encoding the point as x + y * width indexed at 0
        q.push(std::pair<int, int>(0,0));
        while(!q.empty()) {
            std::pair<int, int> currPoint = q.front();
            q.pop();
            x = currPoint.first;
            y = currPoint.second;

            if (y == _height - 1) {
                //reached the bottom
                //check against the largest path size and replace it if necessary
            }
            //find the things next to it
            if(canTravel(x, y, 0)) {
                //right
                if (!visited[x+1][y]) {
                    visited[x+1][y] = true;
                    q.push(std::pair<int, int>(x+1, y));
                }
            }
            if(canTravel(x, y, 1)) {
                //down
                if (!visited[x][y+1]) {
                    visited[x][y+1] = true;
                    q.push(std::pair<int, int>(x, y+1));
                }
            }
            if(canTravel(x, y, 2)) {
                //left
                if (!visited[x-1][y]) {
                    visited[x-1][y] = true;
                    q.push(std::pair<int, int>(x-1, y));
                }
            }
            if(canTravel(x, y, 0)) {
                //top
                if (!visited[x][y-1]) {
                    visited[x][y-1] = true;
                    q.push(std::pair<int, int>(x, y-1));
                }
            }
        }

        return vector<int>(10);
    }

    vector<int> SquareMaze::BFS(vector<vector<bool>>& visited, vector<int> solution, int x, int y) {
        if (y == _height - 1) {
            return solution;
        }
        //visit right
        if (!visited[x+1][y]) {
            visited[x+1][y] = true;
            solution.push_back(0);
            return BFS(visited, solution, x+1, y);
        }
        //visit down
        if (!visited[x][y+1]) {
            visited[x][y+1] = true;
            solution.push_back(0);
            return BFS(visited, solution, x+1, y);
        }
        //visit up
        //visit left

    }

    PNG * SquareMaze::drawMaze() const {
        PNG * mazePNG = new PNG(_width*10+1, _height*10+1);
        //border stuff
        for (int x = 0; x < _width*10+1; ++x) {
            if (x > 9) {
                cs225::HSLAPixel& toChange = mazePNG->getPixel(x, 0);
                toChange.l = 0.0;
            }
            
        }
        for (int y = 0; y < _height*10+1; ++y) {
            cs225::HSLAPixel& toChange = mazePNG->getPixel(0, y);
            toChange.l = 0.0;
        }
        
        //actual maze
        for (size_t i = 0; i < mazeSquares.size(); ++i) {
            for (size_t j = 0; j < mazeSquares[i].size(); ++j) {
                if (mazeSquares[i][j].first) {
                    //right
                    for (int k = 0; k <= 10; ++k) {  
                        cs225::HSLAPixel& toChange = mazePNG->getPixel((i + 1) * 10, j * 10 + k);
                        toChange.l = 0.0;
                    }
                }
                if (mazeSquares[i][j].second) {
                    //bottom
                    for (int k = 0; k <= 10; ++k) {  
                        cs225::HSLAPixel& toChange = mazePNG->getPixel(i * 10 + k, (j + 1) * 10);
                        toChange.l = 0.0;
                    }
                }
                
            }
        }
        return mazePNG;
    }

    PNG * SquareMaze::drawMazeWithSolution() {
        return new PNG();
    }
/* Your code here! */
#pragma once

#include "dsets.h"
#include "cs225/PNG.h"

using cs225::PNG;
class SquareMaze{
    public:
        /*
        No-parameter constructor.
        Creates an empty maze.
        */
        SquareMaze();
        
  
        //Makes a new SquareMaze of the given height and width.
        //If this object already represents a maze it will clear all the existing data before doing so.
        //You will start with a square grid (like graph paper) with the specified height and width. 
        //You will select random walls to delete without creating a cycle,
        //until there are no more walls that could be deleted without creating a cycle.
        //Do not delete walls on the perimeter of the grid.
        void makeMaze(int width, int height);
        
        
        //This uses your representation of the maze to determine whether it is possible to travel
        //in the given direction from the square at coordinates (x,y).  
        bool canTravel(int x, int y, int dir) const;

         
        //Sets whether or not the specified wall exists.

        // This function should be fast (constant time).
        // You can assume that in grading we will not make your maze a non-tree and then call one of the other member functions. 
        // setWall should not prevent cycles from occurring, but should simply set a wall to be present or not present. 
        // Our tests will call setWall to copy a specific maze into your implementation.
        void setWall(int x, int y, int dir, bool exists);
            
        /**
        *Solves this SquareMaze.
        *For each square on the bottom row (maximum y coordinate), there is a distance from the origin (i.e. the top-left cell),
        * which is defined as the length (measured as a number of steps) of the only path through the maze from the origin to that square.
        *Select the square in the bottom row with the largest distance from the origin as the destination of the maze. solveMaze() returns the winning path from the origin to the destination as a vector of integers, where each integer represents the direction of a step, using the same encoding as in canTravel().
        *If multiple paths of maximumtraverse  length exist, use the one with the destination cell that has the smallest x value.
        *Hint: this function should run in time linear in the number of cells in the maze.
        */
        vector< int > solveMaze();

        //Draws the maze without the solution.
        PNG * drawMaze() const;
        
        //This function calls drawMaze, then solveMaze; it modifies the PNG from drawMaze to show the solution vector and the exit.
        PNG * drawMazeWithSolution();

    private:
        vector<int> BFS(vector<vector<bool>>& visited, vector<int> solution, int x, int y);
        DisjointSets dset;
        vector<vector<std::pair<bool, bool>>> mazeSquares;
        int _height;
        int _width;
};
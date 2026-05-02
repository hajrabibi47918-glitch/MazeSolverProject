#ifndef MENU_H
#define MENU_H

#include "Maze.h"
#include "Solver.h"
#include "PathMarker.h"
#include <iostream>
#include <vector>

using namespace std;

//menu class
class Menu
{
    //public attributed and methods
    public:
        //parameterized constructor
        Menu(int rows, int cols);
        //show the menu of maze
        void show_Menu();
        //start maze
        void start();

    protected:

    //private attributes and methods
    private:
        //maze class object
        Maze maze;
        //solver class object
        Solver solver;
        //find and stores start and end position
        void setStartExitPositions();
        int startRow, startCol;
        int exit_Row, exit_Col;
        //call dfs algorithm for maze solving
        void SolveUsingDFS();
        //call bfs algorithm for maze solving
        void SolveUsingBFS();
        //used to input maze
        void inputMaze();

};

#endif // MENU_H

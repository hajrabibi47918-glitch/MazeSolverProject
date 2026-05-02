#ifndef SOLVER_H
#define SOLVER_H
#include <vector>
#include "Maze.h"
#include<iostream>

using namespace:: std;
//structure cell to access row and column
struct Cell
{
    int row;
    int col;
    //constructor of cell structure
    Cell()
    {
        row = -1;
        col = -1;
    }
    Cell(int r = -1, int c = -1)
    {
        row = r;
        col = c;
    }
};

class Solver
{
    public:
        //parameterized constructor
        Solver(Maze &mazeObj);

        //bfs and dfs algorithmns
        bool dfs(int startRow, int startCol);
        bool bfs(int startRow, int startCol);
        //resets the parent matrix to state (-1,-1)
        void resetParent();
        //reconstruct solution path or backtracting
        vector<Cell> reconstructPath(int exit_Row, int exit_Col);
    protected:

    private:
        //maze class object with reference
        Maze &maze;
        //stores parent cell for backtracking
        vector<vector<Cell>> parent;
};

#endif // SOLVER_H

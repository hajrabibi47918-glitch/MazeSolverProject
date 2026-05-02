#include "PathMarker.h"
#include <iostream>
using namespace std;


//marks the path using *
 void PathMarker::mark_Path(Maze &maze, const vector<Cell> &path)
{
    for(const auto &p : path)
    {
        int row= p.row;
        int col= p.col;
        //mark path but does not overwrite start and end
        if(maze.getCell(row , col) != 'S' && maze.getCell(row, col) != 'E')
            maze.setCell(row, col, '*');
    }
}

//remove marked paths
 void PathMarker:: resetPath(Maze &maze)
{
    int rows = maze.getRows();
    int cols = maze.getCols();

    for(int i = 0; i< rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(maze.getCell(i,j) =='*')
                maze.setCell(i,j, '.');
        }
    }

}

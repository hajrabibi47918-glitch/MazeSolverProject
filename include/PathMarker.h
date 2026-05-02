#ifndef PATHMARKER_H
#define PATHMARKER_H

#include "Maze.h"
#include "Solver.h"

#include <vector>
#include <iostream>
using namespace std;

//path marker class
class PathMarker
{
    //public methods
    public:
        //marks the path with *
         static void mark_Path(Maze &maze, const vector<Cell> &path);
         //remove previous marks
         static void resetPath(Maze &maze);

    protected:

    private:
};

#endif // PATHMARKER_H

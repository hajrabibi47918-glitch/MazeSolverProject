#ifndef MAZE_H
#define MAZE_H
#include <vector>
#include <iostream>
using namespace std;

//maze class
class Maze
{
    public:
        //constructor
        Maze();
        Maze(int r = 5, int c = 5);

        //input maze from user
        void inputMaze();
        //display maze
        void printMaze() const;

        //check if a cell is valid or not
        bool isValid(int r, int c)const;
        //check if a cell is a wall
        bool isWall(int r, int c)const;

        //reset visited matrix
        void resetVisited();

        int getRows()const;
        int getCols()const;

        //get value of a cell
        char getCell(int r, int c)const;
        //set value of a cell
        void setCell(int r, int c, char value);

        //mark a cell as visited
        void markVisited(int r, int c);
        //check if a cell was visited
        bool isVisited(int r, int c)const;

        const vector<vector<char>>& getGrid() const;

    private:

        //maze grid
        vector<vector<char>> grid;

        //tracks visited cells
        vector<vector<bool>> visited;

        //maze dimensions
        int rows,cols;

        //start position
        int startRow, startCol;

        //end position
        int endRow, endCol;

};


#endif // MAZE_H

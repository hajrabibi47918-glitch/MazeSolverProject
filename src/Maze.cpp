#include "Maze.h"
#include <iostream>
using namespace std;

//constructor
Maze::Maze()
{
    rows = 0;
    cols = 0;
    startRow = -1;
    startCol = -1;
    endRow = -1;
    endCol = -1;
}
//parameterized constructor
Maze:: Maze(int r, int c)
{
    rows = r;
    cols = c;
    //create a 2D grid
    grid.resize(rows, vector<char>(cols));
    //create a 2D array initially false
    visited.resize(rows, vector<bool>(cols, false));

}

//input maze from user
void Maze::inputMaze()
{
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    //resize grid
    grid.resize(rows, vector<char>(cols));
    //resize visited matrix
    visited.resize(rows, vector<bool>(cols, false));

    startRow = startCol = endRow = endCol = -1;

    cout<< "Enter maze row by row:\n";
    cout<< "(Use following:\n S = Start, E = Exit, & = Wall, . = Path)\n";

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin >> grid[i][j];

            if(grid[i][j] == 'S')
            {
                startRow = i;
                startCol = j;
            }
            else if(grid[i][j] == 'E')
            {
                endRow = i;
                endCol = j;
            }
        }
    }
        if(startRow == -1 || endRow == -1)
            cout << "Warning! Start or End position is missing!\n";

}

//display maze
void Maze::printMaze() const
{
    cout <<"\n Maze:\n";
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

//check if rows and columns are within boundaries of maze
bool Maze::isValid(int r, int c)const
{
    return(r>=0 && r<rows && c>=0 && c<cols);

}

//check is a cell is a wall
bool Maze::isWall(int r, int c) const
{
    return (grid[r][c] == '&');
}

//reset visited matrix
void Maze::resetVisited()
{
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
        visited[i][j] = false;
}

//mark a cell as visited
void Maze::markVisited(int r, int c)
{
    visited[r][c] = true;
}

//check if a cell was already visited
bool Maze::isVisited(int r, int c)const
{
    return visited[r][c];
}

//return maze dimensions
int Maze::getRows()const
{
    return grid.size();
}
//get columns
int Maze::getCols()const
{
    if(grid.empty())
        return 0;
    return grid[0].size();
}

//Get the value of cell
char Maze::getCell(int r, int c)const
{
    return grid[r][c];
}

//set the value of cell
void Maze::setCell(int r, int c, char value)
{
    grid[r][c] = value;
}

//return a const reference to grid
const vector<vector<char>>& Maze::getGrid()const
{
    return grid;
}




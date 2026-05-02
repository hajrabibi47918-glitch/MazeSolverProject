#include "Solver.h"
#include <algorithm>
#include "Stack.h"
#include "Queue.h"

using namespace std;


//constructor
Solver::Solver(Maze &mazeObj):maze(mazeObj)
{
    int t_Rows = maze.getRows();
    int t_Cols = maze.getCols();

    parent.resize(t_Rows);

    for(int row = 0; row < t_Rows; row++)
        parent[row].resize(t_Cols, Cell(-1,-1));
}

void Solver::resetParent()
{
    parent.clear();
    parent.resize(maze.getRows(),vector<Cell>(maze.getCols(), Cell(-1,-1)));
}
//find pat through dfs algorithm
bool Solver::dfs(int startRow, int startCol)
{
    Stack st;
    Cell Start(startRow, startCol);
    st.push(Start);
    maze.resetVisited();
    //for Up and down
    int rowChange[4] = {-1,1,0,0};
    //for left and right
    int colChange[4] = {0,0,-1,1};

    while(!st.isEmpty())
    {
        Cell curr_Cell = st.top();
        st.pop();

        int curr_Row = curr_Cell.row;
        int curr_Col = curr_Cell.col;

        if(maze.isVisited(curr_Row,curr_Col))
            continue;

        maze.markVisited(curr_Row, curr_Col);

        if(maze.getCell(curr_Row,curr_Col) == 'E')
           return true;
        //for direction
        for(int d = 0; d<4; d++)
        {
            int next_Row = curr_Row + rowChange[d];
            int next_Col = curr_Col + colChange[d];

            if(maze.isValid(next_Row, next_Col) && !maze.isWall(next_Row, next_Col)&& !maze.isVisited(next_Row, next_Col))
            {
                parent[next_Row][next_Col] = Cell(curr_Row, curr_Col);
                st.push(Cell(next_Row,next_Col));
            }
        }
    }
    return false;
}


//find pat through bfs algorithm
bool Solver::bfs(int startRow, int startCol)
{
    Queue q;
    Cell Start(startRow, startCol);
    q.enqueue(Start);
    maze.resetVisited();
    //for Up and down
    int rowChange[4] = {-1,1,0,0};
    //for left and right
    int colChange[4] = {0,0,-1,1};

    while(!q.isEmpty())
    {
        Cell curr_Cell = q.front();
        q.dequeue();

        int curr_Row = curr_Cell.row;
        int curr_Col = curr_Cell.col;

        if(maze.isVisited(curr_Row,curr_Col))
            continue;

        maze.markVisited(curr_Row, curr_Col);

        if(maze.getCell(curr_Row,curr_Col) == 'E')
           return true;
        //for direction
        for(int d = 0; d<4; d++)
        {
            int next_Row = curr_Row + rowChange[d];
            int next_Col = curr_Col + colChange[d];

            if(maze.isValid(next_Row, next_Col) && !maze.isWall(next_Row, next_Col)&& !maze.isVisited(next_Row, next_Col))
            {
                parent[next_Row][next_Col] = Cell(curr_Row, curr_Col);
                q.enqueue(Cell(next_Row,next_Col));
            }
        }
    }
    return false;
}

//for reconstructing path
vector<Cell> Solver:: reconstructPath(int exit_Row, int exit_Col)
{
    vector<Cell> sol_Path;
    Cell curr_Cell(exit_Row, exit_Col);

    while(curr_Cell.row != -1 && curr_Cell.col !=-1)
    {
        sol_Path.push_back(curr_Cell);
        curr_Cell = parent[curr_Cell.row][curr_Cell.col];
    }
    reverse(sol_Path.begin(), sol_Path.end());
    return sol_Path;
}

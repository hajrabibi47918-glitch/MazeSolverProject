#include "Menu.h"
#include "Maze.h"
#include <iostream>
using namespace std;

//parameterized constructor
Menu::Menu(int rows, int cols):maze(rows, cols),solver(maze)
{
    startRow = startCol = -1;
    exit_Row = exit_Col = -1;
}

//show menu of maze
void Menu::show_Menu()
{
    cout << "\n\t MAZE SOLVER MENU" << endl;
    cout << "1. Input Maze " << endl;
    cout << "2. Display Maze " << endl;
    cout << "3. Solve using DFS " << endl;
    cout << "4. Solve using BFS " << endl;
    cout << "5. Exit" << endl;
    cout << "Enter choice: ";
}
 //find and stores start and end position
void Menu::setStartExitPositions()
{
    startRow = startCol = exit_Row = exit_Col = -1;
    for(int r = 0; r< maze.getRows(); r++)
    {
        for(int c = 0; c < maze.getCols();c++)
        {
            if(maze.getCell(r,c) == 'S')
            {
                startRow = r;
                startCol = c;
            }
            else if( maze.getCell(r,c) == 'E')
            {
                exit_Row = r;
                exit_Col = c;
            }
        }
    }
}
//start maze
void Menu::start()
{
    int choice;
    while(true)
    {
        show_Menu();
        cin >> choice;

        if(choice == 1)
        {
            maze.inputMaze();
            setStartExitPositions();
        }
        else if(choice == 2)
            maze.printMaze();
        else if(choice == 3)
                SolveUsingDFS();
        else if(choice == 4)
                SolveUsingBFS();
        else if(choice == 5)
        {
            cout << "Exiting" << endl;
            break;
        }
        else
            cout << "Invalid choice! Try again." << endl;
    }
}
//solving maze hrough DFS
void Menu::SolveUsingDFS()
{
   if(startRow == -1 || startCol == -1)
   {
       cout << "Maze not initialized. Input maze first" << endl;
       return;
   }

   if(exit_Row == -1 || exit_Col == -1)
   {
       cout << "Exit not found in maze!" << endl;
       return;
   }
   //clears visited cells in the maze
   maze.resetVisited();
   //resets the parent tracking for path reconstruction
   solver.resetParent();
   //clear any previously marked path
   PathMarker::resetPath(maze);

   bool found = solver.dfs(startRow, startCol);
   if(found)
   {
       vector<Cell> path = solver.reconstructPath(exit_Row, exit_Col);
       PathMarker::mark_Path(maze, path);
       cout << "Path found using DFS :" << endl;
       maze.printMaze();
   }
   else
    cout << "No path found using DFS." << endl;
}


void Menu::SolveUsingBFS()
{
   if(startRow == -1 || startCol == -1)
   {
       cout << "Maze not initialized. Input maze first" << endl;
       return;
   }

   if(exit_Row == -1 || exit_Col == -1)
   {
       cout << "Exit not found in maze!" << endl;
       return;
   }
   //clear visited cells
   maze.resetVisited();
   //resets the parent tracking
   solver.resetParent();
   //clear previous marked path
   PathMarker::resetPath(maze);

   bool found = solver.bfs(startRow, startCol);
   if(found)
   {
       vector<Cell> path = solver.reconstructPath(exit_Row, exit_Col);
       PathMarker::mark_Path(maze, path);
       cout << "Path found using BFS :" << endl;
       maze.printMaze();
   }
   else
    cout << "No path found using BFS." << endl;
}



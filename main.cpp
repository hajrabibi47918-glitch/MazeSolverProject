#include <iostream>
#include "Maze.h"
#include "Solver.h"
#include "Menu.h"

using namespace std;

int main() {
    // Create a menu with maze size, for example 5x5
    Menu menu(5, 5);

    // Start the program
    menu.start();

    return 0;
}

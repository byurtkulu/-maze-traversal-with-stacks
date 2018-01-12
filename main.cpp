//
//  main.cpp
//  maze_solver
//
//  Created by Bahadır on 26.10.2017.
//  Copyright © 2017 Bahadir. All rights reserved.
//

#include <iostream>

#include <iostream>
#include <string>
#include <vector>
#include "linkedStack.hpp"
using namespace std;


void check_around (vector<vector<int>> &maze, Stack &stack) {
    
    // Current coordinates.
    int x = stack.get_x();
    int y = stack.get_y();
    
    
    // First check if we find an exit.
    bool is_out = (maze[x+1][y] == 9) || (maze[x-1][y] == 9) || (maze[x][y+1] == 9) || (maze[x][y-1] == 9);
    
    // Check and push the exit coordinate
    if (is_out){
        
        cout << "Maze Solved!" << endl;
        
        // add the exit into the stack.
        if (maze[x+1][y] == 9)
            stack.push(x+1, y);
        else if (maze[x-1][y] == 9)
            stack.push(x-1, y);
        else if (maze[x][y+1] == 9)
            stack.push(x, y+1);
        else if (maze[x][y-1] == 9)
            stack.push(x, y-1);
            
        
        // Print the stack here...
        cout << "Printing the stack: " << endl;
        stack.print();
        return; // To make sure it is out of recursion
    }
    
    
    // Check north
    else if (maze[x-1][y] == 0) {
        maze[x][y] = 1;
        stack.push(x-1, y);
        //cout << "Added: " << x-1 << " " << y << endl;
        check_around(maze, stack);
    }
    
    // Check east
    else if (maze[x][y+1] == 0) {
        maze[x][y] = 1;
        stack.push(x, y+1);
        //cout << "Added: " << x << " " << y+1 << endl;
        check_around(maze, stack);
    }
    // Check south
    else if (maze[x+1][y] == 0) {
        maze[x][y] = 1;
        stack.push(x+1, y);
        //cout << "Added: " << x+1 << " " << y << endl;
        check_around(maze, stack);
    }
    // Check west
    else if (maze[x][y-1] == 0) {
        maze[x][y] = 0;
        stack.push(x, y-1);
        //cout << "Added: " << x << " " << y-1 << endl;
        check_around(maze, stack);
    }
    
    // We have a dead end.
    // pop the stack and check again for possible ways.
    else {
        stack.pop();
        maze[stack.get_prev_x()][stack.get_prev_y()] = 1;
        //cout << "Dead end! Going back!" << endl;
        check_around(maze, stack);
    }
    
    
}




int main() {
    /*
     Take inputs and construct matrix.
     */
    
    
    
    int size_x, size_y;
    int start_x, start_y;
    cin >> size_x >> size_y;
    cin >> start_x >> start_y;
    
    struct mazeNode {
        int val;
        bool visited;
    };
    
    vector<vector<int>> maze(size_x, vector<int>(size_y));
    int value;
    
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            cin.clear();
            cin >> value;
            maze[i][j] = value;
        }
    }
    
    // Print matrix ect.
    cout << endl;
    cout << size_x << " " << size_y << endl;
    cout << start_x << " " << start_y << endl;
    
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    
    // Label start with 2
    maze[start_x][start_y] = 2;
    
    // label exits with 9
    for (int i = 0; i < size_x; i++) {
        if (maze[i][0] == 0)
            maze[i][0] = 9;
        if (maze[i][size_y-1] == 0)
            maze[i][size_y-1] = 9;
    }
    
    for (int i = 0; i < size_y; i++) {
        if (maze[0][i] == 0)
            maze[0][i] = 9;
        if (maze[size_x-1][i] == 0)
            maze[size_x-1][i] = 9;
    }
    
    // Start!
    
    Stack stack(start_x, start_y); // push start index as start index
    
    int x = start_x;
    int y = start_y;
    
    // Check around and move.
    if (x == 0){
        stack.push(x+1, y);
    }
    else if (x == size_x-1) {
        stack.push(x-1, y);
    }
    else if (y == 0) {
        stack.push(x, y+1);
    }
    else if (y == size_y-1) {
        stack.push(x, y-1);
    }
    
    //cout << "First step: " << stack.get_x() << " " << stack.get_y() << endl;
    
    
    // When a coordinate is visited, make its value 1. So be sure that you will never visit it again.
    maze[stack.get_x()][stack.get_y()] = 1;
    
    // Start the recursive function.
    check_around(maze, stack);
    
    
    
    
    
    
    
    return 0;
}



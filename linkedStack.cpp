//
//  linkedStack.cpp
//  maze
//
//  Created by Bahadır on 25.10.2017.
//  Copyright © 2017 Bahadir. All rights reserved.
//

#include "linkedStack.hpp"

// Default Constructor
Stack::Stack() {
    top = new stackNode();
}

// Constructor
Stack::Stack(int init_x, int init_y) {
    top = new stackNode(init_x, init_y);
}

// Destructor
Stack::~Stack() {
    if (top->up != NULL) {
        delete top->up;
        top->up = NULL;
    }
    while (top->down != NULL){
        top = top->down;
        delete top->up;
        top->up = NULL;
    }
    delete top;
}

// Add new element. Erase the previous up node.
void Stack::push(int x, int y) {
    stackNode * temp = top->up;
    top->up = NULL;
    delete temp;
    
    top->up = new stackNode(x,y);
    top->up->down = top;
    top = top->up;
}

// move top down
void Stack::pop() {
    if (top->up != NULL) {
        delete top->up;
        top->up = NULL;
    }
    top = top->down;
}


int Stack::get_x() {
    return top->x;
}

int Stack::get_y() {
    return top->y;
}

int Stack::get_prev_x() {
    return top->up->x;
}

int Stack::get_prev_y() {
    return top->up->y;
}

void Stack::print() {
    stackNode * printer = top;
    
    while (printer->down != NULL) {
        printer = printer->down;
    }
    
    while (printer != top->up) {
        cout << printer->x << " " << printer->y << endl;
        printer = printer->up;
    }
}















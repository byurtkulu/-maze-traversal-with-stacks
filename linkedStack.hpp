//
//  linkedStack.hpp
//  maze
//
//  Created by Bahadır on 25.10.2017.
//  Copyright © 2017 Bahadir. All rights reserved.
//

#ifndef linkedStack_hpp
#define linkedStack_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

struct stackNode {
    stackNode* down;
    stackNode* up;
    int x;
    int y;
    
    
    stackNode()
    :x(0), y(0),up(NULL), down(NULL)
    {}
    
    stackNode(int x1, int y1)
    :x(x1), y(y1), up(NULL), down(NULL)
    {}
    
};

class Stack {
    
    stackNode * top;
    
public:
    Stack();
    Stack(int init_x, int init_y);
    ~Stack();
    
    void pop(); // remove the top element (LIFO).
    void push(int x, int y); // add new element.
    int get_x(); // returns x value of the top.
    int get_y(); // gives y value of the top.
    int get_prev_x();
    int get_prev_y();
    
    void print();
    
};



#endif /* linkedStack_hpp */

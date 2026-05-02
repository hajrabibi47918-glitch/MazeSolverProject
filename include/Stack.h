#ifndef STACK_H
#define STACK_H
#include <vector>
#include "Solver.h"

using namespace::std;

//structure of Node
 struct Node
        {
            Cell data;
            Node* next;
            //constructor
            Node(const Cell& value):data(value),next(NULL)
            {
            }
        };

class Stack
{
    //public methods
    public:
        //constructor
        Stack();
        //destructor
        ~Stack();
        //checks if empty or not
        bool isEmpty()const;
        //add value
        void push(const Cell& value);
        //delete value
        void pop();
        //return top of stack
        Cell top() const;

    protected:

    //private attribute
    private:
        //tope node of stack
        Node* topNode;

};

#endif // STACK_H

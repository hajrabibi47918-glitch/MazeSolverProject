#ifndef QUEUE_H
#define QUEUE_H
#include <vector>

#include "Stack.h"


class Queue
{
    //public methods
    public:
        //constructor
        Queue();
        //destructor
        ~Queue();
        //checks if empty or not
        bool isEmpty()const;
        //add value
        void enqueue(const Cell& value);
        //delete value
        void dequeue();
        //returns front
        Cell front() const;

    protected:
    //private attributes
    private:
        //front
        Node* frontNode;
        //end
        Node* rearNode;
};

#endif // QUEUE_H

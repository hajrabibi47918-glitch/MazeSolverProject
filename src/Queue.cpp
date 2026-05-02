#include "Queue.h"
#include <iostream>
#include "Stack.h"

using namespace std;
//constructor
Queue::Queue()
{
    frontNode = NULL;
    rearNode = NULL;
}
//destructor
Queue::~Queue()
{
    while(!isEmpty())
        dequeue();
}
//checks empty of not
bool Queue::isEmpty()const
{
    if(frontNode == NULL)
        return true;
    else
        return false;
}
//add value
void Queue::enqueue(const Cell& value)
{
    Node* newNode = new Node(value);
    newNode->data = value;
    newNode->next = NULL;
    if(isEmpty())
    {
        frontNode = rearNode = newNode;
    }
    else
    {
        rearNode->next = newNode;
        rearNode = newNode;
    }
}
//delete value
void  Queue::dequeue()
{
    if(isEmpty())
        return;
    Node* tmp = frontNode;
    frontNode = frontNode->next;
    delete tmp;
    if(frontNode == NULL)
        rearNode = NULL;
}
//return front
Cell Queue::front()const
{
    if(isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return Cell(-1,-1);
    }
    return frontNode->data;
}

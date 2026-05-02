#include "Stack.h"
#include <iostream>

using namespace std;

//constructor
Stack::Stack()
{
    topNode = NULL;
}

//destructor
Stack::~Stack()
{
    while(!isEmpty())
        pop();
}
//checks if empty or not
bool Stack::isEmpty()const
{
    if(topNode == NULL )
        return true;
    else
        return false;
}
//add value
void Stack::push(const Cell& value)
{
    Node* newNode = new Node(value);
    newNode->data = value;
    newNode->next = topNode;
    topNode = newNode;
}
//delete value
 void Stack::pop()
 {
     if(isEmpty())
        return;
     Node* tmp = topNode;
     topNode = topNode->next;
     delete tmp;
 }
//returns the top
 Cell Stack::top()const
 {
     if(isEmpty())
     {
         cout << "Stack is empty!" << endl;
         return Cell(-1,-1);
     }
     return topNode->data;
 }

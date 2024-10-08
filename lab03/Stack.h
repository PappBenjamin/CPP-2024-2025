#ifndef LAB3_STACK_H
#define LAB3_STACK_H

#include <iostream>
#include "List.h"

using namespace std;


class Stack{

public:

        /* creates an empty stack */
        Stack();

        Stack(int size);

/* destroys this stack */
        ~Stack();

        void push(int d);

        int pop();

        bool isEmpty() const;

        void print() const;

private:

       typedef struct Node
       {
           int value;
           Node *next;
       } Node;

       static Node * createNode(int d)
       {
           Node *n = new Node;
           n->value = d;
           n->next = nullptr;
           return n;
       }

       Node *top;
       int size;
       int nodeCounter;
};


#endif //LAB3_STACK_H

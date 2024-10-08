#include "Stack.h"

Stack::Stack()
{
    this->top = nullptr;
    this->size = 100;
    this->nodeCounter = 0;
}

Stack::Stack(int size)
{
    this->top = nullptr;
    this->size = size;
    this->nodeCounter = 0;
}

Stack::~Stack() {
    while(this->top != nullptr)
    {
        Node *temp = this->top;
        this->top = this->top->next;
        delete temp;
    }
}

void Stack::push(int d)
{
    if(this->nodeCounter >= this->size){throw overflow_error("Stack is full");}

    Node *temp = createNode(d);
    temp->next = this->top;
    this->top = temp;

    this->nodeCounter++;
}

int Stack::pop()
{

    if(isEmpty()){throw domain_error("Stack is empty");}

    Node *temp = this->top;
    int d = this->top->value;
    this->top = this->top->next;
    delete temp;
    return d;
}

bool Stack::isEmpty() const
{
   if(this->top == nullptr)
   {
       return true;
   }

   return false;
}

void Stack::print() const
{
        Node *temp = this->top;

        while(temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
}



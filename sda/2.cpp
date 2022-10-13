#include <iostream>
using namespace std;

struct stack
{
    int data;
    stack *next;
};

stack *push(stack *&top, int x)
{
    stack *t = new stack;
    t->data = x;
    t->next = top;
    top = t;
    return top;
}

int pop(stack *&top)
{
    if (top == NULL)
    {
        return -1;
    }
    stack *p;
    int x = top->data;
    p = top;
    top = top->next;
    delete (p);
    return x;
}

void display(stack *top)
{
    stack *curr = top;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    stack *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    display(top);
    cout << pop(top) << endl;
    cout << pop(top) << endl;
    cout << pop(top) << endl;
    return 0;
}
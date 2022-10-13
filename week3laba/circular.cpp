#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void insertAtTail(node *&tail, int x)
{
    node *n = new node(x);
    if (tail == NULL)
    {
        n->next = n;
        tail = n;
        return;
    }
    n->next = tail->next;
    tail->next = n;
    tail = n;
}

void insertAtHead(node *&tail, int x)
{
    node *n = new node(x);
    if (tail == NULL)
    {
        n->next = n;
        tail = n;
        return;
    }
    n->next = tail->next;
    tail->next = n;
}

void display(node *tail)
{
    node *temp = tail->next;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "\n";
}

int main()
{
    node *tail = NULL;
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    display(tail);
    return 0;
}
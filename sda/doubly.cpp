#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *next;
    node *prev;
    node(int x)
    {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

void reverse(node *&head){
    node* temp;
    node* curr = head;
    while(curr!=NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if(temp!=NULL){
        head = temp->prev;
    }
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    return;
}

void display(node* head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    reverse(head);
    display(head);
    return 0;
}
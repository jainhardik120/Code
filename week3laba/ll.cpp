#include <bits/stdc++.h>
using namespace std;

struct node{
    node* next;
    int val;
};

void insertAtTail(node* &head, int val){
    node* n = new node;
    n->val = val;
    n->next = NULL;
    if(head==NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
}

void display(node* head){
    while(head!=NULL){
        cout << head->val << " ";
        head=head->next;
    }
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);
    return 0;
}
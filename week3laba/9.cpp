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

void insertAtBegin(node *&head, int x)
{
    node *n = new node(x);
    n->next = head;
    head = n;
    return;
}

void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtEnd(node *&head, int x)
{
    node *n = new node(x);
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
}

int count(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

node* findOdd(node* head){
    while(head!=NULL){
        if(head->data%2==1){
            return head;
        }
        head=head->next;
    }
    return NULL;
}

void rearrange(node* &head){
    node* temp = head;
    int odd = 0;
    int even = 0;
    while(temp!=NULL){
        if(temp->data%2==0){
            even++;
        } else {
            odd++;
        }
        temp = temp->next;
    }
    node* evenhead = head;
    node* oddhead = head;
    while(odd){
        evenhead=evenhead->next;
        odd--;
    }
    while(oddhead!=evenhead){
        if(oddhead->data%2==0){
            evenhead = findOdd(evenhead);
            if(evenhead==NULL){
                return;
            }
            int tempval = evenhead->data;
            evenhead->data = oddhead->data;
            oddhead->data = tempval;
        }
        oddhead=oddhead->next;
    }
}

int main()
{
     node *head = NULL;
    insertAtEnd(head, 8);
    insertAtEnd(head, 3);
    insertAtEnd(head, 6);
    insertAtEnd(head, 5);
    insertAtEnd(head, 4);
    insertAtEnd(head, 2);
    insertAtEnd(head, 5);
    insertAtEnd(head, 3);
    display(head);
    rearrange(head);
    display(head);
    return 0;
}
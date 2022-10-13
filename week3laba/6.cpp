#include <iostream>
#include<climits>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node(int x)
  {
      data=x;
      next=NULL;
  }
}*head;

void display(Node* head)
{
    Node*curr = head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

Node* begin(Node*head, int x)
{
    Node*temp = new Node(x);
    temp ->next = head;
    return temp;
}

Node* end(Node* head, int x)
{
    if(head==NULL)
    {
        return new Node(x);
    }
    Node* curr = head;
    while(curr->next!=NULL)
    {
        curr = curr-> next;
    }
    curr-> next = new Node(x);
    return head;
}

int count(Node* head)
{
    Node* p = head;
    if(p==0)
    {
        return 0;
    }
    else
    {
        return count(p->next)+1;
    }
}

int sum(Node* head)
{
    Node* p = head;
    int sum = 0;
    while(p!=NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}
int max(Node* head)
{
    Node* p = head;
    int m = INT_MIN;
    while(p!=NULL)
    {
        if(p->data>m)
        {
            m = p->data;
            p = p->next;
        }
    }
    return m;
}

Node* search(Node* head , int key)
{
    Node* p = head;
    while(p!=NULL)
    {
        if(key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

Node* insert(Node* head ,int x,int pos)
{
    Node* t = new Node(x);
    Node* p = head;
    t->data = x;
    if(pos==0)
    {
        t->next=p;
        p=t;
        return p;
    }
    else if(pos>0){
     for(int i=0; i<pos-1; i++) 
     {
      p = p->next;
     }
     t->next = p->next;
     p->next = t;
    }
}
int main() {
    Node* head=new Node(-1);
    Node* temp=head;
    for(int i=0; i<10; i++)
    {
      int x;
      cin>>x;
      Node* n = new Node(x);
      temp->next=n;
      temp=n;
    }
    head=head->next;
    display(head);
    head = begin(head,0);
    head = end(head,30);
    display(head);
    cout<<endl;
    cout<<"Number of elements : "<<count(head);
    cout<<endl;
    cout<<"Sum of element : "<<sum(head);
    cout<<endl;
    cout<<"Max element : "<<max(head);
    cout<<endl;
    cout<<"After insertion : ";
    head = insert(head,10,1);
    display(head);
    cout<<endl;
    cout<<"Searched element : ";
    head = search(head,10);
    display(head);

    return 0;
}
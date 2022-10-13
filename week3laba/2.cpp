#include <iostream>

using namespace std;

class node{
public:
    int data;
    node* next;
    node(int val){
        data= val;
        next = NULL;
    }
};

node* concatenate(node* t1, node* t2){
    node* h1 = t1->next;
    node* h2 = t2->next;
    t1->next = h2;
    t2->next = h1;
    return t2;
}

void display(node* tail){
    node* temp = tail;
    do{
        temp=temp->next;
        cout << temp->data << " ";

    } while(temp!=tail);
    cout << endl;
}

int main(){
    node* tail = new node(4);
    tail->next = new node(1);
    tail->next->next = new node(2);
    tail->next->next->next = new node(3);
    tail->next->next->next->next = tail;
    display(tail);
    node* tail2 = new node(8);
    tail2->next = new node(5);
    tail2->next->next = new node(6);
    tail2->next->next->next = new node(7);
    tail2->next->next->next->next = tail2;
    display(tail2);
    node* t3 = concatenate(tail,tail2);
    display(t3);
}
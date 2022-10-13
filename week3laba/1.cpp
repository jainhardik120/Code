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

void deleteNode(node* &tail, int key){
    node* temp = tail;
    if(temp->data==key){
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=tail->next;
        delete tail;
        tail=temp;
        return;
    }
    while(temp->next->data!=key){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;
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
    deleteNode(tail, 3);
    display(tail);
}
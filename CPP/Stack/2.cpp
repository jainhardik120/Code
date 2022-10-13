#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* next;
    int val;
    Node(int x){
        next = NULL;
        val = x;
    }
};

class MyStack{
    Node* head;
    int stsize;
    public:
    MyStack(){
        head = NULL;
        stsize = 0;
    }
    void push(int val){
        Node* temp = new Node(val);
        temp->next = head;
        stsize++;
        head = temp;
    }
    int peek(){
        if(head==NULL){
            cout << "StackUnderflow\n";
            return -1;
        }
        return head->val;
    }
    int pop(){
        if(head==NULL){
            cout << "StackUnderflow\n";
            return -1;
        }
        Node* todelete = head;
        int res = head->val;
        head = head->next;
        stsize--;
        delete todelete;
        return res;
    }
    bool isEmpty(){
        return (head==NULL);
    }
    int size(){
        return stsize;
    }
};

int main()
{
    MyStack* st = new MyStack();
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);
    st->push(6);
    while(!st->isEmpty()){
        cout << st->pop() << " ";
    }
    return 0;
}
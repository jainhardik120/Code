#include <iostream>

using namespace std;

struct node{
    node* next;
    int data;
    node(int x){
        next = NULL;
        data = x;
    }
};

void insertAtEnd(node* &head, int x){
    node* n = new node(x);
    if(head==NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
    return;
}

void display(node* head){
    while(head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
    return;
}

void createCycle(node* &head, int i){
    node* last = head;
    node* temp = head;
    while(i--){
        temp=temp->next;
    }
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = temp;
    return;
}

bool isCyclePresent(node* &head){
    node* fast = head;
    node* slow = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    int temp;
    node* head = NULL;
    cout << "Enter no. of elements in linked list : ";
    cin >> n;
    cout << "Enter linked list: ";
    for(int i=0; i<n; i++){
        cin >> temp;
        insertAtEnd(head, temp);
    }
    cout << "Linked list is: ";
    display(head);
    cout << "Do you want to create cycle or not? (y/n): ";
    char choice;
    cin >> choice;
    if(choice=='y' || choice=='Y'){
        int i;
        cout << "Enter index where you want to create cycle: ";
        cin >> i;
        createCycle(head, i);
    }
    //display(head);
    if(isCyclePresent(head)){
        cout << "Yes cycle present\n";
    } else {
        cout << "No cycle detected\n";
    }
    return 0;
}

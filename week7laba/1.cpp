#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *next;
    int amt;
    int dist;
    node(int a, int d)
    {
        amt = a;
        dist = d;
        next = NULL;
    }
};

void insertAtTail(node *&tail, int amt, int dist)
{
    node *n = new node(amt, dist);
    if (tail == NULL)
    {
        tail = n;
        tail->next = tail;
        return;
    }
    n->next = tail->next;
    tail->next = n;
    tail = tail->next;
}

void display(node *tail)
{
    node *temp = tail;
    do
    {
        temp = temp->next;
        cout << "(" << temp->amt << ", " << temp->dist << "), ";
    } while (temp != tail);
}

int main()
{
    int n;
    cin >> n;
    node *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        insertAtTail(tail, a, b);
    }
    for (int i = 0; i < n; i++)
    {
        int count = i;
        node* temp = tail->next;
        while(count--){
            temp=temp->next;
        }
        node* temp2 = temp;
        int petrolLeft = 0;
        int count2 = 0;
        do{
            petrolLeft+= temp->amt;
            petrolLeft-= temp->dist;
            temp=temp->next;
            count2++;
        } while ((petrolLeft>=0)  && (temp != temp2));
        if(count2==n){
            cout << i;
            break;
        }
    }
    
    return 0;
}
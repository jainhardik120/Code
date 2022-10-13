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

void findPairs(node *head, int x)
{
    set <pair<int, int>> s1;

    int c = count(head);
    int pairs = 0;
    for (int i = 0; i < c - 1; i++)
    {
        node *temp = head;
        int j = i;
        while (j > 0)
        {
            temp = temp->next;
            j--;
        }
        int v1 = temp->data;
        while (temp->next != NULL)
        {
            if (v1 + temp->next->data > x)
            {
                int a = v1;
                int b = temp->next->data;
                s1.insert(pair<int,int> (max(a,b), min(a,b)));
            }
            temp = temp->next;
        }
    }
    for (auto i : s1)
    {
        cout << i.first << " " << i.second << "\n";
    }
    
}

int main()
{
    node *head = NULL;
    insertAtEnd(head, 8);
    insertAtEnd(head, 3);
    insertAtEnd(head, 1);
    insertAtEnd(head, 5);
    insertAtEnd(head, 7);
    insertAtEnd(head, 2);
    insertAtEnd(head, 5);
    insertAtEnd(head, 3);
    display(head);
    findPairs(head, 10);
    return 0;
}
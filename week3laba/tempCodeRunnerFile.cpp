#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;

        next = NULL;
    }
} * head;
void display(Node *head_temp)
{
    Node *curr = head_temp;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}
Node *insertNodeatEND(Node *head_temp, int key)
{
    Node *temp = new Node(key);
    if (head_temp == NULL)
    {
        head_temp = temp;
        return head_temp;
    }
    Node *curr = head_temp;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head_temp;
}
Node *removedupli(Node *head_temp)
{
    Node *start = head_temp;
    Node *curr = head_temp;
    Node *prev = head_temp;
    int data;
    while (curr != NULL)
    {
        start = head_temp;
        data = curr->data;
        while (start && start != curr)
        {
            if (start->data == data)
            {
                // delete
                if (curr->next == NULL)
                {
                    prev->next = NULL;
                }
                prev->next = curr->next;
                break;
            }
            start = start->next;
        }
        prev = curr;
        curr = curr->next;
    }
    return head_temp;
}
int main()
{
    cout << "Enter elements: ";
    int key;
    for (int i = 1; i < 6; i++)
    {
        cin >> key;
        head = insertNodeatEND(head, key);
    }
    cout << "\nInitial list: ";
    display(head);
    head = removedupli(head);
    cout << "\nFinal List: ";
    display(head);
}
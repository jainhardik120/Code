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
} * head, *head1;
Node *insertNodeatEND(Node *head_temp, int key)
{
    Node *temp = new Node(key);
    if (head_temp == NULL)
    {
        head_temp = temp;
        temp->next = temp;
        return head_temp;
    }
    Node *curr = head_temp->next;
    while (curr->next != head_temp && curr != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = head_temp;
    return head_temp;
}
void display(Node *head_temp)
{
    Node *curr = head_temp;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
        if (curr == head_temp)
        {
            break;
        }
    }
}
Node *halves(Node *head_temp, int listsize)
{
    Node *curr1, *curr2;
    curr1 = curr2 = head_temp;
    for (int i = 1; i < (listsize / 2) + 1; i++)
    {
        curr2 = curr2->next;
    }
    head1 = curr2;
    while (curr2->next != head_temp)
    {
        curr2 = curr2->next;
    }
    curr2->next = NULL;
    for (int i = 1; i < (listsize / 2); i++)
    {
        curr1 = curr1->next;
    }
    curr1->next = NULL;
    return head_temp;
}
int main()
{
    int key;
    cout << "Enter ELements: ";
    for (int i = 1; i <= 6; i++)
    {
        cin >> key;
        head = insertNodeatEND(head, key);
    }
    cout << "\nInitial list is: ";
    display(head);
    cout << "\nLists after Halving: " << endl;
    head = halves(head, 6);
    display(head);
    cout << " \n";
    display(head1);
    return 0;
}
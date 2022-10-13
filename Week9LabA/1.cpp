#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int val;
    node *next;
    node *child;
    node(int x)
    {
        val = x;
        next = NULL;
        child = NULL;
    }
};
void horizontalFlatten(node *head)
{
    node *temp = head;
    queue<node *> st;
    while (temp != NULL || !st.empty())
    {
        if (temp == NULL)
        {
            temp = st.front();
            st.pop();
        }
        cout << temp->val << " ";
        if (temp->child != NULL)
        {
            st.push(temp->child);
        }
        temp = temp->next;
    }
}
int main()
{
    node *head = new node(10);
    head->child = new node(4);
    head->child->next = new node(20);
    head->child->next->child = new node(2);
    head->child->next->next = new node(13);
    head->child->next->next->child = new node(16);
    head->child->next->next->child->child = new node(3);
    head->next = new node(5);
    head->next->next = new node(12);
    head->next->next->next = new node(7);
    head->next->next->next->child = new node(17);
    head->next->next->next->child->next = new node(6);
    head->next->next->next->child->child = new node(9);
    head->next->next->next->child->child->next = new node(8);
    head->next->next->next->child->child->child = new node(19);
    head->next->next->next->child->child->child->next = new node(15);
    head->next->next->next->next = new node(11);
    horizontalFlatten(head);
    return 0;
}
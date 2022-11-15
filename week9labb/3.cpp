#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    node *left;
    node *right;
    node(char val){
        data = val;
    }
};

node *add(char a[], int l, int i)
{
    if (i > l)
    {
        return NULL;
    }
    else
    {
        node *n = new node(a[i]);
        n->left = add(a, l, 2 * i + 1);
        n->right = add(a, l, 2 * i + 2);
        return n;
    }
}

void levelOrder(node *root)
{
    if (root == NULL)
        return;

    queue<node*> q;
    q.push(root);
    while (q.empty() == false) {
        node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
 
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

void printGivenLevel(struct node* root, int level, int ltr);
int height(struct node* node);
 
void printSpiral(struct node* root)
{
    int h = height(root);
    int i;
    bool ltr = false;
    for(i = 1; i <= h; i++)
    {
        printGivenLevel(root, i, ltr);
        ltr = !ltr;
    }
}
 
void printGivenLevel(struct node* root, int level, int ltr)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
         
    else if (level > 1)
    {
        if (ltr)
        {
            printGivenLevel(root->left, level - 1, ltr);
            printGivenLevel(root->right, level - 1, ltr);
        }
        else
        {
            printGivenLevel(root->right,  level - 1, ltr);
            printGivenLevel(root->left, level - 1, ltr);
        }
    }
}

int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        if (lHeight > rHeight)
            return (lHeight + 1);
        else
            return (rHeight + 1);
    }
}
int main()
{
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    int b = sizeof(a) / sizeof(char);
    node *root = add(a, b, 0);
    cout << "Level Order : ";
    levelOrder(root);
    cout << "\nSpiral Order : ";
    printSpiral(root);
    return 0;
}

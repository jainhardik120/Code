#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
node *minValueNode(node *root);
node *deleteNode(node *root, int data);
void badd(node *&root, int i)
{
    if (root == NULL)
    {
        node *n = new node;
        n->data = i;
        n->left = NULL;
        n->right = NULL;
        root = n;
        return;
    }
    else
    {
        if (i > root->data)
        {
            badd(root->right, i);
        }
        else
        {
            badd(root->left, i);
        }
    }
}
node *minValueNode(node *root)
{
    node *current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
node *deleteNode(node *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        else if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inOrder(node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
int main()
{
    int a[] = {10, 20, 30, 40, 50, 40, 35, 23, 20, 40, 18, 19, 22, 27, 30, 27};
    int b = sizeof(a) / sizeof(int);
    int c;
    node *root = NULL;
    for (int i = 0; i < b; i++)
    {
        badd(root, a[i]);
    }
    inOrder(root);
    cout << "\nEnter node value you want to delete : ";
    cin >> c;
    root = deleteNode(root, c);
    inOrder(root);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
void preOrder(node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(node *root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

node *constructTree(int a[], int n)
{
    node *root = NULL;
    queue<node *> q;
    int j = 0;
    while (j < n)
    {
        if (root == NULL)
        {
            node *n = new node;
            n->left = NULL;
            n->right = NULL;
            n->data = a[j++];
            root = n;
            q.push(root);
        }
        else
        {
            node *temp2 = q.front();
            q.pop();
            if (a[j] != 0)
            {
                node *n = new node;
                n->left = NULL;
                n->right = NULL;
                n->data = a[j];
                j++;
                temp2->left = n;
                q.push(temp2->left);
            }
            else
            {
                j++;
            }
            if (a[j] != 0)
            {
                node *n = new node;
                n->left = NULL;
                n->right = NULL;
                n->data = a[j];
                j++;
                temp2->right = n;
                q.push(temp2->right);
            }
            else
            {
                j++;
            }
        }
    }
    return root;
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

int sum(node *root, int v, vector<int> &a)
{
    if (root == NULL)
    {
        return 0;
    }
    v += root->data;
    if (root->left == NULL && root->right == NULL)
    {
        a.push_back(v);
        return v;
    }
    return sum(root->left, v, a) + sum(root->right, v, a);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 0, 8, 9, 0, 0, 0, 10, 11, 12, 13, 0, 14, 15, 0, 16, 17};
    int b = sizeof(a) / sizeof(int);
    node *root = constructTree(a, b);
    cout << "Preorder : ";
    preOrder(root);
    cout << endl;
    cout << "Inorder : ";
    inOrder(root);
    cout << endl;
    cout << "Postorder : ";
    postOrder(root);
    cout << endl;
    cout << "Levelorder : ";
    levelOrder(root);
    return 0;
}

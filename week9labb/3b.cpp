#include <bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    node *left;
    node *right;
    node(char val){
        data = val;
        left = right = NULL;
    }
    node(){
        left = right = NULL;
    }
};

node* constructTree(char a[], int l){
    queue<node*> q;
    node* root = new node(a[0]);
    q.push(root);
    int i = 1;
    while(i<l){
        node* tmp = q.front();
        q.pop();
        tmp->left = new node(a[i++]);
        tmp->right = new node(a[i++]);
        q.push(tmp->left);
        q.push(tmp->right);
    }
    return root;
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main()
{
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    int b = sizeof(a) / sizeof(char);
    node* root = constructTree(a, b);
    inOrder(root);
    return 0;
}
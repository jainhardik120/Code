#include <bits/stdc++.h>
using namespace std;

struct node{
    char data;
    node* left;
    node* right;

    node(char x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout << root->data<< " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data<< " ";
    inorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data<< " ";
}

int main()
{
    node* a = new node('^');
    a->left = new node('c');
    a->right = new node('d');
    node* b = new node('-');
    b->left = a;
    b->right = new node('e');
    node *c = new node('*');
    c->left = new node('g');
    c->right = new node('h');
    node* d = new node('+');
    d->left = new node('f');
    d->right = c;
    node* e = new node('^');
    e->left = b;
    e->right = d;
    node* f = new node('*');
    f->left = new node('b');
    f->right = e;
    node* g = new node('+');
    g->left = new node('a');
    g->right = f;
    node* root = new node('-');
    root->left = g;
    root->right = new node('i');
    inorder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
    return 0;
}
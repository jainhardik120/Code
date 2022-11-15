#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *left, *right;
};

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    if (lheight > rheight)
    {
        return lheight + 1;
    } else {
        return rheight + 1;
    }
}

void printLevel(node* root, int level){
    if(level==0) return;
    if(level==1){
        cout << root->val << " ";
        return;
    }
    if(level>1){
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
}

void printLevelOrder(node* root){
    for (int i = 1; i <= height(root); i++)
    {
        printLevel(root, i);
        cout << "\n";
    }
    
}

void itrInOrder(node* root){
    stack<node*> st;
    node* curr = root;
    while(!st.empty() || curr!=NULL){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->val;
        curr = curr->right;
    }
}

void itrPostOrder(node* root){
    stack<node*> s1, s2;
    s1.push(root);
    node* tmp;
    while(!s1.empty()){
        tmp = s1.top();
        s1.pop();
        if(tmp->left)
            s1.push(tmp->left);
        if(tmp->right)
            s1.push(tmp->right);
        s2.push(tmp);
    }
    while(!s2.empty()){
        tmp = s2.top();
        s2.pop();
        cout << tmp->val << " ";
    }
}

void itrPreOrder(node* root){
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        node* tmp = s.top();
        s.pop();
        if(tmp->left)
            s.push(tmp->left);
        if(tmp->right)
            s.push(tmp->right);
        cout << tmp->val << " ";
    }
}

node* newNode(int data)
{
    node* Node = new node();
    Node->val = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return (Node);
}

int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    itrInOrder(root);
    cout << "\n";
    itrPreOrder(root);
    cout << "\n";
    itrPostOrder(root);
    cout << "\n";
    return 0;
}
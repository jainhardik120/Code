#include <iostream>
#include <queue>
using namespace std;

struct node{
    int val;
    node* lchild;
    node* rchild;
    node(int x){
        val = x;
        lchild = NULL;
        rchild = NULL;
    }
    node(){
        lchild = NULL;
        rchild = NULL;
    }
};

void insertInBT(node*&root, int* arr, int n){
    queue<node*> q;
    q.push(root);
    for (int i = 1; i < n; i++)
    {
        node* temp = q.front();
        q.pop();
        if(arr[i]!=0){
            temp = new node(arr[i]);
            q.push(temp->lchild);
            q.push(temp->rchild);
        }
    }
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    cout << root->val << " ";
}

int main()
{
    node* root = NULL;
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertInBT(root, arr, n);
    postorder(root);
    return 0;
}
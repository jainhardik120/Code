#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
    node(){
        left = NULL;
        right = NULL;
    }
};

// node* search(node*root, int val){
//     node* temp = root;
//     while((temp->lchild!=NULL && temp->rchild!=NULL) || temp->val!=val || temp!=NULL){
//         if(temp->val==val){
//             return temp;
//         } else if(temp->val>val){
//             temp = temp->lchild;
//         } else if(temp->val<val){
//             temp = temp->rchild;
//         }
//     }
//     return NULL;
// }


node* search(node*root, int val){
    if(root==NULL){
        return NULL;
    }
    if(root->val == val){
        return root;
    }
    if(root->val>val){
        return search(root->left, val);
    }
    if(root->val<val){
        return search(root->right, val);
    }
    return NULL;
}

node* deleteInBST(node* root, int val){
    if(val<root->val){
        root->left = deleteInBST(root->left, val);
    }

}

void insert(node*&root, int val){
    if(!root){
        root = new node(val);
        return;
    }
    if(val>root->val){
        insert(root->right, val);
        return;
    }
    if(val<root->val){
        insert(root->left, val);
        return;
    }
}

void inOrder(node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main()
{
    node* root = NULL;
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inOrder(root);
    cout << "\n";
    node* searched = search(root, 30);
    inOrder(searched->left);
    cout << "\n";
    inOrder(searched->right);
    cout << "\n";
    return 0;
}
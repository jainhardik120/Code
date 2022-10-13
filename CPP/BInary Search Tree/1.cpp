#include <bits/stdc++.h>
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
        return search(root->lchild, val);
    }
    if(root->val<val){
        return search(root->rchild, val);
    }
    return NULL;
}

node* deleteInBST(node* root, int val){
    if(val<root->val){
        root->lchild = deleteInBST(root->lchild, val);
    }

}

void insert(node*&root, int val){
    if(!root){
        root = new node(val);
        return;
    }
    if(val>root->val){
        insert(root->rchild, val);
        return;
    }
    if(val<root->val){
        insert(root->lchild, val);
        return;
    }
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->lchild);
    cout << root->val << " ";
    inorder(root->rchild);
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
    inorder(root);
    cout << "\n";
    node* searched = search(root, 30);
    inorder(searched->lchild);
    cout << "\n";
    inorder(searched->rchild);
    cout << "\n";
    return 0;
}
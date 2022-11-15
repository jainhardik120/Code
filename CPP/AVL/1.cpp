#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    int height;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
        height = 1;
    }
    node(){
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int height(node* n){
    if(n==NULL) return 0;
    return n->height;
}

int max(int a, int b){
    return (a > b)? a : b;
}

int main(){
    
    return 0;
}
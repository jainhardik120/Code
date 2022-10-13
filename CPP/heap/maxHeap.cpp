#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void insert(vector<int> arr, int n, int val){
    n++;
    arr[n] = val;
    int i = n;
    while(i>1){
        int parent = i/2;
        if(arr[parent]<arr[i]){
            swap(arr, parent, i);
            i=parent;
        } else {
            return;
        }
    }
}

int main()
{
    vector<int> arr = {-1, 50, 30, 40, 10, 20, 25, 15};
    return 0;
}
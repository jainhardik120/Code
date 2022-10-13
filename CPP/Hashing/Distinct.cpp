#include <bits/stdc++.h>
using namespace std;

int countDistinct(int arr[], int n)
{
    unordered_set<int> u;
    for (int i = 0; i < n; i++)
    {
        u.insert(arr[i]);
    }
    return u.size();
}

int setUnion(int arr1[], int arr2[], int m, int n){
    unordered_set<int> u;
    for (int i = 0; i < m; i++)
    {
        u.insert(arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        u.insert(arr2[i]);
    }
    return u.size();
}
int intersection(int arr1[], int arr2[], int m, int n){
    unordered_set<int> u;
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        u.insert(arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        auto x = u.find(arr2[i]);
        if(x!=u.end()){
            count++;
            u.erase(x);
        }
    }
    return count;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 1, 3, 5};
    int arr2[] = {9, 4, 7, 4, 10, 3, 5};
    cout << countDistinct(arr1, 7) << endl;
    cout << setUnion(arr1, arr2, 7, 7) << endl;
    cout << intersection(arr1, arr2, 7, 7) << endl;
    return 0;
}
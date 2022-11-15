#include <bits/stdc++.h>
using namespace std;

void partition(int *arr, int n, int a, int b){
    int* newArray = new int[n];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<a)
            newArray[k++] = arr[i]; 
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>=a && arr[i]<=b)
            newArray[k++] = arr[i]; 
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>b)
            newArray[k++] = arr[i]; 
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = newArray[i];
    }
    delete[] newArray;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int a,b;
    cin >> a >> b;
    partition(arr, n, a,b);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int linearSearch(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {3, 4, 1, 5, 7, 8, 2};
    cout << linearSearch(arr, 9, 5);
    return 0;
}
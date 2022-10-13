#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int a, int b, int key)
{
    if (a > b)
    {
        return -1;
    }
    int mid = (a + b) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, b, key);
    }
    if (arr[mid] > key)
    {
        return binarySearch(arr, a, mid - 1, key);
    }
    return -1;
}

int main()
{

    return 0;
}
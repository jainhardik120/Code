#include <bits/stdc++.h>
using namespace std;

void countingSort(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int *countArr = new int[max + 1];
    int *outputArr = new int[n];
    for (int i = 0; i < max + 1; i++)
    {
        countArr[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        countArr[arr[i]]++;
    }
    for (int i = 1; i < max + 1; i++)
    {
        countArr[i] += countArr[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        outputArr[countArr[arr[i]]-- - 1] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = outputArr[i];
    }
    delete[] countArr;
    delete[] outputArr;
}

int main()
{
    int arr[] = {3, 4, 1, 5, 7, 8, 4, 1, 2};
    countingSort(arr, sizeof(arr) / sizeof(int));
    for (auto i : arr)
    {
        cout << i << " ";
    }
    
    return 0;
}
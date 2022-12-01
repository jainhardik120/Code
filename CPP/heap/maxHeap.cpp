#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void insert(vector<int> &arr, int val)
{
    arr.push_back(val);
    // Index of last inserted value
    int n = arr.size() - 1;
    int i = n;
    while (i)
    {
        int parent = i / 2;
        if (arr[parent] < arr[i])
        {
            swap(arr, parent, i);
            i = parent;
        }
        else
        {
            return;
        }
    }
}

void removeRoot(vector<int> &arr)
{
    int n = arr.size() - 1;
    arr[0] = arr[n];
    arr.pop_back();
    n--;
    int i = 0;
    while (i < n)
    {
        int left = arr[(2 * i) + 1];
        int right = arr[(2 * i) + 2];
        int larger = (left > right) ? ((2 * i) + 1) : ((2 * i) + 2);
        if (arr[i] < arr[larger])
        {
            swap(arr, i, larger);
            i = larger;
        }
        else
        {
            return;
        }
    }
}

void printArray(vector<int> arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> arr;
    insert(arr, 10);
    printArray(arr);
    insert(arr, 20);
    printArray(arr);
    insert(arr, 30);
    printArray(arr);
    insert(arr, 40);
    printArray(arr);
    insert(arr, 50);
    printArray(arr);
    insert(arr, 60);
    printArray(arr);
    insert(arr, 70);
    printArray(arr);
    insert(arr, 80);
    printArray(arr);
    removeRoot(arr);
    printArray(arr);
    removeRoot(arr);
    printArray(arr);
    removeRoot(arr);
    // cout << "fa" << "\n";
    printArray(arr);
    removeRoot(arr);
    printArray(arr);
    removeRoot(arr);
    printArray(arr);
    removeRoot(arr);
    printArray(arr);
    removeRoot(arr);
    printArray(arr);
    return 0;
}
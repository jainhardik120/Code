#include <bits/stdc++.h>
using namespace std;
void print(int arr[])
{
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}
void bubblesort(int arr[], int n)
{

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int mi = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[mi] > arr[j])
            {
                mi = j;
            }
        }
        int temp = arr[mi];
        arr[mi] = arr[i];
        arr[i] = temp;
    }
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
            else
            {
                break;
            }
        }
    }
}
void mergeTwoSOrtedArray(int arr[], int mid, int lo, int high)
{
    int b[high + 1];
    int i = lo, j = mid + 1, k = lo;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = arr[j];
        k++;
        j++;
    }
    for (int i = lo; i <= high; i++)
    {
        arr[i] = b[i];
    }
}
int partition(int arr[], int pi, int lo, int hi)
{
    int i = lo;
    int j = lo;
    while (i <= hi)
    {
        if (arr[i] <= pi)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return (j - 1);
}
void quicksort(int arr[], int lo, int hi)
{
    if (lo > hi)
    {
        return;
    }
    int pivot = arr[hi];
    int pi = partition(arr, pivot, lo, hi);
    quicksort(arr, lo, pi - 1);
    quicksort(arr, pi + 1, hi);
}

void mergeSort(int arr[], int lo, int high)
{
    if (lo < high)
    {
        int mid = (lo + high) / 2;
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid + 1, high);
        mergeTwoSOrtedArray(arr, mid, lo, high);
    }
}

int main()
{
    int arr[] = {2, 3, 1, 4, 7, 8, 3};
    print(arr);
    cout << endl;
    quicksort(arr, 0, 6);
    print(arr);
}

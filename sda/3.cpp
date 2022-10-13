#include <iostream>
using namespace std;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int a[], int s, int e)
{
    int i = s;
    int pivot = a[e];
    for (int j = s; j <= e - 1; j++)
    {
        if (a[j] < pivot)
        {
            swap(&a[i], &a[j]);
            i++;
        }
    }
    swap(&a[i], &a[e]);
    return i;
}
void quicksort(int a[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(a, s, e);
    quicksort(a, s, p - 1);
    quicksort(a, p + 1, e);
}

int main()
{
    int a[] = {2, 6, 3, 8, 7, 4};
    quicksort(a, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
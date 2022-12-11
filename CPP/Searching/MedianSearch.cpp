#include<iostream> 
using namespace std;

int median(int A[], int l, int r, int k)
{
    int index, flag = 0;
    while (l < r)
    {
        int ind = r - l + 1;
        index = rand() % ind;
        int i, j = 0, m = 0, n = 0;
        int S1[10], S3[10], S2[1];
        for (i = 0; i <= r; i++)
        {
            if (A[i] < A[index])
            {
                S1[j] = A[i];
                j++;
            }
            else if (A[i] == A[index])
            {
                S2[n] = A[i];
                n++;
            }
            else
            {
                S3[m] = A[i];
                m++;
            }
        }
        if (j > k)
        {
            for (int y = 0; y < j; y++)
            {
                A[y] = S1[y];
                r = j - 1;
            }
        }
        else if ((j + n) >= k)
        {
            return A[index];
        }
        else
        {
            for (int y = 0; y < m; y++)
            {
                A[y] = S3[y];
                r = m - 1;
                k = k - (j + n);
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15, 8, 12, 6};
    int n = sizeof(arr) / sizeof(arr[0]), k = 3;
    int element = median(arr, 0, n - 1, k);
    cout << "K'th smallest element is " << element;
    return 0;
}
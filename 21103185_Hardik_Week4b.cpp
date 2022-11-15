#include <iostream>
using namespace std;

bool linearSearch(int *arr, int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }
    return false;
}

bool binarySearch(int *arr, int size, int key)
{
    int l = 0, h = size - 1, mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == key)
        {
            return true;
        }
        else if (arr[mid] > key)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return false;
}

int kSmallest(int A[], int l, int r, int k)
{
    {
        int ind = r - l + 1;
        int index = rand() % ind;
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

        if (j >= k)
        {
            return (kSmallest(S1, 0, j - 1, k));
        }
        else if ((j + n) >= k)
            return A[index];
        else
            return (kSmallest(S3, 0, m - 1, k - (j + n)));
    }
}

int kGreatest(int A[], int l, int r, int k)
{
    {
        int ind = r - l + 1;
        int index = rand() % ind;
        int i, j = 0, m = 0, n = 0;
        int S1[10], S3[10], S2[1];
        for (i = 0; i <= r; i++)
        {
            if (A[i] > A[index])
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

        if (j >= k)
        {
            return (kGreatest(S1, 0, j - 1, k));
        }
        else if ((j + n) >= k)
            return A[index];
        else
            return (kGreatest(S3, 0, m - 1, k - (j + n)));
    }
}

int interpolationSearch(int *arr, int size, int x)
{
    int pos, lo = 0, hi = size - 1;
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        if (arr[pos] == x)
            return pos;
        else if (arr[pos] < x)
            lo = pos + 1;
        else if (arr[pos] > x)
            hi = pos - 1;
    }
    return -1;
}

int stringsearch(string str[], int size, string k)
{
    for (int i = 0; i < size; i++)
    {
        if (str[i] == k)
        {
            return i;
        }
    }
    return -1;
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
    int key;
    cin >> key;
    if (linearSearch(arr, n, key))
    {
        cout << "Number is found!!";
    }
    else
    {
        cout << "Number is found!!";
    }
    if (binarySearch(arr, n, key))
    {
        cout << "Number is found!!";
    }
    else
    {
        cout << "Number is found!!";
    }
    cout << key << "th smallest number is " << kSmallest(arr, 0, n - 1, key);
    cout << key << "th greatest number is " << kGreatest(arr, 0, n - 1, key);
    cout << key << " appear at index " << interpolationSearch(arr, n, key);


    int num;
    cin >> num;
    string a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string k;
    cin >> k;
    int ans = stringsearch(a, num, k);
    if (ans == -1)
    {
        cout << "String not found !!";
    }
    else
    {
        cout << "string found in index " << ans;
    }

    return 0;
}
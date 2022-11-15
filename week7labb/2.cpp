#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int curr_min)
{
    int paintersRequired = 1;
    int curr_sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > curr_min)
            return false;
        if (curr_sum + arr[i] > curr_min) {
            paintersRequired++;
            curr_sum = arr[i];
            if (paintersRequired > m)
                return false;
        }
        else
            curr_sum += arr[i];
    }
    return true;
}

int findTime(int arr[], int n, int m)
{
    long long sum = 0;
    if (n < m)
        return -1;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int start = 0, end = sum;
    int result = INT_MAX;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid)) {
            result = mid;
            end = mid - 1;
        }

        else
            start = mid + 1;
    }
    return result;
}
int main()
{
    int arr[] = { 5, 10, 30, 20, 15 };
    int n = sizeof arr / sizeof arr[0];
    int m = 3;

    cout << "Minimum number = "
         << findTime(arr, n, m) << endl;
    return 0;
}

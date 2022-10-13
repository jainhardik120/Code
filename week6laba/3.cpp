#include <bits/stdc++.h>
using namespace std;

int power(int n, int m)
{
    if (m == 0)
    {
        return 1;
    }
    return n * power(n, m - 1);
}

int seriesSum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return power(n, n) + seriesSum(n - 1);
}

int main()
{
    // cout << seriesSum(2) << endl;
    // cout << seriesSum(3) << endl;
    int a;
    cout << "Enter n : ";
    cin >> a;
    cout << "Series sum is : " << seriesSum(a) << endl;
    return 0;
}
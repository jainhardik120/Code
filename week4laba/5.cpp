#include <bits/stdc++.h>
using namespace std;
void hailstone(int n)
{
    cout << n << " ";
    if (n == 1)
    {
        return;
    }
    if (n % 2 != 0)
    {
        hailstone((3 * n) + 1);
    }
    else
    {
        hailstone(n / 2);
    }
}
int main()
{
    int n;
    cin >> n;
    hailstone(n);
    return 0;
}
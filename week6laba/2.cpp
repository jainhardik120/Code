#include <bits/stdc++.h>
using namespace std;

int lcmRecursive(int a, int b, int c, int d)
{
    if (c % a == 0 && c % b == 0)
    {
        return c;
    }
    else
    {
        return lcmRecursive(a, b, c + d, d);
    }
}

int lcm(int a, int b)
{
    return lcmRecursive(a, b, max(a, b), min(a,b));
}

int main()
{
    // cout << lcm(5, 2);
    int a, b;
    cout << "Enter two numbers : ";
    cin >> a >> b;
    cout << "LCM is : " << lcm(a, b) << endl;
    return 0;
}
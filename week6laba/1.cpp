#include <bits/stdc++.h>
using namespace std;

int product(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }
    if (b < 0)
    {
        return (-a + product(a, b + 1));
    }
    return (a + product(a, b - 1));
}

int main()
{
    // cout << product(5, 3) << endl;
    // cout << product(5, -3) << endl;
    // cout << product(-5, 3) << endl;
    // cout << product(-5, -3) << endl;
    int a, b;
    cout << "Enter two numbers : ";
    cin >> a >> b;
    cout << "Product is : " << product(a, b) << endl;
    return 0;
}
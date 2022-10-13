#include <iostream>

using namespace std;
int a[11][11];
void s1et(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
}
bool check(int n, int r, int j)
{
    for (int i = r - 1; i > -1; i--)
    {
        if (a[i][j] == 1)
        {
            return false;
        }
    }
    int k = j - 1, l = j + 1;
    for (int i = r - 1; i > -1; i--)
    {
        if (a[i][k--] == 1)
        {
            return false;
        }
        if (a[i][l++] == 1)
        {
            return false;
        }
    }
    return true;
}
void QUEEN(int n, int r)
{
    if (r == n)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < r; j++)
            {
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            if (check(n, r, j))
            {
                a[r][j] = 1;
                QUEEN(n, r + 1);
                a[r][j] = 0;
            }
        }
    }
}
void PLACE(int n)
{
    s1et(n);
    QUEEN(n, 0);
}
int main()
{
    int n;
    cin >> n;
    PLACE(n);
    return 0;
}
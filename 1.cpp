#include <iostream>
using namespace std;
void print(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
    }
    cout << endl;
}
bool possible(int **a, int x, int y, int n)
{
    for (int i = x - 1; i >= 0; i--)
    {
        if (a[i][y] == 1)
        {
            return false;
        }
    }
    int k = y - 1;
    for (int i = x - 1; i >= 0; i--)
    {
        if (a[i][k--] == 1)
        {
            return false;
        }
    }
    k = y + 1;
    for (int i = x - 1; i >= 0; i--)
    {
        if (a[i][k++] == 1)
        {
            return false;
        }
    }
    return true;
}
void NQ(int **a, int n, int x)
{
    if (x == n)
    {
        print(a, n);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!possible(a, x, i, n))
        {
            continue;
        }
        a[x][i] = 1;
        NQ(a, n, x + 1);
        a[x][i] = 0;
    }
}
void nQueen(int n)
{
    int **a = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        a[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            a[i][j] = 0;
        }
    }
    NQ(a, n, 0);
}
int main()
{
    int n;
    cin >> n;
    nQueen(n);
    
    return 0;
}
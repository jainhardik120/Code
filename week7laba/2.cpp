#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        int *arrX = new int[n];
        int *arrY = new int[n];
        int *arrA = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arrX[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arrY[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arrA[i];
        }
        int radius = 1;
        while (1)
        {
            int noOfPoints = 0;
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (pow((arrX[i] * arrX[i] + arrY[i] + arrY[i]), 0.5) < radius)
                {
                    sum += arrA[i];
                    noOfPoints++;
                }
            }
            if (sum >= p)
            {
                cout << radius;
                break;
            }
            if (noOfPoints == n)
            {
                cout << -1;
                break;
            }
            radius++;
        }
    }
    return 0;
}
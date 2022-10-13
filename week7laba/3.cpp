#include <bits/stdc++.h>
using namespace std;

struct fan{
    char name[20];
    int quotient;
};

void sort(fan arr[], int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (arr[j].quotient<arr[j+1].quotient || (arr[j].quotient==arr[j+1].quotient && strcmp(arr[j].name,arr[j+1].name)>0))
            {
                fan temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n, t;
    cin >> n >> t;
    fan* fans = new fan[n];
    for (int i = 0; i < n; i++)
    {
        cin >> fans[i].name >> fans[i].quotient;
    }
    sort(fans,n);
    for (int i=0;i<t;i++)
    {
        cout << fans[i].name << endl;
    }
    return 0;
}


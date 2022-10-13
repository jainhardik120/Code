#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int min = INT_MAX;
    for (auto i : arr)
    {
        if(i<min){
            min = i;
        }
    }
    int secMin = INT_MAX;
    for (auto i : arr)
    {
        if(i<secMin && i>min){
            secMin=i;
        }
    }
    cout << secMin;
    return 0;
}
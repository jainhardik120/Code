#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    vector<int> freq(10, 0);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (auto i : arr)
    {
        freq[i]++;
    }
    for (int i = 0; i < 10; i++)
    {
        if(freq[i]>0)
            cout << i << " occurs " << freq[i] << " times" << endl;
    }
    
    return 0;
}
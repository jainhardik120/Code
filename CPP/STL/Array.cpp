#include <bits/stdc++.h>
using namespace std;

int main()
{
    array<int, 4> ar = {1,2,3,4};
    for (int i = 0; i < ar.size(); i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
    cout << ar.at(2) << endl;
    cout << ar.empty() << endl;
    cout << ar.front() << endl;
    cout << ar.back() << endl;
    return 0;
}
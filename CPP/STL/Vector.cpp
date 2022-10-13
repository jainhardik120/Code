#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a;
    cout << a.capacity() << endl;
    a.push_back(1);
    cout << a.capacity() << endl;
    a.push_back(2);
    cout << a.capacity() << endl;
    a.push_back(3);
    cout << a.capacity() << endl;
    
    return 0;
}
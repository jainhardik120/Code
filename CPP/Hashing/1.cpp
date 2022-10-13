#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(7);
    cout << s.count(10);
    if(s.count(9)==0){
        cout << "Not present" << endl;
    }
    s.erase(10);
    s.erase(s.begin(), s.end());
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void sortstack(stack<int> &s1)
{
    if (s1.empty())
    {
        return;
    }
    int k = s1.top();
    s1.pop();
    sortstack(s1);
    vector<int> v1;
    while (!s1.empty())
    {
        if (k > s1.top())
        {
            break;
        }
        v1.push_back(s1.top());
        s1.pop();
    }
    s1.push(k);
    for (int i = v1.size() - 1; i >= 0; i--)
    {
        s1.push(v1.at(i));
    }
}
int main()
{
    stack<int> s1;
    int n;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        s1.push(t);
    }
    sortstack(s1);
    cout << "Top element" << s1.top() << endl
         << "Stack s1:\n";
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    return 0;
}
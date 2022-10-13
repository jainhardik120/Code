#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - 1 - i])
        {
            return false;
        }
    }
    return true;
}
void partition(string s)
{
    map<char, int> mp;
    stack<char> s1;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp.find(s[i]) == mp.end())
        {
            mp[s[i]] = i;
            s1.push(s[i]);
        }
        else
        {
            string t = "";
            t += s[i];
            while (s1.top() != s[i])
            {
                t = s1.top() + t;
                mp.erase(mp.find(s1.top()));
                s1.pop();
            }
            t = s1.top() + t;
            mp.erase(mp.find(s1.top()));
            s1.pop();
            if (ispalindrome(t))
            {
                while (!s1.empty())
                {
                    t = " " + t;
                    t = s1.top() + t;
                    mp.erase(mp.find(s1.top()));
                    s1.pop();
                }
                cout << t;
            }
        }
    }
    string o = "";
    while (!s1.empty())
    {
        o = s1.top() + o;
        o = " " + o;
        s1.pop();
    }
    cout << o << endl;
}
int main()
{
    string s;
    cin >> s;
    partition(s);
    return 0;
}
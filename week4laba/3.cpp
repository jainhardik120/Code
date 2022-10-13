#include <bits/stdc++.h>
using namespace std;
string reverse(string s)
{
    if (s[0] == '\0')
    {
        return "";
    }
    char k = s[0];
    s = reverse(s.substr(1)) + k;
    return s;
}
int main()
{
    string s;
    cin >> s;
    s = reverse(s);
    cout << s << endl;
    return 0;
}
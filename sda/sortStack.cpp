#include <bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int> &s){
    stack<int> t;
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        while(!t.empty() && t.top()<temp){
            s.push(t.top());
            t.pop();
        }
        t.push(temp);
    }
    return t;
}

int main()
{
    stack<int> s;
    s.push(26);
    s.push(23);
    s.push(12);
    s.push(45);
    s.push(65);
    s.push(93);
    s.push(14);
    s = sortStack(s);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
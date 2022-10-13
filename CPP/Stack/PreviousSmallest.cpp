#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4,10,5,8,20,15,3,12};
    stack<int> st;
    for (int i = 0; i < 8; i++)
    {
        int curr = arr[i];
        while(1){
            if(st.empty()){
                cout << "-1 ";
                st.push(curr);
                break;
            }
            if(st.top()<curr){
                cout << st.top() << " ";
                st.push(curr);
                break;
            } else {
                st.pop();
            }
        }
    }
    return 0;
}
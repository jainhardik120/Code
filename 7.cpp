#include <bits/stdc++.h>
using namespace std;

void rearrangeStack(stack<int> &st, int *arr, int n)
{
    stack<int> temp;
    for (int i = n - 1; i > -1; i--)
    {
        int key = arr[i];
        while (st.top() != key)
        {
            temp.push(st.top());
            st.pop();
        }
        int tempKey = st.top();
        st.pop();
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        st.push(tempKey);
    }
}

int main()
{
    stack<int> st;
    st.push(6);
    st.push(4);
    st.push(1);
    st.push(2);
    st.push(5);
    st.push(3);
    int arr[] = {2, 5, 6, 3, 1, 4};
    rearrangeStack(st, arr, 6);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
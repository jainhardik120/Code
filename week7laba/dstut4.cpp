#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
void printNumbers(int n)
{
    if (n == 0)
    {
        return;
    }

    printNumbers(n - 1);
    cout << n << " ";
}
void printNum(int n)
{
    stack<int> st;
    for (int i = 50; i >= 1; i--)
    {
        st.push(i);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
int sumNatural(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return n + sumNatural(n - 1);
}
int sumDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int lastDigit = n % 10;
    n = n / 10;
    return lastDigit + sumDigits(n);
}
string reverseString(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    return reverseString(s.substr(1)) + s[0];
}
bool isPalindrome(string s)
{
    string r = reverseString(s);
    if (s == r)
    {
        return 1;
    }
    return 0;
}
void bubbleSort(int *arr)
{
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    cout << "Q1" << endl;
    printNumbers(50);
    cout << endl;
    printNum(50);
    cout << endl;

    cout << "Q2" << endl;
    cout << sumNatural(5) << endl;
    cout << endl;

    cout << "Q3" << endl;
    cout << "Sum of digits of 152 is " << sumDigits(152) << endl;
    cout << endl;

    cout << "Q4" << endl;
    cout << isPalindrome("nitin") << endl;
    cout << endl;

    cout << "Q5" << endl;
    stack<pair<int, string>> s1;
    s1.push(pair<int, string>(1, "Rohit"));
    s1.push(pair<int, string>(4, "Bibhas"));
    s1.push(pair<int, string>(6, "Sanchit"));
    s1.push(pair<int, string>(7, "Harsh"));
    s1.push(pair<int, string>(8, "Piyush"));

    while (!s1.empty())
    {
        if ((s1.top()).first < 5)
        {
            break;
        }
        cout << (s1.top()).second << " ";
        s1.pop();
    }
    cout << endl;
    cout << endl;

    cout << "Q6" << endl;
    int arr[] = {11, 12, 15, 16, 14, 18, 12, 19, 52, 58, 65, 75, 95, 85};
    bubbleSort(arr);
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "4th largest marks: " << arr[n - 4] << endl;
    cout << "4th smallest marks: " << arr[3] << endl;
    cout << "If sorted in descending order then traverse from last element and print till element become less than 15" << endl;
}

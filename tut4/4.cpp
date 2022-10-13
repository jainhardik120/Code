#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(char* str, int a, int b){
    if(a>b){
        return true;
    }
    if(str[a]!=str[b]){
        return false;
    }
    return isPalindrome(str, a+1, b-1);
}

int main()
{
    char* str = "maam";
    cout << isPalindrome(str, 0, 3);
    return 0;
}
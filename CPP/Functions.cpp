#include <bits/stdc++.h>
using namespace std;

// void sum(int a, int b){
//     cout << a << " + " << b << " = " << (a+b) << endl;
// }

// void multiply(int a, int b){
//     cout << a << "*" << b << "=" << (a*b) << endl;
// }

int sumOfN(int n){
    int sum = 0;
    for (int i = 1; i <= n ; i++)
    {
        sum+=i;
    }
    return sum;
}

int main()
{
    // multiply(1,1);
    // multiply(1,2);
    cout << sumOfN(10) << endl;
    cout << sumOfN(15) << endl;
    cout << sumOfN(20) << endl;

    return 0;
}
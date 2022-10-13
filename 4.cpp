#include <iostream>
#include <cmath>
using namespace std;

int ans(){
    int a = 1000212121;
    int mod = (int)(pow(10, 9));
    return a % mod;
}

int main()
{
    cout << ans();
    return 0;
}
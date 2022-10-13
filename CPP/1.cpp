#include<iostream>
#include<string>
using namespace std;

// int sum(int a, int b){
//     int s = a+b;
//     return s;
// }

int main(){
    // int a, b;
    // cout << "Hardik Jain" << endl;
    // cin >> a >> b;
    // cout << a << " " << b << endl;


    // int 10
    // double 10.000
    // float 10.123
    // char 'A' 
    // string "Hardik Jain"
    // int a = 5;
    // int b = 10;

    // if(a > b){

    // } else if(a==b){

    // } else {

    // }

    // while(a>b){

    // }

    // for(int i =0; i < 10; i++){
    //     cout << i << " ";
    // }

    // int a = 2;
    // switch(a){
    //     case 1:
    //     cout << "One" << endl;
    //     break;
    //     case 2:
    //     cout << "Two" << endl;
    //     break;
    //     case 3:
    //     cout << "Three" << endl;
    //     break;
    //     default:
    //     cout << "Default" << endl;
    //     break;

    // }


    // if(a==b){

    // }
    // if(a!=b){

    // }

    // 10%7=3
    // 16%7=2
    // 14%7=0
    
    int a;
    cin >> a;
    a = a%7;
    // int char

    switch (a)
    {
    case 0:
        cout << "Sunday" << endl;
        break;
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    default:
        break;
    }

    return 0;
}
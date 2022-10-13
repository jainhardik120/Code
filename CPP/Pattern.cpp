#include <iostream>
using namespace std;

int main()
{
    /*

    int 5
    for(){

    }

    *
    **
    ***
    ****
    *****



    */


   // 0 1
   // 1 2
   // 2 3
    int a = 10;
    int b = 15;

    // a-1 = 2
    
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if(i==0 || i==a-1 || j==0 || j==b-1){
                cout << (j);
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }


    /*
    i = 0
        j =0 *
        j =1 *
        j =2 *
        j =3 *
        j= 4 *
        cout << endl;
    i = 1
        j =0 " "
        j =1 " "
        j =2 " "
        j =3 " "
        j= 4 " "
        cout << endl;
    i = 2
        j =0 *
        j =1 *
        j =2 *
        j =3 *
        j= 4 *
        cout << endl;
    
    */
    return 0;
}
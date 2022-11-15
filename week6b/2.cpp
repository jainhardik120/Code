#include <iostream>
using namespace std;
void floor_ceil(int *arr, int siz, int key)
{
    int low = 0;
    int high = siz - 1;
    int mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (key == *(arr + mid))
        {
            if (mid > 0)
                cout << "Floor value: " << *(arr + mid - 1) << endl;
            else
                cout << "Floor Value does not exist" << endl;
            if (mid < siz - 1)
                cout << "Ceiling val: " << *(arr + mid + 1) << endl;
            else
                cout << "Ceiling value doesnot exist" << endl;
            return;
        }
        else if (key > *(arr + mid))
        {
            low = mid + 1;
            /*if(high-low==1)
            {
            cout<<"Floor value: "<<*(arr+low)<<endl;
            cout<<"Ceiling vl: "<<*(arr+high)<<endl;
            return;
            }*/
            if (low == high)
            {
                if (*(arr + low) < key)
                    cout << "Floor val: " << *(arr + low) << endl;
                else
                    cout << "Floor not exist";
                if (key > *(arr + siz - 1))
                {
                    if (*(arr + high) > key)
                        cout << "Ceil val" << (arr + high) << endl;
                    else
                        cout << "Ceil not exist" << endl;
                }
                else
                {
                    if (*(arr + high + 1) > key)
                        cout << "Ceil val" << (arr + high + 1) << endl;
                    else
                        cout << "Ceil not exist" << endl;
                }
                return;
            }
        }
        else if (key < *(arr + mid))
        {
            high = mid - 1;
            /*if(high-low==1)
            {
            cout<<"Floor value: "<<*(arr+low)<<endl;
            cout<<"Ceiling vl: "<<*(arr+high)<<endl;
            return;
            }*/
            if (low == high)
            {
                if (*(arr + low) < key)
                    cout << "Floor val: " << *(arr + low);
                else
                    cout << "Floor not exist" << endl;
                if (key < *(arr))
                {
                    if (*(arr + high) > key)
                        cout << "Ceil val: " << *(arr + high) << endl;
                    else
                        cout << "Ceil not exist" << endl;
                }
                else
                {
                    if (*(arr + high + 1) > key)
                        cout << "Ceil val: " << *(arr + high + 1) << endl;
                    else
                        cout << "Ceil not exist" << endl;
                }
                return;
            }
        }
    }
}
int main()
{
    int array[] = {1, 2, 11, 13, 14, 22, 30};
    int *arr = array;
    floor_ceil(arr, 7, 13);
    return 0;
}

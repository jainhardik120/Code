#include <iostream>
using namespace std;
void bblsort(int *arr, int siz)
{
    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j < siz - 1 - i; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
    cout << "Sorted array is: ";
    for (int i = 0; i < siz; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
void error_check(int *arr, int siz)
{
    for (int i = 0; i < siz; i++)
    {
        if (i + 1 != *(arr + i))
        {
            cout << i + 1 << " is missing!" << endl;
            cout << *(arr + i) << " repeats twice." << endl;
            return;
        }
    }
}
int main()
{
    int array[] = {1, 8, 7, 4, 6, 4, 2, 3};
    int *arr = array;
    bblsort(arr, 8);
    error_check(arr, 8);
    return 0;
}

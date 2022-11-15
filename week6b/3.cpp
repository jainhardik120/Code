#include <iostream>
using namespace std;
void diff(int *arr, int siz, int n)
{
    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j < siz; j++)
        {
            if (*(arr + i) - *(arr + j) == n || *(arr + j) - *(arr + i) == n)
            {
                cout << "pair found:" << *(arr + i) << " " << *(arr + j) << endl;
                return;
            }
        }
    }
}
int main()
{
    int array[] = {1, 2, 11, 13, 14, 22, 30};
    int *arr = array;
    diff(arr, 7, 9);
    return 0;
}

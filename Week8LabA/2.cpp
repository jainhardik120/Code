#include <iostream>
using namespace std;

int hashingFunc(int val, int pos){
    return((val+pos)%7);
}


int main()
{
    int *arr = new int[8];
    for (int i = 0; i < 8; i++)
    {
        arr[i] = 0;
    }
    int initalArr[] = {50,700,76,85,92,73,101,70};
    for (int i = 0; i < 8; i++)
    {
        int initPos=0;
        while(1){
            int pos = hashingFunc(initalArr[i], initPos);
            if(arr[pos]==0){
                arr[pos] = initalArr[i];
                break;
            }else{
                initPos++;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
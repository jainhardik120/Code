#include <iostream>
using namespace std;

int hashingFunc(int val, int pos){
    return((val+pos)%9);
}


int main()
{
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 0;
    }
    int initalArr[] = {14,18,24,20,3,23,33,15};
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
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void avg(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    float avg = (float)sum/n;
    cout << "Average is : " << avg << endl;
}

void freq(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    vector<int> freq(10, 0);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (auto i : arr)
    {
        freq[i]++;
    }
    for (int i = 0; i < 10; i++)
    {
        if(freq[i]>0)
            cout << i << " occurs " << freq[i] << " times" << endl;
    }
}

void rotation(){
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int temp = arr[0];
    for (int i = 0; i < n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
    cout << "After rotation : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void secondSmallest(){
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int min = INT_MAX;
    for (auto i : arr)
    {
        if(i<min){
            min = i;
        }
    }
    int secMin = INT_MAX;
    for (auto i : arr)
    {
        if(i<secMin && i>min){
            secMin=i;
        }
    }
    cout << secMin << endl;
}

int main()
{
    avg();
    freq();
    rotation();
    secondSmallest();
    return 0;
}
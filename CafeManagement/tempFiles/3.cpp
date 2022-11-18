#include <iostream>
#include <fstream>
#include <time.h>
#include "type.h"
using namespace std;

int main()
{
    fstream file("17112022.dat", ios::in | ios::out | ios::binary);
    order od;
    file.read((char*) &od, sizeof(order));
    cout << od.orderId << "\n" << od.total << "\n";
    tm *ptm = localtime(&od.time);
    cout << ptm->tm_mon << " " << ptm->tm_mday << "\n";
    return 0;
}
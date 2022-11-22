#include <iostream>
#include "type.h"
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    foodItem fi[2];
    ofstream wf("new/menu.dat", ios::binary);
    for (int i = 0; i < 2; i++)
    {
        fi[i].itemId = i+1;
        fi[i].isAvailable = true;
        fi[i].isPackaged = false;
        fi[i].quantityAvailable = -1;
        fi[i].price = 20.00;
        strcpy(fi[i].size, "Large");
        wf.write((char*) &fi[i], sizeof(foodItem));
    }
    foodItem fi2[2];
    for (int i = 0; i < 2; i++)
    {
        fi2[i].itemId = i+1+2;
        fi2[i].isAvailable = true;
        fi2[i].isPackaged = true;
        fi2[i].quantityAvailable = 10;
        fi2[i].price = 20.00;
        strcpy(fi2[i].size, "Large");
        wf.write((char*) &fi2[i], sizeof(foodItem));
    }
    wf.close();
    return 0;
}
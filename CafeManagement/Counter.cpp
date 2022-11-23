#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <time.h>
#include "type.hpp"
using namespace std;

vector<int> pendingOrders;

int refreshList()
{
    pendingOrders.clear();
    char fileName[14];
    time_t timeNow;
    time(&timeNow);
    tm *ptm = localtime(&timeNow);
    sprintf(fileName, "%02d%02d%04d.dat", ptm->tm_mday, ptm->tm_mon + 1, 1900 + ptm->tm_year);
    fstream file(fileName, ios::in | ios::out | ios::binary);
    int ordersCount;
    if (file)
    {
        file.seekg(0, ios::end);
        ordersCount = (file.tellg() / sizeof(order));
    }
    else
    {
        ordersCount = 0;
    }
    file.close();
    if (ordersCount < 0)
    {
        ordersCount = 0;
    }
    fstream rf(fileName, ios::in | ios::out | ios::binary);
    order *temp = new order();
    for (int i = 0; i < ordersCount; i++)
    {
        rf.read((char *)temp, sizeof(order));
        if (temp->orderStatus == 3)
        {
            pendingOrders.push_back(temp->orderId);
        }
    }
    return 1;
}

void updateOrderAt(int orderId)
{
    char fileName[14];
    time_t timeNow;
    time(&timeNow);
    tm *ptm = localtime(&timeNow);
    sprintf(fileName, "%02d%02d%04d.dat", ptm->tm_mday, ptm->tm_mon + 1, 1900 + ptm->tm_year);
    fstream file(fileName, ios::in | ios::out | ios::binary);
    file.seekg((orderId - 1) * (sizeof(order)), ios::beg);
    order *od = new order();
    file.read((char *)od, sizeof(order));
    od->orderStatus = 4;
    file.seekp((orderId - 1) * (sizeof(order)), ios::beg);
    file.write((char *)od, sizeof(order));
    file.close();
}

int mainMenu()
{
    system("cls");
    cout << "These orders are prepared and ready to be served: \n";
    for (int i = 0; i < pendingOrders.size(); i++)
    {
        cout << pendingOrders[i] << " ";
    }
    cout << "\n\nEnter order id to remove from list (-1 to exit program, 0 to refresh list): ";
    int tempId;
    cin >> tempId;
    if (tempId == -1)
    {
        return -1;
    }
    else if (tempId == 0)
    {
        refreshList();
        return 1;
    }
    else
    {
        vector<int>::iterator index = pendingOrders.end();
        for (auto i = pendingOrders.begin(); i < pendingOrders.end(); i++)
        {
            if (*i == tempId)
            {
                index = i;
                break;
            }
        }
        if (index == pendingOrders.end())
        {
            cout << "Sorry, this order doesn\'t exist in list\n";
            printf("\n\nPress any key to continue...\n");
            getch();
            return 1;
        }
        updateOrderAt(tempId);
        pendingOrders.erase(index);
    }
    return 1;
}

int main()
{
    refreshList();
    while (1)
    {
        int i = mainMenu();
        if (i == -1)
        {
            break;
        }
    }
    return 0;
}
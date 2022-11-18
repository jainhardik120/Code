#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstring>
#include <time.h>
#include "type.h"
#include <queue>
using namespace std;

queue<order *> orderQueue;
vector<foodItem *> itemsInMenu;
int lastCount = 0;

void clearMenu()
{
    for (int i = 0; i < itemsInMenu.size(); i++)
    {
        delete itemsInMenu[i];
    }
    itemsInMenu.clear();
}

void readMenuFile()
{
    clearMenu();
    fstream menuFile("menu.dat", ios::in | ios::out | ios::binary);
    menuFile.seekg(0, ios::end);
    int itemsCount = (menuFile.tellg() / sizeof(foodItem));
    menuFile.seekg(0, ios::beg);
    for (int i = 0; i < itemsCount; i++)
    {
        itemsInMenu.push_back(new foodItem());
        menuFile.read((char *)itemsInMenu[i], sizeof(foodItem));
    }
    menuFile.close();
}

int findProduct(int id)
{
    for (int i = 0; i < itemsInMenu.size(); i++)
    {
        if (itemsInMenu[i]->itemId == id)
        {
            return i;
        }
    }
    return -1;
}


void updateOrderQueue()
{
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
    if (ordersCount == lastCount)
    {
        return;
    }
    fstream rf(fileName, ios::in | ios::out | ios::binary);
    rf.seekg(lastCount * sizeof(order), ios::beg);
    for (int i = 0; i < ordersCount - lastCount; i++)
    {
        orderQueue.push(new order());
        rf.read((char *)orderQueue.back(), sizeof(order));
    }
}

void updateQueueHeadStatus(){
    int id = orderQueue.front()->orderId;
    time_t timeNow;
    time(&timeNow);
    char fileName[14];
    tm *ptm = localtime(&timeNow);
    sprintf(fileName, "%02d%02d%04d.dat", ptm->tm_mday, ptm->tm_mon + 1, 1900 + ptm->tm_year);
    fstream file(fileName, ios::in | ios::out | ios::binary);
    file.seekp((id-1)*sizeof(order), ios::beg);
    file.write((char*) orderQueue.front(), sizeof(order));
    file.close();
}

void displayFrontDetails(){
    if(orderQueue.empty()){
        return;
    }
    readMenuFile();
    time_t timeNow;
    time(&timeNow);
    tm *ptm = localtime(&timeNow);
    char fileName2[18];
    sprintf(fileName2, "%02d%02d%04d%04d.dat", ptm->tm_mday, ptm->tm_mon + 1, 1900 + ptm->tm_year, orderQueue.front()->orderId);
    cout << "Order Id is : " << orderQueue.front()->orderId << "\n";
    fstream file(fileName2, ios::in | ios::out | ios::binary);
    int itemsCount;
    if (file)
    {
        file.seekg(0, ios::end);
        itemsCount = (file.tellg() / sizeof(orderItem));
    }
    else {
        itemsCount = 0;
    }
    file.close();
    if (itemsCount < 0)
    {
        itemsCount = 0;
    }
    if(itemsCount!=orderQueue.front()->itemsCount){
        cout << "Corrupt Order File\n";
        orderQueue.front()->orderStatus = 5;
        
    }
}

int main()
{
    updateOrderQueue();
    displayFrontDetails();
    return 0;
}
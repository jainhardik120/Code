#include <iostream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

#define blankSpaces "                                                                                                                                  "
#define linearLine "----------------------------------------------------------------------------------------------------------------------------------"

struct foodItem
{
    char name[20];
    int itemId;
    bool isAvailable;
    int quantityAvailable;
    bool isPackaged;
    float price;
    char size[20];
};

struct orderItem
{
    int itemId;
    int ind;
    int quantity;
    orderItem *next;
    orderItem(int itemId, int ind, int quantity)
    {
        this->ind = ind;
        this->itemId = itemId;
        this->quantity = quantity;
        this->next = NULL;
    }
    orderItem()
    {
        this->next = NULL;
    }
};

struct order
{
    int orderId;
    time_t time;
    orderItem *headItem = NULL;
    int itemsCount = 0;
    float total;
    int orderStatus;
};
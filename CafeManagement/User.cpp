#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstring>
#include <time.h>
#include "type.hpp"
using namespace std;

vector<foodItem *> itemsInMenu;

void clearMenu()
{
    for (int i = 0; i < itemsInMenu.size(); i++)
    {
        delete itemsInMenu[i];
    }
    itemsInMenu.clear();
}

void writeMenuFile()
{
    ofstream wf("menu.dat", ios::binary);
    for (int i = 0; i < itemsInMenu.size(); i++)
    {
        wf.write((char *)itemsInMenu[i], sizeof(foodItem));
    }
    wf.close();
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

void printProjectTitle()
{
    cout << "\t\t\t\t\t\tCafe Management Program\n\n";
}

void printMenu()
{
    char quantityAvl[5];
    printf("  ID            Name                  Size            Price  Availability\n");
    for (int i = 0; i < itemsInMenu.size(); i++)
    {
        if (itemsInMenu[i]->isPackaged)
        {
            sprintf(quantityAvl, "%03d", itemsInMenu[i]->quantityAvailable);
        }
        else
        {
            if (itemsInMenu[i]->isAvailable)
            {
                strcpy(quantityAvl, "Yes");
            }
            else
            {
                strcpy(quantityAvl, " No");
            }
        }
        printf("  %04d  %.*s%s%.*s  %.*s%s%.*s  %07.2f           %-3s\n",
               itemsInMenu[i]->itemId,
               (20 - strlen(itemsInMenu[i]->name)) / 2, blankSpaces,
               itemsInMenu[i]->name,
               20 - ((20 - strlen(itemsInMenu[i]->name)) / 2 + strlen(itemsInMenu[i]->name)), blankSpaces,
               (20 - strlen(itemsInMenu[i]->size)) / 2, blankSpaces,
               itemsInMenu[i]->size,
               20 - ((20 - strlen(itemsInMenu[i]->size)) / 2 + strlen(itemsInMenu[i]->size)), blankSpaces,
               itemsInMenu[i]->price,
               quantityAvl);
    }
}

int foodMenu()
{
    system("cls");
    readMenuFile();
    printMenu();
    return 1;
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

int insertAtTail(orderItem *&head, int itemId, int ind, int quantity, bool packaged)
{
    if (head == NULL)
    {
        if (packaged)
        {
            if (itemsInMenu[ind]->quantityAvailable < quantity)
            {
                return -1;
            }
        }
        head = new orderItem(itemId, ind, quantity);
        return 1;
    }
    orderItem *temp = head;
    if (itemId == temp->itemId)
    {
        if (packaged)
        {
            if (itemsInMenu[ind]->quantityAvailable < quantity + temp->quantity)
            {
                return -1;
            }
        }
        temp->quantity += quantity;
        return 2;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
        if (itemId == temp->itemId)
        {
            if (packaged)
            {
                if (itemsInMenu[ind]->quantityAvailable < quantity + temp->quantity)
                {
                    return -1;
                }
            }
            temp->quantity += quantity;
            return 2;
        }
    }
    if (packaged)
    {
        if (itemsInMenu[ind]->quantityAvailable < quantity)
        {
            return -1;
        }
    }
    orderItem *newItem = new orderItem(itemId, ind, quantity);
    temp->next = newItem;
    return 1;
}

order *collectOrderDetails()
{
    order *no = new order();
    time(&no->time);
    int tempId;
    int tempSerialNumber;
    int tempQuantity;
    no->orderStatus = 1;
    cout << "Enter items details below: \n";
    cout << "Enter \'-1\' to exit\n";
    while (1)
    {
        cout << "Enter product id: ";
        cin >> tempId;
        if (tempId == -1)
        {
            break;
        }
        tempSerialNumber = findProduct(tempId);
        if (tempSerialNumber == -1)
        {
            cout << "This product doesn't exist\n";
            continue;
        }
        cout << "Enter quantity: ";
        cin >> tempQuantity;
        if (!itemsInMenu[tempSerialNumber]->isPackaged)
        {
            if (!itemsInMenu[tempSerialNumber]->isAvailable)
            {
                cout << "Not available at the moment\n";
                continue;
            }
        }
        int code = insertAtTail(no->headItem, tempId, tempSerialNumber, tempQuantity, itemsInMenu[tempSerialNumber]->isPackaged);
        if (code == -1)
        {
            cout << "The requested quantity is not available at the moment\n";
            continue;
        }
        else if (code == 1)
        {
            no->itemsCount++;
        }
    }
    return no;
}

float calculateBillTotal(order *od)
{
    float amt = 0;
    orderItem *temp = od->headItem;
    while (temp != NULL)
    {
        amt += ((itemsInMenu[temp->ind]->price) * temp->quantity);
        temp = temp->next;
    }
    return amt;
}

void printOrderSummary(order *od)
{
    orderItem *temp = od->headItem;
    while (temp != NULL)
    {
        printf("%-20s  %-20s  %02d  %07.2f\n", itemsInMenu[temp->ind]->name, itemsInMenu[temp->ind]->size, temp->quantity, (temp->quantity * itemsInMenu[temp->ind]->price));
        temp = temp->next;
    }
    printf("\n%.*s%07.2f\n", 48, blankSpaces, od->total);
}

void addToOrdersQueue(order *&od)
{
    char fileName[14];
    tm *ptm = localtime(&od->time);
    sprintf(fileName, "%02d%02d%04d.dat", ptm->tm_mday, ptm->tm_mon + 1, 1900 + ptm->tm_year);
    fstream rf(fileName, ios::in | ios::out | ios::binary);
    int ordersCount;
    if (rf)
    {
        rf.seekg(0, ios::end);
        ordersCount = (rf.tellg() / sizeof(order));
    }
    else
    {
        ordersCount = 0;
    }
    rf.close();
    if (ordersCount < 0)
    {
        ordersCount = 0;
    }
    od->orderId = ordersCount + 1;
    ofstream wf(fileName, ios::binary | ios::app);
    wf.write((char *)od, sizeof(order));
    wf.close();
    char fileName2[18];
    sprintf(fileName2, "%02d%02d%04d%04d.dat", ptm->tm_mday, ptm->tm_mon + 1, 1900 + ptm->tm_year, od->orderId);
    ofstream lf(fileName2, ios::binary);
    orderItem *temp = od->headItem;
    while (temp != NULL)
    {
        lf.write((char *)temp, sizeof(orderItem));
        temp = temp->next;
    }
    lf.close();
}

void updateQuantity(order *od)
{
    orderItem *temp = od->headItem;
    while (temp != NULL)
    {
        if (itemsInMenu[temp->ind]->isPackaged)
        {
            itemsInMenu[temp->ind]->quantityAvailable -= temp->quantity;
        }
        temp = temp->next;
    }
}

void toWords(char arr[], char buf[])
{
    const char *tens_multiple[] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    const char *tens_power[] = {"Hundred ", "Thousand ", "Lakh ", "Crore "};
    const char *single_digits[] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
    const char *two_digits[] = {"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    if (strlen(buf) > 12)
    {
        strcat(arr, "Out Of Range");
        return;
    }
    if (strlen(buf) > 10)
    {
        if (strlen(buf) > 11)
        {
            if (buf[strlen(buf) - 12] == '1')
            {
                strcat(arr, two_digits[buf[strlen(buf) - 11] - 48]);
            }
            else
            {
                strcat(arr, tens_multiple[buf[strlen(buf) - 12] - 48]);
                strcat(arr, single_digits[buf[strlen(buf) - 11] - 48]);
            }
        }
        else
        {
            strcat(arr, single_digits[buf[strlen(buf) - 11] - 48]);
        }
        strcat(arr, tens_power[3]);
    }
    if (strlen(buf) > 8)
    {
        if (strlen(buf) > 9)
        {
            if (buf[strlen(buf) - 10] == '1')
            {
                strcat(arr, two_digits[buf[strlen(buf) - 9] - 48]);
            }
            else
            {
                strcat(arr, tens_multiple[buf[strlen(buf) - 10] - 48]);
                strcat(arr, single_digits[buf[strlen(buf) - 9] - 48]);
            }
        }
        else
        {
            strcat(arr, single_digits[buf[strlen(buf) - 9] - 48]);
        }
        strcat(arr, tens_power[2]);
    }
    if (strlen(buf) > 6)
    {
        if (strlen(buf) > 7)
        {
            if (buf[strlen(buf) - 8] == '1')
            {
                strcat(arr, two_digits[buf[strlen(buf) - 7] - 48]);
            }
            else
            {
                strcat(arr, tens_multiple[buf[strlen(buf) - 8] - 48]);
                strcat(arr, single_digits[buf[strlen(buf) - 7] - 48]);
            }
            if (buf[strlen(buf) - 8] != '0' && buf[strlen(buf) - 7] != 0)
                strcat(arr, tens_power[1]);
        }
        else
        {
            strcat(arr, single_digits[buf[strlen(buf) - 7] - 48]);
            if (buf[strlen(buf) - 7] != 0)
                strcat(arr, tens_power[1]);
        }
    }
    if (strlen(buf) > 5)
    {
        strcat(arr, single_digits[buf[strlen(buf) - 6] - 48]);
        if (buf[strlen(buf) - 6] != '0')
            strcat(arr, tens_power[0]);
    }
    if (strlen(buf) > 3)
    {
        if (strlen(buf) > 4)
        {
            if (buf[strlen(buf) - 5] == '1')
            {
                strcat(arr, two_digits[buf[strlen(buf) - 4] - 48]);
            }
            else
            {
                strcat(arr, tens_multiple[buf[strlen(buf) - 5] - 48]);
                strcat(arr, single_digits[buf[strlen(buf) - 4] - 48]);
            }
        }
        else
        {
            strcat(arr, single_digits[buf[strlen(buf) - 4] - 48]);
        }
    }
    strcat(arr, "Rupees Only");
}

int discardOrder(order *od)
{
    orderItem *prev = od->headItem;
    while (od->headItem)
    {
        od->headItem = od->headItem->next;
        delete prev;
        prev = od->headItem;
    }
    delete od;
    return 1;
}

int placeOrder(order *od)
{
    addToOrdersQueue(od);
    cout << "Order Placed Successfully\nYour Order Id is " << od->orderId << "\n";
    cout << "Your Order total is Rs. " << od->total << "\n";
    char inWords[400] = "";
    char buf[20];
    sprintf(buf, "%0.2f", od->total);
    toWords(inWords, buf);
    cout << inWords << "\n";
    updateQuantity(od);
    writeMenuFile();
    discardOrder(od);
    return 1;
}

int newOrder()
{
    system("cls");
    readMenuFile();
    printMenu();
    order *od = collectOrderDetails();
    od->total = calculateBillTotal(od);
    system("cls");
    printOrderSummary(od);
    cout << "Enter \'Y/N\' to proceed or cancel: ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        system("cls");
        return placeOrder(od);
    }
    else
    {
        return discardOrder(od);
    }
}

int orderStatus()
{
    system("cls");
    int n;
    cout << "Enter your order no: ";
    cin >> n;
    if (n < 1)
    {
        cout << "Invalid order id\n";
        return 1;
    }
    char fileName[14];
    time_t timeNow;
    time(&timeNow);
    tm *ptm = localtime(&timeNow);
    sprintf(fileName, "%02d%02d%04d.dat", ptm->tm_mday, ptm->tm_mon + 1, 1900 + ptm->tm_year);
    fstream file(fileName, ios::in | ios::out | ios::binary);
    if (!file)
    {
        cout << "Sorry, couldn\'t find this order\n";
        return 1;
    }
    file.seekg(0, ios::end);
    int orderCount = (file.tellg() / sizeof(order));
    file.seekg(0, ios::beg);
    if (orderCount < 0)
    {
        orderCount = 0;
    }
    if (n > orderCount)
    {
        cout << "Sorry, couldn\'t find this order\n";
        return 1;
    }
    file.seekg((n - 1) * (sizeof(order)), ios::beg);
    order *od = new order();
    file.read((char *)od, sizeof(order));
    switch (od->orderStatus)
    {
    case 1:
        cout << "Order is in queue\n";
        break;
    case 2:
        cout << "Preparing your order now\n";
        break;
    case 3:
        cout << "Your order is prepared and ready to be collected\n";
        break;
    case 4:
        cout << "Order is received by you\n";
        break;
    case 5:
        cout << "Can't prepare your order\n";
        break;
    default:
        cout << "Can't check status\n";
        break;
    }
    return 1;
}

int mainMenu()
{
    system("cls");
    printProjectTitle();
    char choice;
    printf("Enter X to exit program\n");
    printf("A. View Menu\n");
    printf("B. Place new order\n");
    printf("C. Check order status\n");
    printf("Choose from A-C: ");
    fflush(stdin);
    scanf("%c", &choice);
    if (choice > 90)
    {
        choice = choice - 32;
    }
    if (choice == 'X')
    {
        return -1;
    }
    switch (choice)
    {
    case 'A':
        return foodMenu();
        break;
    case 'B':
        return newOrder();
        break;
    case 'C':
        return orderStatus();
        break;
    default:
        break;
    }
    return 1;
}

int main()
{
    while (1)
    {
        int returnValue = mainMenu();
        if (returnValue == -1)
        {
            break;
        }
        printf("\n\nPress any key to continue...\n");
        getch();
    }
    return 0;
}
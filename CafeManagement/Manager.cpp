#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstring>
#include <cstdio>
#include <time.h>
#include "type.h"
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

void printMenu(int type)
{
    char quantityAvl[5];
    printf("  ID            Name                  Size            Price  Availability\n");
    for (int i = 0; i < itemsInMenu.size(); i++)
    {
        if (type == 0 || type == 1)
        {
            if (itemsInMenu[i]->isPackaged)
            {
                sprintf(quantityAvl, "%03d", itemsInMenu[i]->quantityAvailable);
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
        if (type == 0 || type == 2)
        {
            if (!itemsInMenu[i]->isPackaged)
            {
                if (itemsInMenu[i]->isAvailable)
                {
                    strcpy(quantityAvl, "Yes");
                }
                else
                {
                    strcpy(quantityAvl, " No");
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
    }
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

int foodMenu()
{
    system("cls");
    readMenuFile();
    printMenu(0);
    return 1;
}

int updateQuantities()
{
    system("cls");
    readMenuFile();
    printMenu(1);
    int tempId;
    int tempSerialNumber;
    int tempQuantity;
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
        if (!itemsInMenu[tempSerialNumber]->isPackaged)
        {
            cout << "Item not packaged type\n";
            continue;
        }
        cout << "Enter new quantity: ";
        cin >> tempQuantity;
        itemsInMenu[tempSerialNumber]->quantityAvailable = tempQuantity;
    }
    cout << "Enter \'Y/N\' to proceed or cancel: ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        writeMenuFile();
        cout << "Quantities updated successfully\n";
    }
    else
    {
        clearMenu();
        readMenuFile();
        cout << "Update cancelled\n";
    }
    return 1;
}

int changeAvailability()
{
    system("cls");
    readMenuFile();
    printMenu(2);
    int tempId;
    int tempSerialNumber;
    int tempStatus;
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
        if (itemsInMenu[tempSerialNumber]->isPackaged)
        {
            cout << "Item packaged type\n";
            continue;
        }
        cout << "Enter 1 for available, 0 for not available: ";
        cin >> tempStatus;
        if (tempStatus == 1)
        {
            itemsInMenu[tempSerialNumber]->isAvailable = true;
        }
        else if (tempStatus == 0)
        {
            itemsInMenu[tempSerialNumber]->isAvailable = false;
        }
    }
    cout << "Enter \'Y/N\' to proceed or cancel: ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        writeMenuFile();
        cout << "Quantities updated successfully\n";
    }
    else
    {
        clearMenu();
        readMenuFile();
        cout << "Update cancelled\n";
    }
    return 1;
}

int addNewMenuItem()
{
    system("cls");
    foodItem *temp = new foodItem();
    int tempSerialNumber;
    int tempId;
    cout << "Enter new product name: ";
    fflush(stdin);
    cin.getline(temp->name, 20);
    cout << "Enter id for new product: ";
    while (1)
    {
        cin >> tempId;
        tempSerialNumber = findProduct(tempId);
        if (tempSerialNumber != -1)
        {
            cout << "This product id already exist\n";
            cout << "Enter new product id: ";
        }
        else
        {
            temp->itemId = tempId;
            break;
        }
    }
    cout << "Enter new product size: ";
    fflush(stdin);
    cin.getline(temp->size, 20);
    cout << "Enter new product price: ";
    cin >> temp->price;
    int tempType;
    cout << "Enter 1 for packaged, 0 for not packaged: ";
    cin >> tempType;
    if (tempType == 1)
    {
        temp->isPackaged = true;
    }
    else
    {
        temp->isPackaged = false;
    }
    if (temp->isPackaged)
    {
        cout << "Enter quantity: ";
        cin >> temp->quantityAvailable;
    }
    else
    {
        cout << "Enter 1 for available, 0 for not available: ";
        int tempStatus;
        cin >> tempStatus;
        if (tempStatus == 1)
        {
            temp->isAvailable = true;
        }
        else
        {
            temp->isAvailable = false;
        }
    }

    system("cls");
    char quantityAvl[5];
    if (temp->isPackaged)
    {
        sprintf(quantityAvl, "%03d", temp->quantityAvailable);
    }
    else
    {
        if (temp->isAvailable)
        {
            strcpy(quantityAvl, "Yes");
        }
        else
        {
            strcpy(quantityAvl, " No");
        }
    }
    cout << "New product details are as follows: \n\n";
    printf("  ID            Name                  Size            Price  Availability\n");
    printf("  %04d  %.*s%s%.*s  %.*s%s%.*s  %07.2f           %-3s\n",
           temp->itemId,
           (20 - strlen(temp->name)) / 2, blankSpaces,
           temp->name,
           20 - ((20 - strlen(temp->name)) / 2 + strlen(temp->name)), blankSpaces,
           (20 - strlen(temp->size)) / 2, blankSpaces,
           temp->size,
           20 - ((20 - strlen(temp->size)) / 2 + strlen(temp->size)), blankSpaces,
           temp->price,
           quantityAvl);
    cout << "\n\nEnter \'Y/N\' to proceed or cancel: ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        itemsInMenu.push_back(temp);
        writeMenuFile();
        cout << "New item created successfully\n";
    }
    else
    {
        cout << "Operation cancelled\n";
    }
    return 1;
}

int viewOrders()
{
    system("cls");
    char fileName[14];
    int date;
    cout << "Enter date (DDMMYYYY): ";
    cin >> date;
    sprintf(fileName, "%d.dat", date);
    fstream file(fileName, ios::in | ios::out | ios::binary);
    file.seekg(0, ios::end);
    int ordersCount = (file.tellg() / sizeof(order));
    file.seekg(0, ios::beg);
    order *temp = new order();
    cout << "\n   ID       Time       Total\n";
    for (int i = 0; i < ordersCount; i++)
    {
        file.read((char *)temp, sizeof(order));
        tm *ptm = localtime(&temp->time);
        printf("  %04d    %02d:%02d:%02d    %07.2f\n", temp->orderId, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, temp->total);
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
    printf("B. Update Quantities\n");
    printf("C. Change Availability Status\n");
    printf("D. Add New Menu Item\n");
    printf("E. View orders of day\n");
    printf("Choose from A-E: ");
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
        return updateQuantities();
        break;
    case 'C':
        return changeAvailability();
        break;
    case 'D':
        return addNewMenuItem();
        break;
    case 'E':
        return viewOrders();
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
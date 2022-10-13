/* ----------------------Reference Links------------------------
https://www.tutorialspoint.com/cprogramming/c_constants.htm
https://www.geeksforgeeks.org/sprintf-in-c/
https://www.techonthenet.com/c_language/standard_library_functions/stdlib_h/atof.php
https://www.tutorialspoint.com/what-are-pointers-to-structures-in-c-language/;
https://www.epochconverter.com/
https://zetcode.com/articles/cdatetime/
https://stackoverflow.com/questions/1442116/how-to-get-the-date-and-time-values-in-a-c-program
https://www.geeksforgeeks.org/time-h-header-file-in-c-with-examples/
https://www.geeksforgeeks.org/ctime-function-in-c-c/
https://www.geeksforgeeks.org/time-function-in-c/
https://www.geeksforgeeks.org/basics-file-handling-c/
https://stackoverflow.com/questions/15472299/split-string-into-tokens-and-save-them-in-an-array
https://stackoverflow.com/questions/19424030/why-gets-function-skips-when-preceded-by-scanfd/
https://www.geeksforgeeks.org/strcmp-in-c-cpp/
https://www.geeksforgeeks.org/goto-statement-in-c-cpp/
https://stackoverflow.com/questions/12740268/how-can-i-restart-while-loop-after-certain-condition-if-satisfied-in-c
https://www.educative.io/blog/concatenate-string-c
https://stackoverflow.com/a/32349605
https://stackoverflow.com/a/153895
----------------------------------------------------------------*/

#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

// ***********All Constants Defined Here************//

#define textSizeInventoryFile 4000
#define textSizeSalesFile 4000
#define noOfItemsInInventory 100
#define noOfSales 100

#define billWidth 127

#define billingBrandName "realme"
#define companyNameLine1 "REALME MOBILE"
#define companyNameLine2 "TELECOMMUNICATIONS (INDIA)"
#define companyNameLine3 "Pvt. Ltd."
#define companyAddressLine1 "3rd Floor, Tower B"
#define companyAddressLine2 "Building No. 8, DLF Cyber City, Phase II"
#define companyAddressLine3 "Gurgaon-122002"
#define companyContactNumber "01246719500"

#define blankSpaces "                                                                                                                                  "
#define linearLine "----------------------------------------------------------------------------------------------------------------------------------"

char inventoryListLabels[5][15] = {"Serial Number", "Barcode", "Name", "Quantity", "Price"};

// ***********Structures Defined Here**************//

struct inventoryItem
{
    int serialNumber;
    char barcode[15];
    char name[20];
    int quantity;
    float currentPrice;
};

struct salesItem
{
    int serialNumber;
    struct inventoryItem itemDetails;
    float unitSellingPrice;
    int quantity;
    float netAmount;
    float taxRate;
    float taxAmount;
    float total;
};

struct bill
{
    int invoiceNumber;
    char customerName[30];
    char contactNumber[10];
    time_t time;
    char address[150];
    int numberOfItems;
    struct salesItem details[15];
    float totalTaxes;
    float totalAmount;
};

// **********Global Variables Initialized here**********//

FILE *inventoryFile;
FILE *salesFile;

char inventoryFileName[] = "inventory.txt";
char salesFileName[] = "sales.txt";

char rawTextInventory[textSizeInventoryFile];
char rawTextSales[textSizeSalesFile];

int itemsCount;
int salesCount = 0;

struct inventoryItem inventoryData[noOfItemsInInventory];
struct bill salesData[noOfSales];

char billData[50][billWidth];
int billLines = 0;

// *****************Beginning of functions****************//

int loadDataFilesReadMode()
{
    inventoryFile = fopen(inventoryFileName, "r");
    salesFile = fopen(salesFileName, "r");
    if (inventoryFile == NULL || salesFile == NULL)
    {
        printf("Failed to load data\n");
        printf("Exiting program");
        return 0;
    }
    else
    {
        printf("Data file loaded.\n");
        fgets(rawTextInventory, textSizeInventoryFile, inventoryFile);
        fgets(rawTextSales, textSizeSalesFile, salesFile);
        fclose(inventoryFile);
        fclose(salesFile);
        return 1;
    }
}

void rawDataToInventoryArray()
{
    char *inventoryItems[noOfItemsInInventory];
    char *token = strtok(rawTextInventory, "$$");
    itemsCount = 0;
    while (token != NULL)
    {
        inventoryItems[itemsCount++] = token;
        token = strtok(NULL, "$$");
    }

    for (int i = 0; i < itemsCount; i++)
    {
        char *tempToken = strtok(inventoryItems[i], ",");
        int tempCount = 0;
        while (tempToken != NULL)
        {
            switch (tempCount)
            {
            case 0:
                inventoryData[i].serialNumber = atoi(tempToken);
                break;
            case 1:
                strcpy(inventoryData[i].barcode, tempToken);
                break;
            case 2:
                strcpy(inventoryData[i].name, tempToken);
                break;
            case 3:
                inventoryData[i].quantity = atoi(tempToken);
                break;
            case 4:
                inventoryData[i].currentPrice = atof(tempToken);
                break;
            default:
                break;
            }
            tempCount++;
            tempToken = strtok(NULL, ",");
        }
    }
}

void printAllInventoryItems()
{
    for (int i = 0; i < itemsCount; i++)
    {
        printf("%d\t%-15s\t%-20s\t%d\t%0.2f\n",
               inventoryData[i].serialNumber,
               inventoryData[i].barcode,
               inventoryData[i].name,
               inventoryData[i].quantity,
               inventoryData[i].currentPrice);
    }
}

struct inventoryItem scanNewInventoryItem()
{
    struct inventoryItem newItem;
    newItem.serialNumber = itemsCount + 1;
    for (int i = 1; i < 5; i++)
    {
        printf("Enter %s of new item: ", inventoryListLabels[i]);
        switch (i)
        {
        case 1:
            fflush(stdin);
            gets(newItem.barcode);
            break;
        case 2:
            fflush(stdin);
            gets(newItem.name);
            break;
        case 3:
            scanf("%d", &newItem.quantity);
            break;
        case 4:
            scanf("%f", &newItem.currentPrice);
            break;
        default:
            break;
        }
    }
    return newItem;
}

void printItem(struct inventoryItem item)
{
    printf("%s : %d\n", inventoryListLabels[0], item.serialNumber);
    printf("%s : %s\n", inventoryListLabels[1], item.barcode);
    printf("%s : %s\n", inventoryListLabels[2], item.name);
    printf("%s : %d\n", inventoryListLabels[3], item.quantity);
    printf("%s : %0.2f\n", inventoryListLabels[4], item.currentPrice);
}

int writeDataToInventoryDataFile()
{
    inventoryFile = fopen(inventoryFileName, "w");
    if (inventoryFile == NULL)
    {
        printf("Failed to write data\n");
        printf("Exiting program");
        return 0;
    }
    else
    {
        for (int i = 0; i < itemsCount; i++)
        {
            char dataToBeWritten[100];
            sprintf(dataToBeWritten, "%d,%s,%s,%d,%0.2f",
                    inventoryData[i].serialNumber,
                    inventoryData[i].barcode,
                    inventoryData[i].name,
                    inventoryData[i].quantity,
                    inventoryData[i].currentPrice);

            fputs(dataToBeWritten, inventoryFile);

            if (i != itemsCount - 1)
            {
                fputs("$$", inventoryFile);
            }
        }
        fclose(inventoryFile);
        return 1;
    }
}

int appendLastBillToEndOfSalesFile()
{
    salesFile = fopen(salesFileName, "a");
    if (salesFile == NULL)
    {
        printf("Failed to write data\n");
        printf("Exiting program");
        return 0;
    }
    else
    {
        if (salesCount != 1)
        {
            fputs("$$$", salesFile);
        }
        /*
        $$$   between two bills
        ###   between different data of a bill  24
        ^^^   between two salesItem Details
        |&|   between different data of a salesItem
        */
        char dataToBeWritten[350];
        sprintf(dataToBeWritten, "%d###%s###%s###%d###%s###%d###%0.2f###%0.2f###",
                salesData[salesCount - 1].invoiceNumber,
                salesData[salesCount - 1].customerName,
                salesData[salesCount - 1].contactNumber,
                salesData[salesCount - 1].time,
                salesData[salesCount - 1].address,
                salesData[salesCount - 1].numberOfItems,
                salesData[salesCount - 1].totalTaxes,
                salesData[salesCount - 1].totalAmount);
        fputs(dataToBeWritten, salesFile);
        for (int i = 0; i < salesData[salesCount - 1].numberOfItems; i++)
        {
            char salesItemDetails[1000];
            sprintf(salesItemDetails, "%d|&|%s|&|%0.2f|&|%d|&|%0.2f|&|%0.2f|&|%0.2f|&|%0.2f",
                    salesData[salesCount - 1].details[i].serialNumber,
                    salesData[salesCount - 1].details[i].itemDetails.barcode,
                    salesData[salesCount - 1].details[i].unitSellingPrice,
                    salesData[salesCount - 1].details[i].quantity,
                    salesData[salesCount - 1].details[i].netAmount,
                    salesData[salesCount - 1].details[i].taxRate,
                    salesData[salesCount - 1].details[i].taxAmount,
                    salesData[salesCount - 1].details[i].total);
            fputs(salesItemDetails, salesFile);
            if (i != salesData[salesCount - 1].numberOfItems - 1)
            {
                fputs("^^^", salesFile);
            }
        }
        fclose(salesFile);
        return 1;
    }
}

struct inventoryItem scanNewDetails(struct inventoryItem item)
{
    char tempNameOrBarcode[20];
    float tempPrice;
    printf("Previous details are given below\n");
    printItem(item);
    printf("Enter new details or type -1 to leave as it is:\n");

    printf("Enter %s : ", inventoryListLabels[1]);
    scanf("%s", tempNameOrBarcode);
    if (strcmp("-1", tempNameOrBarcode))
    {
        strcpy(item.barcode, tempNameOrBarcode);
    }

    printf("Enter %s : ", inventoryListLabels[2]);
    fflush(stdin);
    gets(tempNameOrBarcode);
    if (strcmp("-1", tempNameOrBarcode))
    {
        strcpy(item.name, tempNameOrBarcode);
    }

    return item;
}

int returnSerialNumbersFromBarcode(int arr[], char query[15])
{
    int searchCount = 0;
    for (int i = 0; i < itemsCount; i++)
    {
        if (strstr(inventoryData[i].barcode, query) != NULL)
        {
            arr[searchCount++] = inventoryData[i].serialNumber;
        }
    }
    return searchCount;
}

int serialNumberFromBarcode(char barcode[15])
{
    for (int i = 0; i < itemsCount; i++)
    {
        if (strcmp(barcode, inventoryData[i].barcode) == 0)
        {
            return i + 1;
        }
    }
    return -1;
}

int incrementQuantityOfInventory(char barcode[15])
{
    int i = serialNumberFromBarcode(barcode);
    if (i == -1)
    {
        printf("No item with barcode %s found\n", barcode);
        return 1;
    }
    int incrementBy;
    char choice;
    printf("Current quantity of %s %s is %d\n", inventoryData[i - 1].barcode, inventoryData[i - 1].name, inventoryData[i - 1].quantity);
    printf("Enter the quantity by which you want to increment: ");
    scanf("%d", &incrementBy);
    printf("New quantity would be %d\n", inventoryData[i - 1].quantity + incrementBy);
    printf("Press Y to confirm, N to decline the change: ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y')
    {
        inventoryData[i - 1].quantity += incrementBy;
        if (writeDataToInventoryDataFile())
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    return 1;
}

int updatePriceOfItem(char barcode[15])
{
    int i = serialNumberFromBarcode(barcode);
    if (i == -1)
    {
        return 1;
    }
    float newPrice;
    char choice;
    printf("Current price of %s %s is %0.2f\n", inventoryData[i - 1].barcode, inventoryData[i - 1].name, inventoryData[i - 1].currentPrice);
    printf("Enter the new price : ");
    scanf("%f", &newPrice);
    printf("New price would be %0.2f\n", newPrice);
    printf("Press Y to confirm, N to decline the change: ");
    fflush(stdin);
    scanf("%c", &choice);
    if (choice == 'Y' || choice == 'y')
    {
        inventoryData[i - 1].currentPrice = newPrice;
        if (writeDataToInventoryDataFile())
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    return 1;
}

float calculateTotalValueOfInventory()
{
    float sum = 0;
    for (int i = 0; i < itemsCount; i++)
    {
        sum += inventoryData[i].quantity * inventoryData[i].currentPrice;
    }
    return sum;
}

void printListFromSearchIndexes(int list[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d\t\t%s\t\t%s\t\t%d\t\t%0.2f\n",
               inventoryData[list[i] - 1].serialNumber,
               inventoryData[list[i] - 1].barcode,
               inventoryData[list[i] - 1].name,
               inventoryData[list[i] - 1].quantity,
               inventoryData[list[i] - 1].currentPrice);
    }
}

void moveBySinglePosition(int serialNumber)
{
    for (int i = serialNumber; i < itemsCount; i++)
    {
        inventoryData[i].serialNumber--;
    }
    for (int i = serialNumber; i < itemsCount; i++)
    {
        inventoryData[i - 1] = inventoryData[i];
    }
    itemsCount = itemsCount - 1;
}

void funcSearchInventory()
{
    char query[15];
    int searchResults[noOfItemsInInventory];
    system("cls");
    printf("Search: ");
    fflush(stdin);
    scanf("%s", query);
    int noOfSearchResults = returnSerialNumbersFromBarcode(searchResults, query);
    printf("\nThese are the search results\n\n");
    printListFromSearchIndexes(searchResults, noOfSearchResults);
}

void funcPrintSelectiveInventory()
{
    char barcode[15];
    system("cls");
    printf("Enter Barcode: ");
    fflush(stdin);
    scanf("%s", barcode);
    printf("Printing...\n\n");
    printItem(inventoryData[serialNumberFromBarcode(barcode) - 1]);
}

void funcNewInventoryItem()
{
    system("cls");
    printf("Enter new item details :\n");
    struct inventoryItem newItem = scanNewInventoryItem();
    printf("\nThese are the details you entered: \n\n");
    printItem(newItem);
    printf("\nPress Y to save this new item: ");
    char choice;
    scanf("%s", &choice);
    if (choice == 'Y' || choice == 'y')
    {
        inventoryData[itemsCount++] = newItem;
        inventoryData[itemsCount - 1].serialNumber = itemsCount;
        if (writeDataToInventoryDataFile())
        {
            printf("Saved successfully\n");
        }
        else
        {
            printf("An error occured\n");
        }
    }
}

int funcDeleteInventoryItem()
{
    system("cls");
    char barcode[15];
    char choice;
    printf("Enter barcode of product to delete or enter \"search\" to find from list: ");
    fflush(stdin);
    scanf("%s", barcode);
    if (strcmp("search", barcode) == 0)
    {
        funcSearchInventory();
        printf("Enter barcode: ");
        fflush(stdin);
        scanf("%s", barcode);
    }
    int i = serialNumberFromBarcode(barcode);
    if (i == -1)
    {
        printf("No item with barcode %s found\n", barcode);
        return 1;
    }
    printf("Are you sure you want to delete \"%s\" ?\nPress Y/N to confirm/deny: ", inventoryData[i - 1].name);
    fflush(stdin);
    scanf("%c", &choice);
    if (choice == 'Y' || choice == 'y')
    {
        moveBySinglePosition(i);
        if (writeDataToInventoryDataFile())
        {
            printf("Deleted successfully\n");
            return 1;
        }
        else
        {
            printf("An error occured\n");
            printf("Exiting to avoid data corruption...");
            return -1;
        }
    }
    else
    {
        return 1;
    }
}

int funcEditProductDetail()
{
    system("cls");
    char barcode[15];
    char choice;
    printf("Enter current barcode of product to edit or enter \"search\" to find from list: ");
    fflush(stdin);
    scanf("%s", barcode);
    if (strcmp("search", barcode) == 0)
    {
        funcSearchInventory();
        printf("Enter barcode: ");
        fflush(stdin);
        scanf("%s", barcode);
    }
    int i = serialNumberFromBarcode(barcode);
    if (i == -1)
    {
        printf("No item with barcode %s found\n", barcode);
        return 1;
    }
    system("cls");
    struct inventoryItem tempItem = scanNewDetails(inventoryData[i - 1]);
    system("cls");
    printf("The new details you entered are: \n");
    printItem(tempItem);
    printf("\nPress Y/N to save changes: ");
    fflush(stdin);
    scanf("%c", &choice);
    if (choice == 'Y' || choice == 'y')
    {
        strcpy(inventoryData[i - 1].barcode, tempItem.barcode);
        strcpy(inventoryData[i - 1].name, tempItem.name);
        if (writeDataToInventoryDataFile())
        {
            printf("Saved successfully\n");
            return 1;
        }
        else
        {
            printf("An error occured\n");
            printf("Exiting to avoid data corruption...");
            return -1;
        }
    }
    else
    {
        return 1;
    }
}

int funcUpdateProductPrice()
{
    system("cls");
    char barcode[15];
    printf("Enter barcode of product to update or enter \"search\" to find from list: ");
    fflush(stdin);
    scanf("%s", barcode);
    if (strcmp("search", barcode) == 0)
    {
        funcSearchInventory();
        printf("Enter barcode: ");
        fflush(stdin);
        scanf("%s", barcode);
    }
    int i = serialNumberFromBarcode(barcode);
    if (i == -1)
    {
        printf("No item with barcode %s found\n", barcode);
        return 1;
    }
    system("cls");
    return updatePriceOfItem(barcode);
}

int funcIncrementItemQuantity()
{
    system("cls");
    char barcode[15];
    printf("Enter barcode of product to update quantity or enter \"search\" to find from list: ");
    fflush(stdin);
    scanf("%s", barcode);
    if (strcmp("search", barcode) == 0)
    {
        funcSearchInventory();
        printf("Enter barcode: ");
        fflush(stdin);
        scanf("%s", barcode);
    }
    system("cls");
    return incrementQuantityOfInventory(barcode);
}

int funcIncrementItemQuantityBulk()
{
    system("cls");
    printf("Enter barcode and quantity by which to inrement below\n");
    printf("Enter -1 when done\n");
    int serialNumber[noOfItemsInInventory];
    int quantity[noOfItemsInInventory];
    char tempBarcode[15];
    int tempQuantity;
    int c = 0;
    while (1)
    {
        scanf("%s %d", tempBarcode, &tempQuantity);
        if (strcmp(tempBarcode, "-1") == 0)
        {
            break;
        }
        int serialNumberTemp = serialNumberFromBarcode(tempBarcode);
        if (serialNumberTemp != -1)
        {
            serialNumber[c] = serialNumberTemp;
            quantity[c] = tempQuantity;
            c++;
        }
        else
        {
            printf("Invalid barcode entered, continue ahead\n");
        }
    }
    printf("You have requested to increment quantity of %d items\n", c);
    printf("To recheck the changes enter \'R\' or enter \'Y/N\' to confirm without reviewing: ");
    char choice;
    fflush(stdin);
    scanf("%c", &choice);
    if (choice == 'R' || choice == 'r')
    {
        for (int i = 0; i < c; i++)
        {
            printf("%d\t%-15s\tPrevious Quantity: %d\tTo be incremented by: %d\tNew Quantity would be: %d\n", i + 1, inventoryData[serialNumber[i] - 1].barcode, inventoryData[serialNumber[i] - 1].quantity, quantity[i], inventoryData[serialNumber[i] - 1].quantity + quantity[i]);
        }
        printf("Enter \'C\' to modify an entry or enter \'Y/N\' to confirm: ");
        fflush(stdin);
        scanf("%c", &choice);
        if (choice == 'C' || choice == 'c')
        {
            // TO-DO
            printf("Enter \'Y/N\' to confirm: ");
            fflush(stdin);
            scanf("%c", &choice);
            if (choice == 'Y' || choice == 'y')
            {
                goto SaveChanges;
            }
            else
            {
                return 1;
            }
        }
        else if (choice == 'Y' || choice == 'y')
        {
            goto SaveChanges;
        }
        else
        {
            return 1;
        }
    }
    else if (choice == 'Y' || choice == 'y')
    {
        goto SaveChanges;
    }
    else
    {
        return 1;
    }

SaveChanges:
    for (int i = 0; i < c; i++)
    {
        inventoryData[serialNumber[i] - 1].quantity += quantity[i];
    }
    if (writeDataToInventoryDataFile())
    {
        printf("Saved successfully\n");
        return 1;
    }
    else
    {
        printf("An error occured\n");
        printf("Exiting to avoid data corruption...");
        return -1;
    }
}

void decrementQuantityBilling(char barcode[], int decrementBy)
{
    int n = serialNumberFromBarcode(barcode);
    inventoryData[n - 1].quantity = inventoryData[n - 1].quantity - decrementBy;
}

struct bill scanNewBillData()
{
    struct bill newBill;
    newBill.invoiceNumber = salesCount + 1;
    time(&newBill.time);
    printf("Enter customer name: ");
    fflush(stdin);
    gets(newBill.customerName);
    printf("Enter contact number: ");
    fflush(stdin);
    gets(newBill.contactNumber);
    printf("Enter address line 1: ");
    fflush(stdin);
    gets(newBill.address);
    char tempAddressLine[50];
    printf("Enter address line 2: ");
    fflush(stdin);
    gets(tempAddressLine);
    strcat(newBill.address, "@@");
    strcat(newBill.address, tempAddressLine);
    printf("Enter address line 3: ");
    fflush(stdin);
    gets(tempAddressLine);
    strcat(newBill.address, "@@");
    strcat(newBill.address, tempAddressLine);
    newBill.numberOfItems = 0;
    printf("Start entering items details below:\n");
    printf("Enter \'-1\' to exit\n");
    char tempBarcode[15];
    int tempInventoryItemSerialNumber;
    int tempQuantity;
    while (1)
    {
        printf("Enter barcode of item: ");
        fflush(stdin);
        gets(tempBarcode);
        if (strcmp(tempBarcode, "-1") == 0)
        {
            break;
        }
        tempInventoryItemSerialNumber = serialNumberFromBarcode(tempBarcode);
        if (tempInventoryItemSerialNumber == -1)
        {
            printf("Invalid Barcode!\n");
            printf("Continue Ahead\n");
            continue;
        }
        newBill.details[newBill.numberOfItems].itemDetails = inventoryData[tempInventoryItemSerialNumber - 1];
        newBill.details[newBill.numberOfItems].serialNumber = newBill.numberOfItems + 1;
        newBill.details[newBill.numberOfItems].unitSellingPrice = newBill.details[newBill.numberOfItems].itemDetails.currentPrice;
        printf("Enter quantity: ");
        fflush(stdin);
        scanf("%d", &tempQuantity);
        if (tempQuantity > newBill.details[newBill.numberOfItems].itemDetails.quantity)
        {
            printf("Not enough quantity in inventory\n");
            printf("Continue Ahead\n");
            continue;
        }
        newBill.details[newBill.numberOfItems].quantity = tempQuantity;
        newBill.details[newBill.numberOfItems].netAmount = newBill.details[newBill.numberOfItems].unitSellingPrice * newBill.details[newBill.numberOfItems].quantity;
        printf("Enter tax rate: ");
        fflush(stdin);
        scanf("%f", &newBill.details[newBill.numberOfItems].taxRate);
        newBill.details[newBill.numberOfItems].taxAmount = newBill.details[newBill.numberOfItems].netAmount * newBill.details[newBill.numberOfItems].taxRate / 100;
        newBill.details[newBill.numberOfItems].total = newBill.details[newBill.numberOfItems].taxAmount + newBill.details[newBill.numberOfItems].netAmount;
        newBill.numberOfItems++;
    }
    newBill.totalAmount = 0;
    newBill.totalTaxes = 0;
    for (int i = 0; i < newBill.numberOfItems; i++)
    {
        newBill.totalAmount += newBill.details[i].total;
        newBill.totalTaxes += newBill.details[i].taxAmount;
    }
    return newBill;
}

void toWords(char arr[], char buf[])
{
    char *tens_multiple[] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    char *tens_power[] = {"Hundred ", "Thousand ", "Lakh ", "Crore "};
    char *single_digits[] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
    char *two_digits[] = {"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
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

void printBillFormat(struct bill b)
{
    billLines = 0;
    system("cls");
    char *customerAddress[3];
    char *token = strtok(b.address, "@@");
    int tempAddCounter = 0;
    while (token != NULL)
    {
        customerAddress[tempAddCounter++] = token;
        token = strtok(NULL, "@@");
    }
    printf("%.*s%s\n", (billWidth - strlen(billingBrandName)) / 2, blankSpaces, billingBrandName);
    sprintf(billData[billLines++], "%.*s%s", (billWidth - strlen(billingBrandName)) / 2, blankSpaces, billingBrandName);
    printf("%.*sTax Invoice\n\n", (billWidth - strlen("Tax Invoice")) / 2, blankSpaces);
    sprintf(billData[billLines++], "%.*sTax Invoice", (billWidth - strlen("Tax Invoice")) / 2, blankSpaces);
    sprintf(billData[billLines++], "");
    printf("%-77sInvoice Number: %04d\n", companyNameLine1, b.invoiceNumber);
    sprintf(billData[billLines++], "%-77sInvoice Number: %04d", companyNameLine1, b.invoiceNumber);
    printf("%-77s%s", companyNameLine2, ctime(&b.time)); // ctime() automatically adds a \n
    sprintf(billData[billLines++], "%-77s%s", companyNameLine2, ctime(&b.time));
    printf("%-77s%s\n\n", companyNameLine3, b.customerName);
    sprintf(billData[billLines++], "%-77s%s", companyNameLine3, b.customerName);
    sprintf(billData[billLines++], "");
    printf("Regd. Add: %-66s%s\n", companyAddressLine1, customerAddress[0]);
    sprintf(billData[billLines++], "Regd. Add: %-66s%s", companyAddressLine1, customerAddress[0]);
    printf("%-77s%s\n", companyAddressLine2, customerAddress[1]);
    sprintf(billData[billLines++], "%-77s%s", companyAddressLine2, customerAddress[1]);
    printf("%-77s%s\n\n", companyAddressLine3, customerAddress[2]);
    sprintf(billData[billLines++], "%-77s%s", companyAddressLine3, customerAddress[2]);
    sprintf(billData[billLines++], "");
    printf("Contact No: %-65sContact No: %s\n\n", companyContactNumber, b.contactNumber);
    sprintf(billData[billLines++], "Contact No: %-65sContact No: %s", companyContactNumber, b.contactNumber);
    sprintf(billData[billLines++], "");
    printf("%.*s\n\n", 127, linearLine);
    sprintf(billData[billLines++], "%.*s", 127, linearLine);
    sprintf(billData[billLines++], "");
    printf("%-5s   %*s%s%*s   %*s%s%*s   %s   %s   %s   %s   %*s%s%*s   %s\n", "S.No.", 8, " ", "Name", 8, " ", 4, " ", "Barcode", 4, " ", "Quantity", "Unit Price", "Taxable Amount", "Tax Rate", 3, " ", "Taxes", 3, " ", "Total Amount");
    sprintf(billData[billLines++], "%-5s   %*s%s%*s   %*s%s%*s   %s   %s   %s   %s   %*s%s%*s   %s", "S.No.", 8, " ", "Name", 8, " ", 4, " ", "Barcode", 4, " ", "Quantity", "Unit Price", "Taxable Amount", "Tax Rate", 3, " ", "Taxes", 3, " ", "Total Amount");
    /*
    S.No.           Name               Barcode       Quantity   Unit Price   Taxable Amount   Tax Rate      Taxes      Total Amount
    */
    for (int i = 0; i < b.numberOfItems; i++)
    {
        printf("%.*s%02d%23s%18s%.*s%03d%.*s%08.2f%.*s%010.2f%.*s%05.2f%.*s%08.2f%.*s%010.2f\n", 3, blankSpaces, b.details[i].serialNumber, b.details[i].itemDetails.name, b.details[i].itemDetails.barcode, 8, blankSpaces, b.details[i].quantity, 5, blankSpaces, b.details[i].itemDetails.currentPrice, 7, blankSpaces, b.details[i].netAmount, 6, blankSpaces, b.details[i].taxRate, 3, blankSpaces, b.details[i].taxAmount, 8, blankSpaces, b.details[i].total);
        fflush(stdin);
        sprintf(billData[billLines++], "%.*s%02d%23s%18s%.*s%03d%.*s%08.2f%.*s%010.2f%.*s%05.2f%.*s%08.2f%.*s%010.2f", 3, blankSpaces, b.details[i].serialNumber, b.details[i].itemDetails.name, b.details[i].itemDetails.barcode, 8, blankSpaces, b.details[i].quantity, 5, blankSpaces, b.details[i].itemDetails.currentPrice, 7, blankSpaces, b.details[i].netAmount, 6, blankSpaces, b.details[i].taxRate, 3, blankSpaces, b.details[i].taxAmount, 8, blankSpaces, b.details[i].total);
    }

    printf("\n%.*s\n\n", 127, linearLine);
    sprintf(billData[billLines++], "");
    sprintf(billData[billLines++], "%.*s", 127, linearLine);
    sprintf(billData[billLines++], "");
    int widthOfEndColumn = 29;
    if (strlen(companyNameLine1) > widthOfEndColumn)
    {
        widthOfEndColumn = strlen(companyNameLine1);
    }
    if (strlen(companyNameLine2) > widthOfEndColumn)
    {
        widthOfEndColumn = strlen(companyNameLine2);
    }
    if (strlen(companyNameLine3) > widthOfEndColumn)
    {
        widthOfEndColumn = strlen(companyNameLine3);
    }
    printf("%s%.*sTaxable Amount%.*s%011.2f\n", "Total Amount in Words:", billWidth - (widthOfEndColumn + 22), blankSpaces, (widthOfEndColumn - (14 + 11)), blankSpaces, b.totalAmount - b.totalTaxes);
    sprintf(billData[billLines++], "%s%.*sTaxable Amount%.*s%011.2f", "Total Amount in Words:", billWidth - (widthOfEndColumn + 22), blankSpaces, (widthOfEndColumn - (14 + 11)), blankSpaces, b.totalAmount - b.totalTaxes);
    char inWords[400] = "";
    char buf[20];
    sprintf(buf, "%0.2f", b.totalAmount);
    toWords(inWords, buf);
    fflush(stdin);
    printf("%s%.*sTotal Taxes%.*s%011.2f\n\n", inWords, billWidth - (widthOfEndColumn + strlen(inWords)), blankSpaces, widthOfEndColumn - (11 + 11), blankSpaces, b.totalTaxes);
    sprintf(billData[billLines++], "%s%.*sTotal Taxes%.*s%011.2f", inWords, billWidth - (widthOfEndColumn + strlen(inWords)), blankSpaces, widthOfEndColumn - (11 + 11), blankSpaces, b.totalTaxes);
    sprintf(billData[billLines++], "");
    printf("%.*sGrand Total%.*s%011.2f\n\n", billWidth - widthOfEndColumn, blankSpaces, widthOfEndColumn - (11 + 11), blankSpaces, b.totalAmount);
    sprintf(billData[billLines++], "%.*sGrand Total%.*s%011.2f", billWidth - widthOfEndColumn, blankSpaces, widthOfEndColumn - (11 + 11), blankSpaces, b.totalAmount);
    sprintf(billData[billLines++], "");
    printf("%.*s%s\n", billWidth - widthOfEndColumn, blankSpaces, companyNameLine1);
    sprintf(billData[billLines++], "%.*s%s", billWidth - widthOfEndColumn, blankSpaces, companyNameLine1);
    printf("%.*s%s\n", billWidth - widthOfEndColumn, blankSpaces, companyNameLine2);
    sprintf(billData[billLines++], "%.*s%s", billWidth - widthOfEndColumn, blankSpaces, companyNameLine2);
    printf("%.*s%s\n\n\n\n\n", billWidth - widthOfEndColumn, blankSpaces, companyNameLine3);
    sprintf(billData[billLines++], "%.*s%s", billWidth - widthOfEndColumn, blankSpaces, companyNameLine3);
    sprintf(billData[billLines++], "");
    sprintf(billData[billLines++], "");
    sprintf(billData[billLines++], "");
    sprintf(billData[billLines++], "");
    printf("%.*s%s", billWidth - widthOfEndColumn, blankSpaces, "Authorised Signatory");
    sprintf(billData[billLines++], "%.*s%s", billWidth - widthOfEndColumn, blankSpaces, "Authorised Signatory");
}

int addBillToSalesFile(struct bill b)
{
    salesData[salesCount++] = b;
    appendLastBillToEndOfSalesFile();
    // Decrement quantities
    for (int i = 0; i < b.numberOfItems; i++)
    {
        decrementQuantityBilling(b.details[i].itemDetails.barcode, b.details[i].quantity);
    }
    return writeDataToInventoryDataFile();
}

void saveNewBillInTXTFormat(struct bill b)
{
    FILE *billFile;
    char fileName[12];
    char tempLine[billWidth];
    sprintf(fileName, "IN%04d.txt", b.invoiceNumber);
    billFile = fopen(fileName, "w");
    for (int i = 0; i < billLines; i++)
    {
        sprintf(tempLine, "%.*s", billWidth, billData[i]);
        fputs(tempLine, billFile);
        fputs("\n", billFile);
    }
    fclose(billFile);
}

int funcNewBill()
{
    system("cls");
    struct bill newBill = scanNewBillData();
    system("cls");
    printf("Bill data scanned\n");
    printf("Printing Bill Data...\n");
    printBillFormat(newBill);
    printf("\n\nPress any key to continue...\n");
    getch();
    system("cls");
    printf("Enter \'Y/N\' to save the bill and store in sales file: ");
    char choice;
    fflush(stdin);
    scanf("%c", &choice);
    if (choice == 'Y' || choice == 'y')
    {
        saveNewBillInTXTFormat(newBill);
        return addBillToSalesFile(newBill);
    }
    else
    {
        return 1;
    }
}

int mainMenu()
{
    system("cls");
    int choice;
    printf("Enter -1 to exit program\n");
    printf("1. List all inventory items\n");
    printf("2. Search inventory items\n");
    printf("3. List product details\n");
    printf("4. Create new item\n");
    printf("5. Delete a item\n");
    printf("6. Edit a product details\n");
    printf("7. Update product price\n");
    printf("8. Update item quantity\n");
    printf("9. Update item quantity in bulk\n");
    printf("10. Create a new Bill\n");
    printf("Choose from 1-10: ");

    scanf("%d", &choice);
    if (choice == -1)
    {
        return -1;
    }

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Printing all items...\n\n");
        printAllInventoryItems();
        return 1;
        break;
    case 2:
        funcSearchInventory();
        return 1;
        break;
    case 3:
        funcPrintSelectiveInventory();
        return 1;
        break;
    case 4:
        funcNewInventoryItem();
        return 1;
        break;
    case 5:
        return funcDeleteInventoryItem();
        break;
    case 6:
        return funcEditProductDetail();
        break;
    case 7:
        return funcUpdateProductPrice();
        break;
    case 8:
        return funcIncrementItemQuantity();
        break;
    case 9:
        return funcIncrementItemQuantityBulk();
        break;
    case 10:
        return funcNewBill();
        break;
    default:
        printf("Invalid Choice");
        return 1;
        break;
    }
}

int main()
{
    loadDataFilesReadMode();
    rawDataToInventoryArray();
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
#include <iostream>
#include <string.h>
using namespace std;

class library
{
public:
    int booknumber;
    int price;
    int copissue;
    int copmemeber;
    string bookname;
    string author;
    string publisher;

    void Information()
    {
        cout << "Enter Book number :";
        cin >> booknumber;
        cout << "\n";
        cout << "Enter price :";
        cin >> price;
        cout << "\n";
        cout << "Enetr number of copies issued :";
        cin >> copissue;
        cout << "\n";
        cout << "Enter number of copies of member function :";
        cin >> copmemeber;
        cout << "\n";
        cout << "Enter book name :";
        cin.ignore();
        getline(cin, bookname);
        cout << "\n";
        cout << "Enter author name :";
        getline(cin, author);
        cout << "\n";
        cout << "Enter publisher name :";
        getline(cin, publisher);
        cout << "\n";
    }

    void Display()
    {
        cout << "Book number :" << booknumber << endl;
        cout << "Price :" << price << endl;
        cout << "Copies issued :" << copissue << endl;
        cout << "Copies of member function :" << copmemeber << endl;
        cout << "Book name :" << bookname << endl;
        cout << "Author name :" << author << endl;
        cout << "Publisher name :" << publisher << endl;
    }
};

int main()
{
    library L;
    L.Information();
    L.Display();

    return 0;
}
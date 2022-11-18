#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct student{
    char name[20];
    float cg;
};

int main()
{
    student s;
    s.cg = 9.9;
    strcpy(s.name, "kartik");
    ofstream wf("1.dat", ios::binary | ios::app);
    wf.write((char*) &s, sizeof(student));
    wf.close();
    fstream file("1.dat", ios::in | ios::out | ios::binary);
    file.seekg(0, ios::end);
    int itemsCount = (file.tellg() / sizeof(student));
    file.seekg(0, ios::beg);
    for (int i = 0; i < itemsCount; i++)
    {
        file.read((char*)&s, sizeof(student));
        cout << s.name << " " << s.cg << "\n";
    }
    file.close();
    return 0;
}
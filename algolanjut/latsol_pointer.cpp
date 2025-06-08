#include <iostream>
using namespace std;

int main()
{
    string item[3];
    string *ptrItem = item;
    for (int i = 0; i < 3; i++)
    {
        cout << "masukkan item ke-" << i+1 << ": ";
        cin >> *(ptrItem+i);
    }
    cout << "daftar belanja : " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i+1 << "." << *(ptrItem+i) << endl;
        // cout << "alamat ke-" << i+1 << (ptrItem+i) << endl;
    }
}
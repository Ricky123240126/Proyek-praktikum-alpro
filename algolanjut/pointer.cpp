#include <iostream>
using namespace std;

int kuadrat(int *c)
{
    return (*c) * (*c);
}

int main()
{
    int a = 5; //int a memiliki value dan addres
    int *aPTR = &a;
    //aPTR = &a; // memasukkan address ke aPTR

    cout << "nilai dari a = " << a << endl;
    cout << "alamat dari a = " << &a << endl; // cara ambil address dari variabel a

    cout << "nilai dari aPTR diambil dari a : " << *aPTR << endl;

    *aPTR = 10;
    cout << a << endl;
    cout << kuadrat(&a) << endl;

    string Okto[5] = {"magelangan1", "magelangan2", "magelangan3", "magelangan4", "magelangan5"};
    string *ptrOkto = Okto;
    for (int i = 0; i < 5; i++)
    {
        cout << "okto : " << *(ptrOkto + i) << endl;
    }
}
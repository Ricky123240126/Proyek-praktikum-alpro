#include <iostream>
using namespace std;


void bubbleSortAsc(string nama[],int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x - i - 1; j++)
        {
            if (nama[j] > nama[j+1])
            {
                string temp = nama[j];
                nama[j] = nama[j+1];
                nama[j+1] = temp;
                // swap(angka[j], angka[j+1]);
            }
        }
    }
}

void bubbleSortDsc(string nama[],int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x - i - 1; j++)
        {
            if (nama[j] < nama[j+1])
            {
                string temp = nama[j];
                nama[j] = nama[j+1];
                nama[j+1] = temp;
                // swap(angka[j], angka[j+1]);
            }
        }
    }
}

void print(string nama[], int size)
{
    for ( int i = 0; i < size; i++)
    {
        cout << nama[i] << " ";
    }
    cout << endl;
}

int main()
{
    string nama[10];
    int x = sizeof(nama) / sizeof(nama[0]);
    for (int i=0; i<5; i++)
    {
    cout << "Masukkan nama mahasiswa : ";
    cin >> nama[i];
    }
    bubbleSortAsc(nama,x);
    cout << "nama asc :" << endl;
    print(nama,x);
    bubbleSortDsc(nama,x);
    cout << "nama dsc :" << endl;
    print(nama,x);
}
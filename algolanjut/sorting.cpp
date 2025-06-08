#include <iostream>
using namespace std;

void bubbleSort(int angka[],int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x - i - 1; j++)
        {
            if (angka[j] > angka[j+1])
            {
                int temp = angka[j];
                angka[j] = angka[j+1];
                angka[j+1] = temp;
                // swap(angka[j], angka[j+1]);
            }
        }
    }
}

int partition(int angka[], int kiri, int kanan)
{
    int pivot = angka[kanan];
    int i = kiri-1;
    for (int j = kiri; j < kanan; j++)
    {
        if (angka[j] < pivot)
        {
            i++;
            int temp = angka[i];
            angka[i] = angka[j];
            angka[j] = temp;
        }
    }
    int temp = angka[i+1];
    angka[i+1] = angka[kanan];
    angka[kanan] = temp;

    return i+1;
}

void quickSort(int angka[], int kiri, int kanan)
{
    if (kiri < kanan)
    {
        int partisi = partition(angka, kiri, kanan);
        quickSort(angka,kiri,partisi-1);
        quickSort(angka,partisi+1,kanan);
    }
}

void print(int angka[], int size)
{
    for ( int i = 0; i < size; i++)
    {
        cout << angka[i] << " ";
    }
    cout << endl;
}

int main()
{
    int angka[] = {2,23,12,62,15,16,5};
    int x = sizeof(angka) / sizeof(angka[0]);
    
    cout << "sebelum di urutkan : " << endl;
    print(angka, x);
    // bubbleSort(angka,x);
    quickSort(angka, 0, x - 1);
    cout << endl;
    cout << "setelah di urutkan : " << endl;
    print(angka,x);
}
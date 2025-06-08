#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
int main () 
{
    string nama ;
    int nim, totalSks, sksMka, sksD, sksE, lama; 
    float IPK;

    cout << "nama : ";
    getline(cin,nama);
    cout << "NIM : ";
    cin >> nim;
    cout << "Total SKS  : ";
    cin >> totalSks;
    cout << "Jumlah SKS MKA pilihan : ";
    cin >> sksMka;
    cout << "Jumlah SKS D : ";
    cin >> sksD;
    cout << "Jumlah SKS E : ";
    cin >> sksE;
    cout << "Lama lulus (semester) : ";
    cin >> lama;
    cout << "IPK : ";
    cin >> IPK;

   if (IPK >= 2.25 && totalSks >= 144 && sksMka > 15 && sksD < 0.25*totalSks && sksE == 0)
    {
        cout << "Mahasiswa dinyatakan LULUS dengan ";
    } else {
        cout << "anda dinyatakan TIDAK LULUS";
        return 0;
    }
    
    
    if (IPK >= 3.51 && lama <= 8)
        {
            cout << "Cumlaude";
            cout << " dan dapat diusulkan mendapatkan karya cendikia";
        }
        else if (3.01 <= IPK <= 3.50 || IPK >= 3.51 && lama > 8)
        {
            cout << "Very satisfactory";
        }
        else if (2.76 <= IPK <= 3.00)
        {
            cout  << "satisfactory";
        }

   
    getch ();
}
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
int main (){
    string Jabatan;
    int Lama, Bonus;

    cout << "====================" << endl;
    cout << "| Penghitung Bonus |" << endl;
    cout << "====================" << endl;

    cout << "berikut jabatan yang anda pilih : " << endl;
    cout << "- Karyawan" << endl;
    cout << "- Manajer" << endl;
    cout << "- CEO" << endl;

    cout << "\nmasukkan jabatan anda : ";
    cin >> Jabatan;

    if (Jabatan != "Karyawan" && Jabatan != "Manajer" && Jabatan != "CEO")
    {
        cout << "Jabatan anda tidak valid";
        return 0;
    }
    

    cout << "\nlama kerja : ";
    cin >> Lama;

    if (Lama <= 0)
    {
        cout << "Lama kerja anda tidak valid";
    } 

    if (Jabatan == "Karyawan")
    {
        if (Lama < 3)
        {
            Bonus = 100000 * Lama;
        }
        else if ( 3 <= Lama < 7)
        {
            Bonus = 125000 * Lama;
        }
        else if (Lama >= 7)
        {
            Bonus = 150000 * Lama;
        }
        
    }

    if (Jabatan == "Manajer")
    {
        if (Lama < 3)
        {
            Bonus = 300000 * Lama;
        }
        else if ( 3 <= Lama < 7)
        {
            Bonus = 325000 * Lama;
        }
        else if (Lama >= 7)
        {
            Bonus = 350000 * Lama;
        }
        
    }

    if (Jabatan == "CEO")
    {
        if (Lama < 3)
        {
            Bonus = 500000 * Lama;
        }
        else if ( 3 <= Lama < 7)
        {
            Bonus = 525000 * Lama;
        }
        else if (Lama >= 7)
        {
            Bonus = 550000 * Lama;
        }
        
    }
    cout << "Bonus anda : " << Bonus<<endl;

    getch();
    return 0;
}
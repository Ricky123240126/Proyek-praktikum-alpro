#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main ()
{
    char NIM [12];
    string Nama;
    char Plug [5];
    
    cout << "Input Data" << endl;
    cout << "NIM : ";
    cin.getline(NIM, 12);
    cout << "Nama : ";
    getline(cin,Nama);
    cout << "Plug : ";
    cin.getline(Plug, 5);
    cin.ignore();

    system ("cls");
    cout << "inilah data anda" << endl;
    cout << "NIM : " << NIM << endl;
    cout << "Nama : " << Nama << endl;
    cout << "Plug : " << Plug << endl;
    
    cout << "Dalam bentuk tabel" << endl;
    cout << "=================================================" << endl;
    cout << setw(10) << left << "NIM" << " | " 
    << setw(20) << left << "Nama" << " | "
    << setw(10) << left << "Plug" << endl;
    cout << "=================================================" << endl;
    cout << setw(10) << left << NIM << " | " 
    << setw(20) << left << Nama << " | " 
    << setw(10) << left << Plug << endl;
    cout << "-------------------------------------------------" << endl;

    return 0;
}
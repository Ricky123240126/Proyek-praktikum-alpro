#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string nim, nama, plug;

    // Input data dari pengguna
    cout << "Masukkan NIM: ";
    getline(cin, nim);
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan Plug: ";
    getline(cin, plug);

    // Menampilkan data
    cout << "\nInilah data anda" << endl;
    cout << "NIM   : " << nim << endl;
    cout << "Nama  : " << nama << endl;
    cout << "Plug  : " << plug << endl;

    // Menampilkan data dalam bentuk tabel
    cout << "\nDalam bentuk tabel" << endl;
    cout << "==================================================" << endl;
    cout << setw(10) << left << "NIM" << " | " 
         << setw(20) << left << "Nama" << " | "
         << setw(10) << left << "Plug" << endl;
    cout << "==================================================" << endl;
    cout << setw(10) << left << nim << " | " 
         << setw(20) << left << nama << " | " 
         << setw(10) << left << plug << endl;
    cout << "--------------------------------------------------" << endl;

    return 0;
}

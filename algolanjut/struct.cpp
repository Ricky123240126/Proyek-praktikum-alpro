#include <iostream>
using namespace std;

struct Mahasiswa{
    string nama,NIM;
    int umur;
};



int main(){
    Mahasiswa mhs;
    cout << "input data mahasiswa\n";
    cout << "Nama : "; cin >> mhs.nama;
    cout << "NIM : "; cin >> mhs.NIM;
    cout << "umur : "; cin >> mhs.umur;


}
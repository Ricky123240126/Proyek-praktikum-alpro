#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool login(string username, string password, int banyakUser);

struct Sepatu {
    int kode;
    string brand;
    string model;
    double harga;
    int stok;
};





int main()
{
    int life = 3, pilihan;
    string username, password;
    bool program = true;

    while (life > 0 & program == true)
    {
        system("cls");
        cout << setw(50) << setfill('=') << "\n";
        cout << setw(35) << setfill(' ') << "SELAMAT DATANG !\n";
        cout << setw(50) << setfill('=') << "\n";
        cout << "1. Login\n";
        cout << "2. Keluar\n";
        cout << setw(50) << setfill('=') << "\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;
        system("cls");
        switch (pilihan)
        {
            case 1:
            {
                cout << "Masukkan Username : ";
                cin >> username;
                cout << "Masukkan password : ";
                cin >> password;
                if (username == "bakul sepatu" && password == "fufufafa123")
                {
                    cout << "Login Berhasil :D";
                }
                else
                {
                    cout << "Login Gagal";
                    life--;
                    cout << "sisa percobaan " << life << "kali lagi";
                }
                break;
            }
            case 2:
            {
                program = false;
                break;
            }
        }
    }
}

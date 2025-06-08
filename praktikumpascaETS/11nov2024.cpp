#include <iostream>
#include <string>

using namespace std;

void login();
void daftar();
string nama[100];
string pass[100];
int banyak_user = 0;

int main() {
    int choice;
    bool ulang = true;

    while(ulang) {
        system("cls");
        cout << "Banyaknya user : "<<banyak_user<<endl;
        cout << "Selamat Datang!" << endl;
        cout << "1. Daftar" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character left by cin

        switch(choice) {
            case 1:
                daftar();
                break;
            case 2:
                login();
                break;
            case 3:
                ulang = false;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        cout << "Banyaknya user: " << banyak_user << endl;
        system("pause");
    }

    return 0;
}

void login() {
    system("cls");
    string input_nama, input_pass;
    cout << "Masukan nama anda: ";
    getline(cin, input_nama);
    cout << "Masukan pass anda: ";
    getline(cin, input_pass);

    bool found = false;
    for(int i = 0; i < banyak_user; ++i) {
        if(nama[i] == input_nama && pass[i] == input_pass) {
            found = true;
            break;
        }
    }

    if(found) {
        cout << "Login berhasil!" << endl;
    } else {
        cout << "Nama atau password salah!" << endl;
    }
}

void daftar() {
    system("cls");
    cout << "Masukan nama anda: ";
    getline(cin, nama[banyak_user]);
    cout << "Masukan pass anda: ";
    getline(cin, pass[banyak_user]);
    
    ++banyak_user;
    cout << "Registrasi berhasil!" << endl;
}
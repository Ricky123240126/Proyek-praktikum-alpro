#include <iostream>
#include <string>

using namespace std;

void login();
void daftar();
void menu();
string akun[100][3];
int kodeBarang[11] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011};
string jenisBarang[11] = {"Ayam Goreng", "Lotek", "Gado-Gado", "Wagyu A5", "Gurame Bakar", "Bebek Peking", "Telur Triceratops", "Daging Zombie", "Magelangan Mba Lis", "Babi Guling", "Unagi"};
int hargaBarang[11] = {18750, 12190, 10680, 767250, 45328, 31313, 56570, 123456, 12100, 27894, 60456};

int banyak_user = 0;
int life = 3;


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
        cin.ignore();

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

    void menu();
}

void login() {
    do {
    system("cls");
    string input_nama, input_pass;
    cout << "Masukan nama anda: ";
    getline(cin, input_nama);
    cout << "Masukan pass anda: ";
    getline(cin, input_pass);

    bool found = false;
    for(int i = 0; i < banyak_user; ++i) {
        if (input_nama == akun[i][0] && input_pass == akun[i][1])
        {
            cout << "Login Berhasil!\n";
            found = true;
        }
        
        else {
            life--;
            cout << "username atau password salah !" << endl;
            cout << "sisa percobaan " << life << endl;
            found = false;
            system ("pause");
        }
        }
    } while (life > 0);

}

void daftar()
{
    system("cls");
    cout << "Masukkan nama anda : ";
    cin >> akun[banyak_user][2];
    cin.ignore();
    cout << "Masukan username anda: ";
    getline(cin, akun[banyak_user][0]);
    cout << "Masukan pass anda: ";
    getline(cin, akun[banyak_user][1]);
    ++banyak_user;
    cout << "Registrasi berhasil!" << endl;
}
void menu() 
{
    bool keluar = false;
    int pilihan, kdBarang;
    string namaCust;
    while (!keluar)
    {
        system ("cls");
        cout << "[1] Tambah pesan" << endl;
        cout << "[2] Lihat daftar pesanan" << endl;
        cout << "[3] keluar" << endl;
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
            cout << "Masukkan nama customer : ";
            cin >> namaCust;
            cin.ignore();
            cout << "Masukkan kode barang : ";
            cin >> kdBarang;
            

            break;
            case 2:

            break;
            case 3:

            break;
            default:

            break;
        }
    }
}
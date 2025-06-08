#include <iostream>
using namespace std;

struct pengguna{
    string nama;
    string no_telp;
    string pin;
    int saldo;
};
void cariPengguna(){
    
}

int main(){
    pengguna daftar_pgn[10] =   {
                            {"Hisyam L Baihaq", "08123456789", "12345678", 100000000},
                            {"Fiernaz Ingga Pratamai", "08123456788", "Ab3De6Gh9", 2000000},
                            {"Aushaf Fathin Irsyad Nabil S", "08123456787", "11111111", 10000000},
                            {"Raihan Natawangsa", "08123456786", "satudelapankali", 2000000},
                            {"Timothy Brian Megaranto Padang", "08123456789", "admin123", 1000000}
                            };
    int x = 5, y = 2, kembali = 1, menu, jumlahtambah;
    char ulang = 'y';

    do{
        system("cls");
        cout << "PROGRAM E-MONEY" << endl;
        cout << "1. Tampilkan Data Pengguna" << endl;
        cout << "2. Tambah Data Pengguna" << endl;
        cout << "3. Cari Pengguna" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih Menu : "; cin >> menu;
        cin.ignore();

        switch(menu){
            case 1 :
            do{
                system("cls");
                for (int i = 0; i < x; i++) {
                    cout << "Pengguna ke-" << i + 1 << " : " << daftar_pgn[i].nama << endl;
                    cout << "Nomor Hp       : " << daftar_pgn[i].no_telp << endl;
                    cout << "PIN     : " << daftar_pgn[i].pin << endl;
                    cout << "Saldo     : " << daftar_pgn[i].saldo << endl;
                    cout << endl;
                }
                cout << "Apakah anda ingin kembali? y/n "; cin >> ulang;
                cin.ignore();
            }while(ulang == 'n');
            break;
            
            case 2 :
            do{
            system("cls");
            cout << "Berapa banyak data pengguna yang ingin ditambahkan : ";
            cin >> jumlahtambah;
            cin.ignore();
            cout << endl;

            for (int i = 0; i < jumlahtambah; i++) {
                if (x >= 10) {
                    cout << "Maaf, kapasitas data pengguna sudah penuh!" << endl;
                    break;
                }
                cout << "Nama Pengguna  : ";
                getline(cin, daftar_pgn[x].nama);
                cout << "No Hp Pengguna   : ";
                cin >> daftar_pgn[x].no_telp;
                cin.ignore();
                cout << "PIN Pengguna      : ";
                getline(cin, daftar_pgn[x].pin);
                cout << "Saldo Pengguna   : ";
                cin >> daftar_pgn[x].saldo;
                cin.ignore();
                x++;
            }
                cout << "Apakah anda ingin kembali? y/n "; cin >> ulang;
                cin.ignore();
            }while(ulang == 'n');
            break;
            
            case 3 :

            case 4 :
            kembali = 5;
            break;

            default :
            kembali = 1;
            break;
        }
    }while(kembali != 5);
}
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void login();
void daftar();
void menu();
int banyakPesan = 0;
string akun[100][3];
int kodeBarang[11] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011};
string jenisBarang[11] = {"Ayam Goreng", "Lotek", "Gado-Gado", "Wagyu A5", "Gurame Bakar", "Bebek Peking", "Telur Triceratops", "Daging Zombie", "Magelangan Mba Lis", "Babi Guling", "Unagi"};
int hargaBarang[11] = {18750, 12190, 10680, 767250, 45328, 31313, 56570, 123456, 12100, 27894, 60456};
string daftarPesanan[11];
float hargaPesanan[11][3];
bool found = false;
int banyak_user = 0;
int life = 3;

int main()
{
    int choice;
    bool ulang = true;

    while (ulang)
    {
        system("cls");
        cout << "Banyaknya user : " << banyak_user << endl;
        cout << "Selamat Datang!" << endl;
        cout << "1. Daftar" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            daftar();
            break;
        case 2:
            login();
            if (found == true)
            {
                menu();
            }
            break;
        case 3:
            ulang = false;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
        cout << "Banyaknya user: " << banyak_user << endl;
    }

    void menu();
}

void login()
{
    life = 3; 
    do
    {
        system("cls");
        string input_nama, input_pass;
        cout << "Masukan username anda: ";
        getline(cin, input_nama);
        cout << "Masukan pass anda    : ";
        getline(cin, input_pass);
        
        if (banyak_user == 0)
        {
            cout << "User tidak ada! Harap daftar terlebih dahulu\n";
        }

        for (int i = 0; i < banyak_user; ++i)
        {
            if (input_nama == akun[i][0] && input_pass == akun[i][1])
            {
                cout << "Login Berhasil!\n";
                found = true;
                system ("pause");
                return;
            }
        }

        life--;
        if (life > 0)
        {
            cout << "Username atau password salah!\n Sisa percobaan : " << life << endl;
            system ("pause");
        }
        else if (life == 0)
        {
            cout << "Login gagal! Anda telah kehabisan percobaan." << endl;

        }
    } while (life > 0);
}

void daftar()
{
    system("cls");
    string username;
    bool usernameValid;

    do
    {
        usernameValid = true;
        cout << "Masukan username anda: ";
        getline(cin, username);

        for (int i = 0; i < banyak_user; ++i)
        {
            if (username == akun[i][0])
            {
                usernameValid = false;
                cout << "Username sudah digunakan! Silahkan gunakan username lain.\n";
                cin.ignore();
                system ("cls");
            }
        }
    } while (!usernameValid);

    akun[banyak_user][0] = username;
    cout << "Masukan password anda: ";
    getline(cin, akun[banyak_user][1]);
    cout << "Masukkan nama anda: ";
    getline(cin, akun[banyak_user][2]);
    cout << "Registrasi berhasil!" << endl;
    banyak_user++;
    system ("pause");
}
void menu()
{
    bool keluar = false;
    int pilihan, kdBarang, jumlah;
    string namaCust[10];
    bool check = false, barang = false;
    char tambahan;
    while (!keluar)
    {
        system("cls");
        cout << "[1] Tambah pesan" << endl;
        cout << "[2] Lihat daftar pesanan" << endl;
        cout << "[3] keluar" << endl;
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            do
            {
                system("cls");
                cout << "Kode Barang" << "        " << "Nama Barang" << "          " << "Harga Barang" << endl;
                for (int i = 0; i < 11; i++)
                {
                    cout << "   " << kodeBarang[i] << setw(23) << setfill(' ') << jenisBarang[i] << setw(18) << hargaBarang[i] << endl;
                }
                cout << endl;
                cout << "Masukkan nama customer : ";
                cin >> namaCust[banyakPesan];
                cout << "Masukkan kode barang : ";
                cin >> kdBarang;
                if (kdBarang >= kodeBarang[0] && kdBarang <= kodeBarang[10])
                {

                    for (int i = -1; i <= 11; i++)
                    {
                        check = true;
                        if (kdBarang == kodeBarang[i])
                        {
                            barang = true;
                        }

                        if (barang == true)
                        {
                            cout << "Barang yang ingin anda beli adalah " << jenisBarang[i] << endl;
                            cout << "Berapa banyak barang yang ingin anda beli  : ";
                            cin >> jumlah;
                            cout << "Harga satuan barang tersebut adalah " << hargaBarang[i] << endl;
                            int subTotal = jumlah * hargaBarang[i];
                            cout << "SubTotal harga yang harus anda bayar = " << subTotal << endl;
                            float Total = (subTotal * 0.1) + subTotal;
                            cout << "Total harga setelah ditambah pajak 10% = " << Total << endl;
                            daftarPesanan[banyakPesan] = jenisBarang[i];
                            hargaPesanan[banyakPesan][2] = hargaBarang[i];
                            hargaPesanan[banyakPesan][0] = subTotal;
                            hargaPesanan[banyakPesan][1] = Total;
                            banyakPesan++;
                            cout << "Apakah ada barang tambahan (y/n) ? : ";
                            cin >> tambahan;
                            barang = false;
                        }
                    }
                }
                else
                {
                    cout << "Kode barang tidak valid!\n";
                    cin.ignore();
                    cin.get();
                }

            } while (tambahan != 'n');
            break;

        case 2:
        system("cls");
            if (banyakPesan == 0)
            {
                cout << "Anda belum memesan!\nSilahkan lakukan pemesanan terlebih dahulu\n";
            }
            else
            {
            cout << "--------------------Daftar Pesanan Anda--------------------" << endl;
                for (int i = 0; i < banyakPesan; i++)
                {
                    cout << "Nama Customer  : " << namaCust[i] << endl;
                    cout << "Nama Barang    : " << daftarPesanan[i] << endl;
                    cout << "Harga Satuan   : " << hargaPesanan[i][2] << endl;
                    cout << "Harga Subtotal : " << hargaPesanan[i][0] << endl;
                    cout << "Harga Total    : " << hargaPesanan[i][1] << endl;
                    cout << "-----------------------------------------------------------" << endl;
                }
            }
            cin.ignore();
            cin.get();
            break;
        case 3:
            keluar = true;
            break;
        default:
            cout << "Nomor menu tidak valid!\nMohon pilih nomor menu yang valid!\n";
            cin.ignore();
            cin.get();
            break;
        }
    }
}
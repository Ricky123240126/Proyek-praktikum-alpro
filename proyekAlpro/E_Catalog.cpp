#include <iostream>
#include <iomanip>
using namespace std;

/*Kelompok 6
1. Ricky muhammad haruniansyah (123240126)
2. Andini Papa Sulima (123240118)
3. Rafi Dzaka Pratama Putra (123240104)
4. Muhammad Wafa Akmal (123240113)
5. Nicolaus Narindra Lianto (123240100)
*/








bool admin = false;
string akun[100][3];
string nmBarang[100] = {"barang1", "barang2", "barang3", "barang4"}, deskripsi[100] = {"ini barang 1", "ini barang 2", "ini barang 3", "ini barang 4"};
int hargaBarang[100] = {10000, 20000, 30000, 40000}, stockBarang[100] = {10, 0, 30, 25}, banyakUser = 0, barang = 4;
bool login(string username, string password, int banyakUser);
void menuAdmin(bool &program), menuUser(bool &program), tampilkanBarang(), cariBarang(), kelolaBarang();
int main()
{
    int life = 3, pilihan;
    string username, password;
    bool program = true, user = false;

    while (life > 0 & program == true)
    {
        admin = false;
        system("cls");
        cout << setw(50) << setfill('=') << "\n";
        cout << setw(30) << setfill(' ') << "E-Catalog\n";
        cout << setw(50) << setfill('=') << "\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Keluar\n";
        cout << setw(50) << setfill('=') << "\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            if (banyakUser == 0)
            {
                cout << "Belum ada akun yang terdaftar!\nRegister terlebih dahulu..\n";
            }
            else
            {
                cout << "Masukkan username : ";
                cin >> username;
                cout << "Masukkan password : ";
                cin >> password;
                login(username, password, banyakUser);
                if (login(username, password, banyakUser) == true)
                {
                    cout << "Login berhasil...\n";
                    cin.ignore();
                    cin.get();
                    if (admin == true)
                    {
                        menuAdmin(program);
                    }
                    else
                    {
                        menuUser(program);
                    }
                }
                else
                {
                    life--;
                    if (life > 0)
                    {
                        cout << "Username / Password salah!!\nSilahkan coba lagi!\n";
                        cout << "tersisa " << life << "x percobaan lagi!\n";
                    }
                    else
                    {
                        cout << "percobaan habis program akan dihentikan...\n";
                    }
                }
            }
            cin.ignore();
            cin.get();
            break;
        case 2:
            cout << "Masukkan Username : ";
            cin >> akun[banyakUser][0];
            cout << "Masukkan Password : ";
            cin >> akun[banyakUser][1];
            cout << "Masukkan Nama     : ";
            cin >> akun[banyakUser][2];

            for (int i = 0; i < banyakUser; i++)
            {
                if (akun[banyakUser][0] == akun[i][0])
                {
                    user = true;
                }
            }
            if (user == false)
            {
                cout << "Akun dengan username " << akun[banyakUser][0] << " Berhasil dibuat!\n";
                banyakUser++;
            }
            else
            {
                cout << "Username " << akun[banyakUser][0] << " sudah terdaftar!\nGunakan username lain!!!\n";
            }
            cin.ignore();
            cin.get();
            break;
        case 3:
            program = false;
            break;

        default:
            cout << "Pilihan tidak valid!!\n";
            cin.ignore();
            cin.get();
            break;
        }
    }
}
bool login(string username, string password, int banyakUser)
{
    bool ketemu = false;
    for (int i = 0; i < banyakUser; i++)
    {
        if (username == akun[i][0] && password == akun[i][1])
        {
            ketemu = true;
        }
        else if (username == "admin" && password == "123")
        {
            ketemu = true;
            admin = true;
        }
    }

    if (ketemu == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void menuAdmin(bool &program)
{
    int pilihan;
    bool keluar = false;
    while (!keluar)
    {

        system("cls");
        cout << setw(50) << setfill('=') << "\n";
        cout << setw(30) << setfill(' ') << "Menu Admin\n";
        cout << setw(50) << setfill('=') << "\n";
        cout << "1. Tampilkan Barang\n";
        cout << "2. Kelola Barang\n";
        cout << "3. Kembali\n";
        cout << "4. Keluar\n";
        cout << setw(50) << setfill('=') << "\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            tampilkanBarang();
            cin.ignore();
            cin.get();
            break;
        case 2:
            kelolaBarang();
            break;
        case 3:
            keluar = true;
            break;
        case 4:
            keluar = true;
            program = false;
            break;

        default:
            cout << "Pilihan tidak valid!!\n";
            cin.ignore();
            cin.get();
            break;
        }
    }
}
void menuUser(bool &program)
{
    int pilihan;
    bool keluar = false;
    while (!keluar)
    {

        system("cls");
        cout << setw(50) << setfill('=') << "\n";
        cout << setw(30) << setfill(' ') << "Menu User\n";
        cout << setw(50) << setfill('=') << "\n";
        cout << "1. Tampilkan Barang\n";
        cout << "2. Cari Barang\n";
        cout << "3. Kembali\n";
        cout << "4. Keluar\n";
        cout << setw(50) << setfill('=') << "\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            tampilkanBarang();
            cin.ignore();
            cin.get();
            break;
        case 2:
            cariBarang();
            break;
        case 3:
            keluar = true;
            break;
        case 4:
            keluar = true;
            program = false;
            break;

        default:
            cout << "Pilihan tidak valid!!\n";
            cin.ignore();
            cin.get();
            break;
        }
    }
}
void tampilkanBarang()
{
    string stock;
    system("cls");
    cout << setw(75) << setfill('=') << "\n";
    cout << setw(42) << setfill(' ') << "E-Catalog\n";
    cout << setw(75) << setfill('=') << "\n";
    cout << "No" << setw(15) << setfill(' ') << "Nama Barang" << setw(26) << "Harga Barang" << setw(28) << "Stock Barang" << endl
         << endl;
    for (int i = 0; i < barang; i++)
    {
        if (stockBarang[i] == 0)
        {
            stock = "kosong  ";
        }
        else
        {
            stock = "tersedia";
        }
        cout << i + 1 << setw(13) << setfill(' ') << nmBarang[i] << setw(25) << hargaBarang[i] << setw(30) << stock << endl;
    }
}
void cariBarang()
{
    string nama;
    bool ketemu = false;
    system("cls");
    cout << "Masukkan nama barang yang ingin anda cari : ";
    cin >> nama;
    for (int i = 0; i < barang; i++)
    {
        if (nama == nmBarang[i])
        {
            cout << "Nama Barang    : " << nmBarang[i] << endl;
            cout << "Harga Barang   : " << hargaBarang[i] << endl;
            cout << "Stock Barang   : " << stockBarang[i] << endl;
            cout << "Deskripsi      : " << deskripsi[i] << endl;
            ketemu = true;
        }
    }
    if (ketemu == false)
    {
        cout << "Barang tidak ditemukan!\n";
    }
    cin.ignore();
    cin.get();
}

void kelolaBarang()
{
    int pilihan;
    char hapus;
    string nama;
    bool keluar = false, ganda = false, ketemu = false;
    while (!keluar)
    {
        pilihan = 0;
        system("cls");
        cout << setw(50) << setfill('=') << "\n";
        cout << setw(29) << setfill(' ') << "Menu kelola\n";
        cout << setw(50) << setfill('=') << "\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Hapus Barang\n";
        cout << "3. Edit Barang\n";
        cout << "4. Kembali\n";
        cout << setw(50) << setfill('=') << "\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            system("cls");

            cout << "Masukkan\n";
            cout << "Nama Barang      : ";
            cin >> nmBarang[barang];
            cout << "Harga Barang     : ";
            cin >> hargaBarang[barang];
            if (hargaBarang[barang] < 0)
            {
                cout << "Error!\nHarga hanya boleh bilangan bulat dan positif!\n";
                cin.ignore();
                cin.get();
                break;
            }
            cout << "Stock Barang     : ";
            cin >> stockBarang[barang];
            cin.ignore();
            cout << "Deskripsi Barang : ";
            getline(cin, deskripsi[barang]);
            for (int i = 0; i < barang; i++)
            {
                if (nmBarang[barang] == nmBarang[i])
                {
                    ganda = true;
                }
            }
            if (ganda == true)
            {
                cout << "Barang sudah ada!\nMohon input barang yang berbeda...\n";
            }
            else
            {
                cout << "Barang berhasil ditambahkan!\n";
                barang++;
            }
            cin.ignore();
            cin.get();
            break;
        case 2:
            tampilkanBarang();
            cout << "Masukkan nama barang yang ingin anda hapus : ";
            cin >> nama;
            cout << "Yakin ingin menghapus barang? (y/n) : ";
            cin >> hapus;
            tolower(hapus);
            if (hapus == 'y')
            {

                for (int i = 0; i < barang; i++)
                {
                    if (nama == nmBarang[i])
                    {
                        ketemu = true;

                        for (int j = i; j < barang - 1; j++)
                        {
                            nmBarang[j] = nmBarang[j + 1];
                            hargaBarang[j] = hargaBarang[j + 1];
                            stockBarang[j] = stockBarang[j + 1];
                            deskripsi[j] = deskripsi[j + 1];
                        }

                        barang--;
                        cout << "Barang berhasil dihapus!\n";
                        break;
                    }
                }

                if (ketemu == false)
                {
                    cout << "Barang tidak ditemukan!\n";
                }
            }
            else if (hapus == 'n')
            {
                cout << "Penghapusan dibatalkan!\n";
            }
            else
            {
                cout << "Mohon input jawaban yang valid (y/n)!\n";
            }
            cin.ignore();
            cin.get();
            break;
            break;
        case 3:
            tampilkanBarang();
            cout << "Masukkan nama barang yang ingin anda edit: ";
            cin >> nama;

            for (int i = 0; i < barang; i++)
            {
                if (nama == nmBarang[i])
                {
                    ketemu = true;
                    cout << "Barang ditemukan!\n";
                    cout << "Nama Barang Lama      : " << nmBarang[i] << endl;
                    cout << "Harga Barang Lama     : " << hargaBarang[i] << endl;
                    cout << "Stok Barang Lama      : " << stockBarang[i] << endl;
                    cout << "Deskripsi Barang Lama : " << deskripsi[i] << endl;

                    cout << "\nMasukkan data baru untuk barang ini:\n";
                    cout << "Nama Barang Baru      : ";
                    cin >> nmBarang[i];
                    cout << "Harga Barang Baru     : ";
                    cin >> hargaBarang[i];
                    if (hargaBarang[i] < 0)
                    {
                        cout << "Error! Harga hanya boleh bilangan bulat dan positif!\n";
                        cin.ignore();
                        cin.get();
                        break;
                    }
                    cout << "Stok Barang Baru      : ";
                    cin >> stockBarang[i];
                    cin.ignore();
                    cout << "Deskripsi Barang Baru : ";
                    getline(cin, deskripsi[i]);

                    cout << "\nBarang berhasil diperbarui!\n";
                    break;
                }
            }

            if (ketemu == false)
            {
                cout << "Barang tidak ditemukan!\n";
            }

            cin.ignore();
            cin.get();
            break;
            break;
        case 4:
            keluar = true;
            break;

        default:
            cout << "Pilihan tidak valid!!\n";
            cin.ignore();
            cin.get();
            break;
        }
    }
}
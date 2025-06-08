#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

//pengelola toko sepatu
//kurang menu edit sepatu(brand, model,harga,kpde,dll), hapus data sepatu, fungsi rekursif DONEEE
//fungsi search(mencari sepatu berdasar brand, model,hrga, dll) DONEEE

const int MAX_SEPATU = 100;

struct Sepatu {
    int kode;
    string brand;
    string model;
    int harga;
    int stok;
};

void tambahSepatu(Sepatu tokoSepatu[], int &jumlah) 
{
    if (jumlah >= MAX_SEPATU) {
        cout << "Data penuh, tidak dapat menambah sepatu baru.\n";
        return;
    }
    cout << "Silahkan Input\n";
    cout << "Kode Sepatu: ";
    cin >> tokoSepatu[jumlah].kode;
    cin.ignore();
    cout << "Brand Sepatu: ";
    getline(cin, tokoSepatu[jumlah].brand);
    cout << "Model Sepatu: ";
    getline(cin, tokoSepatu[jumlah].model);
    cout << "Harga Sepatu: ";
    cin >> tokoSepatu[jumlah].harga;
    cout << "Stok Sepatu: ";
    cin >> tokoSepatu[jumlah].stok;
    jumlah++;
    cout << "Sepatu berhasil ditambahkan!\n";
}

void tampilkanSepatu(Sepatu tokoSepatu[], int jumlah, int index = 0) 
{
    if (jumlah == 0)
    {
        cout << "Silahkan input sepatu terlebih dahulu\n";
        return;
    }
    if (index >= jumlah) return;
    else if (index <= jumlah)
    {
        cout << "Sepatu ke-" << index + 1 << endl;
        cout << "Kode: " << tokoSepatu[index].kode << endl;
        cout << "Brand: " << tokoSepatu[index].brand << endl;
        cout << "Model: " << tokoSepatu[index].model << endl;
        cout << "Harga: " << tokoSepatu[index].harga << endl;
        cout << "Stok: " << tokoSepatu[index].stok << endl;
        cout << "-------------------------\n";
        tampilkanSepatu(tokoSepatu, jumlah, index + 1);
    }
}

void hapusSepatu(Sepatu tokoSepatu[], int &jumlah, int kode) 
{
    bool ditemukan = false;
    string pilihHapus;
    for (int i = 0; i < jumlah; i++) {
        if (tokoSepatu[i].kode == kode) {
            ditemukan = true;
            for (int j = i; j < jumlah - 1; j++) {
                tokoSepatu[j] = tokoSepatu[j + 1];
            }
            jumlah--;
            cout << "Sepatu berhasil dihapus!\n";
            cout << "sepatu telah ditemukan dengan data berikut :\n";
            cout << "Kode: " << tokoSepatu[i].kode << endl;
            cout << "Brand: " << tokoSepatu[i].brand << endl;
            cout << "Model: " << tokoSepatu[i].model << endl;
            cout << "Harga: " << tokoSepatu[i].harga << endl;
            cout << "Stok: " << tokoSepatu[i].stok << endl;
            cout << "apakah anda yakin ingin menghapus sepatu? (y/n)\n";
            cout << "masukkan pilihan : \n"
            cin >> pilihHapus;
            if (pilihHapus == "y" || pilihHapus == "Y")
            {
                jumlah--;
                cout << "sepatu berhasil dihapus!" << endl;
            }
            else if (pilihHapus == "n" || pilihHapus == "N")
            {
                cout << "Sepatu gagal dihapus!" << endl;
            }
            break;
        }
    }
    if (!ditemukan) {
        cout << "Sepatu tidak ditemukan!\n";
    }
}

void editSepatuData(Sepatu* sepatu) {
    cout << "Masukkan data baru untuk sepatu:\n";
    cin.ignore();
    cout << "Brand Baru: ";
    getline(cin, sepatu->brand);
    cout << "Model Baru: ";
    getline(cin, sepatu->model);
    cout << "Harga Baru: ";
    cin >> sepatu->harga;
    cout << "Stok Baru: ";
    cin >> sepatu->stok;
    cout << "Sepatu berhasil diperbarui!\n";
}

void editSepatu(Sepatu tokoSepatu[], int jumlah, int kode) {
    bool ditemukan = false;
    for (int i = 0; i < jumlah; i++) {
        if (tokoSepatu[i].kode == kode) {
            ditemukan = true;
            editSepatuData(&tokoSepatu[i]);
            break;
        }
    }
    if (!ditemukan) {
        cout << "Sepatu tidak ditemukan!\n";
    }
}

void cariSepatu(Sepatu tokoSepatu[], int jumlah)
{
    bool found = false;
    int i = 0;
    int kode;
    cout << "masukkan kode sepatu yang ingin dicari = ";
    cin >> kode;

    while(i<jumlah && found==false)
    {
        if (tokoSepatu[i].kode == kode)
        {
            found = true;
            if (found)
            {
            cout << "sepatu telah ditemukan dengan data berikut :\n";
            cout << "Kode: " << tokoSepatu[i].kode << endl;
            cout << "Brand: " << tokoSepatu[i].brand << endl;
            cout << "Model: " << tokoSepatu[i].model << endl;
            cout << "Harga: " << tokoSepatu[i].harga << endl;
            cout << "Stok: " << tokoSepatu[i].stok << endl;
            }
        }
        else
        { 
        i++;
        }
    }
    if (!found) 
    {
        cout << "Sepatu tidak ditemukan!\n";
    }
}

void sortingSepatu_Desc(Sepatu tokoSepatu[], int jumlah) {
    int pilihan;
    do {
        system("cls");
        cout << "=== Menu Sorting ===\n";
        cout << "1. Brand (Z-A)\n";
        cout << "2. Kode (Besar ke Kecil)\n";
        cout << "3. Harga (Mahal ke Murah)\n";
        cout << "4. Kembali ke Menu Utama\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 4) break;

        for (int i = 0; i < jumlah - 1; i++) {
            for (int j = 0; j < jumlah - i - 1; j++) {
                bool tukar = false;
                switch (pilihan) {
                    case 1: 
                        if (tokoSepatu[j].brand < tokoSepatu[j + 1].brand)
                            tukar = true;
                        break;
                    
                    case 2: 
                        if (tokoSepatu[j].kode < tokoSepatu[j + 1].kode)
                            tukar = true;
                        break;
                    
                    case 3: 
                        if (tokoSepatu[j].harga < tokoSepatu[j + 1].harga)
                            tukar = true;
                        break;
                    
                    default:
                        cout << "Pilihan tidak valid.\n";
                        break;
                }
                if (tukar) {
                    Sepatu temp = tokoSepatu[j];
                    tokoSepatu[j] = tokoSepatu[j + 1];
                    tokoSepatu[j + 1] = temp;
                }
            }
        }

        if (pilihan >= 1 && pilihan <= 6) {
            cout << "\nData berhasil diurutkan!\n\n";
            tampilkanSepatu(tokoSepatu, jumlah);
            system("pause");
        }

    } while (pilihan != 4);
}


void sortingSepatu_Asc(Sepatu tokoSepatu[], int jumlah) {
    int pilihan;
    do {
        system("cls");
        cout << "=== Menu Sorting ===\n";
        cout << "1. Brand (A-Z)\n";
        cout << "2. Kode (Kecil ke Besar)\n";
        cout << "3. Harga (Murah ke Mahal)\n";
        cout << "4. Kembali ke Menu Utama\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 4) break;

        for (int i = 0; i < jumlah - 1; i++) {
            for (int j = 0; j < jumlah - i - 1; j++) {
                bool tukar = false;
                switch (pilihan) {
                    case 1: 
                        if (tokoSepatu[j].brand > tokoSepatu[j + 1].brand)
                            tukar = true;
                        break;
                    
                    case 2: 
                        if (tokoSepatu[j].kode > tokoSepatu[j + 1].kode)
                            tukar = true;
                        break;
                    
                    case 3: 
                        if (tokoSepatu[j].harga > tokoSepatu[j + 1].harga)
                            tukar = true;
                        break;
                    
                    default:
                        cout << "Pilihan tidak valid.\n";
                        break;
                }
                if (tukar) {
                    Sepatu temp = tokoSepatu[j];
                    tokoSepatu[j] = tokoSepatu[j + 1];
                    tokoSepatu[j + 1] = temp;
                }
            }
        }

        if (pilihan >= 1 && pilihan <= 6) {
            cout << "\nData berhasil diurutkan!\n\n";
            tampilkanSepatu(tokoSepatu, jumlah);
            system("pause");
        }

    } while (pilihan != 4);
}

void simpanKeFile(Sepatu tokoSepatu[], int jumlah) {
    ofstream file("data Sepatu.txt");
    if (file.is_open()) {
        file << left << setw(8) << "Kode"
            << setw(15) << "Brand"
            << setw(20) << "Model"
            << setw(12) << "Harga"
            << setw(6) << "Stok" << endl;

        for (int i = 0; i < jumlah; i++) {
            file << left << setw(8) << tokoSepatu[i].kode
                << setw(15) << tokoSepatu[i].brand
                << setw(20) << tokoSepatu[i].model
                << setw(12) << tokoSepatu[i].harga
                << setw(6) << tokoSepatu[i].stok << endl;
        }

        file.close();
    } else {
        cout << "Gagal membuka file!" << endl;
    }
}

void bacaDariFile(Sepatu tokoSepatu[], int &jumlah) {
    ifstream file("data Sepatu.txt");
    jumlah = 0;

    if (file.is_open()) {
        string baris;
        getline(file, baris); 

        while (getline(file, baris)) {
            if (baris.empty()) continue; 

            istringstream iss(baris);
            Sepatu temp;

            if (!(iss >> temp.kode >> temp.brand >> temp.model >> temp.harga >> temp.stok)) {
                continue;
            }

            tokoSepatu[jumlah++] = temp;
        }

        file.close();
    } else {
        cout << "Gagal membuka file!" << endl;
    }
}


int main() {
    Sepatu tokoSepatu[MAX_SEPATU];
    int jumlah = 0;
    int pilihan, kode;
    
    tokoSepatu[0] = {1002, "Nike", "Air-Max", 1250000, 10};
    tokoSepatu[1] = {1003, "Adidas", "Ultraboost", 1500000, 5};
    tokoSepatu[2] = {1001, "Puma", "RS-X", 1100000, 8};
    bacaDariFile(tokoSepatu,jumlah);

    do {
        cout << "\n====== MENU TOKO SEPATU ======\n";
        cout << "1. Tambah Sepatu\n";
        cout << "2. Tampilkan semua Sepatu\n";
        cout << "3. Edit Sepatu\n";
        cout << "4. Hapus Sepatu\n";
        cout << "5. Cari Sepatu\n";
        cout << "6. Sorting Sepatu\n";
        cout << "7. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << endl;
        switch (pilihan) {
            case 1:
                system("cls");
                tambahSepatu(tokoSepatu, jumlah);
                simpanKeFile(tokoSepatu, jumlah);
                break;

            case 2:
                system("cls");
                bacaDariFile(tokoSepatu, jumlah);
                tampilkanSepatu(tokoSepatu, jumlah);
                break;

            case 3:
                system("cls");
                cout << "Masukkan kode sepatu yang ingin diedit: ";
                cin >> kode;
                editSepatu(tokoSepatu, jumlah, kode);
                simpanKeFile(tokoSepatu, jumlah);
                break;

            case 4:
                system("cls");
                cout << "Masukkan kode sepatu yang ingin dihapus: ";
                cin >> kode;
                hapusSepatu(tokoSepatu, jumlah, kode);
                simpanKeFile(tokoSepatu, jumlah);

                break;
            case 5:
                system("cls");
                cariSepatu(tokoSepatu, jumlah);
                break;
            case 6:
                system("cls");
                int milihcase_ascdesc;
                cout<<"1. Urutkan Berdasarkan Data Terbesar - Terkecil (Descending)"<<endl;
                cout<<"2. Urutkan Berdasarkan Data Terkecil - Terbesar (Ascending)"<<endl;
                cout<<"Masukkan Pilihan Anda :";
                cin>>milihcase_ascdesc;
                switch (milihcase_ascdesc)
                {
                case 1:
                    sortingSepatu_Desc(tokoSepatu, jumlah);
                    break;
                case 2:
                    sortingSepatu_Asc(tokoSepatu, jumlah);
                    break;
                default:
                    break;
                }
                break;
            case 7:
                cout << "Keluar dari program.\n";
                return 0;
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (pilihan != 8);
    return 0;
}

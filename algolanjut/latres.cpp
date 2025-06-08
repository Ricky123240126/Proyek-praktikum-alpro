#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


struct penduduk {
    int no_kependudukan;
    string nama, jenis_kelamin;
};


int tampilkan_data_dari_file(penduduk P[]);
void input_data(penduduk P[], int &data, int &jumlah);
void tampilkanData(penduduk P[], int jumlah, int index = 0);


int tampilkan_data_dari_file(penduduk P[]) {
    ifstream file("Data Kependudukan.txt");
    int i = 0;

    if (!file.is_open()) {
        cout << "Gagal membuka file untuk membaca data.\n";
        return 0;
    }

    while (!file.eof()) {
        int no_urut;
        file >> no_urut;

        if (file.eof()) break;

        file >> P[i].no_kependudukan;

        string nama_kata, nama_lengkap = "", jenis_kelamin;

        while (file >> nama_kata) {
            if (nama_kata == "Laki-laki" || nama_kata == "Perempuan") {
                P[i].jenis_kelamin = nama_kata;
                break;
            } else {
                if (!nama_lengkap.empty()) nama_lengkap += " ";
                nama_lengkap += nama_kata;
            }
        }

        P[i].nama = nama_lengkap;
        i++;
    }

    file.close();
    return i;
}


void input_data(penduduk P[], int &data, int &jumlah) {
    jumlah = tampilkan_data_dari_file(P); 

    cout << "Masukkan jumlah data yang ingin diinput : ";
    cin >> data;
    cin.ignore();
    cout << endl;

    for (int i = jumlah; i < jumlah + data; i++) {
        cout << "Inputkan data ke-" << i + 1 << endl;
        cout << "Nomor Kependudukan : ";
        cin >> P[i].no_kependudukan;
        cin.ignore();
        cout << "Nama Penduduk : ";
        getline(cin, P[i].nama);
        cout << "Jenis Kelamin (L/P) : ";
        getline(cin, P[i].jenis_kelamin);

        if (P[i].jenis_kelamin == "l" || P[i].jenis_kelamin == "L")
            P[i].jenis_kelamin = "Laki-laki";
        else if (P[i].jenis_kelamin == "p" || P[i].jenis_kelamin == "P")
            P[i].jenis_kelamin = "Perempuan";

        cout << endl;
    }


    ofstream fileOutput("Data Kependudukan.txt", ios::app);
    if (fileOutput.is_open()) {
        for (int i = jumlah; i < jumlah + data; i++) {
            fileOutput << left << setw(3) << i + 1
                       << setw(20) << P[i].no_kependudukan
                       << setw(25) << P[i].nama
                       << setw(15) << P[i].jenis_kelamin << endl;
        }
        fileOutput.close();
        cout << "Data berhasil disimpan ke file!\n\n";
    } else {
        cout << "Gagal membuka file untuk penulisan.\n";
    }

    jumlah += data;
    system("pause");
}

void tampilkanData(penduduk P[], int jumlah, int index) {
    if (jumlah == 0) {
        cout << "Tidak ada data untuk ditampilkan.\n";
        return;
    }

    if (index >= jumlah) return;

    cout << "Data Kependudukan ke-" << index + 1 << endl;
    cout << "Nomor Kependudukan : " << P[index].no_kependudukan << endl;
    cout << "Nama               : " << P[index].nama << endl;
    cout << "Jenis Kelamin      : " << P[index].jenis_kelamin << endl;
    cout << "-------------------------------------------------\n";

    tampilkanData(P, jumlah, index + 1);
}

int main() {
    int pilihan;
    int data = 0;
    int jumlah;
    penduduk P[100];
    bool kembali = true;
    string back;

    while (kembali) {
        system("cls");
        cout << setw(30) << setfill('=') << "\n";
        cout << setw(15) << setfill(' ') << "MENU" << endl;
        cout << setw(30) << setfill('=') << "\n";
        cout << "1. Input Data" << endl;
        cout << "2. Lihat Data" << endl;
        cout << "3. Sorting Data (belum tersedia)" << endl;
        cout << "4. Filter Data (belum tersedia)" << endl;
        cout << "5. Exit" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << setw(40) << setfill('=') << "\n";
                cout << setw(25) << setfill(' ') << "INPUT DATA" << endl;
                cout << setw(40) << setfill('=') << "\n";
                input_data(P, data, jumlah);
                cout << "Apakah Anda ingin kembali ke menu (y/n)? ";
                cin >> back;
                if (back == "y" || back == "Y")
                {
                    kembali = true;
                }
                else if (back == "n" || back == "N")
                {
                    kembali = false;
                }
                break;

            case 2:
                system("cls");
                jumlah = tampilkan_data_dari_file(P);
                tampilkanData(P, jumlah);
                system("pause");
                break;

            case 3:
                cout << "Fitur sorting belum tersedia.\n";
                break;

            case 4:
                cout << "Fitur filter belum tersedia.\n";
                break;

            case 5:
                cout << "Terima kasih telah menggunakan program ini!\n";
                kembali = false;
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}

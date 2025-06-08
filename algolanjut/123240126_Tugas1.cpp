#include <iostream>

using namespace std;


struct Pegawai {
    int id;
    string nama, tanggal;
    string jabatan;
    int gaji;
};

struct Jabatan {
    string namaJabatan;
    int gaji;
};

Jabatan daftarJabatan[] = {
    {"Direktur", 10000000},
    {"Manajer Keuangan", 9000000},
    {"Supervisor", 8500000},
    {"Staff IT", 6500000},
    {"Admin", 5000000}
};

double hitungGajiBersih(double gaji) {
    if (gaji == 0) 
    {
        return 0;
    }else
    return gaji - (gaji * 0.12);
}

void inputPegawai(Pegawai pegawai[], int &total_diinput, int total) {
    if (total_diinput >= total) {
        cout << "Jumlah pegawai telah mencapai batas maksimal!\n";
        return;
    }

    Pegawai p;
    cout << "\nMasukkan ID Pegawai: ";
    cin >> p.id;
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, p.nama);
    cout << "Masukkan Tanggal Lahir (dd-mm-yyyy): ";
    cin >> p.tanggal;

    cout << "Pilih Jabatan:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << daftarJabatan[i].namaJabatan << " (Gaji: Rp " << daftarJabatan[i].gaji << ")\n";
    }
    int pilihanJabatan;
    cout << "Masukkan nomor jabatan: ";
    cin >> pilihanJabatan;

    if (pilihanJabatan < 1 || pilihanJabatan > 5) {
        cout << "Pilihan jabatan tidak valid!\n";
        return;
    }

    p.jabatan = daftarJabatan[pilihanJabatan - 1].namaJabatan;
    p.gaji = hitungGajiBersih(daftarJabatan[pilihanJabatan - 1].gaji); 
    pegawai[total_diinput] = p;
    total_diinput++;

    cout << "Pegawai berhasil ditambahkan!\n";
}

void cariPegawai(Pegawai pegawai[], int total_diinput) {
    if (total_diinput == 0) {
        cout << "Belum ada data pegawai!\n";
        return;
    }

    int cari;
    cout << "Masukkan ID pegawai yang ingin dicari: ";
    cin >> cari;

    bool found = false;
    int i=0;
    while(i < total_diinput && found == false) {
        if (pegawai[i].id == cari) {
            cout << "\nPegawai ditemukan:\n";
            cout << "Nama         : " << pegawai[i].nama << endl;
            cout << "ID           : " << pegawai[i].id << endl;
            cout << "Tanggal Lahir: " << pegawai[i].tanggal << endl;
            cout << "Jabatan      : " << pegawai[i].jabatan << endl;
            cout << "Gaji Bersih  : Rp " << pegawai[i].gaji << endl;
            found = true;
            break;
        }
        else{
            i++;
        }
    }

    if (!found) {
        cout << "Data karyawan tidak ditemukan!\n";
    }
}

void menu() {
    int total, total_diinput = 0;
    
    cout << "Masukkan jumlah pegawai yang akan diinput: ";
    cin >> total;
    Pegawai pegawai[total];

    int pilihan;
    while (true) {
        cout << "\n=== PERUSAHAAN TATANG ===\n";
        cout << "1. Input data pegawai\n";
        cout << "2. Cari data pegawai\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputPegawai(pegawai, total_diinput, total);
                break;
            case 2:
                cariPegawai(pegawai, total_diinput);
                break;
            case 3:
                cout << "Terima kasih telah menggunakan program!\n";
                return;
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}

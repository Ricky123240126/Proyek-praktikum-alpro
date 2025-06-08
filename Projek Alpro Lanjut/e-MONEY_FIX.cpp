#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// variabel global
struct pengguna
{
    string nama[50];        
    string password[50][2]; 
    string tanggalLahir[50];
    int saldo[50];         
    int sisasaldo[50];
    string pin, no_rek;
    float saldo_akhir, uang, nominal;
    int randomNum;
    int bulanTertunggak[50] = {0, 0, 0, 0, 0};
    double hutang[50] = {0, 0, 0, 0, 0};
} dataPengguna;

struct transaksi
{
    string tanggal;
    double jumlah;
    string deskripsi;
};

transaksi dataTransaksi[5][100] = {
    {{"2025-03-01", 150000, "Pembelian buku"},
     {"2025-03-03", 200000, "Pembayaran utang"},
     {"2025-03-10", 500000, "Transfer uang ke teman"},
     {"2025-03-07", 250000, "Pembelian gadget"},
     {"2025-03-09", 100000, "Top up saldo"}},

    {{"2025-03-02", 50000, "Top up saldo"},
     {"2025-03-04", 150000, "Pembelian pulsa"},
     {"2025-03-06", 70000, "Pembayaran belanja"},
     {"2025-03-08", 300000, "Pembelian tiket pesawat"},
     {"2025-03-09", 500000, "Transfer uang"}},

    {{"2025-03-01", 250000, "Pembelian tiket"},
     {"2025-03-04", 300000, "Transfer uang ke keluarga"}},

    {{"2025-03-02", 180000, "Pembelian makanan"},
     {"2025-03-04", 250000, "Pembayaran utang"},
     {"2025-03-07", 350000, "Pembelian buku"}},

    {{"2025-03-01", 500000, "Transfer uang"},
     {"2025-03-03", 100000, "Top up saldo"}}};

int jumlahTransaksi[5] = {5, 5, 2, 3, 2};
int i;
char pilih;
int jumlahpengguna = 5;

// Deklarasi fungsi
void gantiPin(int i);
void menuInd(int i);
void cetakResiTf();
void resiSetor(int i);
void simpanTransaksiKeFile();
void bacaTransaksiDariFile();
void tambahTransaksi(int userIndex, string tanggal, double jumlah, string deskripsi);

// Fungsi untuk mendapatkan tanggal sekarang
string getTanggalSekarang() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    char buffer[12];
    sprintf(buffer, "%04d-%02d-%02d", 
            1900 + ltm->tm_year, 
            1 + ltm->tm_mon, 
            ltm->tm_mday);
    
    return string(buffer);
}

// Fungsi untuk menyimpan transaksi ke file
void simpanTransaksiKeFile() {
    ofstream file("riwayat_transaksi.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file transaksi untuk penulisan!" << endl;
        return;
    }

    for (int i = 0; i < jumlahpengguna; i++) {
        file << "USER:" << dataPengguna.nama[i] << "|" << jumlahTransaksi[i] << endl;
        for (int j = 0; j < jumlahTransaksi[i]; j++) {
            file << dataTransaksi[i][j].tanggal << "|" 
                 << dataTransaksi[i][j].jumlah << "|" 
                 << dataTransaksi[i][j].deskripsi << endl;
        }
    }
    file.close();
}

// Fungsi untuk membaca transaksi dari file
void bacaTransaksiDariFile() {
    ifstream file("riwayat_transaksi.txt");
    if (!file.is_open()) {
        cout << "File transaksi tidak ditemukan, menggunakan data default." << endl;
        return;
    }

    string line;
    int currentUser = -1;
    
    while (getline(file, line)) {
        if (line.find("USER:") == 0) {
            size_t pos1 = line.find(':');
            size_t pos2 = line.find('|');
            if (pos1 != string::npos && pos2 != string::npos) {
                string namaUser = line.substr(pos1 + 1, pos2 - pos1 - 1);
                int jumlah = stoi(line.substr(pos2 + 1));
                
                // Cari index user berdasarkan nama
                for (int i = 0; i < jumlahpengguna; i++) {
                    if (dataPengguna.nama[i] == namaUser) {
                        currentUser = i;
                        jumlahTransaksi[i] = jumlah;
                        break;
                    }
                }
            }
        } else if (currentUser != -1 && !line.empty()) {
            size_t pos1 = line.find('|');
            size_t pos2 = line.find('|', pos1 + 1);
            
            if (pos1 != string::npos && pos2 != string::npos) {
                string tanggal = line.substr(0, pos1);
                double jumlah = stod(line.substr(pos1 + 1, pos2 - pos1 - 1));
                string deskripsi = line.substr(pos2 + 1);
                
                // Cari slot kosong untuk transaksi
                for (int j = 0; j < jumlahTransaksi[currentUser]; j++) {
                    if (dataTransaksi[currentUser][j].tanggal.empty()) {
                        dataTransaksi[currentUser][j] = {tanggal, jumlah, deskripsi};
                        break;
                    }
                }
            }
        }
    }
    file.close();
}

// Fungsi untuk menambah transaksi baru
void tambahTransaksi(int userIndex, string tanggal, double jumlah, string deskripsi) {
    if (jumlahTransaksi[userIndex] < 100) {
        dataTransaksi[userIndex][jumlahTransaksi[userIndex]] = {tanggal, jumlah, deskripsi};
        jumlahTransaksi[userIndex]++;
        simpanTransaksiKeFile();
    }
}

// Fungsi untuk export riwayat transaksi ke file terpisah
void exportRiwayatTransaksi(int userIndex) {
    string filename = "riwayat_" + dataPengguna.nama[userIndex] + ".txt";
    ofstream file(filename);
    
    if (!file.is_open()) {
        cout << "Gagal membuat file export!" << endl;
        return;
    }

    file << "===============================================" << endl;
    file << "           RIWAYAT TRANSAKSI" << endl;
    file << "===============================================" << endl;
    file << "Nama Pengguna: " << dataPengguna.nama[userIndex] << endl;
    file << "Nomor Rekening: " << dataPengguna.password[userIndex][0] << endl;
    file << "Tanggal Export: " << getTanggalSekarang() << endl;
    file << "===============================================" << endl << endl;

    if (jumlahTransaksi[userIndex] == 0) {
        file << "Tidak ada transaksi yang tercatat." << endl;
    } else {
        for (int j = 0; j < jumlahTransaksi[userIndex]; j++) {
            file << "Tanggal: " << dataTransaksi[userIndex][j].tanggal << endl;
            file << "Jumlah: Rp " << fixed << setprecision(0) << dataTransaksi[userIndex][j].jumlah << endl;
            file << "Deskripsi: " << dataTransaksi[userIndex][j].deskripsi << endl;
            file << "-----------------------------------------------" << endl;
        }
    }

    file << endl << "Total Transaksi: " << jumlahTransaksi[userIndex] << endl;
    file << "===============================================" << endl;
    file.close();

    cout << "\nRiwayat transaksi berhasil disimpan ke file: " << filename << endl;
    cout << "File tersimpan di direktori program." << endl;
}

int hitungUmur(string tanggalLahir) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int tahunSekarang = 1900 + ltm->tm_year;
    int bulanSekarang = 1 + ltm->tm_mon;
    int hariSekarang = ltm->tm_mday;
    
    int hari = stoi(tanggalLahir.substr(0, 2));
    int bulan = stoi(tanggalLahir.substr(3, 2));
    int tahun = stoi(tanggalLahir.substr(6, 4));
    
    int umur = tahunSekarang - tahun;

    if (bulanSekarang < bulan || (bulanSekarang == bulan && hariSekarang < hari)) {
        umur--;
    }
    
    return umur;
}

bool validasiTanggal(string tanggal) {
    if (tanggal.length() != 10) return false;
    if (tanggal[2] != '/' || tanggal[5] != '/') return false;
    
    try {
        int hari = stoi(tanggal.substr(0, 2));
        int bulan = stoi(tanggal.substr(3, 2));
        int tahun = stoi(tanggal.substr(6, 4));
        
        if (hari < 1 || hari > 31) return false;
        if (bulan < 1 || bulan > 12) return false;
        if (tahun < 1900 || tahun > 2025) return false;
        
        return true;
    } catch (...) {
        return false;
    }
}

void simpanDataKeFile()
{
    FILE *file = fopen("data_pengguna.txt", "w");
    if (file == NULL)
    {
        cout << "Gagal membuka file untuk penulisan!" << endl;
        return;
    }

    for (int i = 0; i < jumlahpengguna; i++)
    {
        fprintf(file, "%s %s %s %s %d\n",
                dataPengguna.nama[i].c_str(),
                dataPengguna.password[i][0].c_str(),
                dataPengguna.password[i][1].c_str(),
                dataPengguna.tanggalLahir[i].c_str(),
                dataPengguna.saldo[i]);
    }

    fclose(file);
}

void bacaDataDariFile()
{
    FILE *file = fopen("data_pengguna.txt", "r");
    if (file == NULL)
    {
        cout << "File tidak ditemukan, menggunakan data default." << endl;
        dataPengguna.nama[0] = "Alice";
        dataPengguna.password[0][0] = "123456";
        dataPengguna.password[0][1] = "111111";
        dataPengguna.tanggalLahir[0] = "01/01/1990";
        dataPengguna.saldo[0] = 1000000;

        dataPengguna.nama[1] = "Bob";
        dataPengguna.password[1][0] = "234567";
        dataPengguna.password[1][1] = "222222";
        dataPengguna.tanggalLahir[1] = "15/05/1985";
        dataPengguna.saldo[1] = 1500000;

        dataPengguna.nama[2] = "Charlie";
        dataPengguna.password[2][0] = "345678";
        dataPengguna.password[2][1] = "333333";
        dataPengguna.tanggalLahir[2] = "20/12/1992";
        dataPengguna.saldo[2] = 800000;

        dataPengguna.nama[3] = "Diana";
        dataPengguna.password[3][0] = "456789";
        dataPengguna.password[3][1] = "444444";
        dataPengguna.tanggalLahir[3] = "10/08/1988";
        dataPengguna.saldo[3] = 1200000;

        dataPengguna.nama[4] = "Eve";
        dataPengguna.password[4][0] = "567890";
        dataPengguna.password[4][1] = "555555";
        dataPengguna.tanggalLahir[4] = "25/03/1995";
        dataPengguna.saldo[4] = 900000;
        return;
    }

    jumlahpengguna = 0;
    char nama[50], pass1[50], pass2[50], tglLahir[15];
    int saldo;

    while (fscanf(file, "%s %s %s %s %d", nama, pass1, pass2, tglLahir, &saldo) == 5)
    {
        if (jumlahpengguna >= 50)
            break;

        dataPengguna.nama[jumlahpengguna] = nama;
        dataPengguna.password[jumlahpengguna][0] = pass1;
        dataPengguna.password[jumlahpengguna][1] = pass2;
        dataPengguna.tanggalLahir[jumlahpengguna] = tglLahir;
        dataPengguna.saldo[jumlahpengguna] = saldo;
        jumlahpengguna++;
    }
    fclose(file);
}

void daftarPengguna()
{
    system("cls");
    cin.ignore();
    if (jumlahpengguna >= 50)
    {
        cout << "Maaf, jumlah pengguna maksimal telah tercapai." << endl;
        system("pause");
        return;
    }

    string namaBaru, norekBaru, pinBaru, tanggalLahirBaru;
    cout << "\n=== PENDAFTARAN PENGGUNA BARU ===\n";
    cout << "Masukkan nama: ";
    cin >> namaBaru;
    cout << "Masukkan nomor HP : ";
    cin >> norekBaru;

    for (int i = 0; i < jumlahpengguna; i++)
    {
        if (dataPengguna.password[i][0] == norekBaru)
        {
            cout << "Nomor rekening sudah terdaftar!" << endl;
            system("pause");
            return;
        }
    }

    bool tanggalValid = false;
    while (!tanggalValid) {
        cout << "Masukkan tanggal lahir (DD/MM/YYYY): ";
        cin >> tanggalLahirBaru;
        
        if (!validasiTanggal(tanggalLahirBaru)) {
            cout << "Format tanggal tidak valid! Gunakan format DD/MM/YYYY" << endl;
            system("pause");
            continue;
        }
        
        int umur = hitungUmur(tanggalLahirBaru);
        if (umur < 17) {
            cout << "Maaf, Anda harus berusia minimal 17 tahun untuk mendaftar." << endl;
            cout << "Umur Anda saat ini: " << umur << " tahun" << endl;
            cout << "Pendaftaran dibatalkan." << endl;
            system("pause");
            return; 
        }
        
        tanggalValid = true;
        cout << "Umur Anda: " << umur << " tahun - Valid untuk mendaftar!" << endl;
    }

    cout << "Masukkan PIN (6 digit): ";
    cin >> pinBaru;

    dataPengguna.nama[jumlahpengguna] = namaBaru;
    dataPengguna.password[jumlahpengguna][0] = norekBaru;
    dataPengguna.password[jumlahpengguna][1] = pinBaru;
    dataPengguna.tanggalLahir[jumlahpengguna] = tanggalLahirBaru;
    dataPengguna.saldo[jumlahpengguna] = 0;
    jumlahTransaksi[jumlahpengguna] = 0;
    
    jumlahpengguna++;

    simpanDataKeFile();
    cout << "Pendaftaran berhasil! Silakan login dengan PIN Anda." << endl;
    system("pause");
}

void pilihMenu(int i)
{
    int pilihmenu;
    bool ulang = 1;
    char selesai;
    while (ulang == true)
    {
        cout << "Apakah Anda Ingin Mengganti PIN?" << endl;
        cout << "1. Iya" << endl;
        cout << "2 Tidak" << endl;
        cin >> pilihmenu;
        if (pilihmenu == 1)
        {
            gantiPin(i);
            break;
        }
        else if (pilihmenu == 2)
        {
            selesai = 'y';
            break;
        }
        else
        {
            cout << "Anda Salah Memasukkan Pilihan Masukkan Pilihan Yang Benar" << endl;
            getch();
            system("cls");
            ulang = 1;
        }
    }
    while (selesai != 'y')
        ;
}

void infoInd(int i)
{
    system("cls");
    cout << setiosflags(ios::left) << setw(32) << setfill('=') << "" << endl;
    cout << "|" << setiosflags(ios::left) << setw(6) << setfill(' ') << "" << "INFORMASI PENGGUNA" << setw(6) << setfill(' ') << "" << "|" << endl;
    cout << setiosflags(ios::left) << setw(32) << setfill('=') << "" << endl;
    cout << "|" << setiosflags(ios::left) << setw(1) << setfill(' ') << "" << "Nama Pengguna  : " << dataPengguna.nama[i] << setw(8) << setfill(' ') << "" << "|" << endl;
    cout << "|" << setiosflags(ios::left) << setw(1) << setfill(' ') << "" << "Nomor Rekening : " << dataPengguna.password[i][0] << setw(3) << setfill(' ') << "" << "|" << endl;
    cout << "|" << setiosflags(ios::left) << setw(1) << setfill(' ') << "" << "Tanggal Lahir  : " << dataPengguna.tanggalLahir[i] << setw(3) << setfill(' ') << "" << "|" << endl;
    cout << "|" << setiosflags(ios::left) << setw(1) << setfill(' ') << "" << "PIN            : " << dataPengguna.password[i][1] << setw(6) << setfill(' ') << "" << "|" << endl;
    cout << setiosflags(ios::left) << setw(32) << setfill('=') << "" << endl;
    cout << endl;
    pilihMenu(i);
}

void gantiPin(int i)
{
    system("cls");
    string passwordBaru;
    cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
    cout << "|" << setiosflags(ios::left) << setw(10) << setfill(' ') << "" << "GANTI PIN" << setw(10) << setfill(' ') << "" << "|" << endl;
    cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
    cout << "Masukkan PIN Baru : ";
    cin >> passwordBaru;
    dataPengguna.password[i][1] = passwordBaru;
    simpanDataKeFile();
    cout << "PIN Berhasil Diubah!" << endl;
    getch();
    menuInd(i);
}

void saldoPengguna(int i)
{
    system("cls");
    cout << "=============================" << endl;
    cout << "                            " << endl;
    cout << "    SALDO REKENING ANDA     " << endl;
    cout << "                            " << endl;
    cout << "       Rp. " << dataPengguna.saldo[i] << " " << endl;
    cout << "                            " << endl;
    cout << "=============================" << endl;
}

void setorTunai(int &i)
{
    char resi;
    system("cls");
    cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
    cout << "|" << setiosflags(ios::left) << setw(9) << setfill(' ') << "" << "SETOR TUNAI" << setw(9) << setfill(' ') << "" << "|" << endl;
    cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
    cout << "Masukkan nominal setor anda : ";
    cin >> dataPengguna.nominal;

    dataPengguna.sisasaldo[i] = dataPengguna.saldo[i] + dataPengguna.nominal;
    dataPengguna.saldo[i] = dataPengguna.sisasaldo[i];
    simpanDataKeFile();

    tambahTransaksi(i, getTanggalSekarang(), dataPengguna.nominal, "Setor Tunai");

    cout << "\nTransaksi Berhasil!" << endl;

    cout << "Apakah Anda Ingin Cetak Resi? (y/n) : " << resi;
    cin >> resi;

    if (resi == 'y' || resi == 'Y')
    {
        resiSetor(i);
    }
    else
    {
        cout << "Nominal Saldo Anda : " << dataPengguna.sisasaldo[i] << endl << endl;
    }
}

void TarikTunai(int i)
{
    system("cls");
    int pilihan;

    cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
    cout << "|" << setiosflags(ios::left) << setw(9) << setfill(' ') << "" << "TARIK TUNAI" << setw(9) << setfill(' ') << "" << "|" << endl;
    cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
    cout << "1. 100.000" << endl;
    cout << "2. 300.000" << endl;
    cout << "3. 500.000" << endl;
    cout << "4. 1.000.000" << endl;
    cout << "5. 2.000.000" << endl;
    cout << "6. Nominal lain" << endl;
    cout << "Pilih nominal : ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        dataPengguna.nominal = 100000;
        break;
    case 2:
        dataPengguna.nominal = 300000;
        break;
    case 3:
        dataPengguna.nominal = 500000;
        break;
    case 4:
        dataPengguna.nominal = 1000000;
        break;
    case 5:
        dataPengguna.nominal = 2000000;
        break;
    case 6:
        cout << "Masukkan nominal yang ingin diambil : ";
        cin >> dataPengguna.nominal;
        break;
    default:
        cout << "Pilihan tidak valid!" << endl;
        return;
    }
    
    if (dataPengguna.saldo[i] >= dataPengguna.nominal)
    {
        dataPengguna.sisasaldo[i] = dataPengguna.saldo[i] - dataPengguna.nominal;
        dataPengguna.saldo[i] = dataPengguna.sisasaldo[i];
        simpanDataKeFile();
        
        // Tambah transaksi ke riwayat
        tambahTransaksi(i, getTanggalSekarang(), -dataPengguna.nominal, "Tarik Tunai");
        
        system("cls");
        cout << "Transaksi berhasil!" << endl;
        cout << "Saldo setelah penarikan: Rp " << dataPengguna.saldo[i] << endl;
    }
    else
    {
        system("cls");
        cout << "Saldo anda tidak mencukupi." << endl;
    }
}

int cariPengguna(string rekening)
{
    for (int i = 0; i < jumlahpengguna; i++)
    {
        if (dataPengguna.password[i][0] == rekening)
        {
            return i;
        }
    }
    return -1;
}

void transfer(int i)
{
    system("cls");
    cout << setiosflags(ios::left) << setw(28) << setfill('=') << "" << endl;
    cout << "|" << setiosflags(ios::left) << setw(9) << setfill(' ') << "" << "TRANSFER" << setw(9) << setfill(' ') << "" << "|" << endl;
    cout << setiosflags(ios::left) << setw(28) << setfill('=') << "" << endl;
    
    cout << "Masukkan nomor tujuan: ";
    cin >> dataPengguna.no_rek;

    int id_penerima = cariPengguna(dataPengguna.no_rek);
    if (id_penerima == -1)
    {
        cout << "Nomor rekening tidak valid!" << endl;
        getch();
        return;
    }

    cout << "Masukkan nominal yang akan di transfer : ";
    cin >> dataPengguna.uang;
    
    cout << "Masukkan PIN anda : ";
    cin >> dataPengguna.pin;
    if (dataPengguna.pin != dataPengguna.password[i][1])
    {
        cout << "PIN salah! Silahkan coba lagi!" << endl;
        return;
    }

    int *saldoPengirim = &dataPengguna.saldo[i];
    int *saldoPenerima = &dataPengguna.saldo[id_penerima];

    if (*saldoPengirim >= dataPengguna.uang)
    {
        int saldoAwal = *saldoPengirim;

        *saldoPengirim -= dataPengguna.uang;
        *saldoPenerima += dataPengguna.uang;
        simpanDataKeFile();

        string deskripsiPengirim = "Transfer ke " + dataPengguna.password[id_penerima][0];
        tambahTransaksi(i, getTanggalSekarang(), -dataPengguna.uang, deskripsiPengirim);
        string deskripsiPenerima = "Transfer dari " + dataPengguna.password[i][0];
        tambahTransaksi(id_penerima, getTanggalSekarang(), dataPengguna.uang, deskripsiPenerima);

        cout << "Berhasil Mentransfer Uang!" << endl;
        cout << "Saldo Awal       : " << saldoAwal << endl;
        cout << "Nominal Transfer : " << dataPengguna.uang << endl;
        cout << "Saldo Akhir      : " << *saldoPengirim << endl;

        cout << "Transfer Berhasil. Apakah Anda ingin cetak resi (y/n)? ";
        cin >> pilih;
        if (pilih == 'y' || pilih == 'Y')
        {
            cetakResiTf();
        }
        else
        {
            cout << "Terima kasih telah melakukan transaksi!" << endl;
        }
    }
    else
    {
        cout << "Saldo anda tidak cukup untuk melakukan transfer!" << endl;
    }
}

void simulasiPembayaran(string metodePembayaran, float jumlah) {
    cout << "\n=== SIMULASI PEMBAYARAN ===" << endl;
    cout << "Metode Pembayaran: " << metodePembayaran << endl;
    cout << "Jumlah: Rp " << jumlah << endl;
    cout << "\nMenghubungkan ke " << metodePembayaran << "..." << endl;
    
    // Simulasi loading
    for (int i = 0; i < 3; i++) {
        cout << ".";
        usleep(500000); // 0.5 detik
    }
    cout << endl;
    
    if (metodePembayaran == "Kartu Kredit/Debit") {
        string nomorKartu, cvv, nama;
        cout << "\n--- INPUT DATA KARTU ---" << endl;
        cout << "Masukkan nomor kartu (16 digit): ";
        cin >> nomorKartu;
        cout << "Masukkan CVV (3 digit): ";
        cin >> cvv;
        cin.ignore();
        cout << "Masukkan nama pemegang kartu: ";
        getline(cin, nama);
        
        cout << "\nMemproses pembayaran..." << endl;
        usleep(1000000); 
        cout << "✓ Pembayaran berhasil!" << endl;
        
    } else if (metodePembayaran == "E-Wallet") {
        string nomorHP;
        cout << "\n--- E-WALLET PAYMENT ---" << endl;
        cout << "Masukkan nomor HP e-wallet: ";
        cin >> nomorHP;
        
        cout << "\nMengirim notifikasi ke aplikasi e-wallet..." << endl;
        usleep(1000000); 
        cout << "Silakan konfirmasi pembayaran di aplikasi e-wallet Anda." << endl;
        cout << "Menunggu konfirmasi..." << endl;
        usleep(2000000);
        cout << "✓ Pembayaran dikonfirmasi!" << endl;
        
    } else if (metodePembayaran == "Transfer Bank") {
        cout << "\n--- TRANSFER BANK ---" << endl;
        cout << "Bank Tujuan: Bank Mandiri" << endl;
        cout << "No. Rekening: 1234567890" << endl;
        cout << "Atas Nama: FUFUFAFAPAY" << endl;
        cout << "Jumlah: Rp " << jumlah << endl;
        cout << "\nSilakan lakukan transfer dan konfirmasi dalam 24 jam." << endl;
        cout << "Sistem akan memverifikasi pembayaran secara otomatis." << endl;
        
    }
    cout << "\n=== TRANSAKSI SELESAI ===" << endl;
    cout << "Terima kasih telah menggunakan layanan kami!" << endl;
}

void topUp(int i)
{
    system("cls");
    float jumlahTopUp;
    int metodePembayaran;

    cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
    cout << "|" << setiosflags(ios::left) << setw(9) << setfill(' ') << "" << "TOP UP SALDO" << setw(9) << setfill(' ') << "" << "|" << endl;
    cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;

    cout << "Masukkan jumlah top up: ";
    cin >> jumlahTopUp;

    if (jumlahTopUp <= 0)
    {
        cout << "Jumlah top up tidak valid!" << endl;
        return;
    }

    cout << "\n=== PILIH METODE PEMBAYARAN ===" << endl;
    cout << "1. Kartu Kredit/Debit" << endl;
    cout << "2. E-Wallet (OVO, GoPay, Dana, dll)" << endl;
    cout << "3. Transfer Bank" << endl;
    cout << "Pilih metode pembayaran (1-4): ";
    cin >> metodePembayaran;

    string namaMetode;
    switch (metodePembayaran) {
        case 1:
            namaMetode = "Kartu Kredit/Debit";
            break;
        case 2:
            namaMetode = "E-Wallet";
            break;
        case 3:
            namaMetode = "Transfer Bank";
            break;
        case 4:
            namaMetode = "QRIS";
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return;
    }

    simulasiPembayaran(namaMetode, jumlahTopUp);

    dataPengguna.saldo[i] += jumlahTopUp;
    simpanDataKeFile();

    cout << "\nTop Up berhasil! Saldo baru Anda: Rp. " << dataPengguna.saldo[i] << endl;

    char cetakResi;
    cout << "Apakah Anda ingin mencetak resi? (y/n): ";
    cin >> cetakResi;
    
    if (cetakResi == 'y' || cetakResi == 'Y') {
        system("cls");
        cout << " \t \t-++ FUFUFAFAPAY ++-" << endl << endl;
        cout << "========== RESI TOP UP ==========" << endl;
        cout << "Tanggal: ";
        
        time_t timestamp;
        char output[50];
        struct tm *datetime;
        time(&timestamp);
        datetime = localtime(&timestamp);
        strftime(output, 50, "%d %B %Y %I:%M:%S %p", datetime);
        cout << output << endl;
        
        cout << "Nama: " << dataPengguna.nama[i] << endl;
        cout << "Metode Pembayaran: " << namaMetode << endl;
        cout << "Jumlah Top Up: Rp " << jumlahTopUp << endl;
        cout << "Saldo Sebelum: Rp " << (dataPengguna.saldo[i] - jumlahTopUp) << endl;
        cout << "Saldo Sesudah: Rp " << dataPengguna.saldo[i] << endl;
        cout << "=================================" << endl;
        cout << "\nSimpan resi ini sebagai bukti transaksi" << endl;
    }
}

double hitungHutang(double hutang, int bulan)
{
    if (bulan == 0)
    {
        return hutang;
    }
    else
    {
        return hitungHutang(hutang * 1.025, bulan - 1);
    }
}

void paylater(int i)
{
    if (dataPengguna.hutang[i] > 0)
    {
        dataPengguna.hutang[i] = hitungHutang(dataPengguna.hutang[i], dataPengguna.bulanTertunggak[i]);
        dataPengguna.bulanTertunggak[i]++;
        cout << "Anda memiliki hutang tertunggak Rp" << fixed << setprecision(2) << dataPengguna.hutang[i] << " yang harus segera dibayar!" << endl;
        return;
    }

    double pinjaman;
    cout << "Masukkan jumlah pinjaman: ";
    cin >> pinjaman;

    dataPengguna.hutang[i] = pinjaman * 1.025;
    dataPengguna.bulanTertunggak[i] = 1;
    dataPengguna.saldo[i] += pinjaman;
    simpanDataKeFile();

    cout << "Pinjaman disetujui. Anda harus membayar Rp" << fixed << setprecision(2) << dataPengguna.hutang[i] << " bulan depan." << endl;
    cout << "Saldo setelah pinjaman: Rp" << dataPengguna.saldo[i] << endl;
}

void search(string tanggal, int i)
{
    bool ditemukan = false;

    for (int j = 0; j < jumlahTransaksi[i]; j++)
    {
        if (tanggal == dataTransaksi[i][j].tanggal)
        {
            if (!ditemukan)
            {
                cout << "Transaksi pada tanggal " << tanggal << " ditemukan pada akun berikut:\n";
                ditemukan = true;
            }
            cout << "Akun: " << dataPengguna.nama[i] << " | ";
            cout << "Jumlah: Rp " << dataTransaksi[i][j].jumlah << " | ";
            cout << "Deskripsi: " << dataTransaksi[i][j].deskripsi << endl;
        }
    }

    if (!ditemukan)
    {
        cout << "Tidak ada transaksi yang ditemukan pada tanggal " << tanggal << ".\n";
    }
}

void sorttanggal(transaksi arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].tanggal < arr[j + 1].tanggal) // dari terbaru ke terlama
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void tampiltransaksi(transaksi arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Tanggal: " << arr[i].tanggal << " | ";
        cout << "Jumlah: Rp " << arr[i].jumlah << " | ";
        cout << "Deskripsi: " << arr[i].deskripsi << endl;
    }
}

void menusort(transaksi dataTransaksi[], int n)
{
    char pilihan;

    cout << "Apakah Anda ingin mengurutkan transaksi berdasarkan tanggal? (y/n): ";
    cin >> pilihan;

    if (pilihan == 'y' || pilihan == 'Y')
    {
        sorttanggal(dataTransaksi, n);
        cout << "\nSetelah diurutkan berdasarkan tanggal:" << endl;
    }
    else
    {
        cout << "Transaksi tidak diurutkan." << endl;
    }

    tampiltransaksi(dataTransaksi, n);
}

void tampilkanRiwayatTransaksi(int i)
{
    int total = 5;
    cout << "Riwayat transaksi untuk " << dataPengguna.nama[i] << ":" << endl;
    for (int j = 0; j < jumlahTransaksi[i]; j++)
    {
        cout << "Tanggal: " << dataTransaksi[i][j].tanggal << " | ";
        cout << "Jumlah: Rp " << dataTransaksi[i][j].jumlah << " | ";
        cout << "Deskripsi: " << dataTransaksi[i][j].deskripsi << endl;
    }
    cout << endl;

    menusort(dataTransaksi[i], jumlahTransaksi[i]);
      string tanggalCari;
    cout << "\nMasukkan tanggal yang ingin dicari (format yang sama dengan data): ";
    cin >> tanggalCari;
    search(tanggalCari, i);
}

void menuInd(int i)
{
    char next = 'y';
    int menu;
    do
    {
        system("cls");
        cout << "WASPADA JUDI ONLINE!" << endl;
        cout << "FUFUFAFAPAY" << endl;
        cout << "Selamat Datang " << dataPengguna.nama[i] << endl;
        cout << "Saldo Kamu Rp " << dataPengguna.saldo[i] << endl;
        cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "1. Informasi Saldo" << setw(9) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "2. Tarik Tunai" << setw(13) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "3. Aktifkan Paylater" << setw(7) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "4. Transfer" << setw(16) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "5. Informasi Pengguna" << setw(6) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "6. Riwayat Transaksi" << setw(7) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "7. Top Up" << setw(18) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "8. Keluar" << setw(18) << setfill(' ') << "" << "|" << endl;
        cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
        cout << "Pilihan menu : ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            saldoPengguna(i);
            break;
        case 2:
            TarikTunai(i);
            break;
        case 3:
            paylater(i);
            break;
        case 4:
            transfer(i);
            break;
        case 5:
            infoInd(i);
            break;
        case 6:
            tampilkanRiwayatTransaksi(i);
            break;
        case 7:
            topUp(i);
            break;
        case 8:
            break;
        default:
            break;
        }
        cout << "Apakah anda ingin melanjutkan transaksi? (y/n) : ";
        cin >> next;
    } while (next == 'y' || next == 'Y' && menu != 8);
}

int main()
{

    bacaDataDariFile();
    int batas = 0;
    string username, passwordAwal;
    bool loginSukses = false;
    int userIndex;
    int menu;

    do
    {
        system("cls");
        cout << "====== SELAMAT DATANG DI FUFUFAFAPAY ======" << endl;
        cout << "1. Login" << endl;
        cout << "2. Daftar Pengguna Baru" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            system("cls");
            cin.ignore();
            while(batas<3&&!loginSukses)
            {
                cout<<"Masukkan Security Code Kamu :- "<<endl;
                cin>>passwordAwal;
                for (int i = 0; i < 5; i++)
                {
                  if (passwordAwal==dataPengguna.password[i][i])
                  {
                    loginSukses=true;
                    userIndex=i;
                    break;
                  }

                  
                }if (!loginSukses)
                {
                    batas++;
                    if (batas<3)
                    {
                        cout<<"Security Code Salah,Sisa Percobaan Login Anda : - "<<3-batas<<endl;

                    }   else
                    {
                        cout<<"Percobaan Login Anda Habis";
                    }
                    
                }
                if (loginSukses)
                {
                    menuInd(userIndex);
                }
                
                
                
            } break;
        case 2:
            daftarPengguna();
            break;


        case 3:
            cout << "Terima kasih, sampai jumpa!" << endl;
            return 0;

        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (!loginSukses);
}

void cetakResiTf()
{
    srand(time(0));
    dataPengguna.randomNum = rand() % 10000000;
    system("cls");
    usleep(300000);
    cout << " \t \t-++ BANK BANKTUT ++-" << endl
         << endl;
    usleep(300000);
    cout << "TANGGAL \t \t WAKTU" << endl;
    time_t timestamp;
    char output[50];
    struct tm *datetime;

    // Mengambil waktu saat ini
    usleep(300000);
    time(&timestamp);
    datetime = localtime(&timestamp);

    // Mengatur format tanggal
    strftime(output, 50, "%d %B %Y", datetime);
    cout << output;

    strftime(output, 50, "%I:%M:%S %p", datetime);
    cout << "\t" << output << "\n";
    usleep(300000);
    cout << "LOKASI \t PLG CB DEMANG LBR DAUN" << endl;
    usleep(300000);
    cout << "\nNO. RECORD " << dataPengguna.randomNum << endl;
    usleep(300000);
    cout << "======= TRANSFER DARI ==========" << endl;
    usleep(300000);
    cout << "          FUFUFAFAPAY" << endl;
    usleep(300000);
    cout << "NO. REK : XXXXXXXXX" << endl;
    usleep(300000);
    cout << "=============== KE ===========" << endl;
    usleep(300000);
    cout << "BANK    : BANK BRI" << endl;
    usleep(300000);
    cout << "NO. REK : " << dataPengguna.no_rek << endl;
    usleep(300000);
    cout << "JUMLAH  : RP. " << dataPengguna.uang << endl;
    usleep(300000);
    cout << "\n\tHARAP SIMPAN RESI INI" << endl;
    usleep(300000);
    cout << "\tSEBAGAI BUKTI TRANSFER" << endl;
}

void resiSetor(int i)
{
    srand(time(0));
    dataPengguna.randomNum = rand() % 10000000;
    system("cls");
    usleep(300000);
    cout << " \t \t-++ BANK BANKTUT ++-" << endl
         << endl;
    usleep(300000);
    cout << "TANGGAL \t \t WAKTU" << endl;
    time_t timestamp;
    char output[50];
    struct tm *datetime;
    dataPengguna.saldo[i] = dataPengguna.sisasaldo[i];

    // Mengambil waktu saat ini
    usleep(300000);
    time(&timestamp);
    datetime = localtime(&timestamp);

    // Mengatur format tanggal
    strftime(output, 50, "%d %B %Y", datetime);
    cout << output;

    strftime(output, 50, "%I:%M:%S %p", datetime);
    cout << "\t" << output << "\n";
    usleep(300000);
    cout << "LOKASI \t PLG CB DEMANG LBR DAUN" << endl;
    usleep(300000);
    cout << "\nNO. RECORD " << dataPengguna.randomNum << endl;
    usleep(300000);
    cout << "=========== SETOR TUNAI ==========" << endl;
    usleep(300000);
    cout << "NOMINAL SETOR     : RP. " << dataPengguna.nominal << endl;
    usleep(300000);
    cout << "SALDO ANDA        : Rp. " << dataPengguna.saldo[i] << endl;
    usleep(300000);
    cout << "\n\tHARAP SIMPAN RESI INI" << endl;
}
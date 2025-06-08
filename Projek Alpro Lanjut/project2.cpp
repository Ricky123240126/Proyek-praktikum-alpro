#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
using namespace std;

// variabel global

struct pengguna{
    string nama[5] = {{"Ricky"}, {"Zaky"}, {"Yaya"}, {"Rifty"}, {"Okto"}};
    string password[5][2] = {{"123240126", "270105"}, {"123240096", "280104"}, {"123240101", "190805"}, {"123240108", "210505"}, {"123240114", "161006"}};
    int saldo[5] = {500000, 600000, 800000, 500000, 600000};
    int sisasaldo[5];
    string pin, no_rek;
    float saldo_akhir, uang, nominal;
    int randomNum;
    int bulanTertunggak[5] = {0, 0, 0, 0, 0};
    double hutang[5] = {0, 0, 0, 0, 0};
}dataPengguna;

struct transaksi {
    string tanggal;
    double jumlah;
    string deskripsi;
};

transaksi dataTransaksi[5][5] = {
    {{"2025-03-01", 150000, "Pembelian buku"}, 
     {"2025-03-03", 200000, "Pembayaran utang"}, 
     {"2025-03-05", 500000, "Transfer uang ke teman"},
     {"2025-03-07", 250000, "Pembelian gadget"}, 
     {"2025-03-10", 100000, "Top up saldo"}},
    
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
     {"2025-03-03", 100000, "Top up saldo"}}
};

int jumlahTransaksi[5] = {5, 5, 2, 3, 2};
int i;
char pilih;

void gantiPin(int i);
void menuInd(int i);
void cetakResiTf();
// void resiTarik(int i, int nominal);
void resiSetor(int i);

void pilihMenu(int i){
    int pilihmenu;
    bool ulang = 1;
    char selesai;
    while (ulang == true)
    {
        cout << "Apakah Anda Ingin Mengganti PIN?" << endl;
        cout << "1. Iya" << endl;
        cout << "2 Tidak" << endl;
        cin >> pilihmenu;
        if(pilihmenu == 1){
            gantiPin(i);
            break;
        }else if(pilihmenu == 2){
            selesai = 'y';
            break;
        }else{
            cout << "Anda Salah Memasukkan Pilihan Masukkan Pilihan Yang Benar" << endl;
            getch();
            system ("cls");
            ulang = 1;
        }
    }
    while (selesai != 'y');
}

void infoInd(int i)
{
    system ("cls");
    cout << setiosflags(ios::left) << setw(32) << setfill('=') << "" << endl;
    cout << "|" << setiosflags(ios::left) << setw(6) << setfill(' ') << "" << "INFORMASI PENGGUNA" << setw(6) << setfill(' ') << "" << "|" << endl;
    cout << setiosflags(ios::left) << setw(32) << setfill('=') << "" << endl;
    cout << "|" << setiosflags(ios::left) << setw(1) << setfill(' ') << "" << "Nama Pengguna  : " << dataPengguna.nama[i] << setw(8) << setfill(' ') << "" << "|" << endl;
    cout << "|" << setiosflags(ios::left) << setw(1) << setfill(' ') << "" << "Nomor Rekening : " << dataPengguna.password[i][0] << setw(3) << setfill(' ') << "" << "|" << endl;
    cout << "|" << setiosflags(ios::left) << setw(1) << setfill(' ') << "" << "PIN            : " << dataPengguna.password[i][1] << setw(6) << setfill(' ') << "" << "|" << endl;
    cout << setiosflags(ios::left) << setw(32) << setfill('=') << "" << endl;
    cout << endl;
    pilihMenu(i);
}

void gantiPin(int i){
    system("cls");
    string passwordBaru;
    cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
    cout << "|" << setiosflags(ios::left) << setw(10) << setfill(' ') << "" << "GANTI PIN" << setw(10) << setfill(' ') << "" << "|" << endl;
    cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
    cout << "Masukkan PIN Baru : ";
    cin >> passwordBaru;
    dataPengguna.password[i][1] = passwordBaru;
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
    cout << "       Rp. " << dataPengguna.saldo[i]    << " " << endl;
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

    cout << "\nTransaksi Berhasil!" << endl;

    cout << "Apakah Anda Ingin Cetak Resi? (y/n) : " << resi;
    cin >> resi;

    if (resi == 'y' || resi == 'Y')
    {
        resiSetor(i);
    }
    else
    {
        cout << "Nominal Saldo Anda : " << dataPengguna.sisasaldo[i] << endl
             << endl;
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
        system("cls");
        // resiTarik(i, dataPengguna.nominal);
    }
    else
    {
        system("cls");
        cout << "Saldo anda tidak mencukupi." << endl;
    }
}

int cariPengguna(string rekening) {
    for (int i = 0; i < 5; i++) {
        if (dataPengguna.password[i][0] == rekening) {
            return i;
        }
    }
    return -1;
}

void transfer(int i) {
    system("cls");
    cout << setiosflags(ios::left) << setw(28) << setfill('=') << "" << endl;
    cout << "|" << setiosflags(ios::left) << setw(9) << setfill(' ') << "" << "TRANSFER" << setw(9) << setfill(' ') << "" << "|" << endl;
    cout << setiosflags(ios::left) << setw(28) << setfill('=') << "" << endl;
    double jumlah;
    cout << "Masukkan nomor tujuan: ";
    cin >> dataPengguna.no_rek;
    
    string rekTujuan = dataPengguna.no_rek;
    int idTujuan = cariPengguna(rekTujuan);
    if (idTujuan == -1) {
        cout << "Nomor tidak ditemukan!" << endl;
        return;
    }
    
    cout << "Masukkan nominal yang akan di transfer : ";
    cin >> dataPengguna.uang;
    if (dataPengguna.no_rek != dataPengguna.password[i][0])
    {
        dataPengguna.saldo_akhir = dataPengguna.saldo[i] - dataPengguna.uang;
    }
    else
    {
        dataPengguna.saldo_akhir = dataPengguna.saldo[i];
    }

    cout << "Masukkan PIN anda : ";
    cin >> dataPengguna.pin;
    if (dataPengguna.pin == dataPengguna.password[i][1])
    {
        if (dataPengguna.saldo_akhir >= 0)
        {
            cout << "Berhasil Mentransfer Uang!" << endl;
            cout << "Saldo Awal       : " << dataPengguna.saldo[i] << endl;
            cout << "Nominal Transfer : " << dataPengguna.uang << endl;
            cout << "Saldo Akhir      : " << dataPengguna.saldo_akhir << endl;
            dataPengguna.saldo[i] = dataPengguna.saldo_akhir;

            cout << "Transfer Berhasil. Apakah Anda ingin cetak resi (y/n) ? ";
            cin >> pilih;
            if (pilih == 'y' || pilih == 'Y')
            {
                cetakResiTf();
            }
            else
            {
                cout << "Terimakasih telah melakukan transaksi! ";
            }
        }
        else
        {
            cout << "Saldo anda tidak cukup untuk melakukan transfer!" << endl;
        }
    }
    else
    {
        cout << "PIN salah! Silahkan coba lagi!" << endl;
    }
}


// void transfer(int i)
// {
//     system("cls");
//     cout << setiosflags(ios::left) << setw(28) << setfill('=') << "" << endl;
//     cout << "|" << setiosflags(ios::left) << setw(9) << setfill(' ') << "" << "TRANSFER" << setw(9) << setfill(' ') << "" << "|" << endl;
//     cout << setiosflags(ios::left) << setw(28) << setfill('=') << "" << endl;
//     cout << "Masukkan nomor rekening yang dituju : ";
//     cin >> dataPengguna.no_rek;
//     cout << "Masukkan nominal yang akan di transfer : ";
//     cin >> dataPengguna.uang;
//     if (dataPengguna.no_rek != dataPengguna.password[i][0])
//     {
//         dataPengguna.saldo_akhir = dataPengguna.saldo[i] - dataPengguna.uang;
//     }
//     else
//     {
//         dataPengguna.saldo_akhir = dataPengguna.saldo[i];
//     }

//     cout << "Masukkan PIN anda : ";
//     cin >> dataPengguna.pin;
//     if (dataPengguna.pin == dataPengguna.password[i][1])
//     {
//         if (dataPengguna.saldo_akhir >= 0)
//         {
//             cout << "Berhasil Mentransfer Uang!" << endl;
//             cout << "Saldo Awal       : " << dataPengguna.saldo[i] << endl;
//             cout << "Nominal Transfer : " << dataPengguna.uang << endl;
//             cout << "Saldo Akhir      : " << dataPengguna.saldo_akhir << endl;
//             dataPengguna.saldo[i] = dataPengguna.saldo_akhir;

//             cout << "Transfer Berhasil. Apakah Anda ingin cetak resi (y/n) ? ";
//             cin >> pilih;
//             if (pilih == 'y' || pilih == 'Y')
//             {
//                 cetakResiTf();
//             }
//             else
//             {
//                 cout << "Terimakasih telah melakukan transaksi! ";
//             }
//         }
//         else
//         {
//             cout << "Saldo anda tidak cukup untuk melakukan transfer!" << endl;
//         }
//     }
//     else
//     {
//         cout << "PIN salah! Silahkan coba lagi!" << endl;
//     }
// }

double hitungHutang(double hutang, int bulan) {
    if (bulan == 0) {
        return hutang;
    }else{
        return hitungHutang(hutang * 1.025, bulan - 1);    
    }
}

void paylater(int i) {
    if (dataPengguna.hutang[i] > 0) {
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
    
    cout << "Pinjaman disetujui. Anda harus membayar Rp" << fixed << setprecision(2) << dataPengguna.hutang[i] << " bulan depan." << endl;
    cout << "Saldo setelah pinjaman: Rp" << dataPengguna.saldo[i] << endl;
}

void search(string tanggal, int i) {
    bool ditemukan = false;
 
    for (int j = 0; j < jumlahTransaksi[i]; j++) {
        if (tanggal == dataTransaksi[i][j].tanggal) {
            if (!ditemukan) {
                cout << "Transaksi pada tanggal " << tanggal << " ditemukan pada akun berikut:\n";
                ditemukan = true;
            }
            cout << "Akun: " << dataPengguna.nama[i] << " | ";
            cout << "Jumlah: Rp " << dataTransaksi[i][j].jumlah << " | ";
            cout << "Deskripsi: " << dataTransaksi[i][j].deskripsi << endl;
        }
    }

    if (!ditemukan) {
        cout << "Tidak ada transaksi yang ditemukan pada tanggal " << tanggal << ".\n";
    }
}

int partition(transaksi arr[],int low,int high)
{
    transaksi pivot = arr[high];
    int i=(low-1);\
    for (int j = low; j < high; j++)
    {
        if (arr[j].tanggal<=pivot.tanggal)
        {
            i++;
            swap(arr[i+1],arr[j]);
        }   
    }   
        swap(arr[i+1],arr[high]);
    return(i+1);
}

void sorttanggal(transaksi arr[],int low,int high)
{
    if (low<high)
    {
        int pi=partition(arr,low,high);
        sorttanggal(arr,low,pi-1);
        sorttanggal(arr,pi+1,high);
    }
    
}

void tampiltransaksi(transaksi arr[],int n)
{
for (int i = 0; i < n; i++)
{
    cout << "Tanggal: " << arr[i].tanggal << " | ";
        cout << "Jumlah: Rp " << arr[i].jumlah << " | ";
        cout << "Deskripsi: " << arr[i].deskripsi << endl;
}

}

void menusort(transaksi dataTransaksi[],int n)
{

    char pilihan;
    
    cout << "Apakah Anda ingin mengurutkan transaksi berdasarkan tanggal? (y/n): ";
    cin >> pilihan;

    if (pilihan == 'y' || pilihan == 'Y') {
        sorttanggal(dataTransaksi, 0, n - 1);
        cout << "\nSetelah diurutkan berdasarkan tanggal:" << endl;
    } else {
        cout << "Transaksi tidak diurutkan." << endl;
    }

    tampiltransaksi(dataTransaksi, n);
}

void tampilkanRiwayatTransaksi(int i) {
    int total = 5;
    cout << "Riwayat transaksi untuk " << dataPengguna.nama[i] << ":" << endl;
    for (int j = 0; j < jumlahTransaksi[i]; j++) {
        cout << "Tanggal: " << dataTransaksi[i][j].tanggal << " | ";
        cout << "Jumlah: Rp " << dataTransaksi[i][j].jumlah << " | ";
        cout << "Deskripsi: " << dataTransaksi[i][j].deskripsi << endl;
    }
    cout << endl;

    string tanggalCari;
    cout << "Masukkan tanggal yang ingin dicari (format: YYYY-MM-DD): ";
    cin >> tanggalCari;

    search(tanggalCari, i);
    menusort(dataTransaksi[i],jumlahTransaksi[i]);
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
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "7. Keluar" << setw(18) << setfill(' ') << "" << "|" << endl;
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
        default:
            break;
        }
        cout << "Apakah anda ingin melanjutkan transaksi? (y/n) : ";
        cin >> next;
    } while (next == 'y' || next == 'Y' && menu != 6);
}

// void menuInd(int i)
// {
//     char next = 'y';
//     int menu;
//     do
//     {
//         system("cls");
//         cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
//         cout << "|" << setiosflags(ios::left) << setw(9) << setfill(' ') << "" << "FUFUFAFAPAY" << setw(9) << setfill(' ') << "" << "|" << endl;
//         cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
//         cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "1. Informasi Saldo" << setw(9) << setfill(' ') << "" << "|" << endl;
//         cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "2. Tarik Tunai" << setw(13) << setfill(' ') << "" << "|" << endl;
//         cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "3. Setor Tunai" << setw(13) << setfill(' ') << "" << "|" << endl;
//         cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "4. Transfer" << setw(16) << setfill(' ') << "" << "|" << endl;
//         cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "5. Informasi Pengguna" << setw(6) << setfill(' ') << "" << "|" << endl;
//         cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "6. Keluar" << setw(18) << setfill(' ') << "" << "|" << endl;
//         cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
//         cout << "Pilihan menu : ";
//         cin >> menu;

//         switch (menu)
//         {
//         case 1:
//             saldoPengguna(i);
//             break;
//         case 2:
//             TarikTunai(i);
//             break;
//         case 3:
//             setorTunai(i);
//             break;
//         case 4:
//             transfer(i);
//             break;
//         case 5:
//             infoInd(i);
//             break;
//         default:
//             break;
//         }
//         cout << "Apakah anda ingin melanjutkan transaksi? (y/n) : ";
//         cin >> next;
//     } while (next == 'y' || next == 'Y' && menu != 6);
// }

int main(){
    system("cls");
    int batas = 0;
    string username, passwordAwal;
    bool loginSukses = false;
    int userIndex;

    cout << "Masukkan Security Code Kamu" << endl;
    cout << "Password : ";
    cin >> passwordAwal;

    for (int i = 0; i < 5; i++)
    {
        if (passwordAwal == dataPengguna.password[i][1])
        {
            loginSukses = true;
            userIndex = i;
            break;
        }
    }
    if (loginSukses)
    {
        menuInd(userIndex);
    }
    else
    {
        batas++;
        if (batas < 3)
        {
            cout << "Sisa Percobaan Login Anda " << 3 - batas << " Kali Percobaan\n";
        }
        else
        {
            cout << "Percobaan Login Anda Telah Habis\n";
        }
    }
}

void cetakResiTf()
{
    srand(time(0));
    dataPengguna.randomNum = rand() % 10000000;
    system("cls");
    usleep(300000);
    cout << " \t \t-++ BANK BANKTUT ++-" << endl << endl;
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

// void resiTarik(int i, int dataPengguna.nominal)
// {
//      srand(time(0));
//      dataPengguna.randomNum = rand() % 10000000;
//     system("cls");
//     usleep(300000);
//     cout << " \t \t-++ BANK BANKTUT ++-" << endl << endl;
//     usleep(300000);
//     cout << "TANGGAL \t \t WAKTU" << endl;
//     time_t timestamp;
//     char output[50];
//     struct tm *datetime;

//     // Mengambil waktu saat ini
//     usleep(300000);
//     time(&timestamp);
//     datetime = localtime(&timestamp);

//     // Mengatur format tanggal
//     strftime(output, 50, "%d %B %Y", datetime);
//     cout << output;

//     strftime(output, 50, "%I:%M:%S %p", datetime);
//     cout << "\t" << output << "\n";
//     usleep(300000);
//     cout << "LOKASI \t PLG CB DEMANG LBR DAUN" << endl;
//     usleep(300000);
//     cout << "\nNO. RECORD " << dataPengguna.randomNum<< endl;
//     usleep(300000);
//     cout << "===========TARIK TUNAI==========" << endl;
//     usleep(300000);
//     cout << "BANK       : MANDIRI" << endl;
//     usleep(300000);
//     cout << "NO. REK    : XXXXXXXXX" << endl; // Contoh placeholder untuk bank lain
//     usleep(300000);
//     cout << "BANK       : BANK BRI" << endl;
//     usleep(300000);
//     cout << "NO. REK    : " << dataPengguna.no_rek << endl;
//     usleep(300000);
//     cout << "JUMLAH     : RP. " << dataPengguna.nominal << endl;
//     usleep(300000);
//     cout << "SISA SALDO : Rp. " << dataPengguna.sisasaldo[i] << endl;
//     usleep(300000);
//     cout << "\n\tHARAP SIMPAN RESI INI" << endl;
// }

void resiSetor(int i)
{
    srand(time(0));
    dataPengguna.randomNum = rand() % 10000000;
    system("cls");
    usleep(300000);
    cout << " \t \t-++ BANK BANKTUT ++-" << endl << endl;
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

#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>

using namespace std;
int main ()
{
    string user_name, nama_pembeli;
    int password, kode_transaksi, nomor_menu, banyak_pesanan;
    float total_harga_menu, diskon, harga_setelah_diskon, harga_satuan;

    cout << setfill ('=') << setw(38) <<"" << endl;
    cout << "|| PROGRAM KASIR TOKO BESI PAK IMAN ||" << endl;
    cout << setfill ('=') << setw(38) <<"" << endl;
    cout << endl;

    cout << "Masukkan username : ";
    cin >> user_name;
    cout << "masukkan Password : ";
    cin >> password;
    if (user_name == "Ricky" && password == 123240126)
    {
        cout << "LOGIN BERHASIL CIHUYYY !!" << endl;
    }else
    {cout << "Username atau password yang anda masukkan salah";
     return 1;
    }
    cout << endl;
    cout << setfill ('=') << setw(40) <<"" << endl;
    cout << "||            MENU PESANAN            ||" << endl;
    cout << setfill ('=') << setw(40) <<"" << endl;
    
    cout << "masukkan kode transaksi : ";
    cin >> kode_transaksi;
    cout << "masukkan nama pembeli : ";
    cin >> nama_pembeli;
    cout << endl;

    cout << setfill ('=') << setw(40) << "" << endl;
    cout << "|  NO  |    NAMA MENU    |    HARGA    |" << endl;
    cout << setfill ('=') << setw(40) << "" << endl;

    cout << "|" << setfill (' ') << setw(6) << left << "1." << "|";
    cout << setfill (' ') << setw(17) << left << "Palu" << "|"; 
    cout << setfill (' ') << setw(13) << left << "Rp45.000,00" << "|\n";     
    
    cout << "|" << setfill (' ') << setw(6) << left << "2." << "|";
    cout << setfill (' ') << setw(17) << left << "Paku" << "|"; 
    cout << setfill (' ') << setw(13) << left << "Rp1.000,00" << "|\n";

    cout << "|" << setfill (' ') << setw(6) << left << "3." << "|";
    cout << setfill (' ') << setw(17) << left << "Paku beton" << "|"; 
    cout << setfill (' ') << setw(13) << left << "Rp2.000,00" << "|\n";

    cout << "|" << setfill (' ') << setw(6) << left << "4." << "|";
    cout << setfill (' ') << setw(17) << left << "Gergaji" << "|"; 
    cout << setfill (' ') << setw(13) << left << "Rp65.000,00" << "|\n";

    cout << "|" << setfill (' ') << setw(6) << left << "5." << "|";
    cout << setfill (' ') << setw(17) << left << "Cangkul" << "|"; 
    cout << setfill (' ') << setw(13) << left << "Rp250.000,00" << "|\n";

    cout << "|" << setfill (' ') << setw(6) << left << "6." << "|";
    cout << setfill (' ') << setw(17) << left << "Obeng" << "|"; 
    cout << setfill (' ') << setw(13) << left << "Rp60.000,00" << "|\n";

    cout << "|" << setfill (' ') << setw(6) << left << "7." << "|";
    cout << setfill (' ') << setw(17) << left << "Pahat" << "|"; 
    cout << setfill (' ') << setw(13) << left << "Rp190.000,00" << "|\n";

    cout << "|" << setfill (' ') << setw(6) << left << "8." << "|";
    cout << setfill (' ') << setw(17) << left << "Kuas" << "|"; 
    cout << setfill (' ') << setw(13) << left << "Rp20.000,00" << "|\n";

    cout << "|" << setfill (' ') << setw(6) << left << "9." << "|";
    cout << setfill (' ') << setw(17) << left << "Engsel pintu" << "|"; 
    cout << setfill (' ') << setw(13) << left << "Rp20.000,00" << "|\n";

    cout << "|" << setfill (' ') << setw(6) << left << "10." << "|";
    cout << setfill (' ') << setw(17) << left << "cat" << "|"; 
    cout << setfill (' ') << setw(13) << left << "Rp92.000,00" << "|\n";

    cout << setfill ('=') << setw(40) << "" << endl;

    cout << "masukkan nomor menu   : ";
    cin >> nomor_menu;
    cout << endl;

    if (nomor_menu == 1)
    {
        cout << "\nNama Menu             : Palu";
        cout << "\nHarga Satuan          : Rp45.000,00";
        harga_satuan = 45000;
    }else if (nomor_menu == 2)
    {
        cout << "\nNama Menu             : Paku";
        cout << "\nHarga Satuan          : Rp1.000,00";
        harga_satuan = 1000;
    }else if (nomor_menu == 3)
    {
        cout << "\nNama Menu             : Paku Beton";
        cout << "\nHarga Satuan          : Rp2.000,00";
        harga_satuan = 2000;
    }else if (nomor_menu == 4)
    {
        cout << "\nNama Menu             : Gergaji";
        cout << "\nHarga Satuan          : Rp65.000,00";
        harga_satuan = 65000;
    }else if (nomor_menu == 5)
    {
        cout << "\nNama Menu             : Cangkul";
        cout << "\nHarga Satuan          : Rp250.000,00";
        harga_satuan = 250000;
    }else if (nomor_menu == 6)
    {
        cout << "\nNama Menu             : Obeng";
        cout << "\nHarga Satuan          : Rp30.000,00";
        harga_satuan = 30000;
    }else if (nomor_menu == 7)
    {
        cout << "\nNama Menu             : Pahat";
        cout << "\nHarga Satuan          : Rp190.000,00";
        harga_satuan = 190000;
    }else if (nomor_menu == 8)
    {
        cout << "\nNama Menu             : Kuas";
        cout << "\nHarga Satuan          : Rp20.000,00";
        harga_satuan = 20000;
    }else if (nomor_menu == 9)
    {
        cout << "\nNama Menu             : Engsel Pintu";
        cout << "\nHarga Satuan          : Rp20.000,00";
        harga_satuan = 20000;
    }else if (nomor_menu == 10)
    {
        cout << "\nNama Menu             : Cat";
        cout << "\nHarga Satuan          : Rp92.000,00";
        harga_satuan = 92000;
    }else 
    {
        cout << "menu yang dimasukkan tidak ada";
        return 1;
    }
    cout << "\nBanyak Pesanan        : ";
    cin  >> banyak_pesanan;
    total_harga_menu = banyak_pesanan * harga_satuan;
    cout << "total harga menu : " << total_harga_menu << endl;
    if (total_harga_menu > 125000 )
    {   
        diskon = total_harga_menu * 0.025 ;
        if ( diskon > 21000)
        {
        harga_setelah_diskon = total_harga_menu - 21000;
        cout << "harga setelah diskon : " << harga_setelah_diskon;
        }else if (diskon <= 21000)
        {
        harga_setelah_diskon = total_harga_menu - diskon;
        cout << "harga setelah diskon : " << harga_setelah_diskon;
        }
    }
    
}   
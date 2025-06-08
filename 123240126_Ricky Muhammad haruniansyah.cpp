#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
 main ()
{
    string username, kode_transaksi, nama_pembeli, harga_diskon, banyak_pesanan, nama_menu, diskon, uang_dibayarkan, kembalian ;
    int password, harga, harga_menu, nomor_menu ;
    

    cout << "++=====================================================++" << endl;
    cout << "||          PROGRAM KASIR IN-N-OUT RESTAURANT          ||" << endl;
    cout << "++=====================================================++" << endl;
    cout << "username : ";
    cin >> username;
    cout << "password : ";
    cin >> password;

    if (username == "Ricky" && password == 123240126)
    {
        cout << "LOGIN BERHASIL !" << endl;
    }else 
    {
        cout << "LOGIN GAGAL !" << endl;
        return 0;
    }

     cout << "++====================================================++" << endl;
     cout << "||                    MENU PESANAN                    ||" << endl;
     cout << "++====================================================++" << endl;
    
    cout << " Kode Transaksi : ";
    cin >> kode_transaksi;
    cout << "Masukkan Nama Pembeli : ";
    cin >> nama_pembeli;
    cout << endl;
    cout << "+---------------------------+-----------------------+" << endl;
    cout << "+ NO |      NAMA MENU       |         HARGA         +" << endl;
    cout << "+---------------------------+-----------------------+" << endl;
    cout << "| 1. | DOUBLE-DOUBLE        | Rp60.000,00           |" << endl;
    cout << "| 2. | CHEESEBURGER         | Rp42.000,00           |" << endl;
    cout << "| 3. | HAMBURGER            | Rp35.000,00           |" << endl;
    cout << "| 4. | FRENCH FRIES         | Rp30.000,00           |" << endl;
    cout << "| 5. | SHAKES               | Rp35.000,00           |" << endl;
    cout << "| 6. | COKE                 | Rp23.000,00           |" << endl;
    cout << "| 7. | DIET COKE            | Rp25.000,00           |" << endl;
    cout << "| 8. | MILK                 | Rp15.000,00           |" << endl;
    cout << "| 9. | HOT COCOA            | Rp20.000,00           |" << endl;
    cout << "| 10.| COFFEE               | Rp18.000,00           |" << endl;
    cout << "+---------------------------+-----------------------+" << endl;

    cout << "masukkan nomor menu : ";
    cin >> nomor_menu;
    if (nomor_menu == 1 ){
        cout << "Nama Menu : DOUBLE-DOUBLE";
        cout << "60000 rupiah";
        harga = 60000;
        nama_menu = "DOUBLE-DOUBLE";
    }else  if (nomor_menu == 2){
        cout << "Nama Menu : CHEESEBURGER";
        cout << "42000 rupiah";
        harga = 42000;
        nama_menu = "CHEESEBURGER";
    }else  if (nomor_menu == 3){
        cout << "Nama Menu : HAMBURGER";
        cout << "35000 rupiah";
        harga = 35000;
        nama_menu = "HAMBURGER";
    }else  if (nomor_menu == 4){
        cout << "Nama Menu : FRENCH FRIES";
        cout << "30000 rupiah";
        harga = 30000;
        nama_menu = "FRENCH FRIES";
    }else  if (nomor_menu == 5){
        cout << "Nama Menu : SHAKES";
        cout << "35000 rupiah";
        harga = 35000;
        nama_menu = "SHAKES";
    }else  if (nomor_menu == 6){
        cout << "Nama Menu : COKE";
        cout << "23000 rupiah";
        harga = 23000;
        nama_menu = "COKE";
    }else  if (nomor_menu == 7){
        cout << "Nama Menu : DIET COKES";
        cout << "25000 rupiah";
        harga = 25000;
        nama_menu = "DIET COKES";
    }else  if (nomor_menu == 8){
        cout << "Nama Menu : MILK";
        cout << "15000 rupiah";
        harga = 15000;
        nama_menu = "MILK";
    }else  if (nomor_menu == 9){
        cout << "Nama Menu : HOT COCOA";
        cout << "20000 rupiah";
        harga = 20000;
        nama_menu = "HOT COCOA";
    }else  if (nomor_menu == 10){
        cout << "Nama Menu : COFFEE";
        cout << "18000 rupiah";
        harga = 18000;
        nama_menu = "COFFEE";
    }else {
        cout << "Menu yang anda pilih tidak ada";
        return o;
    }
    cout << "banyak pesanan : ";
    cin >> banyak_pesanan;
    harga_menu = harga * banyak_pesanan;
    cout << "harga menu : " << harga_menu;
    cout << "masukkan uang yang dibayarkan : ";
    cin >> uang_dibayarkan;
    kembalian = harga_diskon - uang_dibayarkan;
    cout << "jumlah kembalian : ";
    cin >> kembalian;

    
    if (harga_menu >= 60000)
    { 
        if(uang_dibayarkan >= harga_diskon ){
    diskon = harga_menu * 0.30;
    harga_diskon = harga_menu - diskon
     cout << "++====================================================++" << endl;
     cout << "||                   NOTA PEMBELIAN                   ||" << endl;
     cout << "++====================================================++" << endl;
     cout << "Kode transaksi  : " << kode_transaksi << endl;
     cout << "Nama pembeli    : " << nama_pembeli << endl;
     cout << "Nama menu :     : " << nama_menu << endl;
     cout << "Banyak pesan an : " << banyak_pesanan << endl;
     cout << "Harga per porsi : " << harga << endl;
     cout << endl;
     cout << "--------------------------------------------------------" << endl;
     cout << endl;
     cout << setfill (" ") << setw(35) << left << "Total harga : " << harga_menu << endl;
     cout << "------(Diskon 30% (maks 25 rb) min pembelian 60 rb------" << endl;
     cout << setfill (" ") << setw(35) << left << "Nominal diskon : " << diskon << endl;
     cout << setfill (" ") << setw(35) << left << "Total pembayaran : " << harga_diskon << endl;
     cout << endl;
     cout << setfill (" ") << setw(35) << left << "Jumlah uang yang dibayarkan : " << uang_dibayarkan << endl;
     cout << setfill (" ") << setw(35) << left << "Jumlah kembalian : " << kembalian << endl;
     cout << "--------------------------------------------------------" << endl;
        }else if (uang_dibayarkan < harga_diskon){
            cout << "Maaf uang anda kurang";
            return 1;
        }
    } else if (harga_menu < 60000 )
    {
        if (uang_dibayarkan >= harga_menu)
         cout << "++====================================================++" << endl;
     cout << "||                   NOTA PEMBELIAN                   ||" << endl;
     cout << "++====================================================++" << endl;
     cout << "Kode transaksi  : " << kode_transaksi << endl;
     cout << "Nama pembeli    : " << nama_pembeli << endl;
     cout << "Nama menu :     : " << nama_menu << endl;
     cout << "Banyak pesan an : " << banyak_pesanan << endl;
     cout << "Harga per porsi : " << harga << endl;
     cout << endl;
     cout << "--------------------------------------------------------" << endl;
     cout << endl;
     cout << setfill (" ") << setw(35) << left << "Total harga : " << harga_menu << endl;
     cout << setfill (" ") << setw(35) << left << "Total pemabayaran : " << harga_menu << endl;
     cout << "---------------------------------------------------------" << endl;
     cout << setfill (" ") << setw(35) << left << "Jumlah uang yang dibayarkan : " << uang_dibayarkan << endl;
     cout << setfill (" ") << setw(35) << left << "Jumlah kembalian : " << kembalian << endl;
     cout << "--------------------------------------------------------" << endl;
    }else if (uang_dibayarkan < harga_menu)
    {
        cout << "Maaf uang anda kurang";
    }
    

}

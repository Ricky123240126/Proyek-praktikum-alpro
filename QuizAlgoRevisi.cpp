#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
 main ()
{
    string username, nama_pembeli, nama_menu;
    int password, harga, harga_menu, nomor_menu, banyak_pesanan, kembalian, harga_diskon,  uang_dibayarkan,  kode_transaksi ;
    

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
        exit(0);
    }
    cout << endl;

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
        cout << "\nNama Menu : DOUBLE-DOUBLE";
        cout << "\nHarga per porsi : 60000 rupiah";
        harga = 60000;
        nama_menu = "DOUBLE-DOUBLE";
    }else  if (nomor_menu == 2){
        cout << "\nNama Menu : CHEESEBURGER";
        cout << "\nHarga per porsi : 42000 rupiah";
        harga = 42000;
        nama_menu = "CHEESEBURGER";
    }else  if (nomor_menu == 3){
        cout << "\nNama Menu : HAMBURGER";
        cout << "\nHarga per porsi : 35000 rupiah";
        harga = 35000;
        nama_menu = "HAMBURGER";
    }else  if (nomor_menu == 4){
        cout << "\nNama Menu : FRENCH FRIES";
        cout << "\nHarga per porsi : 30000 rupiah";
        harga = 30000;
        nama_menu = "FRENCH FRIES";
    }else  if (nomor_menu == 5){
        cout << "\nNama Menu : SHAKES";
        cout << "\nHarga per porsi : 35000 rupiah";
        harga = 35000;
        nama_menu = "SHAKES";
    }else  if (nomor_menu == 6){
        cout << "\nNama Menu : COKE";
        cout << "\nHarga per porsi : 23000 rupiah";
        harga = 23000;
        nama_menu = "COKE";
    }else  if (nomor_menu == 7){
        cout << "\nNama Menu : DIET COKES";
        cout << "\nHarga per porsi : 25000 rupiah";
        harga = 25000;
        nama_menu = "DIET COKES";
    }else  if (nomor_menu == 8){
        cout << "\nNama Menu : MILK";
        cout << "\nHarga per porsi : 15000 rupiah";
        harga = 15000;
        nama_menu = "MILK";
    }else  if (nomor_menu == 9){
        cout << "\nNama Menu : HOT COCOA";
        cout << "\nHarga per porsi : 20000 rupiah";
        harga = 20000;
        nama_menu = "HOT COCOA";
    }else  if (nomor_menu == 10){
        cout << "\nNama Menu : COFFEE";
        cout << "\nHarga per porsi : 18000 rupiah";
        harga = 18000;
        nama_menu = "COFFEE";
    }else {
        cout << "\nMenu yang anda pilih tidak ada";
        exit(0);
    }
    cout << "\nbanyak pesanan : ";
    cin >> banyak_pesanan;
    harga_menu = harga * banyak_pesanan;
    cout << "\nharga menu : " << harga_menu;   
 
}

#include <iostream>
using namespace std;
main()
{ int nomor, angka;
 char nama;
 cout<<"Nomor = ";cin>>nomor; //input 1 digit terakhir NIM Anda
 cout<<"Nama = ";cin>>nama; //input 1 karakter awal nama Anda(lowercase)
 angka = (nomor+1)*100 % 2;
 switch (angka){
 case 1 : if (nomor >= 5 && nama >= 'p')
 nomor = (angka+nomor)+nomor/2+1;
 else nomor = (angka+nomor)-nomor/2+2;
 angka = (angka+1)*2+nomor;
 case 0 : if (nomor <= 4 && nama >= 'j')
 angka = (angka+nomor)+nomor/2+1;
 else angka = (angka+nomor)-nomor/2+2;
 nomor = (angka+1)*2+nomor;
 default: nomor = (angka+nomor)+nomor;
 angka = (angka+1)*2+nomor;
 }
 if (angka>5) cout<<"Hasil = "<< angka;
 else cout<<"Hasil = "<< nomor;
}

#include <iostream>
using namespace std;

struct pegawai{
    string nama, NIP;
    int hari,gajiPerhari;
    int totalGaji;
};

int main(){
    pegawai pgw[3];
    
    for (int i=0; i<3; i++)
    {
        cout << "DATA GAJI PEGAWAI\n";
        cout << "Nama : ";
        getline(cin, pgw[i].nama);
        cout << "NIP : ";
        cin >> pgw[i].NIP;
        cout << "hari kerja : "; 
        cin >> pgw[i].hari;
        cout << "gaji per hari : "; 
        cin >> pgw[i].gajiPerhari;
        pgw[i].totalGaji = pgw[i].hari*pgw[i].gajiPerhari;
        cin.ignore();
        cout << endl;

    }
    system ("cls");        
    cout << "DATA GAJI PEGAWAI\n";
    cout << "---------------------\n";
    for (int j=0; j<3; j++)
    {
        cout << "Nama : " << pgw[j].nama << endl;
        cout << "NIP : " << pgw[j].NIP << endl;
        cout << "Hari kerja : " << pgw[j].hari << endl;
        cout << "Gaji per hari : " << pgw[j].gajiPerhari << endl;
        cout << "Total Gaji : " << pgw[j].totalGaji << endl;
        cout << "---------------------\n";
    }

}
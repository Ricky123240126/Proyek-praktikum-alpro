#include <iostream>
using namespace std;

int nilai[10];
void mencariTertinggi();
int nilaiTertinggi = nilai[0];
int jumlahOrang = 0;

int main()
{
    system("cls");
    cout << "Selamat Datang!\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "Masukkan nilai mahasiswa ke " << i + 1 << " : ";
        cin >> nilai[i];
    }
    mencariTertinggi();
    for (int i = 0; i < 10; i++)
    {
        if (nilai[i] == nilaiTertinggi)
        {
            jumlahOrang++;
        }
    }
    cout << "Nilai tertinggi = " << nilaiTertinggi << endl;
    cout << "Banyaknya mahasiswa memiliki nilai tertinggi = " << jumlahOrang << endl;

}

void mencariTertinggi(){
    for (int i = 0; i < 10; i++)
    {
        if (nilai[i] > nilaiTertinggi)
        {
            nilaiTertinggi = nilai[i];
        }
    }
}
#include <iostream>
using namespace std;


void print(string daftarTeam[], int totalPoint[], int n)
{
    cout << "=============================" << endl;
    cout << "|     KLASEMEN SEMENTARA    |" << endl;
    cout << "=============================" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << daftarTeam[i] << " dengan point : " << totalPoint[i];
        cout << endl;
    }
}

void printFinal(string daftarTeam[], int totalPoint[], int n)
{
    cout << "=============================" << endl;
    cout << "|       KLASEMEN FINAL      |" << endl;
    cout << "=============================" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << daftarTeam[i] << " dengan point : " << totalPoint[i];
        cout << endl;
    }
}

void SelectionSort(string daftarTeam[], int totalPoint[], int n){
    int  k;
    for (int i = 0; i < n; i++){
    k = i;
        for (int j = i+1; j < n; j++){
            if (totalPoint[j] > totalPoint[k]){
                k=j;
            }
        }

        swap(totalPoint[i], totalPoint[k]);
        cout << "Iterasi ke-" << i+1<<" : " << endl;
        printFinal(daftarTeam, totalPoint, n);
    }
}

void InsertionSort(string daftarTeam[], int totalPoint[], int n){
    for (int i=0; i < n; i++){
        int temp = totalPoint[i];

        int j = i - 1;
        while (j >= 0 && totalPoint[j] < temp){
            totalPoint[j+1] = totalPoint[j];
            j = j-1;
        }

        totalPoint[j+1] = temp;
        cout << "Iterasi ke-" << i+1<<" : " << endl;
        printFinal(daftarTeam, totalPoint, n);
    }
}

int main()
{
    string daftarTeam[] = {"PERSIBA", "PSS", "PSIM", "PERSIKUP", "PERSIG"};
    int totalPoint[] = {35, 24, 25, 16, 26};
    int n = sizeof(totalPoint) / sizeof(totalPoint[0]);
    int pilihan;
    
    cout << "berikut daftar klasemen sementara : " << endl;
    print(daftarTeam, totalPoint, n);
    cout << endl;

    cout << "DAFTAR SORTING" << endl;
    cout << "1.selection sort" << endl;
    cout << "2.insertion sort" << endl;
    cout << "Masukkan sorting yang ingin dipakai : ";
    cin >> pilihan;
    switch (pilihan)
    {
        case 1:
        cout << "berikut daftar klasemen dengan selection sort : " << endl;
        SelectionSort(daftarTeam, totalPoint, n);
        break;

        case 2:
        cout << "berikut daftar klasemen dengan insertion sort : " << endl;
        InsertionSort(daftarTeam, totalPoint, n);
        break;

        default:
        cout << "pilihan tidak valid!";
        break;
    }
}
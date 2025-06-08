#include <iostream>
using namespace std;

int tambah (int a, int b);

int main(){
    int a;
    int b;
    cin >> a;
    cin >> b;
    int jumlah = tambah(a,b);
    cout << "hasil : " << jumlah << endl;
}

int tambah (int c, int d){
    int proses = c+d;
    return proses;
}
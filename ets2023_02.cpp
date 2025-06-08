#include <iostream>

using namespace std;
int main (){
    int tahun;

    cout << "tahun : ";
    cin >> tahun;

    if (tahun%4 == 0)
    {
        cout << tahun << " merupakan tahun kabisat";
    } else if (tahun%4 != 0)
    {
        cout << tahun << " bukan tahun kabisat";

    }
    
    
}


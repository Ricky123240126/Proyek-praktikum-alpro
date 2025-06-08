#include <iostream>
using namespace std;

int main (){
    int nilai;
    cout << "masukkan nilai : ";
    cin >> nilai;

    if(nilai ==100 && nilai>85){
        cout << "nilai anda adalah A" << endl;
    }else if(nilai >=70 && nilai<85 ){
        cout << "nilai anda adalah B" << endl;
    }else if (nilai >=50 && nilai<70){
        cout << "nilai anda adalah C" << endl;
    }else if(nilai <50 && nilai==0 ){
       cout << "CIE NGULANG" << endl;
    }else if(nilai >100 or nilai<0){
        cout << "nilai harus diantara 0 - 100" << endl;
    }
}
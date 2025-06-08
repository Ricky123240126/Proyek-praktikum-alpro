#include <iostream>
using namespace std;

float jumlah(float,float);

int main (){
    int a = 6;
    int b = 3;
    float c;

    c = jumlah(a,b);
    cout << "a + b = " << c;
    cout << "\nhasil penjumlahan : " << jumlah(20.1,0.9);
    return 0;
}
float jumlah (float x, float y){
    return (x+y);
}
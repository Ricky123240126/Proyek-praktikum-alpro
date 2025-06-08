#include <iostream>
using namespace std;

int pangkatI(int a, int b){
    int hasil = a;
    for (int i=1; i<b; i++)
    {
        hasil = hasil * a;
    }
    return hasil;
}
int pangkatRekursif(int a, int b){
    if (b == 1)
    {
        return a;
    }
    else if (b == 0)
    {
        return 1;
    }
    else
    {
        return a * pangkatRekursif(a, b - 1);
    }
}
int fibonacci(int a)
{
    if (a == 0 || a == 1)
    {
        return a;
    }
    else 
    {
        return fibonacci(a-1) + fibonacci(a-2);
    }
}

main(){
    int a,b;
    cout << "masukkan angka : ";
    cin >> a;
    cout << "masukkan pangkat : "; 
    cin >> b;
    cout << "hasil pangkat : " << pangkatRekursif(a, b) << endl;
}
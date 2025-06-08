#include <iostream>

using namespace std;
void luas();


main()
{
    luas();
} 
void luas(){
    int p,l,luas;
    cout << "panjang : ";
    cin >> p;
    cout << "lebar : ";
    cin >> l;
    luas = p*l;
    cout << "luas : " << luas;

}
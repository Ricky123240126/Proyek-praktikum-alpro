#include <iostream>
using namespace std;

int angkaMAX(int array[], int n) {

    if (n == 1) {
        return array[0];
    }
    else{
    return max(array[n - 1], angkaMAX(array, n - 1));
    }
}

int main() {
    int angka[] = {42, 64, 15, 17, 77};
    int panjangArray = sizeof(angka) / sizeof(angka[0]);
    int angkaTerbesar = angkaMAX(angka, panjangArray);
    cout << "Angka Terbesar yaitu = " << angkaTerbesar << endl;
    
    return 0;
}
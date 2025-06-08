#include <iostream>
using namespace std;

int main()
{
    float m = 0.5;
    int T_awal = 30;
    int c = 450;
    int T_akhir = 100;

    for (int i = 0; i < 10; i++)
    {
        float delta_T = T_akhir - T_awal;
        float Q = m * c * delta_T;
        cout << "suhu akhir : " << T_akhir << endl;
        cout << "kalor akhir : " << Q << endl;
        T_akhir += 10;
    }
}


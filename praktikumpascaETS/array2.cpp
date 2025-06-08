#include <iostream>

using namespace std;
int main()
{
    int a[4][2];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "masukkan data A[" << i << "][" << j << "J : ";
            cin >> a[i][j];
        }
        
    }
    
}
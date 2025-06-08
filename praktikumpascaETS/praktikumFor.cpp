#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int a = 3;
    int b = 3;

    int matriks[a][b];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matriks[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = b-1; j >= 0; j--)
        {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
    
    
}
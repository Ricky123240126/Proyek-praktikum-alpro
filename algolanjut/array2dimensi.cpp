#include <iostream>
using namespace std;

int main()
{
    int tatang[4][5] = {{11,22,33,44,55},{1,2,3,4,5},{5,4,3,2,1},{21,22,23,24,25}};

    for (int i=0 ; 0<i<=4 ; i++)
    {
        for (int j=0 ; 0<j<=5 ; j++)
        {
        cout << tatang[i][j] << " ";
        }
    }
    cout << endl;
}
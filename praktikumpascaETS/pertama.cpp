#include <iostream>

using namespace std;
 main ()
{
   int jml;
   int n;
   int n_1 = 1;
   int n_2 = 0;

    cout << "masukkan jumlah deret fibonacci : ";
    cin >> jml;

   for (int n = 1; n <= jml; n++)
   {
    n = n_1 + n_2;
    cout << n << " ";
    n_2 = n_1;
    n_1 = n;
   }
   
}
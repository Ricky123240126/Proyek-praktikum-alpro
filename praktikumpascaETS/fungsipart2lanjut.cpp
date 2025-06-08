#include <iostream>

using namespace std;

int max(int a, int b) {
    if (a > b)
    {
         return a;
    }else 
    {
         return b;
    }
}


int main()
{
    int a = 5, b = 3, c = 10;
    int maks = max(max(a,b),c);
    cout << maks;
}


    

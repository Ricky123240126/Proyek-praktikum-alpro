#include <iostream>

using namespace std;

int x[10] = {0,2,4,5,6,7,8,10,11};

void search_NonSentinel()
{
    bool found = false;
    int i = 0;
    int cari;
    cout << "masukkan angka yang ingin dicari = ";
    cin >> cari;

    while(i<10 && found==false)
    {
        if (x[i] == cari)
        {
            found = true;
        }
        else
        { 
        i++;
        }
    if (found)
    {
    cout << "ditemukan pada indeks ke " << i+1 ;
    }
}
}
void search_Sentinel()
{
    int i = 0;
    int search;
    cout << "masukkan angka yang ingin dicari = ";
    cin >> search;
    x[10] = search;

    while (x[i] != search)
    {
        i++;
    }
    if (i > 9)
    {
        cout << search << "angka tidak ada" << endl;
    }
    else 
    {
        cout << search << " di indeks ke-" << i << endl;
    }
void binary_Search()
{
    int first, mid, last, search;
    bool found = false;
    first = 0;
    last = 11;

    cout << "masukkan angka yang ingin dicari = ";
    cin >> search;

    while(!found && first <= last)
    {
        mid = (first + last) / 2;
        if (search == x[mid])
        {
            found = true;
        }
        else
        {
            if(search < x[mid])
            {
                last = mid - 1;
            }
            else
            {
                last mid + 1;
            }
        }
        if (found)
        {
            cout << "ditemukan pada indeks ke " << i+1 ;
        }
    }
}

}
int main()
{
    // search_Sentinel();
    // // search_NonSentinel();
    // binary_Search();
}
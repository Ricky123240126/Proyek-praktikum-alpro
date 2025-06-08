#include <iostream>

using namespace std;

struct buku{
    string nama;
    int harga;
};

// void search_NonSentinel()
// {
//     buku bk[5] = {
//         {"biologi", 27000},
//         {"mtk", 15000},
//         {"bindo", 30000},
//         {"fisika", 25000},
//         {"kimia", 20000}
//     };
//     bool found = false;
//     int i = 0;
//     int cari;
//     cout << "masukkan harga buku yang ingin dicari = ";
//     cin >> cari;

//     while(i<5 && found==false)
//     {
//         if (bk[i].harga == cari)
//         {
//             found = true;
//         }
//         else
//         { 
//         i++;
//         }
//     if (found)
//     {
//     cout << "buku ditemukan dengan judul " << bk[i].nama;
//     }
// }
// }
// void search_Sentinel()
// {
//     buku bk[5] = {
//         {"biologi", 27000},
//         {"bindo", 30000},
//         {"fisika", 25000},
//         {"mtk", 15000},
//         {"kimia", 20000}
//     };
//     int i = 0;
//     int search;
//     cout << "masukkan harga buku yang ingin dicari = ";
//     cin >> search;
//     bk[5] = search;

//     while (bk[i] != search)
//     {
//         i++;
//     }
//     if (i > 5)
//     {
//         cout << "buku dengan harga " << search << " tidak ada" << endl;
//     }
//     else 
//     {
//         cout << "buku dengan harga " << search << " ditemukan" << endl;
//     }
// }
void binary_Search()
{
    buku bk[5] = {
        {"mtk", 15000},
        {"kimia", 20000},
        {"fisika", 25000},
        {"biologi", 27000},
        {"bindo", 30000}
    };

    int first, mid, last, search;
    bool found = false;
    int i;
    first = 0;
    last = 4;
    cout << "masukkan buku dengan harga yang ingin dicari = ";
    cin >> search;

    while(!found && first <= last)
    {
        mid = (first + last) / 2;
        if (search == bk[mid].harga)
        {
            found = true;
        }
        else
        {
            if(search < bk[mid].harga)
            {
                last = mid - 1;
            }
            else
            {
                first = mid + 1;
            }
        }
        if (found)
        {
            cout << "buku ditemukan dengan judul " << bk[mid].nama;
        }
    }
    if (!found)
    {
        cout << "buku tidak ditemukan, baca lagi daftar buku nya kocak";
    }
}

int main()
{
    binary_Search();
}
#include <iostream>
#include <string>

using namespace std;
int main()
{

    string bonus, fungsional, lama, pendidikan;

    cout << "lama kerja : ";
    cin >> lama;
    cout << "Fungsional :";
    cin >> fungsional;
    cout << "pendidikan : ";
    cin >> pendidikan;
    if (lama == "X" ||  lama == "Y" || lama == "Z")
    {
        if (fungsional == "A" || fungsional == "B" || fungsional == "C")
        {
            if (pendidikan == "1" || pendidikan == "2" || pendidikan == "3")
            {
                cout << "Jenis bonus : cuti";
            }
        }
    }
}
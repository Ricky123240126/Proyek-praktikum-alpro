#include <iostream>
#include <string>

using namespace std;
int main (){
    string cuaca, kelembaban, angin;

    cout << "cuaca : ";
    cin >> cuaca;

    if (cuaca == "mendung")
    {
        cout << "bermain";
    }if (cuaca == "hujan")
    {
        cout << "angin : ";
        cin >> angin;
        if (angin == "berangin")
        {
            cout << "tidak bermain";
        }
    }if (cuaca == "cerah")
    {   
        cout << "kelembaban : ";
        cin >> kelembaban;
        if (kelembaban == "tinggi")
        {
            cout << "tidak bermain";
        }   
    }
}
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

struct pengguna {
    string no_rek;
    float saldo_akhir, uang, nominal;
    int i, randomNum;
    char pilih;
    string pin;
};

string nama[5] = {{"Ricky"}, {"Zaky"}, {"Yaya"}, {"Rifty"}, {"Okto"}};
string pengguna[5][2] = {{"123240095", "270105"}, {"123240096", "280104"}, {"123240101", "190805"}, {"123240108", "210505"}, {"123240114", "161006"}};
int saldo[5] = {500000, 600000, 800000, 500000, 600000};
int sisasaldo[5];


void menuInd(int i)
{
    char next = 'y';
    int menu;
    do
    {
        system("cls");
        cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
        cout << "|" << setiosflags(ios::left) << setw(9) << setfill(' ') << "" << "FUFUFAFAPAY" << setw(9) << setfill(' ') << "" << "|" << endl;
        cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "1. Informasi Saldo" << setw(9) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "2. Tarik Tunai" << setw(13) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "3. Setor Tunai" << setw(13) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "4. Transfer" << setw(16) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "5. Informasi Pengguna" << setw(6) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "6. Keluar" << setw(18) << setfill(' ') << "" << "|" << endl;
        cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
        cout << "Pilihan menu : ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
        }
        cout << "Apakah anda ingin melanjutkan transaksi? (y/n) : ";
        cin >> next;
    } while (next == 'y' || next == 'Y' && menu != 6);
}

void menuEng(int i)
{
    char next = 'y';
    int menu;
    do
    {
        system("cls");
        cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
        cout << "|" << setiosflags(ios::left) << setw(9) << setfill(' ') << "" << "FUFUFAFAPAY" << setw(9) << setfill(' ') << "" << "|" << endl;
        cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "1. Check Balance" << setw(11) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "2. Withdraw Money" << setw(10) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "3. Deposit Money" << setw(11) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "4. Transfer" << setw(16) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "5. Show User Details" << setw(7) << setfill(' ') << "" << "|" << endl;
        cout << "|" << setiosflags(ios::left) << setw(2) << setfill(' ') << "" << "6. Exit" << setw(20) << setfill(' ') << "" << "|" << endl;
        cout << setiosflags(ios::left) << setw(31) << setfill('=') << "" << endl;
        cout << "Pilihan menu : ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
        }
        cout << "Do you want to continue the transaction? (y/n) : ";
        cin >> next;
    } while (next == 'y' || next == 'Y' && menu != 6);
}

int main()
{
    system("cls");
    int batas = 0, language;
    cout << "      PILIH BAHASA      " << endl;
    cout << "-------------------------" << endl;
    cout << "   SELECT THE LANGUAGE   " << endl
         << endl;
    cout << "1. INDONESIA" << endl;
    cout << "2. ENGLISH" << endl
         << endl;
    cout << "PILIH / SELECT : ";
    cin >> language;
    if (language == 1)
    {
        while (batas != 3)
        {

            system("cls");

            string username, password;
            bool loginSukses = false;
            int userIndex;
            cout << "Username : ";
            cin >> username;
            cout << "Password : ";
            cin >> password;

            for (int i = 0; i < 5; i++)
            {
                if (username == pengguna[i][0] && password == pengguna[i][1])
                {
                    // cout << "Login Berhasil";
                    loginSukses = true;
                    userIndex = i;
                    break;
                }
            }
            if (loginSukses)
            {
                menuInd(userIndex);
                break;
            }
            else
            {
                batas++;
                if (batas < 3)
                {
                    cout << "Sisa Percobaan Login Anda " << 3 - batas << " Kali Percobaan\n";
                }
                else
                {
                    cout << "Percobaan Login Anda Telah Habis\n";
                }
            }
        }
    }
    else if (language == 2)
    {
        while (batas != 3)
        {
            system("cls");

            string username, password;
            bool loginSukses = false;
            int userIndex;
            cout << "Username : ";
            cin >> username;
            cout << "Password : ";
            cin >> password;

            for (int i = 0; i < 5; i++)
            {
                if (username == pengguna[i][0] && password == pengguna[i][1])
                {
                    // cout << "Login Berhasil";
                    loginSukses = true;
                    userIndex = i;
                    break;
                }
            }
            if (loginSukses)
            {
                menuEng(userIndex);
                break;
            }
            else
            {
                batas++;
                if (batas < 3)
                {
                    cout << "invalid username or password. You have " << 3 - batas << " chance to login.\n";
                }
                else
                {
                    cout << "You don't have more chance to login.\n";
                }
            }
        }
    }
    return 0;
}
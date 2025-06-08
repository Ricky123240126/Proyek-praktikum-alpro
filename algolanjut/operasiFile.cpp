#include <iostream>
#include <fstream>
#include <vector>
#include <ssstream>
#include <fstream>


using namespace std;

struct mahasiswa
{
    string id, nama;
};

string convertMahasiswaToString(mahasiswa mahasiswa)
{
    return mahasiswa.id + ", " + mahasiswa.nama;
}

int main()
{
    //fungsi read
    // ofstream ofs("coba.txt");
    // if(ofs.is_open())
    // {
    //     cout  << "berhasil" << endl;
    //     ofs << "hahahhahah";
    // ofs.close();
    // }
    // else
    // {
    //     cout << "ga bisa";
    // }
    // ofstream file(coba.txt);

    // file << "informatika";

    // file.close();
    // return 0;


    //fungsi hapus
    // ifstream fileOpen("coba.txt");
    // string lines[10];
    // int lineCounter = 0;
    
    // if(fileOpen.is_open())
    // {
    //     string line;
    //     while(getline(fileOpen, line))
    //     {
    //         if(line != "teknik elektro")
    //         {
                
    //             lines[lineCounter] = line;
    //             lineCounter++;
                
    //         }
    //     }
    // }
    // fileOpen.close();
    // ofstream fileInput("coba.txt");

    // for (int i = 0; i < lineCounter; i++)
    // {
    //     fileInput << lines[i] << endl;
    // }
    // fileInput.close();



    //fungsi update
    // ifstream fileOpen("coba.txt");
    // string lines[10];
    // int lineCounter = 0;
    
    // if(fileOpen.is_open())
    // {
    //     string line;
    //     while(getline(fileOpen, line))
    //     {
    //         if(line == "teknik elektro")
    //         {
    //             line  = "teknik kimia";
    //         }
    //         lines[lineCounter] = line;
    //         lineCounter++;
    //     }
    // }
    // fileOpen.close();

    // ofstream fileInput("coba.txt");

    // for (int i = 0; i < lineCounter; i++)
    // {
    //     fileInput << lines[i] << endl;
    // }
    // fileInput.close();



    mahasiswa ricky({"1", "Ricky"});
    ofstream file("mahasiswa.csv");
    file << convertMahasiswaToString;

    file.close();
}
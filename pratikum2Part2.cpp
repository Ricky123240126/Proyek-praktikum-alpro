#include <iostream>
using namespace std;

int main(){
    int A,B,C;
    cout << "nilai A : ";
    cin >> A;
    cout << "nilai B : ";
    cin >> B;
    cout << "nilai C : ";
    cin >> C;

    if(A>B && A>C){
       cout << "A paling besar" << endl;
    }if(B>A && B>C){
       cout << "B paling besar" << endl;
    }if(C>B && C>A){
       cout << "C paling besar" << endl;
    }




}
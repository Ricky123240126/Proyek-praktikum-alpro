#include <iostream>


using namespace std;
int main ()
{ 

  for (int i = 1; i <= 5 ; i++)
  {
    for (int j = i; j < 5 ; j++)
    {
      cout <<  " " ;
    }
    for (int j = 1; j <= (2*i-1) ; j++)
    {
      cout << "*";
    }
    
      cout << endl;
  }
    
  for (int i = 1; i < 5; i++)
  {
    for (int j = i ; j < (2*i)  ; j++)
    {
      cout << " ";
    }
    for (int j = 7; j >= (2*i-1); j--)
    {
      cout << "*";
    }
    
    cout << endl;
  }
  
}

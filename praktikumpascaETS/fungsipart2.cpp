#include <iostream>

using namespace std;

void printArray(int *array, int lenght);

main()
{
    int array[6] = {2,4,6,8,10,12};
    printArray(array, 6);

}

void printArray(int *array, int lenght){
    for (int i = 0; i < lenght; i++)
    {
    cout << array[i] << " ";
    }
    
}
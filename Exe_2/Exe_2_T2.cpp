#include <iostream>
#include <time.h>
using namespace std;

void invert(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        if (arr[i] != arr[size - 1 - i])
        {
            swap(arr[i], arr[size - 1 - i]);
        }
    }
}

int main()
{
    int size = 9;
    srand(time(NULL));
    int arr[size] = {0};
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    invert(arr, size);
    cout << "after invert" << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}